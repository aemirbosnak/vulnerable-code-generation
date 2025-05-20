//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_NAME_LENGTH 20

typedef struct Device {
    char name[MAX_NAME_LENGTH];
    struct Device *connections[MAX_DEVICES];
    int connection_count;
} Device;

typedef struct Network {
    Device *devices[MAX_DEVICES];
    int device_count;
} Network;

void initialize_network(Network *network) {
    network->device_count = 0;
}

Device* create_device(const char *name) {
    Device *new_device = (Device *)malloc(sizeof(Device));
    strncpy(new_device->name, name, MAX_NAME_LENGTH);
    new_device->connection_count = 0;
    return new_device;
}

void add_device(Network *network, const char *name) {
    if (network->device_count >= MAX_DEVICES) {
        printf("Network is full! Cannot add more devices.\n");
        return;
    }
    Device *new_device = create_device(name);
    network->devices[network->device_count++] = new_device;
    printf("Device '%s' added to the network.\n", name);
}

void connect_devices(Device *dev1, Device *dev2) {
    if (dev1->connection_count >= MAX_DEVICES || dev2->connection_count >= MAX_DEVICES) {
        printf("One of the devices is already connected to the maximum number of devices.\n");
        return;
    }
    dev1->connections[dev1->connection_count++] = dev2;
    dev2->connections[dev2->connection_count++] = dev1;
    printf("Connected %s and %s.\n", dev1->name, dev2->name);
}

void display_network(const Network *network) {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < network->device_count; i++) {
        Device *device = network->devices[i];
        printf("Device: %s\n", device->name);
        printf("Connections: ");
        for (int j = 0; j < device->connection_count; j++) {
            printf("%s ", device->connections[j]->name);
        }
        printf("\n");
    }
}

Device* find_device(Network *network, const char *name) {
    for (int i = 0; i < network->device_count; i++) {
        if (strcmp(network->devices[i]->name, name) == 0) {
            return network->devices[i];
        }
    }
    return NULL;
}

int main() {
    Network network;
    initialize_network(&network);

    int choice;
    char name1[MAX_NAME_LENGTH], name2[MAX_NAME_LENGTH];

    while (1) {
        printf("\n1. Add Device\n2. Connect Devices\n3. Display Network\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                scanf("%s", name1);
                add_device(&network, name1);
                break;

            case 2:
                printf("Enter first device name: ");
                scanf("%s", name1);
                printf("Enter second device name: ");
                scanf("%s", name2);
                Device *dev1 = find_device(&network, name1);
                Device *dev2 = find_device(&network, name2);
                
                if (dev1 && dev2) {
                    connect_devices(dev1, dev2);
                } else {
                    printf("One or both devices not found!\n");
                }
                break;

            case 3:
                display_network(&network);
                break;

            case 4:
                printf("Exiting...\n");
                for (int i = 0; i < network.device_count; i++) {
                    free(network.devices[i]);
                }
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}