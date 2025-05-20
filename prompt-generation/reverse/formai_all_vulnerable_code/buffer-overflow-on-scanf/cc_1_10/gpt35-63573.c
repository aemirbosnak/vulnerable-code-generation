//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIGNAL_STRENGTH 100

/* Function to calculate signal strength percentage from signal strength (dBm) */
float calculateStrengthPercentage(int signalStrength) {
    return ((float)(signalStrength + 100) / MAX_SIGNAL_STRENGTH) * 100;
}

int main() {
    printf("Welcome to the Wi-Fi Signal Strength Analyzer!\n");

    /* Simulating signal strength values from -100 dBm to 0 dBm */
    int signalStrengths[] = {-80, -70, -60, -50, -40, -30, -20, -10, 0};
    int numSignalStrengths = sizeof(signalStrengths) / sizeof(int);

    /* Getting the current signal strength from user */
    int currentSignalStrength;
    printf("Please enter current signal strength (dBm): ");
    scanf("%d", &currentSignalStrength);

    /* Checking if the user input is valid */
    if (currentSignalStrength > 0 || currentSignalStrength < -100) {
        printf("Invalid input! Signal strength should be between -100 and 0 dBm.\n");
        return 0;
    }

    /* Finding the closest signal strength value from the simulated values */
    int closestSignalStrengthIndex = 0;
    int minDistance = abs(currentSignalStrength - signalStrengths[0]);
    for (int i = 1; i < numSignalStrengths; i++) {
        int distance = abs(currentSignalStrength - signalStrengths[i]);
        if (distance < minDistance) {
            minDistance = distance;
            closestSignalStrengthIndex = i;
        }
    }

    /* Displaying the current signal strength and closest signal strength value */
    printf("Current signal strength (dBm): %d\n", currentSignalStrength);
    printf("Closest signal strength value (dBm): %d\n", signalStrengths[closestSignalStrengthIndex]);

    /* Calculating signal strength percentage for current and closest signal strengths */
    float currentSignalStrengthPercentage = calculateStrengthPercentage(currentSignalStrength);
    float closestSignalStrengthPercentage = calculateStrengthPercentage(signalStrengths[closestSignalStrengthIndex]);

    /* Displaying the signal strength percentages for current and closest signal strengths */
    printf("Current signal strength percentage: %.2f%%\n", currentSignalStrengthPercentage);
    printf("Closest signal strength percentage: %.2f%%\n", closestSignalStrengthPercentage);

    /* Checking if the signal strength is good, fair, or poor */
    if (currentSignalStrengthPercentage >= 60) {
        printf("Signal strength is good.\n");
    } else if (currentSignalStrengthPercentage < 60 && currentSignalStrengthPercentage >= 30) {
        printf("Signal strength is fair.\n");
    } else {
        printf("Signal strength is poor.\n");
    }

    return 0;
}