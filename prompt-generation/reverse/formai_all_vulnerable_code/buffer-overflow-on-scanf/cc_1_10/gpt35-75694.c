//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DEVICES 100
#define MAX_CONNECTIONS 100
#define MAX_NAME_LENGTH 20

struct Device {
    int id;
    char name[MAX_NAME_LENGTH];
    char ip_address[16];
};

struct Connection {
    int id;
    int device1_id;
    int device2_id;
    float latency;
};

int device_count = 0;
struct Device devices[MAX_DEVICES];

int connection_count = 0;
struct Connection connections[MAX_CONNECTIONS];

void addDevice() {
    if (device_count >= MAX_DEVICES) {
        printf("Maximum number of devices exceeded.\n");
        return;
    }
    
    struct Device device;
    device.id = device_count + 1;
    
    printf("Enter device name: ");
    scanf("%s", device.name);
    
    printf("Enter device IP address: ");
    scanf("%s", device.ip_address);
    
    devices[device_count++] = device;
    printf("Device added.\n");
}

void addConnection() {
    if (connection_count >= MAX_CONNECTIONS) {
        printf("Maximum number of connections exceeded.\n");
        return;
    }
    
    struct Connection connection;
    connection.id = connection_count + 1;
    
    printf("Enter ID of first device: ");
    scanf("%d", &connection.device1_id);
    
    printf("Enter ID of second device: ");
    scanf("%d", &connection.device2_id);
    
    printf("Enter latency between devices (in ms): ");
    scanf("%f", &connection.latency);
    
    connections[connection_count++] = connection;
    printf("Connection added.\n");
}

void printDevices() {
    printf("=== Devices ===\n");
    for (int i = 0; i < device_count; i++) {
        printf("ID: %d, Name: %s, IP Address: %s\n", devices[i].id, devices[i].name, devices[i].ip_address);
    }
}

void printConnections() {
    printf("=== Connections ===\n");
    for (int i = 0; i < connection_count; i++) {
        printf("ID: %d, Device 1 ID: %d, Device 2 ID: %d, Latency: %.2fms\n", connections[i].id, connections[i].device1_id, connections[i].device2_id, connections[i].latency);
    }
}

void showMenu() {
    printf("\n=== Network Topology Mapper ===\n");
    printf("1. Add device\n");
    printf("2. Add connection\n");
    printf("3. Print devices\n");
    printf("4. Print connections\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    
    do {
        showMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addDevice();
                break;
            case 2:
                addConnection();
                break;
            case 3:
                printDevices();
                break;
            case 4:
                printConnections();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}