//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_planets, num_inhabited, num_attacked;
    double probability;
    char choice;

    // Initialize random number generator
    srand(time(NULL));

    // Prompt user for number of planets
    printf("Enter the number of planets in the galaxy: ");
    scanf("%d", &num_planets);

    // Prompt user for number of planets that are inhabited
    printf("Enter the number of planets that are inhabited: ");
    scanf("%d", &num_inhabited);

    // Calculate probability of alien invasion
    probability = ((double) num_inhabited / num_planets) * 100;

    // Print probability of alien invasion
    printf("The probability of an alien invasion is %.2f%%\n", probability);

    // Prompt user for number of planets that have been attacked
    printf("Enter the number of planets that have been attacked: ");
    scanf("%d", &num_attacked);

    // Calculate probability of being attacked
    probability = ((double) num_attacked / num_inhabited) * 100;

    // Print probability of being attacked
    printf("The probability of being attacked by aliens is %.2f%%\n", probability);

    // Ask user if they want to try again
    printf("Do you want to try again? (y/n): ");
    scanf(" %c", &choice);

    // If user wants to try again, loop back to start
    if (choice == 'y' || choice == 'Y') {
        main();
    }

    // If user does not want to try again, exit program
    else {
        return 0;
    }
}