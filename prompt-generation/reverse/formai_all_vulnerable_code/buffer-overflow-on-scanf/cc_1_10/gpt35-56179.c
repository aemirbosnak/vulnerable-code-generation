//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct device {
    char ssid[20];
    int signal_strength;
};

typedef struct device Device;

void generate_device(Device* device) {
    char chars[26] = "abcdefghijklmnopqrstuvwxyz";
    int i;

    // Generate random ssid
    for (i = 0; i < 5; i++) {
        device->ssid[i] = chars[rand() % 26];
    }
    device->ssid[i] = '\0';

    // Generate random signal strength
    device->signal_strength = rand() % 101;
}

void print_devices(Device* devices, int num_devices) {
    printf("------------------------------------------\n");
    printf("| %-7s | %-17s | %-6s |\n", "Index", "SSID", "Strength");
    printf("------------------------------------------\n");
    for (int i = 0; i < num_devices; i++) {
        printf("| %-7d | %-17s | %-6d |\n", i+1, devices[i].ssid, devices[i].signal_strength);
    }
    printf("------------------------------------------\n");
}

int main() {
    srand(time(NULL)); // Initialize random seed
    
    int num_devices;

    printf("Enter number of devices to generate (max 10): ");
    scanf("%d", &num_devices);

    if (num_devices < 1 || num_devices > 10) {
        printf("Error: Invalid number of devices\n");
        return 1;
    }

    Device devices[num_devices];

    for (int i = 0; i < num_devices; i++) {
        generate_device(&devices[i]);
    }

    print_devices(devices, num_devices);

    return 0;
}