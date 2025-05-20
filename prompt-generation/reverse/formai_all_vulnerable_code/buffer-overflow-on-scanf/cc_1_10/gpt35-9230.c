//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

// Function to generate random signal strength
int generateSignalStrength() {
    return (rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1)) + MIN_SIGNAL_STRENGTH;
}

int main() {
    int signalStrength[5], i, j, average, peak, lowest;
    char ssid[20];

    // Get SSID input from user
    printf("Enter the SSID: ");
    scanf("%s", ssid);

    // Generate random signal strengths for 5 different access points
    for (i = 0; i < 5; i++) {
        signalStrength[i] = generateSignalStrength();
    }

    // Display the signal strengths for each access point
    printf("\nSignal Strength for Access Points:\n");
    for (i = 0; i < 5; i++) {
        printf("Access Point %d: %d\n", i+1, signalStrength[i]);
    }

    // Calculate the average signal strength
    average = 0;
    for (i = 0; i < 5; i++) {
        average += signalStrength[i];
    }
    average /= 5;

    // Display the average signal strength
    printf("\nAverage Signal Strength: %d\n", average);

    // Calculate the peak signal strength
    peak = signalStrength[0];
    for (i = 1; i < 5; i++) {
        if (signalStrength[i] > peak) {
            peak = signalStrength[i];
        }
    }

    // Display the peak signal strength
    printf("Peak Signal Strength: %d\n", peak);

    // Calculate the lowest signal strength
    lowest = signalStrength[0];
    for (i = 1; i < 5; i++) {
        if (signalStrength[i] < lowest) {
            lowest = signalStrength[i];
        }
    }

    // Display the lowest signal strength
    printf("Lowest Signal Strength: %d\n", lowest);

    // Check for signal strength range
    printf("\nAccess Points within Range:\n");
    for (i = 0; i < 5; i++) {
        if (signalStrength[i] >= (average - 10) && signalStrength[i] <= (average + 10)) {
            printf("Access Point %d\n", i+1);
        }
    }

    return 0;
}