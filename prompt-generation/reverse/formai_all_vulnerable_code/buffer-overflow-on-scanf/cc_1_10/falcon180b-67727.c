//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_STEPS 10000
#define MAX_DISTANCE 1000000
#define MAX_CALORIES 10000
#define MAX_TIME 86400

typedef struct {
    int steps;
    double distance;
    int calories;
    time_t start_time;
    time_t end_time;
} fitness_data;

void print_fitness_data(fitness_data data) {
    printf("Steps: %d\n", data.steps);
    printf("Distance: %.2f km\n", data.distance);
    printf("Calories burned: %d\n", data.calories);
    printf("Time taken: %ld seconds\n", difftime(data.end_time, data.start_time));
}

int main() {
    fitness_data data;
    int steps = 0;
    double distance = 0;
    int calories = 0;
    time_t start_time = time(NULL);

    while (1) {
        printf("Enter number of steps taken: ");
        scanf("%d", &steps);
        if (steps < 0 || steps > MAX_STEPS) {
            printf("Invalid input. Please enter a number between 0 and %d.\n", MAX_STEPS);
            continue;
        }
        data.steps += steps;
        distance += (double)steps / 1000;
        calories += (int)((double)steps / 100) * 100;
        if (distance > MAX_DISTANCE || calories > MAX_CALORIES || difftime(time(NULL), start_time) > MAX_TIME) {
            printf("Maximum limit reached. Exiting program...\n");
            break;
        }
    }

    data.start_time = start_time;
    data.end_time = time(NULL);

    print_fitness_data(data);

    return 0;
}