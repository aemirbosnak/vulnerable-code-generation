//FormAI DATASET v1.0 Category: Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the probability of a roll based on the number of sides on the dice
double calc_probability(int num_sides, int roll) {
    double prob = 1.0 / num_sides;
    if (roll < 1 || roll > num_sides) return 0.0;
    return prob;
}

int main() {
    int num_sides, num_rolls, i, j;
    double *prob_table;

    printf("Enter the number of sides on the dice: ");
    scanf("%d", &num_sides);

    // Allocate memory for probability table
    prob_table = (double *) malloc ((num_sides + 1) * sizeof(double));
    if (prob_table == NULL) {
        printf("Error: Unable to allocate memory for probability table.\n");
        return -1;
    }

    // Initialize probability table
    for (i = 0; i <= num_sides; i++) {
        prob_table[i] = 0.0;
    }

    printf("Enter the number of rolls: ");
    scanf("%d", &num_rolls);

    // Calculate probability table
    for (i = 1; i <= num_sides; i++) {
        for (j = 1; j <= num_rolls; j++) {
            prob_table[i] += calc_probability(num_sides, i);
        }
    }

    // Print probability table
    printf("\nRoll\tProbability\n");
    for (i = 1; i <= num_sides; i++) {
        printf("%d\t%lf\n", i, prob_table[i]);
    }

    // Calculate average and standard deviation
    double avg = 0.0, std_dev = 0.0;
    for (i = 1; i <= num_sides; i++) {
        avg += i * prob_table[i];
    }
    for (i = 1; i <= num_sides; i++) {
        std_dev += (i - avg) * (i - avg) * prob_table[i];
    }
    std_dev = sqrt(std_dev);

    printf("\nAverage: %lf\n", avg);
    printf("Standard deviation: %lf\n", std_dev);

    // Free memory
    free(prob_table);

    return 0;
}