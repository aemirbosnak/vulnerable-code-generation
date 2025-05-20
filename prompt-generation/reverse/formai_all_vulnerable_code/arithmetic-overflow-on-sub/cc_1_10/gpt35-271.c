//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10
#define MAX_LINKS 20

typedef struct {
    char device_name[20];
    int device_id;
    char device_type[20];
} Device;

typedef struct {
    int link_id;
    int source_device_id;
    int dest_device_id;
    char link_type[20];
} Link;

int main() {
    Device devices[MAX_DEVICES];
    Link links[MAX_LINKS];

    // Adding devices
    Device device1 = {"Router 1", 1, "router"};
    Device device2 = {"Switch 1", 2, "switch"};
    Device device3 = {"Router 2", 3, "router"};
    Device device4 = {"Server 1", 4, "server"};
    Device device5 = {"Switch 2", 5, "switch"};
    devices[0] = device1;
    devices[1] = device2;
    devices[2] = device3;
    devices[3] = device4;
    devices[4] = device5;

    // Adding links
    Link link1 = {1, 1, 2, "ethernet"};
    Link link2 = {2, 2, 4, "ethernet"};
    Link link3 = {3, 2, 5, "ethernet"};
    Link link4 = {4, 3, 5, "fiber"};
    Link link5 = {5, 4, 5, "ethernet"};
    links[0] = link1;
    links[1] = link2;
    links[2] = link3;
    links[3] = link4;
    links[4] = link5;

    // Printing the network topology
    printf("Network Topology Map\n");
    printf("--------------------\n");
    for(int i=0; i<MAX_DEVICES; i++) {
        printf("%s (ID: %d, Type: %s)\n", devices[i].device_name, devices[i].device_id, devices[i].device_type);
        printf("Links:\n");
        for(int j=0; j<MAX_LINKS; j++) {
            if(links[j].source_device_id == devices[i].device_id || links[j].dest_device_id == devices[i].device_id) {
                printf("Link ID: %d, Type: %s, ", links[j].link_id, links[j].link_type);
                if(links[j].source_device_id == devices[i].device_id) {
                    printf("Connected to: %s (ID: %d)\n", devices[links[j].dest_device_id-1].device_name, devices[links[j].dest_device_id-1].device_id);
                }
                else {
                    printf("Connected to: %s (ID: %d)\n", devices[links[j].source_device_id-1].device_name, devices[links[j].source_device_id-1].device_id);
                }
            }
        }
        printf("\n");
    }
    return 0;
}