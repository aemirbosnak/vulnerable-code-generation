//Gemma-7B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415926535

int main()
{
    // Probability of alien invasion calculator
    // Version: 1.0

    // Define variables
    double probability;
    int year;
    char alien_type;

    // Get user input
    printf("Enter the year: ");
    scanf("%d", &year);

    printf("Enter the alien type (A, B, C): ");
    scanf(" %c", &alien_type);

    // Calculate probability
    switch (alien_type)
    {
        case 'A':
            probability = 0.05 * year + 0.2;
            break;
        case 'B':
            probability = 0.1 * year - 0.1;
            break;
        case 'C':
            probability = 0.15 * year + 0.3;
            break;
        default:
            printf("Invalid alien type.\n");
            return 1;
    }

    // Display results
    printf("The probability of alien invasion in %d is %f.\n", year, probability);

    // Calculate the number of alien invasions
    int num_invasions = (int) (probability * 1000);

    // Display the number of alien invasions
    printf("The number of alien invasions in %d is %d.\n", year, num_invasions);

    return 0;
}