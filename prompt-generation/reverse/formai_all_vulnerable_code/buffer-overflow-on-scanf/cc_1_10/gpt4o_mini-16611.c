//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 50
#define MAX_NAME_LENGTH 30

typedef struct Device {
    char name[MAX_NAME_LENGTH];
    struct Device* connections[MAX_DEVICES];
    int connectionCount;
} Device;

Device* devices[MAX_DEVICES];
int deviceCount = 0;

void addDevice(const char* name) {
    if (deviceCount >= MAX_DEVICES) {
        printf("Error: Cannot add more devices.\n");
        return;
    }
    Device* newDevice = (Device*)malloc(sizeof(Device));
    strncpy(newDevice->name, name, MAX_NAME_LENGTH);
    newDevice->connectionCount = 0;
    devices[deviceCount++] = newDevice;
}

void addConnection(const char* deviceName1, const char* deviceName2) {
    Device *dev1 = NULL, *dev2 = NULL;

    for (int i = 0; i < deviceCount; i++) {
        if (strcmp(devices[i]->name, deviceName1) == 0)
            dev1 = devices[i];
        if (strcmp(devices[i]->name, deviceName2) == 0)
            dev2 = devices[i];
    }

    if (dev1 && dev2 && dev1 != dev2) {
        dev1->connections[dev1->connectionCount++] = dev2;
        dev2->connections[dev2->connectionCount++] = dev1;
    } else {
        printf("Connection could not be established between %s and %s.\n", deviceName1, deviceName2);
    }
}

void printNetworkTopology(Device* device, int visited[]) {
    if (visited[device - devices[0]]) return; // Convert pointer to index
    visited[device - devices[0]] = 1; // Mark as visited
    
    printf("%s\n", device->name);
    
    for (int i = 0; i < device->connectionCount; i++) {
        printNetworkTopology(device->connections[i], visited);
    }
}

void displayTopology() {
    printf("Network Topology:\n");
    int visited[MAX_DEVICES] = {0}; // Initialize all as not visited
    
    for (int i = 0; i < deviceCount; i++) {
        if (!visited[i]) {
            printNetworkTopology(devices[i], visited);
        }
    }
}

void freeMemory() {
    for (int i = 0; i < deviceCount; i++) {
        free(devices[i]);
    }
}

int main() {
    int choice;
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];

    do {
        printf("\n--- Network Topology Mapper ---\n");
        printf("1. Add Device\n");
        printf("2. Add Connection\n");
        printf("3. Display Network Topology\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", name1);
                addDevice(name1);
                break;
            case 2:
                printf("Enter first device name: ");
                scanf("%s", name1);
                printf("Enter second device name: ");
                scanf("%s", name2);
                addConnection(name1, name2);
                break;
            case 3:
                displayTopology();
                break;
            case 4:
                freeMemory();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    
    return 0;
}