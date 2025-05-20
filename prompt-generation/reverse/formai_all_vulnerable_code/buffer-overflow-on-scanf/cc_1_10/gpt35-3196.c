//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Function to map the network topology */
void map_topology(char *device_name, int device_port) {
    printf("Mapping network topology...\n");

    // Check if device is connected to internet
    bool is_connected = true;

    if (device_port == 0) {
        printf("%s is not connected to the internet.\n", device_name);
        is_connected = false;
    }

    // Scanning nearby devices
    for (int i = 0; i < 5; i++) {
        char nearby_device_name[10];
        int nearby_device_port;

        // Randomly assigning names to nearby devices
        switch(i) {
            case 0:
                strcpy(nearby_device_name, "John's PC");
                nearby_device_port = 11111;
                break;

            case 1:
                strcpy(nearby_device_name, "Sarah's Laptop");
                nearby_device_port = 22222;
                break;

            case 2:
                strcpy(nearby_device_name, "Mike's Phone");
                nearby_device_port = 33333;
                break;

            case 3:
                strcpy(nearby_device_name, "Lisa's Tablet");
                nearby_device_port = 44444;
                break;

            case 4:
                strcpy(nearby_device_name, "Tom's Smart TV");
                nearby_device_port = 55555;
                break;
        }

        // Check if nearby device is connected to internet
        bool nearby_device_connected = true;

        if (nearby_device_port == 0) {
            printf("%s is not connected to the internet.\n", nearby_device_name);
            nearby_device_connected = false;
        }

        // Checking if devices are connected to each other
        if (is_connected && nearby_device_connected) {
            printf("%s is connected to %s.\n", device_name, nearby_device_name);
        }
    }
}

int main() {
    char device_name[10];
    int device_port;

    // Taking input from user
    printf("Enter the device name: ");
    scanf("%s", device_name);

    printf("Enter the device port number: ");
    scanf("%d", &device_port);

    map_topology(device_name, device_port);

    return 0;
}