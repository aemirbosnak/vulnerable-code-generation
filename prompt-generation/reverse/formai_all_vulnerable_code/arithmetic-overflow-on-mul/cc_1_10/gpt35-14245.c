//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int max_possible_invaders = 1000000;
    int min_possible_invaders = 1000;
    int invasion_probability = (rand() % 101);
    int possible_invaders = (rand() % (max_possible_invaders - min_possible_invaders + 1)) + min_possible_invaders;
    int expected_casualties = 0;
    int invasion_strength = (rand() % 10001) + 500;

    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");

    printf("Calculating probability of an alien invasion...\n");
    printf("Please wait.\n");
    srand(time(NULL));
    sleep(3);

    if (invasion_probability >= 75)
    {
        printf("Probability of an alien invasion: %d%%\n", invasion_probability);
        printf("Recommended action: Evacuate the area immediately!\n");
        printf("Possible number of invaders: %d\n", possible_invaders);
        expected_casualties = (invasion_strength * possible_invaders) / 100;
        printf("Expected civilian casualties: %d\n", expected_casualties);
    }
    else if (invasion_probability >= 50 && invasion_probability < 75)
    {
        printf("Probability of an alien invasion: %d%%\n", invasion_probability);
        printf("Recommended action: Prepare for the worst!\n");
        printf("Possible number of invaders: %d\n", possible_invaders);
        expected_casualties = (invasion_strength * possible_invaders) / 200;
        printf("Expected civilian casualties: %d\n", expected_casualties);
    }
    else if (invasion_probability >= 25 && invasion_probability < 50)
    {
        printf("Probability of an alien invasion: %d%%\n", invasion_probability);
        printf("Recommended action: Remain vigilant and keep monitoring the situation.\n");
        printf("Possible number of invaders: %d\n", possible_invaders);
        expected_casualties = (invasion_strength * possible_invaders) / 300;
        printf("Expected civilian casualties: %d\n", expected_casualties);
    }
    else
    {
        printf("Probability of an alien invasion: %d%%\n", invasion_probability);
        printf("Recommended action: Carry on with your normal routine.\n");
        printf("Possible number of invaders: %d\n", possible_invaders);
    }

    return 0;
}