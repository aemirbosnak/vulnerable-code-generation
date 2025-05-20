//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ada Lovelace
/*
 * Wi-Fi Signal Strength Analyzer Program
 * Written in Ada Lovelace Style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIGNAL 100 // Maximum Wi-Fi signal strength

int main() 
{
    // Welcome message
    printf("Welcome to the Wi-Fi Signal Strength Analyzer\n");

    // Ask user for signal strength values
    int numSignals;
    printf("How many signal strength values would you like to enter?: ");
    scanf("%d", &numSignals);

    // Check if input is valid
    if (numSignals < 1) {
        printf("Invalid input: number of signal strength values must be at least 1\n");
        return 1;
    }

    // Allocate memory for signal strength array
    int *signalStrengths = (int *) malloc(numSignals * sizeof(int));
    if (signalStrengths == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Ask user for signal strength values
    printf("Enter the signal strength values (between 0 and %d):\n", MAX_SIGNAL);
    for (int i = 0; i < numSignals; i++) {
        printf("%d. ", i + 1);
        scanf("%d", &signalStrengths[i]);

        // Check if input is valid
        if (signalStrengths[i] < 0 || signalStrengths[i] > MAX_SIGNAL) {
            printf("Invalid input: signal strength value must be between 0 and %d\n", MAX_SIGNAL);
            free(signalStrengths);
            return 1;
        }
    }

    // Calculate average signal strength
    int sum = 0;
    for (int i = 0; i < numSignals; i++) {
        sum += signalStrengths[i];
    }
    double avgSignalStrength = (double) sum / numSignals;

    // Calculate standard deviation of signal strength
    double variance = 0;
    for (int i = 0; i < numSignals; i++) {
        variance += pow(signalStrengths[i] - avgSignalStrength, 2);
    }
    double stdDevSignalStrength = sqrt(variance / numSignals);

    // Print results
    printf("\nResults:\n");
    printf("Average signal strength: %0.2f\n", avgSignalStrength);
    printf("Standard deviation of signal strength: %0.2f\n", stdDevSignalStrength);

    // Free memory
    free(signalStrengths);

    return 0;
}