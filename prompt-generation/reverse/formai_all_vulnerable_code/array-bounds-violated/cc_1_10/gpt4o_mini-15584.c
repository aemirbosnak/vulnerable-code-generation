//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_NAME_LENGTH 50

typedef struct Device {
    char name[MAX_NAME_LENGTH];
    char ip_address[MAX_NAME_LENGTH];
    int connected_devices[MAX_DEVICES];
    int num_connected;
} Device;

Device devices[MAX_DEVICES];
int device_count = 0;

void add_device(const char *name, const char *ip_address) {
    if (device_count >= MAX_DEVICES) {
        printf("Device limit reached. Cannot add more devices.\n");
        return;
    }
    strcpy(devices[device_count].name, name);
    strcpy(devices[device_count].ip_address, ip_address);
    devices[device_count].num_connected = 0;
    device_count++;
    printf("Device added: %s with IP %s\n", name, ip_address);
}

void connect_devices(int index1, int index2) {
    if (index1 >= device_count || index2 >= device_count) {
        printf("Invalid device index.\n");
        return;
    }
    devices[index1].connected_devices[devices[index1].num_connected++] = index2;
    devices[index2].connected_devices[devices[index2].num_connected++] = index1;
    printf("Connected %s with %s.\n", devices[index1].name, devices[index2].name);
}

void print_network_topology() {
    printf("\nNetwork Topology:\n");
    for (int i = 0; i < device_count; i++) {
        printf("Device: %s (IP: %s)\n", devices[i].name, devices[i].ip_address);
        printf("  Connected to: ");
        for (int j = 0; j < devices[i].num_connected; j++) {
            printf("%s (IP: %s)", devices[devices[i].connected_devices[j]].name, devices[devices[i].connected_devices[j]].ip_address);
            if (j < devices[i].num_connected - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

int main() {
    int choice;
    char name[MAX_NAME_LENGTH], ip_address[MAX_NAME_LENGTH];

    do {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Device\n");
        printf("2. Connect Devices\n");
        printf("3. Print Network Topology\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // remove newline
                printf("Enter device IP address: ");
                fgets(ip_address, MAX_NAME_LENGTH, stdin);
                ip_address[strcspn(ip_address, "\n")] = 0; // remove newline
                add_device(name, ip_address);
                break;
            case 2: {
                int index1, index2;
                printf("Enter index of first device to connect (0 to %d): ", device_count - 1);
                scanf("%d", &index1);
                printf("Enter index of second device to connect (0 to %d): ", device_count - 1);
                scanf("%d", &index2);
                connect_devices(index1, index2);
                break;
            }
            case 3:
                print_network_topology();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}