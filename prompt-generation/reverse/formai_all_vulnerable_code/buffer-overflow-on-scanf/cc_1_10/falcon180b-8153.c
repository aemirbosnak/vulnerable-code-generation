//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIALS 10000
#define TRIAL_SUCCESS 1
#define TRIAL_FAILURE 0

int main() {
    int num_successes = 0;
    int num_trials = 0;
    int i;
    int choice;
    double probability = 0.0;

    srand(time(NULL));

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("We will run %d trials to determine the probability of an alien invasion.\n", MAX_TRIALS);

    do {
        printf("Please choose a number between 1 and 6:\n");
        printf("1. Aliens have landed and are friendly.\n");
        printf("2. Aliens have landed and are hostile.\n");
        printf("3. Aliens have not landed.\n");
        printf("4. Time travelers from the future have arrived.\n");
        printf("5. Zombies have taken over.\n");
        printf("6. Nothing out of the ordinary has happened.\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
            case 2:
                num_successes++;
                break;
            case 3:
            case 4:
            case 5:
            case 6:
                num_trials++;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        num_trials++;
    } while(num_trials < MAX_TRIALS);

    probability = (double)num_successes / num_trials;

    printf("Out of %d trials, an alien invasion occurred %d times.\n", num_trials, num_successes);
    printf("The probability of an alien invasion is %.2f%%\n", probability * 100.0);

    return 0;
}