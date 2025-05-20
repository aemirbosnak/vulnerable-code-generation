//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIALS 10000
#define MAX_ALIENS 100

int main() {
    int i, j, k, num_aliens, num_trials, num_invasions;
    double prob;
    char choice;

    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("This program will help you determine the probability of an alien invasion.\n");
    printf("Please enter the number of trials you wish to run (between 1 and %d): ", MAX_TRIALS);
    scanf("%d", &num_trials);

    num_aliens = 0;
    for (i = 0; i < num_trials; i++) {
        num_aliens += rand() % MAX_ALIENS;
    }

    prob = (double)num_aliens / num_trials;

    printf("\nResults:\n");
    printf("Number of trials: %d\n", num_trials);
    printf("Number of aliens detected: %d\n", num_aliens);
    printf("Probability of alien invasion: %.2f%%\n", prob * 100);

    printf("\nWould you like to run another simulation? (y/n): ");
    scanf(" %c", &choice);

    while (choice == 'y' || choice == 'Y') {
        num_aliens = 0;
        for (i = 0; i < num_trials; i++) {
            num_aliens += rand() % MAX_ALIENS;
        }
        prob = (double)num_aliens / num_trials;

        printf("\nResults:\n");
        printf("Number of trials: %d\n", num_trials);
        printf("Number of aliens detected: %d\n", num_aliens);
        printf("Probability of alien invasion: %.2f%%\n", prob * 100);

        printf("\nWould you like to run another simulation? (y/n): ");
        scanf(" %c", &choice);
    }

    return 0;
}