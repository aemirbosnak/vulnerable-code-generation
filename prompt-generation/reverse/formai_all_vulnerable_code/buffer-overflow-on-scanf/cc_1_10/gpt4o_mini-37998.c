//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100

typedef struct {
    char name[50];
    char ip[16];
    int ping_time;
} Device;

typedef struct {
    Device devices[MAX_DEVICES];
    int device_count;
} Network;

void add_device(Network *network, const char *name, const char *ip, int ping_time) {
    if (network->device_count >= MAX_DEVICES) {
        printf("Network is full. Cannot add more devices.\n");
        return;
    }

    strcpy(network->devices[network->device_count].name, name);
    strcpy(network->devices[network->device_count].ip, ip);
    network->devices[network->device_count].ping_time = ping_time;
    network->device_count++;
    printf("Added device %s with IP %s and ping time %d ms.\n", name, ip, ping_time);
}

void display_network(const Network *network) {
    printf("\nCurrent Network Topology:\n");
    for (int i = 0; i < network->device_count; i++) {
        printf("Device Name: %s, IP: %s, Ping Time: %d ms\n",
               network->devices[i].name,
               network->devices[i].ip,
               network->devices[i].ping_time);
    }
}

void update_device_ping(Network *network, const char *ip, int new_ping_time) {
    for (int i = 0; i < network->device_count; i++) {
        if (strcmp(network->devices[i].ip, ip) == 0) {
            network->devices[i].ping_time = new_ping_time;
            printf("Updated device %s ping time to %d ms.\n", network->devices[i].name, new_ping_time);
            return;
        }
    }
    printf("Device with IP %s not found.\n", ip);
}

void remove_device(Network *network, const char *ip) {
    for (int i = 0; i < network->device_count; i++) {
        if (strcmp(network->devices[i].ip, ip) == 0) {
            printf("Removing device %s with IP %s.\n", network->devices[i].name, ip);
            for (int j = i; j < network->device_count - 1; j++) {
                network->devices[j] = network->devices[j + 1];
            }
            network->device_count--;
            return;
        }
    }
    printf("Device with IP %s not found.\n", ip);
}

int main() {
    Network my_network = { .device_count = 0 };
    int choice, ping_time;
    char name[50], ip[16];

    while (1) {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Device\n");
        printf("2. Display Network\n");
        printf("3. Update Device Ping Time\n");
        printf("4. Remove Device\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Device Name: ");
                scanf("%s", name);
                printf("Enter Device IP: ");
                scanf("%s", ip);
                printf("Enter Ping Time (ms): ");
                scanf("%d", &ping_time);
                add_device(&my_network, name, ip, ping_time);
                break;
            
            case 2:
                display_network(&my_network);
                break;

            case 3:
                printf("Enter Device IP to Update: ");
                scanf("%s", ip);
                printf("Enter New Ping Time (ms): ");
                scanf("%d", &ping_time);
                update_device_ping(&my_network, ip, ping_time);
                break;

            case 4:
                printf("Enter Device IP to Remove: ");
                scanf("%s", ip);
                remove_device(&my_network, ip);
                break;

            case 5:
                printf("Exiting the Network Mapper. Goodbye!\n");
                exit(0);
            
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}