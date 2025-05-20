//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, j, k, count, num, max_prob, total_prob = 0;
    int prob[6] = {30, 20, 15, 10, 5, 3};   // Probability percentages of Alien Invasion
    int weight[6] = {20, 25, 20, 15, 10, 10}; // Weightage for each probability level
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    printf("Please enter the number of simulations to run: ");
    scanf("%d", &num);

    for (i = 0; i < num; i++) // Loop to run simulations
    {
        count = 0;  // Counter for number of times alien invasion occurs in a simulation
        
        for (j = 0; j < 7; j++) // Loop to simulate a week's worth of probabilities
        {
            int r = rand() % 101; // Generate a random number from 0 to 100 for probability

            for (k = 0; k < 6; k++) // Loop to check which probability level applies
            {
                total_prob += prob[k];   // Keep track of total probability for weightage
                
                if (r <= total_prob)    // If the random number falls within a probability level
                {
                    if (k == 0) // If the highest probability level is chosen, alien invasion occurs
                    {
                        count++;    // Increment the counter for number of times alien invasion occurs
                    }
                    break;
                }
            }
            total_prob = 0; // Reset total probability for weightage
        }

        printf("\nSimulation %d:\n", i+1);
        printf("Alien Invasion occurred %d times out of 7 weeks.\n", count);
    }

    max_prob = prob[0]; // Initial maximum probability level assumed to be the highest
    for (i = 1; i < 6; i++)
    {
        if (prob[i] > max_prob) // If any higher probability level exists
        {
            max_prob = prob[i]; // Set it as the new maximum probability level
        }
    }

    printf("\nBased on past data, the likelihood of Alien Invasion is as follows:\n");
    for (i = 0; i < 6; i++)
    {
        printf("%d%% - Probability level %d\n", prob[i], i+1);
    }

    printf("\nThe highest probability level is %d%%.\n", max_prob);
    printf("Weightage for each probability level:\n");

    for (i = 0; i < 6; i++)
    {
        printf("Probability level %d: %d\n", i+1, weight[i]);
    }

    return 0;
}