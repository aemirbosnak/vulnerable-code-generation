//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIES 100
#define MAX_NUM_ALIENS 100
#define MAX_NUM_YEARS 100

int main() {
    int num_aliens, num_years, num_tries;
    int i, j, k;
    double probability;
    char repeat;

    srand(time(NULL));

    // Initialize variables
    num_aliens = 0;
    num_years = 0;
    num_tries = 0;

    // Ask user for input
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("Please enter the number of aliens you think may invade Earth: ");
    scanf("%d", &num_aliens);
    printf("Please enter the number of years you want to simulate: ");
    scanf("%d", &num_years);

    // Simulate invasion
    for (i = 0; i < num_years; i++) {
        for (j = 0; j < num_aliens; j++) {
            // Roll a virtual dice to determine if an alien invades
            if (rand() % 6 == 1) {
                printf("An alien has invaded in year %d!\n", i+1);
                num_tries++;
            }
        }
    }

    // Calculate probability
    probability = ((double) num_tries / (num_aliens * num_years)) * 100;

    // Print results
    printf("The probability of an alien invasion in %d years with %d aliens is %.2f%%\n", num_years, num_aliens, probability);

    // Ask user if they want to try again
    printf("Do you want to try again? (y/n): ");
    scanf(" %c", &repeat);

    // Repeat if desired
    if (repeat == 'y' || repeat == 'Y') {
        main();
    } else {
        return 0;
    }
}