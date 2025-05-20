//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 20
#define MAX_CONNECTIONS 50

// Struct to store device information
typedef struct device {
    char name[20];
    char ip_address[16];
    char subnet_mask[16];
} device;

// Struct to store connection information
typedef struct connection {
    char device1[20];
    char device2[20];
    int port;
} connection;

// Function to add a new device
void add_device(device devices[], int *num_devices) {
    printf("Enter the device name: ");
    scanf("%s", devices[*num_devices].name);
    printf("Enter the device IP address: ");
    scanf("%s", devices[*num_devices].ip_address);
    printf("Enter the device subnet mask: ");
    scanf("%s", devices[*num_devices].subnet_mask);
    (*num_devices)++;
}

// Function to add a new connection
void add_connection(connection connections[], device devices[], int num_devices, int *num_connections) {
    char device1[20];
    char device2[20];
    int valid1 = false;
    int valid2 = false;
    
    // Ask for device names until a valid device is entered
    while (!valid1) {
        printf("Enter the name of the first device: ");
        scanf("%s", device1);
        for (int i = 0; i < num_devices; i++) {
            if (strcmp(devices[i].name, device1) == 0) {
                valid1 = true;
                break;
            }
        }
        if (!valid1) {
            printf("Invalid device name. Please try again.\n");
        }
    }
    
    // Ask for device names until a different valid device is entered
    while (!valid2) {
        printf("Enter the name of the second device: ");
        scanf("%s", device2);
        if (strcmp(device1, device2) == 0) {
            printf("Cannot connect a device to itself. Please try again.\n");
        } else {
            for (int i = 0; i < num_devices; i++) {
                if (strcmp(devices[i].name, device2) == 0) {
                    valid2 = true;
                    break;
                }
            }
            if (!valid2) {
                printf("Invalid device name. Please try again.\n");
            }
        }
    }
    
    // Add the connection
    strcpy(connections[*num_connections].device1, device1);
    strcpy(connections[*num_connections].device2, device2);
    printf("Enter the port number: ");
    scanf("%d", &connections[*num_connections].port);
    (*num_connections)++;
}

// Function to display all devices
void display_devices(device devices[], int num_devices) {
    printf("Devices:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%s, %s, %s\n", devices[i].name, devices[i].ip_address, devices[i].subnet_mask);
    }
}

// Function to display all connections
void display_connections(connection connections[], int num_connections) {
    printf("Connections:\n");
    for (int i = 0; i < num_connections; i++) {
        printf("%s-%d-%s\n", connections[i].device1, connections[i].port, connections[i].device2);
    }
}

int main() {
    device devices[MAX_DEVICES];
    connection connections[MAX_CONNECTIONS];
    int num_devices = 0;
    int num_connections = 0;
    char choice;
    
    while (true) {
        printf("\nMenu:\n");
        printf("1. Add new device\n");
        printf("2. Add new connection\n");
        printf("3. Display all devices\n");
        printf("4. Display all connections\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case '1':
                add_device(devices, &num_devices);
                break;
            case '2':
                add_connection(connections, devices, num_devices, &num_connections);
                break;
            case '3':
                display_devices(devices, num_devices);
                break;
            case '4':
                display_connections(connections, num_connections);
                break;
            case '5':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}