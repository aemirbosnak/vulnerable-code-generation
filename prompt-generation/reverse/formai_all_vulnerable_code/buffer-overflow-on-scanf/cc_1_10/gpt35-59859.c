//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIGNAL_STRENGTH 100
#define MIN_SIGNAL_STRENGTH 0

/* Function to generate random signal strength */
int generate_random_signal_strength() {
    return (rand() % (MAX_SIGNAL_STRENGTH - MIN_SIGNAL_STRENGTH + 1)) + MIN_SIGNAL_STRENGTH;
}

/* Function to calculate standard deviation */
float calculate_standard_deviation(int signal_strengths[], int n) {
    float mean = 0;
    float sum = 0;
    float variance = 0;
    float std_deviation = 0;

    /* Calculate mean */
    for (int i = 0; i < n; i++) {
        mean += signal_strengths[i];
    }
    mean /= n;

    /* Calculate variance */
    for (int i = 0; i < n; i++) {
        sum += pow(signal_strengths[i] - mean, 2);
    }
    variance = sum / n;

    /* Calculate standard deviation */
    std_deviation = sqrt(variance);

    return std_deviation;
}

int main() {
    int n; /* Number of signal strengths to analyze */
    int signal_strengths[100]; /* Array to store signal strengths */

    srand(time(NULL)); /* Seed for random number generator */

    printf("Enter the number of signal strengths to analyze (max 100): ");
    scanf("%d", &n);

    /* Generate random signal strengths and save in array */
    for (int i = 0; i < n; i++) {
        signal_strengths[i] = generate_random_signal_strength();
    }

    /* Print the signal strengths */
    printf("Signal strengths:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", signal_strengths[i]);
    }
    printf("\n");

    /* Calculate and print the average signal strength */
    float average_signal_strength = 0;
    for (int i = 0; i < n; i++) {
        average_signal_strength += signal_strengths[i];
    }
    average_signal_strength /= n;
    printf("Average signal strength: %.2f\n", average_signal_strength);

    /* Calculate and print the standard deviation */
    float std_deviation = calculate_standard_deviation(signal_strengths, n);
    printf("Standard deviation: %.2f\n", std_deviation);

    return 0;
}