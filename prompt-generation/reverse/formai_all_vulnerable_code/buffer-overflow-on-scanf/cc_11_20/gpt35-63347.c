//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int probability = 0;
    int num_of_aliens;
    int alien_tech_level;
    int alien_distance;

    srand(time(NULL)); // seed random number generator

    printf("Welcome to the Alien Invasion Probability Calculator!\n");

    // get user inputs
    printf("How many aliens are we talking about?");
    scanf("%d", &num_of_aliens);
    printf("What is their technology level (1-10)?");
    scanf("%d", &alien_tech_level);
    printf("How many light years away are they?");
    scanf("%d", &alien_distance);

    // calculate probability of invasion based on inputs
    if (num_of_aliens > 1000)
    {
        probability += 50;
    }
    else if (num_of_aliens > 100)
    {
        probability += 30;
    }
    else if (num_of_aliens > 10)
    {
        probability += 15;
    }

    if (alien_tech_level > 5)
    {
        probability += 25;
    }
    else if (alien_tech_level > 2)
    {
        probability += 10;
    }
    else
    {
        probability += 5;
    }

    if (alien_distance < 10)
    {
        probability += 50;
    }
    else if (alien_distance < 100)
    {
        probability += 25;
    }
    else if (alien_distance < 1000)
    {
        probability += 10;
    }
    else
    {
        probability += 1;
    }

    // add some randomness to the probability
    probability += (rand() % 20) - 10;

    // make sure probability is between 0 and 100
    if (probability < 0)
    {
        probability = 0;
    }
    else if (probability > 100)
    {
        probability = 100;
    }

    // present probability to user
    printf("Based on the inputs, the probability of an alien invasion is %d%%.\n", probability);

    return 0;
}