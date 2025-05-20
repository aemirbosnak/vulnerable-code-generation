//GEMINI-pro DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLANETS 1000000000
#define NUM_ALIENS 100000000

int main()
{
    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("We're here to help you figure out the chances of an alien invasion.\n");
    printf("Let's get started!\n");

    printf("First, we need to know a little bit about your planet.\n");
    printf("How many planets are in your solar system?\n");
    int num_planets;
    scanf("%d", &num_planets);

    printf("How many of those planets are habitable?\n");
    int num_habitable_planets;
    scanf("%d", &num_habitable_planets);

    printf("Now, let's talk about the aliens.\n");
    printf("How many aliens are there in the universe?\n");
    int num_aliens;
    scanf("%d", &num_aliens);

    printf("How many of those aliens are hostile?\n");
    int num_hostile_aliens;
    scanf("%d", &num_hostile_aliens);

    printf("Finally, let's put it all together.\n");

    double probability_of_invasion = (double)num_hostile_aliens * (double)num_habitable_planets / (double)num_aliens * (double)num_planets;

    printf("The probability of an alien invasion is %.2f%%\n", probability_of_invasion * 100);

    if (probability_of_invasion < 0.01)
    {
        printf("Don't worry, you're probably safe.\n");
    }
    else if (probability_of_invasion < 0.1)
    {
        printf("You might want to start thinking about building a spaceship.\n");
    }
    else if (probability_of_invasion < 0.5)
    {
        printf("Time to start stockpiling canned goods and learning how to use a bow and arrow.\n");
    }
    else
    {
        printf("You're probably going to die.\n");
    }

    printf("Thanks for using the Alien Invasion Probability Calculator!\n");

    return 0;
}