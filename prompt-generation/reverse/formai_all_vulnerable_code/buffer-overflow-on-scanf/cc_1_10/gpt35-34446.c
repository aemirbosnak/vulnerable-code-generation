//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 50
#define MAX_CONNECTIONS 100

// Struct to hold device data
typedef struct Device {
    char name[20];
    char ip[16];
    char mac[18];
} Device;

// Struct to hold connection data
typedef struct Connection {
    char device1[20];
    char device2[20];
} Connection;

// Arrays to hold devices and connections
Device devices[MAX_DEVICES];
Connection connections[MAX_CONNECTIONS];

// Function to add a new device
void addDevice() {
    bool deviceExists = false;
    char name[20], ip[16], mac[18];
    
    printf("Enter the name of the device: ");
    scanf("%s", name);
    
    // Check if device already exists
    for (int i = 0; i < MAX_DEVICES; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            printf("Device already exists.\n");
            deviceExists = true;
            break;
        }
    }
    
    // Add new device if it doesn't exist
    if (!deviceExists) {
        printf("Enter the IP address of the device: ");
        scanf("%s", ip);
        
        printf("Enter the MAC address of the device: ");
        scanf("%s", mac);
        
        Device newDevice;
        strcpy(newDevice.name, name);
        strcpy(newDevice.ip, ip);
        strcpy(newDevice.mac, mac);
        
        // Find the first empty slot in the devices array
        for (int i = 0; i < MAX_DEVICES; i++) {
            if (strlen(devices[i].name) == 0) {
                devices[i] = newDevice;
                printf("Device added successfully.\n");
                break;
            }
        }
    }
}

// Function to add a new connection
void addConnection() {
    char device1[20], device2[20];
    bool device1Exists = false, device2Exists = false;
    
    printf("Enter the name of the first device: ");
    scanf("%s", device1);
    
    // Check if first device exists
    for (int i = 0; i < MAX_DEVICES; i++) {
        if (strcmp(devices[i].name, device1) == 0) {
            device1Exists = true;
            break;
        }
    }
    
    // Check if second device exists
    printf("Enter the name of the second device: ");
    scanf("%s", device2);
    
    for (int i = 0; i < MAX_DEVICES; i++) {
        if (strcmp(devices[i].name, device2) == 0) {
            device2Exists = true;
            break;
        }
    }
    
    // Add new connection if both devices exist
    if (device1Exists && device2Exists) {
        Connection newConnection;
        strcpy(newConnection.device1, device1);
        strcpy(newConnection.device2, device2);
        
        // Find the first empty slot in the connections array
        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            if (strlen(connections[i].device1) == 0 && strlen(connections[i].device2) == 0) {
                connections[i] = newConnection;
                printf("Connection added successfully.\n");
                break;
            }
        }
    } else {
        printf("One or both devices do not exist.\n");
    }
}

// Function to print all the devices and connections
void printTopology() {
    printf("Devices:\n");
    for (int i = 0; i < MAX_DEVICES; i++) {
        if (strlen(devices[i].name) > 0) {
            printf("Name: %s | IP: %s | MAC: %s\n", devices[i].name, devices[i].ip, devices[i].mac);
        }
    }
    
    printf("\nConnections:\n");
    for (int i = 0; i < MAX_CONNECTIONS; i++) {
        if (strlen(connections[i].device1) > 0 && strlen(connections[i].device2) > 0) {
            printf("%s connected to %s\n", connections[i].device1, connections[i].device2);
        }
    }
}

// Main function
int main() {
    int choice;
    
    while (true) {
        printf("\nEnter your choice:\n");
        printf("1. Add device\n");
        printf("2. Add connection\n");
        printf("3. Print topology\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addDevice();
                break;
            case 2:
                addConnection();
                break;
            case 3:
                printTopology();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    
    return 0;
}