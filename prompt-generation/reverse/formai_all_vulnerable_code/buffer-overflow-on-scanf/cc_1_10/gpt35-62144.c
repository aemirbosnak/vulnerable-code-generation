//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main() {
    // Initialization of variables
    int signal_strength = 0;
    int max_signal_strength = -999;
    int min_signal_strength = 999;
    int num_samples = 0;
    double avg_signal_strength = 0.0;
    double deviation = 0.0;

    // Introduction to program
    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n");
    printf("This program will help you analyze your Wi-Fi signal strength.\n");

    // Prompt user to enter data
    printf("Please enter the number of samples you wish to analyze: ");
    scanf("%d", &num_samples);

    // Check if user entered valid input
    if (num_samples <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    // Get signal strength data from user
    printf("Please enter the signal strength for each sample:\n");

    for (int i = 0; i < num_samples; i++) {
        printf("Sample %d: ", i+1);
        scanf("%d", &signal_strength);

        // Keep track of max and min signal strengths
        if (signal_strength > max_signal_strength) {
            max_signal_strength = signal_strength;
        }
        if (signal_strength < min_signal_strength) {
            min_signal_strength = signal_strength;
        }

        // Calculate running average
        avg_signal_strength = ((avg_signal_strength * i) + signal_strength) / (i+1);
    }

    // Calculate standard deviation
    for (int i = 0; i < num_samples; i++) {
        printf("Sample %d: ", i+1);
        scanf("%d", &signal_strength);

        deviation += pow(signal_strength - avg_signal_strength, 2);
    }

    deviation = sqrt(deviation / num_samples);

    // Output results to user
    printf("\nHere are your results:\n");
    printf("Maximum signal strength: %d\n", max_signal_strength);
    printf("Minimum signal strength: %d\n", min_signal_strength);
    printf("Average signal strength: %.2lf\n", avg_signal_strength);
    printf("Standard deviation: %.2lf\n", deviation);

    // Goodbye message
    printf("\nThank you for using Wi-Fi Signal Strength Analyzer!\n");
    
    return 0;
}