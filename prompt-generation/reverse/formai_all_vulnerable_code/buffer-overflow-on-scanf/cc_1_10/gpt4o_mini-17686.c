//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define NAME_LENGTH 50

typedef struct Device {
    char name[NAME_LENGTH];
    int connections[MAX_DEVICES];
    int connection_count;
} Device;

Device devices[MAX_DEVICES];
int device_count = 0;

void addDevice(char* name) {
    if (device_count < MAX_DEVICES) {
        strcpy(devices[device_count].name, name);
        devices[device_count].connection_count = 0;
        device_count++;
    } else {
        printf("Max device limit reached!\n");
    }
}

void connectDevices(int index1, int index2) {
    if (index1 < device_count && index2 < device_count) {
        devices[index1].connections[devices[index1].connection_count++] = index2;
        devices[index2].connections[devices[index2].connection_count++] = index1;
    } else {
        printf("Invalid device indices for connection!\n");
    }
}

void printNetworkTopology() {
    printf("Network Topology:\n");
    for (int i = 0; i < device_count; i++) {
        printf("Device %s is connected to: ", devices[i].name);
        for (int j = 0; j < devices[i].connection_count; j++) {
            printf("%s ", devices[devices[i].connections[j]].name);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    char name[NAME_LENGTH];
    int index1, index2;

    while (1) {
        printf("1. Add Device\n");
        printf("2. Connect Devices\n");
        printf("3. Print Network Topology\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", name);
                addDevice(name);
                break;

            case 2:
                printf("Enter two device indices to connect (0 to %d): ", device_count - 1);
                scanf("%d %d", &index1, &index2);
                connectDevices(index1, index2);
                break;

            case 3:
                printNetworkTopology();
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}