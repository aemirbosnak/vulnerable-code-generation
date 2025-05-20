//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DEVICES 20
#define MAX_SSID_LENGTH 32

typedef struct wifi_device {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} wifi_device_t;

int main() {
    wifi_device_t devices[MAX_DEVICES];
    int num_devices = 0;

    printf("Wi-Fi Signal Strength Analyzer\n");

    while (num_devices < MAX_DEVICES) {
        char ssid[MAX_SSID_LENGTH];
        int signal_strength;

        printf("Enter the SSID of device #%d (or 'done' to finish): ", num_devices + 1);
        scanf("%s", ssid);

        if (strcmp(ssid, "done") == 0) {
            break;
        }

        printf("Enter the signal strength (0-100) of device #%d: ", num_devices + 1);
        scanf("%d", &signal_strength);

        wifi_device_t device;
        strncpy(device.ssid, ssid, MAX_SSID_LENGTH);
        device.signal_strength = signal_strength;

        devices[num_devices++] = device;
    }

    if (num_devices == 0) {
        printf("No devices were entered.\n");
        return 0;
    }

    printf("\n");

    int total_strength = 0;
    int max_strength = -1;
    int min_strength = 101;
    wifi_device_t* strongest_device = NULL;
    wifi_device_t* weakest_device = NULL;

    printf("Devices detected:\n");
    printf("==================\n");

    for (int i = 0; i < num_devices; i++) {
        wifi_device_t device = devices[i];

        total_strength += device.signal_strength;

        if (device.signal_strength > max_strength) {
            max_strength = device.signal_strength;
            strongest_device = &device;
        }

        if (device.signal_strength < min_strength) {
            min_strength = device.signal_strength;
            weakest_device = &device;
        }

        printf("SSID: %s\tSignal Strength: %d%%\n", device.ssid, device.signal_strength);
    }

    double average_strength = total_strength / (double)num_devices;

    printf("==================\n");
    printf("Overall statistics:\n");
    printf("------------------\n");
    printf("Number of devices: %d\n", num_devices);
    printf("Average signal strength: %.2f%%\n", average_strength);

    if (strongest_device != NULL) {
        printf("Strongest device: SSID %s\tSignal Strength: %d%%\n", strongest_device->ssid, strongest_device->signal_strength);
    }

    if (weakest_device != NULL) {
        printf("Weakest device: SSID %s\tSignal Strength: %d%%\n", weakest_device->ssid, weakest_device->signal_strength);
    }

    return 0;
}