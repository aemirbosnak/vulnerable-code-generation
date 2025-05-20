//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_READINGS 1000

// Function to calculate Wi-Fi signal strength in dBm based on received signal strength indicator (RSSI) value
int calculateSignalStrength(int rssi) {
    int signalStrength = 0;
    if (rssi <= -100) {
        signalStrength = 0;
    } else if (rssi >= -50) {
        signalStrength = 100;
    } else {
        signalStrength = 2 * (rssi + 100);
    }
    return signalStrength;
}

int main() {
    int numberOfReadings;
    int rssiValues[MAX_READINGS];
    bool isInputValid = false;
    // Prompt user to input the number of readings
    while (!isInputValid) {
        printf("Enter the number of Wi-Fi signal strength readings (1-1000): ");
        scanf("%d", &numberOfReadings);
        if (numberOfReadings < 1 || numberOfReadings > 1000) {
            printf("Invalid input! Please enter a value between 1 and 1000.\n");
        } else {
            isInputValid = true;
        }
    }
    // Prompt user to input the RSSI values for each reading
    for (int i = 1; i <= numberOfReadings; i++) {
        bool isReadingValid = false;
        while (!isReadingValid) {
            printf("Enter the RSSI value for reading %d (-100 to 0): ", i);
            scanf("%d", &rssiValues[i-1]);
            if (rssiValues[i-1] < -100 || rssiValues[i-1] > 0) {
                printf("Invalid input! Please enter a value between -100 and 0.\n");
            } else {
                isReadingValid = true;
            }
        }
    }
    // Calculate the average signal strength in dBm and percentage
    float sumDbm = 0;
    for (int i = 0; i < numberOfReadings; i++) {
        sumDbm += rssiValues[i];
    }
    float averageDbm = sumDbm / numberOfReadings;
    int averagePer = calculateSignalStrength(averageDbm);
    // Calculate the standard deviation of signal strength in dBm
    float sumSquares = 0;
    for (int i = 0; i < numberOfReadings; i++) {
        sumSquares += pow((rssiValues[i] - averageDbm), 2);
    }
    float variance = sumSquares / numberOfReadings;
    float standardDeviation = sqrt(variance);
    // Output the results
    printf("Average Wi-Fi signal strength in dBm: %.2f\n", averageDbm);
    printf("Average Wi-Fi signal strength in percentage: %d%%\n", averagePer);
    printf("Standard deviation of Wi-Fi signal strength in dBm: %.2f\n", standardDeviation);
    return 0;
}