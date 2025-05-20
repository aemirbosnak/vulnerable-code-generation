//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEVICES 10

typedef struct {
    char name[20];
    int strength;
} Device;

int main() {
    Device devices[MAX_DEVICES];
    int numDevices = 0;

    printf("Scanning for available Wi-Fi signals...\n");

    // Simulate scanning for available Wi-Fi signals
    for (int i = 0; i < MAX_DEVICES; i++) {
        strncpy(devices[i].name, "Device Name", 20);
        devices[i].strength = rand() % 10 + 1;
        numDevices++;
    }

    printf("\nFound %d Wi-Fi signals:\n", numDevices);

    // Print out list of available Wi-Fi signals and signal strength
    for (int i = 0; i < numDevices; i++) {
        printf("%d. %s - Signal Strength: %d\n", i+1, devices[i].name, devices[i].strength);
    }

    printf("\nEnter the number of the device you would like to analyze: ");
    int choice;
    scanf("%d", &choice);

    // Check if user input is within valid range
    if (choice < 1 || choice > numDevices) {
        printf("\nInvalid choice. Program exiting.\n");
    } else {
        printf("\nAnalyzing signal strength of %s...\n", devices[choice-1].name);

        if (devices[choice-1].strength >= 8) {
            printf("Signal strength is at maximum level. This device is perfect for high-speed data exchange!\n");
        } else if (devices[choice-1].strength >= 6 && devices[choice-1].strength < 8) {
            printf("Signal strength is strong. Data exchange should be fast and efficient.\n");
        } else if (devices[choice-1].strength >= 4 && devices[choice-1].strength < 6) {
            printf("Signal strength is moderate. Data exchange may experience some latency issues.\n");
        } else if (devices[choice-1].strength >= 2 && devices[choice-1].strength < 4) {
            printf("Signal strength is weak. Data exchange may be slow and interrupted.\n");
        } else {
            printf("Signal strength is very weak. Data exchange will be extremely slow and may disconnect frequently.\n");
        }
    }

    return 0;
}