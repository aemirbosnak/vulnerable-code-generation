//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_STEPS 10000

struct step {
    double x;
    double y;
    double z;
};

void step_count(struct step *steps, int num_steps) {
    int i;
    for (i = 0; i < num_steps; i++) {
        printf("Step %d: %.2f steps\n", i + 1, steps[i].x);
    }
}

int main() {
    int num_steps;
    double distance = 0.0;
    double steps = 0.0;
    double speed = 0.0;
    double calories = 0.0;
    double heart_rate = 0.0;
    struct step steps_array[MAX_STEPS];
    time_t start_time, end_time;
    double duration;

    printf("Welcome to the Mind-Bending Fitness Tracker!\n");

    printf("Enter the number of steps you took: ");
    scanf("%d", &num_steps);

    printf("Enter the distance in kilometers: ");
    scanf("%lf", &distance);

    printf("Enter the number of steps per minute: ");
    scanf("%lf", &steps);

    printf("Enter your speed in kilometers per hour: ");
    scanf("%lf", &speed);

    printf("Enter the number of calories burned: ");
    scanf("%lf", &calories);

    printf("Enter your heart rate in beats per minute: ");
    scanf("%lf", &heart_rate);

    time(&start_time);
    srand(start_time);

    int i;
    for (i = 0; i < num_steps; i++) {
        steps_array[i].x = rand() % 101;
        steps_array[i].y = rand() % 101;
        steps_array[i].z = rand() % 101;
    }

    time(&end_time);
    duration = difftime(end_time, start_time);

    printf("Your workout lasted for %.2f seconds.\n", duration);

    step_count(steps_array, num_steps);

    return 0;
}