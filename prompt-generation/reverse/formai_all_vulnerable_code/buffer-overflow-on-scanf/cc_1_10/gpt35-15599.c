//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TIME 10                 // Maximum time span
#define MAX_AP 10                   // Maximum access points
#define MAX_SAMPLES 100            // Maximum samples per access point
#define ONE_METER_SIGNAL_STRENGTH 50    // Signal strength at 1 meter
#define SIGNAL_LOSS_RATE 0.15       // Signal loss rate per meter
#define EVALUATION_DISTANCE 3       // Distance used for evaluation
#define MAX_VALUE 100               // Maximum signal strength value

// Function that generates a random signal strength value
int random_signal_strength()
{
    return (rand() % MAX_VALUE);
}

// Function that calculates the signal strength based on the distance
int calculate_signal_strength(int distance)
{
    return (int)round(ONE_METER_SIGNAL_STRENGTH - (distance * SIGNAL_LOSS_RATE));
}

int main()
{
    // Variable initialization
    int num_access_points, i, j, k;
    int signal_strength[MAX_AP][MAX_SAMPLES][MAX_TIME] = {{{0}}};

    // Seed the random number generator
    srand(time(NULL));

    // Prompt user for number of access points
    printf("Enter the number of access points: ");
    scanf("%d", &num_access_points);

    // For each access point, generate signal strength over time and samples
    for (i = 0; i < num_access_points; i++)
    {
        printf("Access Point %d: \n", i + 1);

        for (j = 0; j < MAX_SAMPLES; j++)
        {
            for (k = 0; k < MAX_TIME; k++)
            {
                // Calculate distance
                int distance = (j + 1) * (k + 1);
                // Calculate signal strength
                int strength = calculate_signal_strength(distance) + random_signal_strength();
                // Limit signal strength to maximum value
                if (strength > MAX_VALUE) strength = MAX_VALUE;

                // Store data
                signal_strength[i][j][k] = strength;

                printf("Sample %d, Time %d: %d\n", j + 1, k + 1, strength);
            }
        }
    }

    // Calculate average signal strength at evaluation distance for each access point
    for (i = 0; i < num_access_points; i++)
    {
        int sum_strength = 0;
        for (j = 0; j < MAX_SAMPLES; j++)
        {
            sum_strength += signal_strength[i][j][EVALUATION_DISTANCE - 1];
        }
        printf("Average Signal Strength for Access Point %d: %d\n", i + 1, (int)round((double)sum_strength / MAX_SAMPLES));
    }

    return 0;
}