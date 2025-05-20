//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int steps;
    int distance;
    int calories;
    int heart_rate;
} fitness_data;

void print_fitness_data(fitness_data data) {
    printf("Steps: %d\n", data.steps);
    printf("Distance: %d m\n", data.distance);
    printf("Calories: %d kcal\n", data.calories);
    printf("Heart rate: %d bpm\n", data.heart_rate);
}

int main() {
    // Create a fitness tracker struct
    fitness_data data = {0, 0, 0, 0};

    // Initialize the fitness tracker
    int steps = 0;
    int distance = 0;
    int calories = 0;
    int heart_rate = 0;

    // Get the user's input
    printf("Enter the number of steps you have taken: ");
    scanf("%d", &steps);
    printf("Enter the distance you have traveled in meters: ");
    scanf("%d", &distance);
    printf("Enter the number of calories you have burned: ");
    scanf("%d", &calories);
    printf("Enter your current heart rate in bpm: ");
    scanf("%d", &heart_rate);

    // Update the fitness tracker
    data.steps = steps;
    data.distance = distance;
    data.calories = calories;
    data.heart_rate = heart_rate;

    // Print the fitness data
    print_fitness_data(data);

    return 0;
}