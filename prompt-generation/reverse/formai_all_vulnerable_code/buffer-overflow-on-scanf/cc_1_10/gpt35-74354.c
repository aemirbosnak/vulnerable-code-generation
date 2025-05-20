//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define NUM_SAMPLES 10

int main()
{
    int signalStrengths[NUM_SAMPLES];
    int i, average;

    printf("Wi-Fi Signal Strength Analyzer\n\n");

    // Get signal strength samples
    for (i = 0; i < NUM_SAMPLES; i++)
    {
        printf("Enter sample %d: ", i + 1);
        scanf("%d", &signalStrengths[i]);
    }

    // Calculate average signal strength
    average = 0;
    for (i = 0; i < NUM_SAMPLES; i++)
    {
        average += signalStrengths[i];
    }
    average /= NUM_SAMPLES;

    // Determine signal strength quality
    printf("\nAverage signal strength: %d\n\n", average);
    if (average >= -50)
    {
        printf("Signal strength: Excellent\n");
    }
    else if (average >= -60)
    {
        printf("Signal strength: Good\n");
    }
    else if (average >= -70)
    {
        printf("Signal strength: Fair\n");
    }
    else if (average >= -80)
    {
        printf("Signal strength: Weak\n");
    }
    else
    {
        printf("Signal strength: Very weak\n");
    }

    return 0;
}