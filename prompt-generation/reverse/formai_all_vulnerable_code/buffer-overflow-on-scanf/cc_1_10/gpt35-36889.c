//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate Wi-Fi signal strength values
int simulateSignalStrength() {
    // Simulate signal strengths from -100 to -20 dbm
    return (rand() % 81) - 100;
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Display program header
    printf("Wi-Fi Signal Strength Analyzer\n");
    printf("==============================\n\n");
    
    // Prompt user for number of signal strength samples
    int numSamples;
    printf("How many signal strength samples would you like to analyze? ");
    scanf("%d", &numSamples);
    
    // Validate user input
    if (numSamples <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }
    
    // Declare arrays to hold signal strength data
    int signalStrengths[numSamples];
    
    // Populate signal strength array with simulated values
    for (int i = 0; i < numSamples; i++) {
        signalStrengths[i] = simulateSignalStrength();
    }
    
    // Calculate average signal strength
    int total = 0;
    for (int i = 0; i < numSamples; i++) {
        total += signalStrengths[i];
    }
    float average = (float) total / numSamples;
    
    // Calculate maximum and minimum signal strengths
    int maxStrength = signalStrengths[0];
    int minStrength = signalStrengths[0];
    for (int i = 1; i < numSamples; i++) {
        if (signalStrengths[i] > maxStrength) {
            maxStrength = signalStrengths[i];
        }
        if (signalStrengths[i] < minStrength) {
            minStrength = signalStrengths[i];
        }
    }
    
    // Display summary statistics
    printf("\nSignal Strength Summary\n");
    printf("------------------------\n");
    printf("Average: %.2f dbm\n", average);
    printf("Minimum: %d dbm\n", minStrength);
    printf("Maximum: %d dbm\n", maxStrength);
    
    // Determine signal quality based on average signal strength
    printf("\nSignal Quality\n");
    printf("--------------\n");
    if (average >= -30) {
        printf("Excellent signal quality!\n");
    } else if (average >= -67) {
        printf("Good signal quality.\n");
    } else if (average >= -70) {
        printf("Fair signal quality.\n");
    } else if (average >= -80) {
        printf("Poor signal quality.\n");
    } else {
        printf("No signal. :(\n");
    }
    
    // Determine signal stability based on standard deviation of signal strengths
    printf("\nSignal Stability\n");
    printf("-----------------\n");
    float variance = 0;
    for (int i = 0; i < numSamples; i++) {
        variance += (signalStrengths[i] - average) * (signalStrengths[i] - average);
    }
    variance /= numSamples;
    float stdev = sqrt(variance);
    if (stdev < 10) {
        printf("Very stable signal.\n");
    } else if (stdev < 20) {
        printf("Somewhat stable signal.\n");
    } else {
        printf("Unstable signal.\n");
    }
    
    return 0;
}