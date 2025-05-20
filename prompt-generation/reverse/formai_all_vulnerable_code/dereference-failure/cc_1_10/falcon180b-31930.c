//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIALS 1000000
#define MAX_DIMENSIONS 10

int main() {
    srand(time(NULL));

    int num_trials = 0;
    int num_successes = 0;
    int num_dimensions = 0;
    double *invasion_probability = NULL;

    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    printf("This program will calculate the probability of an alien invasion based on various factors.\n");
    printf("Please answer the following questions:\n\n");

    // Get number of trials
    printf("How many trials do you want to run? ");
    scanf("%d", &num_trials);

    // Get number of dimensions
    printf("How many dimensions do you want to consider? ");
    scanf("%d", &num_dimensions);

    // Allocate memory for invasion probability array
    invasion_probability = (double *) malloc(num_trials * sizeof(double));

    // Run trials and calculate invasion probability
    for (int i = 0; i < num_trials; i++) {
        double probability = 1.0;

        for (int j = 0; j < num_dimensions; j++) {
            printf("Question %d: ", j + 1);
            scanf("%d", &probability);
            probability *= (double) probability / 100.0;
        }

        invasion_probability[i] = probability;
        num_successes += probability >= 0.5? 1 : 0;
    }

    // Print results
    double success_rate = (double) num_successes / num_trials;
    printf("\nOut of %d trials, there was a %.2f%% chance of an alien invasion.\n", num_trials, success_rate * 100.0);

    free(invasion_probability);

    return 0;
}