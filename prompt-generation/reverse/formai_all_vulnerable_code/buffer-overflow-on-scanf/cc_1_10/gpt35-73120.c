//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_CONNECTIONS 500

typedef struct {
    char name[20];
    int ip_address;
    int num_connections;
    int connected_devices[MAX_DEVICES];
} Device;

typedef struct {
    int source_device_index;
    int destination_device_index;
} Connection;


int num_devices = 0;
int num_connections = 0;
Device devices[MAX_DEVICES];
Connection connections[MAX_CONNECTIONS];


void add_device() {
    if(num_devices >= MAX_DEVICES) {
        printf("Maximum number of devices reached.\n");
        return;
    }
    printf("\nEnter device name: ");
    scanf("%s", devices[num_devices].name);
    printf("Enter IP address: ");
    scanf("%d", &devices[num_devices].ip_address);
    devices[num_devices].num_connections = 0;
    num_devices++;
    printf("Device added successfully.\n");
}


void add_connection() {
    if(num_connections >= MAX_CONNECTIONS) {
        printf("Maximum number of connections reached.\n");
        return;
    }
    char source_name[20], dest_name[20];
    printf("\nEnter source device name: ");
    scanf("%s", source_name);
    int source_index = -1;
    for(int i=0; i<num_devices; i++) {
        if(strcmp(devices[i].name, source_name) == 0) {
            source_index = i;
            break;
        }
    }
    if(source_index == -1) {
        printf("Device not found.\n");
        return;
    }
    printf("Enter destination device name: ");
    scanf("%s", dest_name);
    int dest_index = -1;
    for(int i=0; i<num_devices; i++) {
        if(strcmp(devices[i].name, dest_name) == 0) {
            dest_index = i;
            break;
        }
    }
    if(dest_index == -1) {
        printf("Device not found.\n");
        return;
    }
    int found = 0;
    for(int i=0; i<devices[source_index].num_connections; i++) {
        if(devices[source_index].connected_devices[i] == dest_index) {
            found = 1;
            break;
        }
    }
    if(found) {
        printf("Already connected.\n");
        return;
    }
    devices[source_index].connected_devices[devices[source_index].num_connections++] = dest_index;
    connections[num_connections].source_device_index = source_index;
    connections[num_connections].destination_device_index = dest_index;
    num_connections++;
    printf("Connection added successfully.\n");
}


void print_topology() {
    printf("\n Network Topology\n============================\n");
    for(int i=0; i<num_devices; i++) {
        printf("Device %s [%d.%d.%d.%d]: ", devices[i].name, 
            (devices[i].ip_address >> 24) & 0xFF, 
            (devices[i].ip_address >> 16) & 0xFF, 
            (devices[i].ip_address >> 8) & 0xFF, 
            devices[i].ip_address & 0xFF);
        for(int j=0; j<devices[i].num_connections; j++) {
            printf("%s ", devices[devices[i].connected_devices[j]].name);
        }
        printf("\n");
    }
}


int main() {
    int choice;
    do {
        printf("\n Menu\n========\n");
        printf("[1] Add device\n");
        printf("[2] Add connection\n");
        printf("[3] Print topology\n");
        printf("[4] Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_device();
                break;
            case 2:
                add_connection();
                break;
            case 3:
                print_topology();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    } while(choice != 4);
    return 0;
}