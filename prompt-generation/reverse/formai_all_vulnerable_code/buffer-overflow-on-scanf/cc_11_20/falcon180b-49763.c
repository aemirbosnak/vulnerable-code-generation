//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 1000
#define MAX_INVADERS 100
#define MIN_INVADERS 1
#define MAX_YEARS 1000
#define MIN_YEARS 1

int main()
{
    srand(time(NULL));
    int num_invaders;
    int num_tries = 0;
    int num_years = 0;
    int num_successful_invasions = 0;

    // Get number of invaders from user
    printf("Enter the number of alien invaders (between %d and %d): ", MIN_INVADERS, MAX_INVADERS);
    scanf("%d", &num_invaders);

    // Validate input
    if (num_invaders < MIN_INVADERS || num_invaders > MAX_INVADERS)
    {
        printf("Invalid number of invaders. Exiting program.\n");
        return 1;
    }

    // Simulate invasions
    while (num_successful_invasions == 0 && num_tries < MAX_TRIES)
    {
        num_tries++;
        num_years = 0;

        // Simulate invasion attempts for a number of years
        while (num_successful_invasions == 0 && num_years < MAX_YEARS)
        {
            num_years++;

            // Simulate a year of invasion attempts
            for (int i = 0; i < num_invaders; i++)
            {
                // Generate random number between 0 and 1
                double rand_num = rand() / (RAND_MAX + 1.0);

                // If random number is less than or equal to the probability of a successful invasion,
                // mark the invasion as successful
                if (rand_num <= 0.01)
                {
                    num_successful_invasions++;
                    break;
                }
            }
        }

        // If no successful invasions have occurred after a certain number of years,
        // aliens have given up on invading Earth
        if (num_successful_invasions == 0 && num_years == MAX_YEARS)
        {
            printf("The aliens have given up on invading Earth.\n");
            break;
        }
    }

    // Print results
    if (num_successful_invasions == 0)
    {
        printf("Earth has successfully repelled %d alien invaders!\n", num_invaders);
    }
    else
    {
        printf("Earth has been invaded by %d alien invaders!\n", num_successful_invasions);
    }

    return 0;
}