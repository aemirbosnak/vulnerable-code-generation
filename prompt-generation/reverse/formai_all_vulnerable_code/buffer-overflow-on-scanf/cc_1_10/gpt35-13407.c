//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_DEVICES 50
#define MAX_CONNECTIONS 100

typedef struct Device {
    char name[20];
    char ip_address[15];
    char mac_address[18];
} Device;

typedef struct Connection {
    char device1_name[20];
    char device2_name[20];
} Connection;

void display_menu();
void add_device(Device devices[], int* num_devices);
void add_connection(Connection connections[], int* num_connections, Device devices[], int num_devices);
void display_topology(Device devices[], int num_devices, Connection connections[], int num_connections);
void clear_buffer();

int main() {
    Device devices[MAX_DEVICES];
    Connection connections[MAX_CONNECTIONS];
    int num_devices = 0;
    int num_connections = 0;
    char choice;

    printf("Welcome to the Network Topology Mapper!\n");

    do {
        display_menu();

        printf("Enter your choice: ");
        scanf(" %c", &choice);
        clear_buffer();

        switch (choice) {
            case '1':
                add_device(devices, &num_devices);
                break;
            case '2':
                add_connection(connections, &num_connections, devices, num_devices);
                break;
            case '3':
                display_topology(devices, num_devices, connections, num_connections);
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != '4');

    return 0;
}

void display_menu() {
    printf("\nMenu:\n");
    printf("1. Add device\n");
    printf("2. Add connection\n");
    printf("3. Display topology\n");
    printf("4. Exit\n");
}

void add_device(Device devices[], int* num_devices) {
    Device new_device;

    printf("Enter name of device: ");
    fgets(new_device.name, sizeof(new_device.name), stdin);

    printf("Enter IP address of device: ");
    fgets(new_device.ip_address, sizeof(new_device.ip_address), stdin);

    printf("Enter MAC address of device: ");
    fgets(new_device.mac_address, sizeof(new_device.mac_address), stdin);

    devices[(*num_devices)++] = new_device;

    printf("Device successfully added!\n");
}

void add_connection(Connection connections[], int* num_connections, Device devices[], int num_devices) {
    char device1_name[20];
    char device2_name[20];
    bool device1_found = false;
    bool device2_found = false;

    printf("Enter name of first device: ");
    fgets(device1_name, sizeof(device1_name), stdin);

    printf("Enter name of second device: ");
    fgets(device2_name, sizeof(device2_name), stdin);

    for (int i = 0; i < num_devices; i++) {
        if (strcmp(devices[i].name, device1_name) == 0) {
            device1_found = true;
        }
        if (strcmp(devices[i].name, device2_name) == 0) {
            device2_found = true;
        }
    }

    if (device1_found && device2_found) {
        Connection new_connection;
        strcpy(new_connection.device1_name, device1_name);
        strcpy(new_connection.device2_name, device2_name);
        connections[(*num_connections)++] = new_connection;
        printf("Connection successfully added!\n");
    } else {
        printf("One or both of the devices could not be found, please try again.\n");
    }
}

void display_topology(Device devices[], int num_devices, Connection connections[], int num_connections) {
    printf("\nTopology:\n\n");

    for (int i = 0; i < num_connections; i++) {
        printf("%s <----> %s\n", connections[i].device1_name, connections[i].device2_name);
    }

    printf("\nDevices:\n\n");

    for (int i = 0; i < num_devices; i++) {
        printf("Name: %s", devices[i].name);
        printf("IP Address: %s", devices[i].ip_address);
        printf("MAC Address: %s", devices[i].mac_address);
        printf("\n");
    }
}

void clear_buffer() {
    while(getchar() != '\n');
}