#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estructuras de Datos
struct Viajero {
    int id;
    string nombre;
    string lugarReside;
    string pasaporte;
    string nacionalidad;
    string fechaVencimientoVisa;
};

struct Ingreso {
    int idViajero;
    string fechaIngreso;
    string lugarIngreso;
    string lugarHospedaje;
    string motivoVisita;
    int tiempoEstadia; // en días
    bool visaAprobada;
    bool revisado;
    bool haVisitadoAntes;
};

struct Salida {
    int idViajero;
    string fechaSalida;
    string lugarSalida;
    string destino;
};

struct SistemaMigracion {
    vector<Viajero> viajeros;
    vector<Ingreso> ingresos;
    vector<Salida> salidas;
};

// Función para mostrar texto en color
void setColor(int color) {
    cout << "\033[1;" << color << "m";
}

void resetColor() {
    cout << "\033[0m";
}

// Autenticación de Usuario
bool autenticar() {
    string id;
    string contrasena;

    system("cls");
    setColor(33); // Amarillo
    cout << "Ingrese su ID de usuario: ";
    resetColor();
    cin >> id;

    setColor(33); // Amarillo
    cout << "Ingrese su contrasena: ";
    resetColor();
    cin >> contrasena;

    // Siempre retorna true para cualquier ID y contrasena
    return true;
}

// Mostrar Menú
void mostrarMenu() {
    system("cls");

    setColor(34); // Azul claro
    cout << "+------------------------------------------+" << endl;
    cout << "|              Sistema de Control          |" << endl;
    cout << "|              de Migracion                |" << endl;
    cout << "+------------------------------------------+" << endl;
    resetColor();

    setColor(32); // Verde
    cout << "| 1. Ingresar Viajero                      |" << endl;
    cout << "| 2. Registrar Ingreso                     |" << endl;
    cout << "| 3. Registrar Salida                     |" << endl;
    cout << "| 4. Consultar Informacion de Viajero      |" << endl;
    cout << "| 5. Generar Reporte                       |" << endl;
    cout << "| 6. Borrar Registro de Viajero            |" << endl;
    cout << "| 7. Salir                                |" << endl;
    resetColor();
    cout << "+------------------------------------------+" << endl;
    cout << "Selecciona una opcion: ";
}

// Ingresar Viajero
void ingresarViajero(SistemaMigracion& sistema) {
    Viajero nuevoViajero;
    system("cls");

    setColor(33); // Amarillo
    cout << "Ingrese ID del viajero: ";
    resetColor();
    cin >> nuevoViajero.id;
    setColor(33); // Amarillo
    cout << "Ingrese nombre: ";
    resetColor();
    cin.ignore();
    getline(cin, nuevoViajero.nombre);
    setColor(33); // Amarillo
    cout << "Ingrese lugar donde reside: ";
    resetColor();
    getline(cin, nuevoViajero.lugarReside);
    setColor(33); // Amarillo
    cout << "Ingrese pasaporte: ";
    resetColor();
    getline(cin, nuevoViajero.pasaporte);
    setColor(33); // Amarillo
    cout << "Ingrese nacionalidad: ";
    resetColor();
    getline(cin, nuevoViajero.nacionalidad);
    setColor(33); // Amarillo
    cout << "Ingrese fecha de vencimiento de la visa (DD/MM/AAAA): ";
    resetColor();
    getline(cin, nuevoViajero.fechaVencimientoVisa);

    sistema.viajeros.push_back(nuevoViajero);

    setColor(32); // Verde
    cout << "Viajero ingresado exitosamente." << endl;
    resetColor();
    system("pause");
}

// Registrar Ingreso
void registrarIngreso(SistemaMigracion& sistema) {
    Ingreso nuevoIngreso;
    int id;
    system("cls");

    setColor(33); // Amarillo
    cout << "Ingrese ID del viajero: ";
    resetColor();
    cin >> id;

    vector<Viajero>::iterator it;
    for (it = sistema.viajeros.begin(); it != sistema.viajeros.end(); ++it) {
        if (it->id == id) {
            break;
        }
    }

    if (it != sistema.viajeros.end()) {
        nuevoIngreso.idViajero = id;
        setColor(33); // Amarillo
        cout << "Ingrese fecha de ingreso (DD/MM/AAAA): ";
        resetColor();
        cin >> nuevoIngreso.fechaIngreso;
        setColor(33); // Amarillo
        cout << "Ingrese lugar de ingreso: ";
        resetColor();
        cin.ignore();
        getline(cin, nuevoIngreso.lugarIngreso);
        setColor(33); // Amarillo
        cout << "Ingrese lugar de hospedaje: ";
        resetColor();
        getline(cin, nuevoIngreso.lugarHospedaje);
        setColor(33); // Amarillo
        cout << "Ingrese motivo de visita: ";
        resetColor();
        getline(cin, nuevoIngreso.motivoVisita);
        setColor(33); // Amarillo
        cout << "Ingrese tiempo de estadia (días): ";
        resetColor();
        cin >> nuevoIngreso.tiempoEstadia;
        setColor(33); // Amarillo
        cout << "¿Se realizó revisión del viajero? (1 para sí, 0 para no): ";
        resetColor();
        cin >> nuevoIngreso.revisado;

        // Verificar visa
        string fechaVencimiento = it->fechaVencimientoVisa;
        // Simplificación: se asume que la fecha de vencimiento está en el formato DD/MM/AAAA
        // y solo se comprueba el año
        string anioVencimiento = fechaVencimiento.substr(6, 4);
        nuevoIngreso.visaAprobada = (anioVencimiento >= "2024");
        sistema.ingresos.push_back(nuevoIngreso);

        setColor(32); // Verde
        cout << "Ingreso registrado exitosamente." << endl;
        resetColor();
    } else {
        setColor(31); // Rojo
        cout << "Viajero no encontrado." << endl;
        resetColor();
    }
    system("pause");
}

