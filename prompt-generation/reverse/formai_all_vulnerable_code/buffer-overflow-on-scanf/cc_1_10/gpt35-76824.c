//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_DEVICES 10
#define MAX_CONNECTIONS 20

struct device {
    char ip[16];
    char name[20];
};

struct connection {
    int device1_id;
    int device2_id;
};

int num_devices = 0;
int num_connections = 0;
struct device devices[MAX_DEVICES];
struct connection connections[MAX_CONNECTIONS];

void add_device() {
    if(num_devices == MAX_DEVICES) {
        printf("Maximum number of devices reached!\n");
        return;
    }

    printf("Enter device IP: ");
    scanf("%s", devices[num_devices].ip);

    printf("Enter device name: ");
    scanf("%s", devices[num_devices].name);

    printf("Device added successfully!\n");
    num_devices++;
}

void add_connection() {
    if(num_connections == MAX_CONNECTIONS) {
        printf("Maximum number of connections reached!\n");
        return;
    }

    int device1_id, device2_id;
    printf("Enter ID of device 1: ");
    scanf("%d", &device1_id);

    printf("Enter ID of device 2: ");
    scanf("%d", &device2_id);

    if(device1_id >= num_devices || device2_id >= num_devices) {
        printf("Invalid device ID!\n");
        return;
    }

    connections[num_connections].device1_id = device1_id;
    connections[num_connections].device2_id = device2_id;

    printf("Connection added successfully!\n");
    num_connections++;
}

void display_topology() {
    printf("Network Topology: \n\n");

    for(int i=0; i<num_devices; i++) {
        printf("Device %d -> IP: %s, Name: %s\n", i, devices[i].ip, devices[i].name);
    }

    printf("\n");

    for(int i=0; i<num_connections; i++) {
        int device1_id = connections[i].device1_id;
        int device2_id = connections[i].device2_id;

        printf("Connection %d -> Device %d <--> Device %d\n", i, device1_id, device2_id);
    }
}

int main() {
    printf("Welcome to the Cyberpunk Network Topology Mapper.\n");

    char option;
    do {
        printf("\nOptions:\n");
        printf("1 - Add device\n");
        printf("2 - Add connection\n");
        printf("3 - Display topology\n");
        printf("4 - Exit\n");
        printf("Select an option: ");

        scanf(" %c", &option);

        switch(option) {
            case '1':
                add_device();
                break;
            case '2':
                add_connection();
                break;
            case '3':
                display_topology();
                break;
            case '4':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option!\n");
                break;
        }
    } while(1);

    return 0;
}