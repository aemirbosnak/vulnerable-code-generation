//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NETWORK_DEVICES 50

typedef struct device {
    char ip_address[16];
    char device_name[25];
    int num_connections;
    char connected_devices[MAX_NETWORK_DEVICES][25];
} DEVICE;

//function to add new device to the network
void add_device(DEVICE* d, int* num_devices) {
    printf("\nEnter the IP address of the device: ");
    scanf("%s", d[*num_devices].ip_address);
    printf("Enter the name of the device: ");
    scanf("%s", d[*num_devices].device_name);
    d[*num_devices].num_connections = 0;
    (*num_devices)++;
    printf("\nDevice added successfully to the network!\n");
}

//function to add a connection between two devices
void add_connection(DEVICE* d, int num_devices) {
    char device1_name[25], device2_name[25];
    int device1_index, device2_index;
    printf("\nEnter the name of the first device: ");
    scanf("%s", device1_name);
    printf("Enter the name of the second device: ");
    scanf("%s", device2_name);

    //find the index of the first device
    for(int i=0; i<num_devices; i++) {
        if(strcmp(device1_name, d[i].device_name) == 0) {
            device1_index = i;
            break;
        }
    }

    //find the index of the second device
    for(int i=0; i<num_devices; i++) {
        if(strcmp(device2_name, d[i].device_name) == 0) {
            device2_index = i;
            break;
        }
    }

    //add the connection to the first device
    strcpy(d[device1_index].connected_devices[d[device1_index].num_connections], device2_name);
    d[device1_index].num_connections++;

    //add the connection to the second device
    strcpy(d[device2_index].connected_devices[d[device2_index].num_connections], device1_name);
    d[device2_index].num_connections++;

    printf("\nConnection added successfully between %s and %s\n", device1_name, device2_name);
}

//function to print the network topology
void print_network_topology(DEVICE* d, int num_devices) {
    printf("\n---------------- Network Topology ----------------\n");
    for(int i=0; i<num_devices; i++) {
        printf("%s (%s) is connected to ", d[i].device_name, d[i].ip_address);
        for(int j=0; j<d[i].num_connections; j++) {
            printf("%s ", d[i].connected_devices[j]);
        }
        printf("\n");
    }
    printf("--------------------------------------------------\n");
}

int main() {
    DEVICE devices[MAX_NETWORK_DEVICES];
    int num_devices = 0, choice;

    while(1) {
        printf("\n------ Network Topology Mapper ------\n");
        printf("1. Add a new device to the network\n");
        printf("2. Add a connection between two devices\n");
        printf("3. Print the network topology\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_device(devices, &num_devices);
                break;
            case 2:
                if(num_devices < 2) {
                    printf("\nAt least two devices are required to make a connection.\n");
                }
                else {
                    add_connection(devices, num_devices);
                }
                break;
            case 3:
                if(num_devices == 0) {
                    printf("\nThere are no devices in the network yet.\n");
                }
                else {
                    print_network_topology(devices, num_devices);
                }
                break;
            case 4:
                printf("\nThank you for using Network Topology Mapper!\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }
    return 0;
}