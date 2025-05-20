//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ATTEMPTS 100
#define MAX_INVADERS 1000
#define MIN_INVADERS 1
#define INVASION_THRESHOLD 0.5

int main() {
    srand(time(NULL));
    int num_attempts = 0;
    int num_invaders = 0;
    double invasion_probability = 0.0;
    double invasion_threshold = INVASION_THRESHOLD;
    char choice;

    do {
        num_attempts++;
        printf("Attempt %d:\n", num_attempts);
        printf("How many potential invaders are there? (Between %d and %d): ", MIN_INVADERS, MAX_INVADERS);
        scanf("%d", &num_invaders);

        if (num_invaders < MIN_INVADERS || num_invaders > MAX_INVADERS) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        int num_successful_invaders = 0;
        for (int i = 0; i < num_invaders; i++) {
            if (rand() % 2 == 0) {
                num_successful_invaders++;
            }
        }

        invasion_probability = (double)num_successful_invaders / num_invaders;

        printf("Out of %d potential invaders, %d were able to invade.\n", num_invaders, num_successful_invaders);
        printf("Invasion probability: %.2f%%\n", 100.0 * invasion_probability);

        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' && num_attempts < MAX_ATTEMPTS);

    if (num_attempts == MAX_ATTEMPTS) {
        printf("Exiting due to maximum number of attempts reached.\n");
    } else {
        printf("Exiting due to user choice.\n");
    }

    return 0;
}