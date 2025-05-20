//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int steps;
    double distance;
} FitnessData;

void initialize_fitness_data(FitnessData* data) {
    data->steps = 0;
    data->distance = 0.0;
}

void add_step(FitnessData* data, double step_length) {
    data->steps++;
    data->distance += step_length;
}

void print_fitness_data(FitnessData* data) {
    printf("Steps: %d\n", data->steps);
    printf("Distance: %.2f km\n", data->distance / 1000.0);
}

int main() {
    FitnessData fitness_data;
    initialize_fitness_data(&fitness_data);

    bool done = false;
    while (!done) {
        int steps;
        double step_length;

        printf("Enter the number of steps taken: ");
        scanf("%d", &steps);

        printf("Enter the step length in meters: ");
        scanf("%lf", &step_length);

        add_step(&fitness_data, step_length);

        printf("Do you want to enter another step? (y/n) ");
        char choice;
        scanf(" %c", &choice);
        if (choice!= 'y') {
            done = true;
        }
    }

    print_fitness_data(&fitness_data);

    return 0;
}