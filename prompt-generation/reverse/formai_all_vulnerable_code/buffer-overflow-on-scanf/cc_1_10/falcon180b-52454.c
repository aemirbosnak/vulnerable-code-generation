//Falcon-180B DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0
#define MAX_TRIALS 1000000

// Function prototypes
double calculate_pi(int num_trials);
int is_circle(double x, double y);

int main() {
    int num_trials;
    double pi;
    int i;

    printf("Enter the number of trials: ");
    scanf("%d", &num_trials);

    pi = calculate_pi(num_trials);

    printf("The value of pi after %d trials is: %lf\n", num_trials, pi);

    return 0;
}

double calculate_pi(int num_trials) {
    int i;
    double x, y;
    int num_inside_circle = 0;

    srand(time(0));

    for (i = 0; i < num_trials; i++) {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        if (is_circle(x, y)) {
            num_inside_circle++;
        }
    }

    return (4.0 * num_inside_circle) / num_trials;
}

int is_circle(double x, double y) {
    double distance;

    distance = sqrt(x * x + y * y);

    if (distance <= 1.0) {
        return TRUE;
    } else {
        return FALSE;
    }
}