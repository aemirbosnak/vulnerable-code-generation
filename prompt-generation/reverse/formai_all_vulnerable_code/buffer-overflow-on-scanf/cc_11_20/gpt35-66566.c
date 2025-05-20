//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX_WIFI_STRENGTH 100
#define MIN_WIFI_STRENGTH -100

int main() {

    // declaration of variables
    int n = 0;
    int signal_strength[MAX_WIFI_STRENGTH];
    int i = 0;
    int sum = 0;
    int avg_strength = 0;
    int max_strength = 0;
    int min_strength = 0;
    int strength_count = 0;

    // Get user input
    printf("Enter the number of signal strengths to analyze (must be between 1 and 100): ");
    scanf("%d", &n);

    // Check if user input is valid
    if(n < 1 || n > 100) {
        printf("Invalid input. Program will now exit.");
        exit(0);
    }

    // Get user input for signal strengths and store them in array
    printf("Enter the signal strengths (must be between -100 and 100):\n");
    for(i=0; i<n; i++) {
        scanf("%d", &signal_strength[i]);

        // Check if signal strength is valid
        if(signal_strength[i] < MIN_WIFI_STRENGTH || signal_strength[i] > MAX_WIFI_STRENGTH) {
            printf("Invalid signal strength. Program will now exit.");
            exit(0);
        }

        // Check if signal strength is within acceptable range
        if(signal_strength[i] >= -70 && signal_strength[i] <= -30) {
            strength_count++;
        }
    }

    // Calculate average signal strength
    for(i=0; i<n; i++) {
        sum += signal_strength[i];
        if(signal_strength[i] > max_strength) {
            max_strength = signal_strength[i];
        }
        if(signal_strength[i] < min_strength) {
            min_strength = signal_strength[i];
        }
    }
    avg_strength = sum / n;

    // Print results
    printf("\n\n---Wi-Fi Signal Strength Analyzer---\n\n");
    printf("Average Signal Strength: %d\n", avg_strength);
    printf("Maximum Signal Strength: %d\n", max_strength);
    printf("Minimum Signal Strength: %d\n", min_strength);
    printf("Number of acceptable signal strengths (>= -70 and <= -30): %d\n\n", strength_count);

    // End program
    return 0;
}