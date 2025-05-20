//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define constants
#define MAX_DEVICES 100
#define MAX_CONNECTIONS 500

// Define structs
typedef struct {
    char device_name[20];
    char device_ip[20];
    char device_type[10];
} Device;

typedef struct {
    int connection_id;
    char device1_name[20];
    char device1_port[10];
    char device2_name[20];
    char device2_port[10];
} Connection;

// Define global variables
Device devices[MAX_DEVICES]; // Array of devices
Connection connections[MAX_CONNECTIONS]; // Array of connections
int num_devices = 0; // Number of devices in array
int num_connections = 0; // Number of connections in array

// Function prototypes
void add_device();
void add_connection();
void view_devices();
void view_connections();
void map_topology();

int main() {
    int choice;

    while (1) {
        printf("\nNetwork Topology Mapper\n");
        printf("-----------------------\n");
        printf("1. Add Device\n");
        printf("2. Add Connection\n");
        printf("3. View Devices\n");
        printf("4. View Connections\n");
        printf("5. Map Topology\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_device();
                break;
            case 2:
                add_connection();
                break;
            case 3:
                view_devices();
                break;
            case 4:
                view_connections();
                break;
            case 5:
                map_topology();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Function to add a new device
void add_device() {
    if (num_devices >= MAX_DEVICES) {
        printf("Error: Maximum number of devices reached.\n");
        return;
    }

    printf("Enter device name: ");
    scanf("%s", devices[num_devices].device_name);
    printf("Enter device IP address: ");
    scanf("%s", devices[num_devices].device_ip);
    printf("Enter device type (Router/Switch/PC): ");
    scanf("%s", devices[num_devices].device_type);

    num_devices++;

    printf("Device added successfully.\n");
}

// Function to add a new connection
void add_connection() {
    if (num_connections >= MAX_CONNECTIONS) {
        printf("Error: Maximum number of connections reached.\n");
        return;
    }

    printf("Enter connection ID: ");
    scanf("%d", &connections[num_connections].connection_id);
    printf("Enter device 1 name: ");
    scanf("%s", connections[num_connections].device1_name);
    printf("Enter device 1 port: ");
    scanf("%s", connections[num_connections].device1_port);
    printf("Enter device 2 name: ");
    scanf("%s", connections[num_connections].device2_name);
    printf("Enter device 2 port: ");
    scanf("%s", connections[num_connections].device2_port);

    num_connections++;

    printf("Connection added successfully.\n");
}

// Function to view all devices
void view_devices() {
    printf("Device Name     IP Address     Type\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < num_devices; i++) {
        printf("%-15s%-15s%-10s\n", devices[i].device_name, devices[i].device_ip, devices[i].device_type);
    }
}

// Function to view all connections
void view_connections() {
    printf("Connection ID   Device 1       Port 1         Device 2       Port 2\n");
    printf("--------------------------------------------------------------------\n");

    for (int i = 0; i < num_connections; i++) {
        printf("%-15d%-15s%-15s%-15s%-15s\n", connections[i].connection_id, connections[i].device1_name, connections[i].device1_port, connections[i].device2_name, connections[i].device2_port);
    }
}

// Function to map the network topology
void map_topology() {
    // Create adjacency matrix
    int adj_matrix[MAX_DEVICES][MAX_DEVICES] = {0};

    // Fill adjacency matrix with connections
    for (int i = 0; i < num_connections; i++) {
        int device1_index = -1;
        int device2_index = -1;

        // Find index of device 1 in array
        for (int j = 0; j < num_devices; j++) {
            if (strcmp(connections[i].device1_name, devices[j].device_name) == 0) {
                device1_index = j;
                break;
            }
        }

        // Find index of device 2 in array
        for (int j = 0; j < num_devices; j++) {
            if (strcmp(connections[i].device2_name, devices[j].device_name) == 0) {
                device2_index = j;
                break;
            }
        }

        // Update adjacency matrix
        adj_matrix[device1_index][device2_index] = 1;
        adj_matrix[device2_index][device1_index] = 1;
    }

    // Print adjacency matrix
    printf("Device Name     ");
    for (int i = 0; i < num_devices; i++) {
        printf("%-15s", devices[i].device_name);
    }
    printf("\n");

    for (int i = 0; i < num_devices; i++) {
        printf("%-15s", devices[i].device_name);
        for (int j = 0; j < num_devices; j++) {
            printf("%-15d", adj_matrix[i][j]);
        }
        printf("\n");
    }
}