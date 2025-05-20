//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 100 // Maximum number of devices

// Struct to store device information
typedef struct device {
    char name[20];
    char ip_address[16];
    int num_connections;
    struct device* connections[MAX_DEVICES]; // Stores pointer to connected devices
} device;

// Function to add device to network
void add_device(device* devices[], int* num_devices) {
    if (*num_devices >= MAX_DEVICES) {
        printf("Error: Max number of devices reached\n");
        return;
    }
    device* new_device = (device*) malloc(sizeof(device));
    printf("Enter device name: ");
    scanf("%s", new_device->name);
    printf("Enter IP address: ");
    scanf("%s", new_device->ip_address);
    new_device->num_connections = 0;
    devices[*num_devices] = new_device;
    (*num_devices)++;
}

// Function to connect two devices in the network
void connect_devices(device* devices[], int num_devices) {
    char name1[20], name2[20];
    printf("Enter name of first device: ");
    scanf("%s", name1);
    printf("Enter name of second device: ");
    scanf("%s", name2);
    device* device1 = NULL;
    device* device2 = NULL;
    for (int i=0; i<num_devices; i++) {
        if (strcmp(devices[i]->name, name1) == 0) {
            device1 = devices[i];
        }
        if (strcmp(devices[i]->name, name2) == 0) {
            device2 = devices[i];
        }
    }
    if (device1 == NULL || device2 == NULL) {
        printf("Error: One or more devices not found\n");
        return;
    }
    if (device1->num_connections >= MAX_DEVICES || device2->num_connections >= MAX_DEVICES) {
        printf("Error: Max connections reached for one or both devices\n");
        return;
    }
    device1->connections[device1->num_connections] = device2;
    device1->num_connections++;
    device2->connections[device2->num_connections] = device1;
    device2->num_connections++;
}

// Function to print out network topology
void print_topology(device* devices[], int num_devices) {
    printf("Network Topology:\n");
    for (int i=0; i<num_devices; i++) {
        printf("%s (%s) -> ", devices[i]->name, devices[i]->ip_address);
        for (int j=0; j<devices[i]->num_connections; j++) {
            printf("%s ", devices[i]->connections[j]->name);
        }
        printf("\n");
    }
}

int main() {
    device* devices[MAX_DEVICES];
    int num_devices = 0;
    bool running = true;
    while (running) {
        printf("Options:\n");
        printf("1. Add device\n");
        printf("2. Connect devices\n");
        printf("3. Print topology\n");
        printf("4. Quit\n");
        printf("Enter option: ");
        int input;
        scanf("%d", &input);
        switch (input) {
            case 1:
                add_device(devices, &num_devices);
                break;
            case 2:
                connect_devices(devices, num_devices);
                break;
            case 3:
                print_topology(devices, num_devices);
                break;
            case 4:
                running = false;
                break;
            default:
                printf("Error: Invalid input\n");
                break;
        }
    }
    // Free device memory
    for (int i=0; i<num_devices; i++) {
        free(devices[i]);
    }
    return 0;
}