// Registrar Salida
void registrarSalida(SistemaMigracion& sistema) {
    Salida nuevaSalida;
    int id;
    system("cls");

    setColor(33); // Amarillo
    cout << "Ingrese ID del viajero: ";
    resetColor();
    cin >> id;

    vector<Viajero>::iterator it;
    for (it = sistema.viajeros.begin(); it != sistema.viajeros.end(); ++it) {
        if (it->id == id) {
            break;
        }
    }

    if (it != sistema.viajeros.end()) {
        nuevaSalida.idViajero = id;
        setColor(33); // Amarillo
        cout << "Ingrese fecha de salida (DD/MM/AAAA): ";
        resetColor();
        cin >> nuevaSalida.fechaSalida;
        setColor(33); // Amarillo
        cout << "Ingrese lugar de salida: ";
        resetColor();
        cin.ignore();
        getline(cin, nuevaSalida.lugarSalida);
        setColor(33); // Amarillo
        cout << "Ingrese destino: ";
        resetColor();
        getline(cin, nuevaSalida.destino);

        sistema.salidas.push_back(nuevaSalida);

        setColor(32); // Verde
        cout << "Salida registrada exitosamente." << endl;
        resetColor();
    } else {
        setColor(31); // Rojo
        cout << "Viajero no encontrado." << endl;
        resetColor();
    }
    system("pause");
}

// Consultar Información de Viajero
void consultarInformacionViajero(SistemaMigracion& sistema) {
    int id;
    system("cls");

    setColor(33); // Amarillo
    cout << "Ingrese ID del viajero: ";
    resetColor();
    cin >> id;

    vector<Viajero>::iterator it;
    for (it = sistema.viajeros.begin(); it != sistema.viajeros.end(); ++it) {
        if (it->id == id) {
            break;
        }
    }

    if (it != sistema.viajeros.end()) {
        setColor(32); // Verde
        cout << "Nombre: " << it->nombre << endl;
        cout << "Lugar de residencia: " << it->lugarReside << endl;
        cout << "Pasaporte: " << it->pasaporte << endl;
        cout << "Nacionalidad: " << it->nacionalidad << endl;
        cout << "Fecha de vencimiento de la visa: " << it->fechaVencimientoVisa << endl;
        resetColor();
    } else {
        setColor(31); // Rojo
        cout << "Viajero no encontrado." << endl;
        resetColor();
    }
    system("pause");
}

// Generar Reporte
void generarReporte(SistemaMigracion& sistema) {
    system("cls");

    setColor(34); // Azul claro
    cout << "+------------------------------------------+" << endl;
    cout << "|               Reporte de Viajeros        |" << endl;
    cout << "+------------------------------------------+" << endl;
    resetColor();

    for (vector<Viajero>::iterator it = sistema.viajeros.begin(); it != sistema.viajeros.end(); ++it) {
        setColor(32); // Verde
        cout << "ID: " << it->id << endl;
        cout << "Nombre: " << it->nombre << endl;
        cout << "Lugar de residencia: " << it->lugarReside << endl;
        cout << "Pasaporte: " << it->pasaporte << endl;
        cout << "Nacionalidad: " << it->nacionalidad << endl;
        cout << "Fecha de vencimiento de la visa: " << it->fechaVencimientoVisa << endl;
        cout << "---------------------------------" << endl;
        resetColor();
    }

    system("pause");
}

// Borrar Registro de Viajero
void borrarRegistroViajero(SistemaMigracion& sistema) {
    int id;
    system("cls");

    setColor(33); // Amarillo
    cout << "Ingrese ID del viajero a borrar: ";
    resetColor();
    cin >> id;

    vector<Viajero>::iterator it = sistema.viajeros.begin();
    while (it != sistema.viajeros.end()) {
        if (it->id == id) {
            it = sistema.viajeros.erase(it);
            setColor(32); // Verde
            cout << "Registro de viajero borrado exitosamente." << endl;
            resetColor();
            return;
        } else {
            ++it;
        }
    }

    setColor(31); // Rojo
    cout << "Viajero no encontrado." << endl;
    resetColor();
    system("pause");
}

// Función Principal
int main() {
    SistemaMigracion sistema;
    int opcion;

    if (!autenticar()) {
        cout << "Autenticacion fallida. Saliendo del sistema." << endl;
        return 1;
    }

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarViajero(sistema);
                break;
            case 2:
                registrarIngreso(sistema);
                break;
            case 3:
                registrarSalida(sistema);
                break;
            case 4:
                consultarInformacionViajero(sistema);
                break;
            case 5:
                generarReporte(sistema);
                break;
            case 6:
                borrarRegistroViajero(sistema);
                break;
            case 7:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente nuevamente." << endl;
                system("pause");
                break;
        }
    } while (opcion != 7);

    return 0;
}
//para las demas opciones usar el mismo id que se le asigno al viajero que ingresó

