//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //set random seed for probability calculation
    srand(time(0));

    //declare and assign initial values for variables
    int alien_count = 0;
    double invasion_probability = 0.0;
    int num_simulations = 1000000;
    int invasion_count = 0;

    //prompt user to input number of aliens
    printf("Enter the number of aliens: ");
    scanf("%d", &alien_count);

    //calculate invasion probability for a single alien
    double single_alien_prob = 1.0/alien_count;

    //perform simulations to calculate invasion probability
    for (int i=0; i<num_simulations; i++)
    {
        int rand_num = rand() % 100 + 1; //generate random number between 1 and 100

        if (rand_num <= (single_alien_prob*100)) //check if invasion occurs for single alien
        {
            invasion_count++; //increment invasion count if invasion occurs
        }
        else //invasion does not occur for single alien
        {
            //calculate probability for multiple aliens
            double multi_alien_prob = 1.0 - ((1.0 - single_alien_prob) * alien_count);

            rand_num = rand() % 100 + 1; //generate another random number

            if (rand_num <= (multi_alien_prob*100)) //check if invasion occurs for multiple aliens
            {
                invasion_count++; //increment invasion count if invasion occurs
            }
        }
    }

    //calculate final invasion probability
    invasion_probability = (double)invasion_count/num_simulations;

    //display results
    printf("\n\n");
    printf("Number of aliens: %d\n", alien_count);
    printf("Simulation runs: %d\n", num_simulations);
    printf("Invasion count: %d\n", invasion_count);
    printf("Invasion probability: %.2f%%\n", invasion_probability*100);

    return 0;
}