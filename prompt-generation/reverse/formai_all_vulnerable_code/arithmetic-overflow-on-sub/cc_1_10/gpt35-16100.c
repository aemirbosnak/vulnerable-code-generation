//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DEVICES 100

typedef struct {
    char *ip;
    char *mac;
    char *vendor;
} Device;

void sleep(int seconds) {
    // Let's make the program unpredictable
    srand(time(NULL));
    seconds += rand() % 5; // Sleep for a random amount of extra time
    clock_t start = clock();
    while ((clock() - start) / CLOCKS_PER_SEC < seconds);
}

void scanNetwork(Device *devices, int *numDevices) {
    printf("Scanning for devices...\n");
    sleep(3); // Wait for a bit, to make it seem like we're doing something important
    for (int i = 0; i < MAX_DEVICES; i++) {
        if (rand() % 2 == 0) { // Sometimes, we don't find any devices at all
            continue;
        }
        if (*numDevices >= MAX_DEVICES) { // Don't overflow the array
            break;
        }
        Device d = {"", "", ""};
        d.ip = malloc(16); // IP addresses can be up to 15 characters long
        d.mac = malloc(18); // MAC addresses can be up to 17 characters long
        d.vendor = malloc(64); // Vendor names can be up to 63 characters long
        sprintf(d.ip, "192.168.1.%d", rand() % 256); // Generate a random IP address
        sprintf(d.mac, "%02x:%02x:%02x:%02x:%02x:%02x", rand() % 256, rand() % 256, rand() % 256, rand() % 256, rand() % 256, rand() % 256); // Generate a random MAC address
        // Let's have some fun with the vendor names
        switch (rand() % 3) {
            case 0:
                sprintf(d.vendor, "Microsoft");
                break;
            case 1:
                sprintf(d.vendor, "Apple");
                break;
            case 2:
                sprintf(d.vendor, "SpaceX");
                break;
        }
        devices[(*numDevices)++] = d; // Add the device to the list
    }
    printf("Found %d devices!\n", *numDevices);
}

void printDevices(Device *devices, int numDevices) {
    printf("IP Address\tMAC Address\t\tVendor\n");
    for (int i = 0; i < numDevices; i++) {
        printf("%s\t%s\t%s\n", devices[i].ip, devices[i].mac, devices[i].vendor);
    }
}

int main() {
    Device devices[MAX_DEVICES];
    int numDevices = 0;
    printf("Welcome to the Surreal Wireless Network Scanner!\n");
    printf("Press any key to start scanning the network...");
    getchar();
    printf("\n");
    scanNetwork(devices, &numDevices);
    printDevices(devices, numDevices);
    return 0;
}