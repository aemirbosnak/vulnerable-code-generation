//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIALS 1000
#define MAX_EXTRA_TERRESTRIALS 1000
#define PROBABILITY_THRESHOLD 0.5

void initialize_extra_terrestrials(int num_extra_terrestrials, int *extra_terrestrial_population) {
    int i;
    for (i = 0; i < num_extra_terrestrials; i++) {
        extra_terrestrial_population[i] = rand() % 2;
    }
}

int count_extra_terrestrials(int num_extra_terrestrials, int *extra_terrestrial_population) {
    int count = 0;
    int i;
    for (i = 0; i < num_extra_terrestrials; i++) {
        if (extra_terrestrial_population[i] == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int num_extra_terrestrials, num_trials, num_invasions;
    int extra_terrestrial_population[MAX_EXTRA_TERRESTRIALS];
    double probability_of_invasion;
    double invasion_probability_sum = 0.0;
    int i;

    printf("Alien Invasion Probability Calculator\n");
    printf("===================================\n");

    srand(time(NULL));

    printf("Enter the number of extra terrestrials: ");
    scanf("%d", &num_extra_terrestrials);

    printf("Enter the number of trials: ");
    scanf("%d", &num_trials);

    initialize_extra_terrestrials(num_extra_terrestrials, extra_terrestrial_population);

    for (i = 0; i < num_trials; i++) {
        num_invasions = 0;
        invasion_probability_sum = 0.0;

        printf("\nTrial %d:\n", i + 1);
        printf("Number of extra terrestrials: %d\n", num_extra_terrestrials);

        while (num_invasions < num_extra_terrestrials && invasion_probability_sum < PROBABILITY_THRESHOLD) {
            invasion_probability_sum += rand() % 101;
            num_invasions = count_extra_terrestrials(num_extra_terrestrials, extra_terrestrial_population);
        }

        if (num_invasions >= num_extra_terrestrials) {
            printf("Invasion probability: %.2f%%\n", invasion_probability_sum * 100.0);
        } else {
            printf("No invasion.\n");
        }
    }

    return 0;
}