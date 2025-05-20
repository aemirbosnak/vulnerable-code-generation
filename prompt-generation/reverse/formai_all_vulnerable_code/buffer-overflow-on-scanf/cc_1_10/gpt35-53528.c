//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 10

typedef struct Device {
    char name[20];
    char ip[16];
    int neighbors[MAX_DEVICES];
} Device;

typedef struct Network {
    int num_devices;
    Device devices[MAX_DEVICES];
} Network;

void add_device(Network *network, char *name, char *ip) {
    Device device;
    strcpy(device.name, name);
    strcpy(device.ip, ip);
    device.neighbors[0] = -1;
    network->devices[network->num_devices] = device;
    network->num_devices++;
    printf("Device %s with IP %s added to network.\n", name, ip);
}

void add_neighbor(Network *network, char *device, char *neighbor) {
    int device_index = -1, neighbor_index = -1;
    for (int i = 0; i < network->num_devices; i++) {
        if (strcmp(network->devices[i].name, device) == 0) {
            device_index = i;
        }
        if (strcmp(network->devices[i].name, neighbor) == 0) {
            neighbor_index = i;
        }
    }
    if (device_index == -1 || neighbor_index == -1) {
        printf("Device or neighbor not found.\n");
        return;
    }
    int i = 0;
    while (network->devices[device_index].neighbors[i] != -1) {
        i++;
    }
    network->devices[device_index].neighbors[i] = neighbor_index;
    network->devices[device_index].neighbors[i+1] = -1;
    printf("Device %s added as neighbor to %s.\n", neighbor, device);
}

void print_topology(Network *network) {
    printf("====== NETWORK TOPOLOGY ======\n");
    for (int i = 0; i < network->num_devices; i++) {
        printf("%s (%s) is connected to:", network->devices[i].name, network->devices[i].ip);
        int j = 0;
        while (network->devices[i].neighbors[j] != -1) {
            int neighbor_index = network->devices[i].neighbors[j];
            printf(" %s", network->devices[neighbor_index].name);
            j++;
        }
        printf("\n");
    }
}

int main() {
    Network network;
    network.num_devices = 0;
    char command[20];
    while (true) {
        printf("Enter command ('add_device', 'add_neighbor', 'print_topology', or 'quit'): ");
        scanf("%s", command);
        if (strcmp(command, "add_device") == 0) {
            char name[20], ip[16];
            printf("Enter device name: ");
            scanf("%s", name);
            printf("Enter IP address: ");
            scanf("%s", ip);
            add_device(&network, name, ip);
        } else if (strcmp(command, "add_neighbor") == 0) {
            char device[20], neighbor[20];
            printf("Enter device name: ");
            scanf("%s", device);
            printf("Enter neighbor name: ");
            scanf("%s", neighbor);
            add_neighbor(&network, device, neighbor);
        } else if (strcmp(command, "print_topology") == 0) {
            print_topology(&network);
        } else if (strcmp(command, "quit") == 0) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}