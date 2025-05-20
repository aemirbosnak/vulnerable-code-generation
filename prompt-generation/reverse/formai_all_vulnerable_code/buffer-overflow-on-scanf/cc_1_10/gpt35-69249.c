//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DEVICES 100
#define MAX_NAME_LENGTH 20

struct Device {
    char name[MAX_NAME_LENGTH];
    char mac_address[18];
    int signal_strength;
};

int main() {
    struct Device devices[MAX_DEVICES];
    int num_devices = 0;

    printf("Starting wireless network scanner...\n");

    // simulate scanning for devices
    bool continue_scanning = true;
    while (continue_scanning && num_devices < MAX_DEVICES) {
        printf("Scanning for devices...\n");
        printf("Enter device name ('quit' to exit): ");
        char name[MAX_NAME_LENGTH];
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            continue_scanning = false;
            break;
        }

        printf("Enter device MAC address: ");
        char mac_address[18];
        scanf("%s", mac_address);

        printf("Enter signal strength (0-100): ");
        int signal_strength;
        scanf("%d", &signal_strength);

        // add device to array
        struct Device new_device = {0};
        strcpy(new_device.name, name);
        strcpy(new_device.mac_address, mac_address);
        new_device.signal_strength = signal_strength;
        devices[num_devices] = new_device;
        num_devices++;
    }

    // print out all devices found
    printf("Devices found:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("%d. %s (%s) - %d%% signal strength\n", i+1, devices[i].name,
            devices[i].mac_address, devices[i].signal_strength);
    }

    return 0;
}