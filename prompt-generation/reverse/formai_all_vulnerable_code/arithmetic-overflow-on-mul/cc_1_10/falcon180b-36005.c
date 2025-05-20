//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_TRIALS 1000000
#define MAX_DIMENSIONS 10
#define PI 3.14159265358979323846

int main() {
    int num_trials, num_dimensions, num_hits;
    double *lower_bounds, *upper_bounds, *trial_points, *hit_points;
    double volume, total_volume;
    int i, j, k;
    srand(time(NULL));
    printf("Enter number of trials: ");
    scanf("%d", &num_trials);
    printf("Enter number of dimensions: ");
    scanf("%d", &num_dimensions);
    lower_bounds = (double*) malloc(num_dimensions * sizeof(double));
    upper_bounds = (double*) malloc(num_dimensions * sizeof(double));
    trial_points = (double*) malloc(num_trials * num_dimensions * sizeof(double));
    hit_points = (double*) malloc(num_trials * num_dimensions * sizeof(double));
    for (i = 0; i < num_dimensions; i++) {
        printf("Enter lower bound for dimension %d: ", i + 1);
        scanf("%lf", &lower_bounds[i]);
        printf("Enter upper bound for dimension %d: ", i + 1);
        scanf("%lf", &upper_bounds[i]);
    }
    for (i = 0; i < num_trials; i++) {
        for (j = 0; j < num_dimensions; j++) {
            trial_points[i * num_dimensions + j] = (double) rand() / RAND_MAX;
        }
    }
    num_hits = 0;
    for (i = 0; i < num_trials; i++) {
        for (j = 0; j < num_dimensions; j++) {
            if (trial_points[i * num_dimensions + j] >= lower_bounds[j] && trial_points[i * num_dimensions + j] <= upper_bounds[j]) {
                num_hits++;
                hit_points[i * num_dimensions + j] = trial_points[i * num_dimensions + j];
            }
        }
    }
    volume = 1.0;
    for (i = 0; i < num_dimensions; i++) {
        volume *= upper_bounds[i] - lower_bounds[i];
    }
    total_volume = pow(volume, num_trials);
    printf("Number of hits: %d\n", num_hits);
    printf("Probability of alien invasion: %.6lf\n", (double) num_hits / total_volume);
    free(lower_bounds);
    free(upper_bounds);
    free(trial_points);
    free(hit_points);
    return 0;
}