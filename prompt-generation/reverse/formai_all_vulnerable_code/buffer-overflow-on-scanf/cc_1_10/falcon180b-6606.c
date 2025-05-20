//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_planets, num_civilizations, num_invasions, invasion_probability;
    float avg_invasion_probability;
    char choice;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Get the number of planets to simulate
    printf("How many planets do you want to simulate? ");
    scanf("%d", &num_planets);

    // Get the number of civilizations to simulate
    printf("How many civilizations do you want to simulate? ");
    scanf("%d", &num_civilizations);

    // Simulate the invasions
    for (int i = 0; i < num_planets; i++) {
        num_invasions = 0;

        // Simulate the number of civilizations on the planet
        for (int j = 0; j < num_civilizations; j++) {
            if (rand() % 2 == 0) {
                // Civilization is advanced enough to invade other planets
                num_invasions++;
            }
        }

        // Calculate the invasion probability for the planet
        invasion_probability = (float)num_invasions / num_civilizations;

        // Print the results for the planet
        printf("Planet %d has an invasion probability of %.2f%%\n", i+1, invasion_probability * 100);
    }

    // Calculate the average invasion probability
    avg_invasion_probability = (float)num_invasions / (num_planets * num_civilizations);

    // Print the overall results
    printf("The average invasion probability is %.2f%%\n", avg_invasion_probability * 100);

    // Ask the user if they want to run the simulation again
    printf("Do you want to run the simulation again? (y/n) ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        main();
    } else {
        return 0;
    }
}