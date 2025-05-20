//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_DEVICES 10
#define MAX_NAME_LENGTH 30
#define BUFFER_SIZE 256

typedef struct {
    char name[MAX_NAME_LENGTH];
    char ip_address[INET_ADDRSTRLEN];
} NetworkDevice;

typedef struct {
    NetworkDevice devices[MAX_DEVICES];
    int device_count;
} NetworkTopology;

void initialize_topology(NetworkTopology *topology) {
    topology->device_count = 0;
}

void add_device(NetworkTopology *topology, const char *name, const char *ip) {
    if (topology->device_count < MAX_DEVICES) {
        strncpy(topology->devices[topology->device_count].name, name, MAX_NAME_LENGTH - 1);
        strncpy(topology->devices[topology->device_count].ip_address, ip, INET_ADDRSTRLEN);
        topology->device_count++;
    } else {
        printf("Maximum device limit reached. Cannot add more devices.\n");
    }
}

void display_topology(const NetworkTopology *topology) {
    printf("\nNetwork Topology:\n");
    printf("%-20s %-15s\n", "Device Name", "IP Address");
    printf("------------------------------------------\n");
    for (int i = 0; i < topology->device_count; i++) {
        printf("%-20s %-15s\n", topology->devices[i].name, topology->devices[i].ip_address);
    }
}

int ping_device(const char *ip_address) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "ping -c 1 %s > /dev/null", ip_address);
    return system(command);
}

void scan_network(NetworkTopology *topology) {
    for (int i = 0; i < topology->device_count; i++) {
        printf("Pinging %s at %s...\n", topology->devices[i].name, topology->devices[i].ip_address);
        if (ping_device(topology->devices[i].ip_address) == 0) {
            printf("Device %s is reachable.\n", topology->devices[i].name);
        } else {
            printf("Device %s is NOT reachable.\n", topology->devices[i].name);
        }
    }
}

int main() {
    NetworkTopology topology;
    initialize_topology(&topology);

    int choice;
    char name[MAX_NAME_LENGTH];
    char ip[INET_ADDRSTRLEN];

    do {
        printf("\nNetwork Topology Mapper\n");
        printf("1. Add Device\n");
        printf("2. Display Topology\n");
        printf("3. Scan Network\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline from buffer

        switch (choice) {
            case 1:
                printf("Enter device name: ");
                fgets(name, MAX_NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove trailing newline
                printf("Enter device IP address: ");
                fgets(ip, INET_ADDRSTRLEN, stdin);
                ip[strcspn(ip, "\n")] = 0; // Remove trailing newline
                add_device(&topology, name, ip);
                break;
            case 2:
                display_topology(&topology);
                break;
            case 3:
                scan_network(&topology);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}