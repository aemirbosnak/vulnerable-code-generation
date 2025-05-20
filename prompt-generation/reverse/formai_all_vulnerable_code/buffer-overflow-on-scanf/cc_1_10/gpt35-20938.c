//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 50 // Maximum number of devices in the network
#define MAX_CONNECTIVITY 50 // Maximum number of connections

// Structure to store device information
typedef struct device {
    char* name;
    char* ip_address;
} Device;

// Structure to store connection information
typedef struct connectivity {
    int device1_id;
    int device2_id;
} Connectivity;

int main() {
    int num_devices, num_connections;
    Device device_list[MAX_DEVICES];
    Connectivity connection_list[MAX_CONNECTIVITY];

    // Input the number of devices and their information
    printf("Enter the number of devices in the network: ");
    scanf("%d", &num_devices);
    getchar(); // To consume the newline character left by scanf

    // Input the information for each device
    for (int i=0; i<num_devices; i++) {
        printf("\nEnter the name of device %d: ", i+1);
        device_list[i].name = malloc(sizeof(char)*50); // Maximum length of device name is 50 characters
        fgets(device_list[i].name, 50, stdin);
        device_list[i].name[strcspn(device_list[i].name, "\n")] = 0; // Remove trailing newline character

        printf("Enter the IP address of device %d: ", i+1);
        device_list[i].ip_address = malloc(sizeof(char)*16); // Maximum length of an IP address is 15 characters
        scanf("%s", device_list[i].ip_address);
        getchar(); // To consume the newline character left by scanf
    }

    // Input the number of connections and their information
    printf("\nEnter the number of connections in the network: ");
    scanf("%d", &num_connections);
    getchar(); // To consume the newline character left by scanf

    // Input the information for each connection
    for (int i=0; i<num_connections; i++) {
        printf("\nEnter the IDs of the devices connected by connection %d: ", i+1);
        scanf("%d %d", &connection_list[i].device1_id, &connection_list[i].device2_id);
        getchar(); // To consume the newline character left by scanf
    }

    // Print device information
    printf("\nDevice information:\n");
    for (int i=0; i<num_devices; i++) {
        printf("%d. Device Name: %s | IP Address: %s\n", i+1, device_list[i].name, device_list[i].ip_address);
    }

    // Print connection information
    printf("\nConnection information:\n");
    for (int i=0; i<num_connections; i++) {
        printf("%d. Devices connected: %d and %d\n", i+1, connection_list[i].device1_id, connection_list[i].device2_id);
    }

    // Free memory allocated for device information
    for (int i=0; i<num_devices; i++) {
        free(device_list[i].name);
        free(device_list[i].ip_address);
    }

    return 0;
}