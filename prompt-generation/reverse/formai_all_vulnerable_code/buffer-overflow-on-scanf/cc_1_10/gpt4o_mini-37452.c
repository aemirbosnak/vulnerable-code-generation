//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_CONNECTIONS 10

typedef struct Connection {
    int deviceIndex;
    struct Connection* next;
} Connection;

typedef struct Device {
    char name[50];
    Connection* connections;
} Device;

Device network[MAX_DEVICES];
int deviceCount = 0;

void addDevice(char* name) {
    if (deviceCount >= MAX_DEVICES) {
        printf("Device limit reached. Cannot add more devices.\n");
        return;
    }
    strcpy(network[deviceCount].name, name);
    network[deviceCount].connections = NULL;
    deviceCount++;
    printf("Device %s added.\n", name);
}

void addConnection(int device1Index, int device2Index) {
    if (device1Index >= deviceCount || device2Index >= deviceCount) {
        printf("Invalid device index.\n");
        return;
    }

    Connection* conn1 = (Connection*)malloc(sizeof(Connection));
    conn1->deviceIndex = device2Index;
    conn1->next = network[device1Index].connections;
    network[device1Index].connections = conn1;

    Connection* conn2 = (Connection*)malloc(sizeof(Connection));
    conn2->deviceIndex = device1Index;
    conn2->next = network[device2Index].connections;
    network[device2Index].connections = conn2;

    printf("Connection added between %s and %s.\n", network[device1Index].name, network[device2Index].name);
}

void displayNetwork() {
    printf("Network Topology:\n");
    for (int i = 0; i < deviceCount; i++) {
        printf("%s:\n", network[i].name);
        Connection* conn = network[i].connections;
        while (conn) {
            printf("  - Connected to %s\n", network[conn->deviceIndex].name);
            conn = conn->next;
        }
        printf("\n");
    }
}

void freeConnections(int deviceIndex) {
    Connection* current = network[deviceIndex].connections;
    while (current) {
        Connection* temp = current;
        current = current->next;
        free(temp);
    }
    network[deviceIndex].connections = NULL;
}

void clearNetwork() {
    for (int i = 0; i < deviceCount; i++) {
        freeConnections(i);
    }
    deviceCount = 0;
}

int main() {
    int choice, deviceIndex1, deviceIndex2;
    char deviceName[50];

    while (1) {
        printf("1. Add Device\n");
        printf("2. Add Connection\n");
        printf("3. Display Network\n");
        printf("4. Clear Network\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", deviceName);
                addDevice(deviceName);
                break;
            case 2:
                printf("Enter the indices of two devices to connect (0 to %d): ", deviceCount - 1);
                scanf("%d %d", &deviceIndex1, &deviceIndex2);
                addConnection(deviceIndex1, deviceIndex2);
                break;
            case 3:
                displayNetwork();
                break;
            case 4:
                clearNetwork();
                printf("Network cleared.\n");
                break;
            case 5:
                clearNetwork();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}