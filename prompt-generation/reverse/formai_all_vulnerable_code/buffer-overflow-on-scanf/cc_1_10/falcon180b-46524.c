//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_STEPS 10000
#define MAX_DISTANCE 100000
#define MAX_CALORIES 100000

struct {
    int steps;
    double distance;
    double calories;
} fitness_data;

void init_fitness_data() {
    fitness_data.steps = 0;
    fitness_data.distance = 0;
    fitness_data.calories = 0;
}

void update_fitness_data(int steps) {
    fitness_data.steps += steps;
    fitness_data.distance += steps * 0.65;
    fitness_data.calories += steps * 0.1;
}

void print_fitness_data() {
    printf("Steps: %d\n", fitness_data.steps);
    printf("Distance: %.2f km\n", fitness_data.distance);
    printf("Calories: %.2f kcal\n", fitness_data.calories);
}

int main() {
    init_fitness_data();
    int steps;

    while (1) {
        printf("Enter the number of steps taken: ");
        scanf("%d", &steps);
        if (steps > MAX_STEPS) {
            printf("Invalid input. Maximum steps allowed is %d.\n", MAX_STEPS);
        } else {
            update_fitness_data(steps);
            print_fitness_data();
        }
    }

    return 0;
}