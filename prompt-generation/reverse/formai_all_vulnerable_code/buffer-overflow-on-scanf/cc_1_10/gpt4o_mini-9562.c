//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_NAME_LENGTH 20

typedef struct Device {
    char name[MAX_NAME_LENGTH];
    struct Device* connections[MAX_DEVICES];
    int connection_count;
} Device;

Device* create_device(const char* name) {
    Device* new_device = (Device*)malloc(sizeof(Device));
    strcpy(new_device->name, name);
    new_device->connection_count = 0;
    return new_device;
}

void add_connection(Device* dev1, Device* dev2) {
    if (dev1->connection_count < MAX_DEVICES && dev2->connection_count < MAX_DEVICES) {
        dev1->connections[dev1->connection_count++] = dev2;
        dev2->connections[dev2->connection_count++] = dev1; // Assuming bidirectional connection
    } else {
        printf("Connection limit reached for one of the devices.\n");
    }
}

void print_topology(Device* devices[], int device_count) {
    printf("Current Network Topology:\n");
    for (int i = 0; i < device_count; i++) {
        printf("Device: %s\n", devices[i]->name);
        printf("Connected to: ");
        for (int j = 0; j < devices[i]->connection_count; j++) {
            printf("%s ", devices[i]->connections[j]->name);
        }
        printf("\n\n");
    }
}

void free_memory(Device* devices[], int device_count) {
    for (int i = 0; i < device_count; i++) {
        free(devices[i]);
    }
}

int main() {
    Device* devices[MAX_DEVICES];
    int device_count = 0;
    char input[MAX_NAME_LENGTH];
    
    while (1) {
        printf("Enter device name (or type 'exit' to finish): ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }
        devices[device_count++] = create_device(input);
        
        if (device_count >= MAX_DEVICES) {
            printf("Maximum number of devices reached.\n");
            break;
        }

        printf("Do you want to connect this device to an existing device? (yes/no): ");
        char connection_choice[4];
        scanf("%s", connection_choice);
        
        if (strcmp(connection_choice, "yes") == 0) {
            printf("Available devices to connect to:\n");
            for (int i = 0; i < device_count - 1; i++) {
                printf("%d. %s\n", i + 1, devices[i]->name);
            }
            int connection_index;
            printf("Enter the index of the device to connect to: ");
            scanf("%d", &connection_index);
            if (connection_index > 0 && connection_index <= device_count - 1) {
                add_connection(devices[device_count - 1], devices[connection_index - 1]);
                printf("Connected %s to %s\n", devices[device_count - 1]->name, devices[connection_index - 1]->name);
            } else {
                printf("Invalid index.\n");
            }
        }
    }

    print_topology(devices, device_count);
    free_memory(devices, device_count);
    return 0;
}