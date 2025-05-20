//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_of_planets, num_of_inhabited_planets, num_of_intelligent_life_forms;
    float probability;
    char choice;

    // Seed the random number generator
    srand(time(NULL));

    // Get the number of planets from the user
    printf("Enter the number of planets: ");
    scanf("%d", &num_of_planets);

    // Initialize variables
    num_of_inhabited_planets = 0;
    num_of_intelligent_life_forms = 0;

    // Loop through each planet
    for (int i = 0; i < num_of_planets; i++) {
        // Determine if the planet is inhabited
        if (rand() % 2 == 0) {
            num_of_inhabited_planets++;

            // Determine if the inhabitants are intelligent
            if (rand() % 2 == 0) {
                num_of_intelligent_life_forms++;
            }
        }
    }

    // Calculate the probability of an alien invasion
    probability = ((float) num_of_intelligent_life_forms / num_of_inhabited_planets) * 100.0;

    // Display the results
    printf("Out of %d planets, %d are inhabited and %d have intelligent life forms.\n", num_of_planets, num_of_inhabited_planets, num_of_intelligent_life_forms);
    printf("The probability of an alien invasion is %.2f%%\n", probability);

    // Ask the user if they want to run the program again
    printf("Do you want to run the program again? (y/n): ");
    scanf(" %c", &choice);

    // If the user wants to run the program again, loop back to the beginning
    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        printf("Exiting program...\n");
        return 0;
    }
}