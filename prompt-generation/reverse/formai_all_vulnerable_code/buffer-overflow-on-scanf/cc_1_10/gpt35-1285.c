//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Variables to keep track of probability
    double prob = 0.0;
    int aliens = 0;
    int days = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Get user input for initial probability
    printf("Enter the probability of an alien invasion (%): ");
    scanf("%lf", &prob);

    // Convert percentage to decimal
    prob /= 100.0;

    // Get user input for number of days to calculate
    printf("Enter the number of days to calculate: ");
    scanf("%d", &days);

    // Calculate the probability of each day
    for (int i = 0; i < days; i++)
    {
        // Generate a random number between 0 and 1
        double random_num = (double)rand() / RAND_MAX;

        // If the random number is less than or equal to the probability,
        // increment the number of alien invasions
        if (random_num <= prob)
        {
            aliens++;
        }

        // Increase the probability for the next day
        prob += 0.001;

        // Make sure the probability does not exceed 1.0
        if (prob > 1.0)
        {
            prob = 1.0;
        }
    }

    // Print the results
    printf("After %d days, there were %d alien invasions.\n", days, aliens);

    return 0;
}