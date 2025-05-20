//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 20
#define MAX_NAME_LEN 20
#define MAX_CONNECTIONS 10

struct Device {
    char name[MAX_NAME_LEN];
    int connections[MAX_CONNECTIONS];
    int num_connections;
};

struct NetworkMap {
    int num_devices;
    struct Device devices[MAX_DEVICES];
};

void add_device(struct NetworkMap* map, char* name) {
    if (map->num_devices < MAX_DEVICES) {
        struct Device new_device;
        strncpy(new_device.name, name, MAX_NAME_LEN);
        new_device.num_connections = 0;
        map->devices[map->num_devices] = new_device;
        map->num_devices++;
        printf("Device %s added.\n", name);
    } else {
        printf("Cannot add %s. Maximum number of devices reached.\n", name);
    }
}

void connect_devices(struct NetworkMap* map, char* device1, char* device2) {
    int device1_index = -1, device2_index = -1;
    for (int i = 0; i < map->num_devices; i++) {
        if (strcmp(map->devices[i].name, device1) == 0) {
            device1_index = i;
        } else if (strcmp(map->devices[i].name, device2) == 0) {
            device2_index = i;
        }
    }
    if (device1_index == -1) {
        printf("Device %s not found.\n", device1);
    } else if (device2_index == -1) {
        printf("Device %s not found.\n", device2);
    } else if (map->devices[device1_index].num_connections >= MAX_CONNECTIONS) {
        printf("Cannot connect %s to %s. Maximum number of connections reached.\n", device1, device2);
    } else if (map->devices[device2_index].num_connections >= MAX_CONNECTIONS) {
        printf("Cannot connect %s to %s. Maximum number of connections reached.\n", device2, device1);
    } else {
        map->devices[device1_index].connections[map->devices[device1_index].num_connections] = device2_index;
        map->devices[device1_index].num_connections++;
        map->devices[device2_index].connections[map->devices[device2_index].num_connections] = device1_index;
        map->devices[device2_index].num_connections++;
        printf("%s and %s are now connected.\n", device1, device2);
    }
}

void print_network_map(struct NetworkMap* map) {
    printf("--- Network Map ---\n");
    for (int i = 0; i < map->num_devices; i++) {
        printf("%s is connected to:", map->devices[i].name);
        for (int j = 0; j < map->devices[i].num_connections; j++) {
            printf(" %s", map->devices[map->devices[i].connections[j]].name);
        }
        printf(".\n");
    }
}

int main() {
    srand(time(NULL));
    struct NetworkMap map;
    map.num_devices = 0;

    printf("Welcome to the Network Topology Mapper!\n");
    printf("Enter 'quit' at any time to exit the program.\n");

    char input[20];
    while (1) {
        printf("> ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        } else if (strcmp(input, "add") == 0) {
            printf("Enter device name: ");
            scanf("%s", input);
            add_device(&map, input);
        } else if (strcmp(input, "connect") == 0) {
            printf("Enter first device name: ");
            scanf("%s", input);
            char device1[MAX_NAME_LEN];
            strncpy(device1, input, MAX_NAME_LEN);
            printf("Enter second device name: ");
            scanf("%s", input);
            char device2[MAX_NAME_LEN];
            strncpy(device2, input, MAX_NAME_LEN);
            connect_devices(&map, device1, device2);
        } else if (strcmp(input, "map") == 0) {
            print_network_map(&map);
        } else if (strcmp(input, "help") == 0) {
            printf("add - add a device to the network\n");
            printf("connect - connect two devices in the network\n");
            printf("map - print the network map\n");
            printf("quit - exit the program\n");
        } else {
            printf("Invalid input. Enter 'help' for a list of commands.\n");
        }
    }

    printf("Thanks for using the Network Topology Mapper!\n");

    return 0;
}