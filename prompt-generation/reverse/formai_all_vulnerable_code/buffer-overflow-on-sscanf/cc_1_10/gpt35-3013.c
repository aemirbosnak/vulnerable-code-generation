//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DEVICES 50 // Maximum number of devices to be mapped
#define MAX_CONNECTIONS 100 // Maximum number of connections allowed between devices

typedef struct device {
    char name[20];
    char ip[20];
    char subnet[20];
} Device;

typedef struct connection {
    Device device1;
    Device device2;
} Connection;

/* Function to check if two devices are connected */
bool are_connected(Device device1, Device device2, Connection connections[], int n_connections) {
    for (int i=0; i<n_connections; i++) {
        if ((strcmp(device1.name, connections[i].device1.name) == 0 && strcmp(device2.name, connections[i].device2.name) == 0) || 
            (strcmp(device1.name, connections[i].device2.name) == 0 && strcmp(device2.name, connections[i].device1.name) == 0)) {
            return true;
        }
    }
    return false;
}

/* Function to print the network topology */
void print_topology(Device devices[], int n_devices, Connection connections[], int n_connections) {
    printf("\n### NETWORK TOPOLOGY ###\n");
    for (int i=0; i<n_devices; i++) {
        printf("%s (%s/%s):\n", devices[i].name, devices[i].ip, devices[i].subnet);
        for (int j=0; j<n_devices; j++) {
            if (i != j) {
                if (are_connected(devices[i], devices[j], connections, n_connections)) {
                    printf("  -> %s (%s/%s)\n", devices[j].name, devices[j].ip, devices[j].subnet);
                }
            }
        }
    }
}

int main() {
    Device devices[MAX_DEVICES];
    Connection connections[MAX_CONNECTIONS];
    int n_devices = 0;
    int n_connections = 0;
    char input[50];

    printf("Welcome to the Network Topology Mapper!\n\n");
    printf("Please enter the details of the devices in your network.\n");
    printf("For each device, enter its name, IP address and subnet mask (e.g. 192.168.0.1/24):\n");
    
    /* Loop to get details of all devices */
    while (true) {
        printf("Device %d: ", n_devices+1);
        fgets(input, 50, stdin);
        if (strcmp(input, "done\n") == 0 || n_devices == MAX_DEVICES) {
            break;
        }
        
        // Parse the input to get device details
        sscanf(input, "%s %s %s", devices[n_devices].name, devices[n_devices].ip, devices[n_devices].subnet);
        n_devices++;
    }

    printf("\nPlease enter the connections between devices in your network.\n");
    printf("For each connection, enter the names of the two devices separated by a space (e.g. PC1 Server):\n");

    /* Loop to get details of all connections */
    while (true) {
        printf("Connection %d: ", n_connections+1);
        fgets(input, 50, stdin);
        if (strcmp(input, "done\n") == 0 || n_connections == MAX_CONNECTIONS) {
            break;
        }

        // Parse the input to get device names
        char device1_name[20], device2_name[20];
        sscanf(input, "%s %s", device1_name, device2_name);

        // Find the devices with corresponding names
        Device device1, device2;
        bool device1_found = false, device2_found = false;
        for (int i=0; i<n_devices; i++) {
            if (strcmp(device1_name, devices[i].name) == 0) {
                device1 = devices[i];
                device1_found = true;
            }
            if (strcmp(device2_name, devices[i].name) == 0) {
                device2 = devices[i];
                device2_found = true;
            }
            if (device1_found && device2_found) {
                break;
            }
        }

        // Add the connection if both devices exist
        if (device1_found && device2_found) {
            connections[n_connections].device1 = device1;
            connections[n_connections].device2 = device2;
            n_connections++;
        } else {
            printf("One or both of the devices not found. Please try again.\n");
        }
    }

    // Print the network topology
    print_topology(devices, n_devices, connections, n_connections);

    printf("\nThank you for using the Network Topology Mapper!\n");
    return 0;
}