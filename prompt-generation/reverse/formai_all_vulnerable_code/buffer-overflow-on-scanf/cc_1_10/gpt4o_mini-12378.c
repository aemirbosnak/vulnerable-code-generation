//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define NAME_LEN 50

// Structure for a Device
typedef struct {
    char name[NAME_LEN];
    int connections[MAX_DEVICES]; // holds indices of connected devices
    int conn_count;                // number of connections
} Device;

// Global variables
Device devices[MAX_DEVICES];
int device_count = 0;

// Function declarations
void add_device(const char *name);
void connect_devices(int src_index, int dest_index);
void display_network();
int find_device(const char *name);

int main() {
    int choice;
    char name[NAME_LEN];
    int src_index, dest_index;

    printf("Welcome to the Network Topology Mapper!\n");
    do {
        printf("\nMenu:\n");
        printf("1. Add Device\n");
        printf("2. Connect Devices\n");
        printf("3. Display Network Topology\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear the newline

        switch (choice) {
            case 1:
                printf("Enter the name of the device: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline character
                add_device(name);
                break;

            case 2:
                printf("Enter source device name: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0;
                src_index = find_device(name);
                if (src_index == -1) {
                    printf("Device %s not found!\n", name);
                    break;
                }
                
                printf("Enter destination device name: ");
                fgets(name, NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0;
                dest_index = find_device(name);
                if (dest_index == -1) {
                    printf("Device %s not found!\n", name);
                    break;
                }

                connect_devices(src_index, dest_index);
                break;

            case 3:
                display_network();
                break;

            case 4:
                printf("Exiting the program. Have a great day!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function definitions
void add_device(const char *name) {
    if (device_count < MAX_DEVICES) {
        strncpy(devices[device_count].name, name, NAME_LEN);
        devices[device_count].conn_count = 0;
        device_count++;
        printf("Device '%s' added successfully!\n", name);
    } else {
        printf("Maximum device limit reached!\n");
    }
}

void connect_devices(int src_index, int dest_index) {
    if (src_index != dest_index) {
        devices[src_index].connections[devices[src_index].conn_count++] = dest_index;
        devices[dest_index].connections[devices[dest_index].conn_count++] = src_index;
        printf("Device '%s' connected to device '%s'!\n", devices[src_index].name, devices[dest_index].name);
    } else {
        printf("Cannot connect a device to itself!\n");
    }
}

void display_network() {
    printf("\n--- Network Topology ---\n");
    for (int i = 0; i < device_count; i++) {
        printf("Device: %s\n", devices[i].name);
        printf("Connected to: ");
        for (int j = 0; j < devices[i].conn_count; j++) {
            printf("%s ", devices[devices[i].connections[j]].name);
        }
        printf("\n\n");
    }
}

int find_device(const char *name) {
    for (int i = 0; i < device_count; i++) {
        if (strcmp(devices[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // device not found
}