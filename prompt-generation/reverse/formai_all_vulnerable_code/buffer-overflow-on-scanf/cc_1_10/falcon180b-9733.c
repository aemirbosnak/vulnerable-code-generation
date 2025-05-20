//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRIALS 1000000
#define MAX_DIMENSIONS 10

int main() {
    int num_dimensions, num_trials, num_successes;
    double **coords;
    double volume;
    int i, j;
    int success;
    double x, y, z;
    int count = 0;

    printf("Enter the number of dimensions: ");
    scanf("%d", &num_dimensions);

    printf("Enter the number of trials: ");
    scanf("%d", &num_trials);

    coords = (double **)malloc(num_dimensions * sizeof(double *));
    for (i = 0; i < num_dimensions; i++) {
        coords[i] = (double *)malloc(num_trials * sizeof(double));
        for (j = 0; j < num_trials; j++) {
            coords[i][j] = (double)rand() / RAND_MAX;
        }
    }

    volume = 1.0;
    for (i = 0; i < num_dimensions; i++) {
        volume *= 2.0;
    }

    for (i = 0; i < num_trials; i++) {
        success = 1;
        for (j = 0; j < num_dimensions; j++) {
            if (coords[j][i] < 0.5 || coords[j][i] > 1.5) {
                success = 0;
                break;
            }
        }
        if (success) {
            count++;
        }
    }

    printf("The probability of an alien invasion in %d dimensions is %.6f\n", num_dimensions, (double)count / num_trials);

    for (i = 0; i < num_dimensions; i++) {
        free(coords[i]);
    }
    free(coords);

    return 0;
}