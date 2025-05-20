//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define MAX_STEPS 100000
#define MAX_DISTANCE 100000
#define MAX_CALORIES 100000

// Define struct for fitness data
typedef struct {
    int steps;
    double distance;
    int calories;
} fitness_data;

// Function to initialize fitness data
void init_fitness_data(fitness_data* data) {
    data->steps = 0;
    data->distance = 0;
    data->calories = 0;
}

// Function to calculate distance based on steps
double calculate_distance(int steps) {
    return steps * 0.762;
}

// Function to calculate calories burned based on steps
int calculate_calories(int steps) {
    return steps * 5;
}

// Function to update fitness data
void update_fitness_data(fitness_data* data, int steps) {
    data->steps += steps;
    data->distance += calculate_distance(steps);
    data->calories += calculate_calories(steps);
}

// Function to print fitness data
void print_fitness_data(fitness_data* data) {
    printf("Steps: %d\n", data->steps);
    printf("Distance: %.2lf km\n", data->distance);
    printf("Calories burned: %d\n", data->calories);
}

int main() {
    // Initialize fitness data
    fitness_data fitness_data;
    init_fitness_data(&fitness_data);

    // Get starting time
    struct timespec start_time;
    clock_gettime(CLOCK_REALTIME, &start_time);

    // Main loop
    while(1) {
        // Get current time
        struct timespec current_time;
        clock_gettime(CLOCK_REALTIME, &current_time);

        // Calculate elapsed time
        double elapsed_time = (current_time.tv_sec - start_time.tv_sec) + (current_time.tv_nsec - start_time.tv_nsec) / 1000000000.0;

        // Check if maximum steps, distance, or calories have been reached
        if(fitness_data.steps >= MAX_STEPS || fitness_data.distance >= MAX_DISTANCE || fitness_data.calories >= MAX_CALORIES) {
            printf("Maximum reached!\n");
            break;
        }

        // Get user input for steps
        int steps;
        printf("Enter number of steps: ");
        scanf("%d", &steps);

        // Update fitness data
        update_fitness_data(&fitness_data, steps);

        // Print current fitness data
        printf("Current data:\n");
        print_fitness_data(&fitness_data);

        // Wait for 1 second
        sleep(1);
    }

    return 0;
}