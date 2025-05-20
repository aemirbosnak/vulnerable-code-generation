//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_NAME_LENGTH 50

typedef struct Device {
    int id;
    char name[MAX_NAME_LENGTH];
    struct Device* connections[MAX_DEVICES];
    int connection_count;
} Device;

Device* devices[MAX_DEVICES];
int device_count = 0;

// Function declarations
Device* create_device(int id, const char* name);
void add_device(const char* name);
void connect_devices(int id1, int id2);
void display_network_topology();
void free_memory();

int main() {
    int choice;
    char name[MAX_NAME_LENGTH];
    int id1, id2;

    while (1) {
        printf("\n--- Network Topology Mapper ---\n");
        printf("1. Add Device\n");
        printf("2. Connect Devices\n");
        printf("3. Display Network Topology\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Device Name: ");
                scanf("%s", name);
                add_device(name);
                break;

            case 2:
                printf("Enter IDs of devices to connect (id1 id2): ");
                scanf("%d %d", &id1, &id2);
                connect_devices(id1, id2);
                break;

            case 3:
                display_network_topology();
                break;

            case 4:
                free_memory();
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

Device* create_device(int id, const char* name) {
    Device* new_device = (Device*)malloc(sizeof(Device));
    new_device->id = id;
    strncpy(new_device->name, name, MAX_NAME_LENGTH);
    new_device->connection_count = 0;
    return new_device;
}

void add_device(const char* name) {
    if (device_count == MAX_DEVICES) {
        printf("Maximum device limit reached.\n");
        return;
    }
    Device* device = create_device(device_count, name);
    devices[device_count++] = device;
    printf("Device '%s' added with ID: %d\n", name, device_count - 1);
}

void connect_devices(int id1, int id2) {
    if (id1 < 0 || id1 >= device_count || id2 < 0 || id2 >= device_count) {
        printf("Invalid device ID(s).\n");
        return;
    }
    
    Device* device1 = devices[id1];
    Device* device2 = devices[id2];

    if (device1->connection_count >= MAX_DEVICES || device2->connection_count >= MAX_DEVICES) {
        printf("Connection limit reached for one of the devices.\n");
        return;
    }

    // Connect each device to the other
    device1->connections[device1->connection_count++] = device2;
    device2->connections[device2->connection_count++] = device1;
    printf("Devices '%s' and '%s' connected.\n", device1->name, device2->name);
}

void display_network_topology() {
    if (device_count == 0) {
        printf("No devices in the network.\n");
        return;
    }

    printf("\n--- Network Topology ---\n");
    for (int i = 0; i < device_count; i++) {
        Device* device = devices[i];
        printf("Device %d (%s): ", device->id, device->name);
        for (int j = 0; j < device->connection_count; j++) {
            printf("%s ", device->connections[j]->name);
        }
        printf("\n");
    }
}

void free_memory() {
    for (int i = 0; i < device_count; i++) {
        free(devices[i]);
    }
}