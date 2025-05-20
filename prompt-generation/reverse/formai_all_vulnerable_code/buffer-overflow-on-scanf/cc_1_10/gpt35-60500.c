//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 100
#define MAX_CONNECTIONS 100

typedef struct {
    char name[20];
    char ip_address[20];
    char mac_address[20];
} Device;

typedef struct {
    Device *src;
    Device *dest;
    float latency;
} Connection;

void scan_device(Device *device, int device_count) {
    printf("Enter the details of device %d:\n", device_count + 1);
    printf("Name: ");
    scanf("%s", device[device_count].name);
    printf("IP Address: ");
    scanf("%s", device[device_count].ip_address);
    printf("MAC Address: ");
    scanf("%s", device[device_count].mac_address);
}

void scan_connection(Connection *connection, int connection_count, Device *devices, int device_count) {
    char src_name[20], dest_name[20];
    int i;

    printf("Enter the details of connection %d:\n", connection_count + 1);
    printf("Source: ");
    scanf("%s", src_name);
    printf("Destination: ");
    scanf("%s", dest_name);
    for(i = 0; i < device_count; i++) {
        if(strcmp(src_name, devices[i].name) == 0) {
            connection[connection_count].src = &devices[i];
        }
        if(strcmp(dest_name, devices[i].name) == 0) {
            connection[connection_count].dest = &devices[i];
        }
    }
    printf("Latency (in ms): ");
    scanf("%f", &connection[connection_count].latency);
}

void map_network(Device *devices, int device_count, Connection *connections, int connection_count) {
    int i, j;

    printf("==== Network Topology ====\n");
    for(i = 0; i < device_count; i++) {
        printf("%s (%s)\n", devices[i].name, devices[i].ip_address);
        for(j = 0; j < connection_count; j++) {
            if(connections[j].src == &devices[i]) {
                printf("--> %s (%s, %s)\n", connections[j].dest->name, connections[j].dest->ip_address, connections[j].dest->mac_address);
                printf("    Latency: %.2fms\n", connections[j].latency);
            } else if(connections[j].dest == &devices[i]) {
                printf("<-- %s (%s, %s)\n", connections[j].src->name, connections[j].src->ip_address, connections[j].src->mac_address);
                printf("    Latency: %.2fms\n", connections[j].latency);
            }
        }
    }
}

int main() {
    Device devices[MAX_DEVICES];
    Connection connections[MAX_CONNECTIONS];
    int device_count = 0, connection_count = 0;
    char action;

    do {
        printf("\nWhat action would you like to perform?\n");
        printf("A - Add a device\n");
        printf("C - Create a connection\n");
        printf("M - Map the network topology\n");
        printf("Q - Quit\n");
        printf("Action: ");
        scanf(" %c", &action);
        switch(action) {
            case 'A':
                scan_device(devices, device_count);
                device_count++;
                break;
            case 'C':
                if(device_count < 2) {
                    printf("You need at least 2 devices to create a connection.\n");
                } else {
                    scan_connection(connections, connection_count, devices, device_count);
                    connection_count++;
                }
                break;
            case 'M':
                if(device_count < 2) {
                    printf("You need at least 2 devices to map the network topology.\n");
                } else {
                    map_network(devices, device_count, connections, connection_count);
                }
                break;
            case 'Q':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid action.\n");
        }
    } while(action != 'Q');

    return 0;
}