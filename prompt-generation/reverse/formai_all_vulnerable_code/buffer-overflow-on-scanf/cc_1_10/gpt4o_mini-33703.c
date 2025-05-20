//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Structure for device
typedef struct Device {
    char name[MAX_NAME_LENGTH];
    struct Device *next;
    struct Connection *connections;
} Device;

// Structure for connection
typedef struct Connection {
    Device *device;
    struct Connection *next;
} Connection;

// Function prototypes
Device* create_device(const char *name);
Connection* create_connection(Device *device);
void add_device(Device **head, const char *name);
void add_connection(Device *device, Device *connected_device);
void display_network(Device *head);
void free_network(Device *head);

int main() {
    Device *network = NULL;
    char device_name[MAX_NAME_LENGTH];
    char command[10];
    
    printf("Welcome to the Network Topology Mapper!\n");
    
    while (1) {
        printf("\nOptions: add_device, connect, display, exit\n");
        printf("Enter command: ");
        scanf("%s", command);
        
        if (strcmp(command, "add_device") == 0) {
            printf("Enter device name: ");
            scanf("%s", device_name);
            add_device(&network, device_name);
        } else if (strcmp(command, "connect") == 0) {
            char target_name[MAX_NAME_LENGTH];
            printf("Enter your device name: ");
            scanf("%s", device_name);
            printf("Enter the device to connect to: ");
            scanf("%s", target_name);
            
            Device *dev = network;
            Device *target = NULL;

            // Find the device and target device
            while (dev != NULL) {
                if (strcmp(dev->name, device_name) == 0) {
                    break;
                }
                dev = dev->next;
            }
            if (dev == NULL) {
                printf("Device %s not found!\n", device_name);
                continue;
            }

            target = network;
            while (target != NULL) {
                if (strcmp(target->name, target_name) == 0) {
                    break;
                }
                target = target->next;
            }
            if (target == NULL) {
                printf("Target device %s not found!\n", target_name);
                continue;
            }

            add_connection(dev, target);
        } else if (strcmp(command, "display") == 0) {
            display_network(network);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command.\n");
        }
    }

    free_network(network);
    printf("Exiting the Network Topology Mapper. Goodbye!\n");
    return 0;
}

// Create a new device
Device* create_device(const char *name) {
    Device *new_device = (Device *)malloc(sizeof(Device));
    strncpy(new_device->name, name, MAX_NAME_LENGTH);
    new_device->next = NULL;
    new_device->connections = NULL;
    return new_device;
}

// Create a new connection
Connection* create_connection(Device *device) {
    Connection *new_connection = (Connection *)malloc(sizeof(Connection));
    new_connection->device = device;
    new_connection->next = NULL;
    return new_connection;
}

// Add a new device to the network
void add_device(Device **head, const char *name) {
    Device *new_device = create_device(name);
    new_device->next = *head;
    *head = new_device;
    printf("Device %s added to the network.\n", name);
}

// Add a connection between devices
void add_connection(Device *device, Device *connected_device) {
    Connection *new_connection = create_connection(connected_device);
    new_connection->next = device->connections;
    device->connections = new_connection;
    printf("Connected %s to %s.\n", device->name, connected_device->name);
}

// Display the network topology
void display_network(Device *head) {
    Device *current_device = head;

    printf("\nNetwork Topology:\n");
    while (current_device != NULL) {
        printf("Device: %s\nConnections: ", current_device->name);
        Connection *current_connection = current_device->connections;
        
        if (current_connection == NULL) {
            printf("None\n");
        } else {
            while (current_connection != NULL) {
                printf("%s ", current_connection->device->name);
                current_connection = current_connection->next;
            }
            printf("\n");
        }
        
        current_device = current_device->next;
    }
}

// Free the allocated memory for the network
void free_network(Device *head) {
    while (head != NULL) {
        Device *temp_device = head;
        head = head->next;

        // Free connections
        Connection *current_connection = temp_device->connections;
        while (current_connection != NULL) {
            Connection *temp_connection = current_connection;
            current_connection = current_connection->next;
            free(temp_connection);
        }
        
        free(temp_device);
    }
}