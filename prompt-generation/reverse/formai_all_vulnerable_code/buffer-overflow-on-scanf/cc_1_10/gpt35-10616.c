//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0
#define MAX_DEVICES 10

int main(void) {
    int num_devices;
    int signal_strength[MAX_DEVICES];
    bool device_status[MAX_DEVICES];

    // Ask user for number of devices
    printf("How many devices are currently connected to the Wi-Fi network?\n");
    scanf("%d", &num_devices);

    // Check if the number of devices is within range
    if (num_devices < 1 || num_devices > MAX_DEVICES) {
        printf("Invalid number of devices. Please try again.\n");
        return 1;
    }

    // Ask user for signal strength for each device
    for (int i = 0; i < num_devices; i++) {
        printf("Please enter the signal strength for device %d (between 0 and 100):\n", i + 1);
        scanf("%d", &signal_strength[i]);

        // Check if signal strength is within range
        if (signal_strength[i] < MIN_SIGNAL_STRENGTH || signal_strength[i] > MAX_SIGNAL_STRENGTH) {
            printf("Invalid signal strength for device %d. Please try again.\n", i + 1);
            i--;
            continue;
        }

        // Update device status based on signal strength
        if (signal_strength[i] >= 50) {
            device_status[i] = true;
        } else {
            device_status[i] = false;
        }
    }

    // Print device status
    printf("\nDevice Status:\n");
    for (int i = 0; i < num_devices; i++) {
        printf("Device %d: ", i + 1);
        if (device_status[i]) {
            printf("Connected\n");
        } else {
            printf("Disconnected\n");
        }
    }

    return 0;
}