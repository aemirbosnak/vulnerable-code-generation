//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

// Function to generate a random number between min and max
int rand_num(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Function to simulate the alien invasion
void simulate_invasion(int population, int technology, int resources)
{
    int success = FALSE;
    int defense = rand_num(1, 100);

    if (defense >= 80)
    {
        printf("Earth's defense was successful!\n");
        success = TRUE;
    }
    else if (defense >= 50)
    {
        printf("The aliens were repelled, but not without causing significant damage.\n");
        success = TRUE;
    }
    else
    {
        printf("The aliens have successfully invaded Earth!\n");
    }

    if (success)
    {
        printf("The probability of a successful alien invasion is %d%%\n", 100 - defense);
    }
}

int main()
{
    srand(time(NULL));

    // Get user input for population, technology, and resources
    int population, technology, resources;
    printf("Enter the alien population: ");
    scanf("%d", &population);
    printf("Enter the alien technology level (1-100): ");
    scanf("%d", &technology);
    printf("Enter the resources available to the aliens (1-100): ");
    scanf("%d", &resources);

    // Simulate the alien invasion
    simulate_invasion(population, technology, resources);

    return 0;
}