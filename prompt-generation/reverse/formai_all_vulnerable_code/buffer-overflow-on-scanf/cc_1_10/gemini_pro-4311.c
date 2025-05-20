//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Constants
#define NUM_STEPS_GOAL 10000
#define NUM_CALORIES_GOAL 2000
#define NUM_MINUTES_GOAL 30

// Data Structures
typedef struct {
    int steps;
    int calories;
    int minutes;
} FitnessData;

// Function Declarations
void print_fitness_data(FitnessData data);
void check_fitness_goal(FitnessData data);
void update_fitness_data(FitnessData *data, int steps, int calories, int minutes);

// Main Function
int main() {
    // Initialize fitness data
    FitnessData data = {0, 0, 0};

    // Main loop
    while (true) {
        // Get user input
        printf("Enter steps taken: ");
        int steps;
        scanf("%d", &steps);

        printf("Enter calories burned: ");
        int calories;
        scanf("%d", &calories);

        printf("Enter minutes exercised: ");
        int minutes;
        scanf("%d", &minutes);

        // Update fitness data
        update_fitness_data(&data, steps, calories, minutes);

        // Print fitness data
        print_fitness_data(data);

        // Check fitness goal
        check_fitness_goal(data);

        // Exit loop if fitness goal is met
        if (data.steps >= NUM_STEPS_GOAL && data.calories >= NUM_CALORIES_GOAL && data.minutes >= NUM_MINUTES_GOAL) {
            break;
        }
    }

    // Print success message
    printf("Congratulations! You have met your fitness goal.\n");

    return 0;
}

// Function Definitions
void print_fitness_data(FitnessData data) {
    printf("Steps: %d\n", data.steps);
    printf("Calories: %d\n", data.calories);
    printf("Minutes: %d\n", data.minutes);
}

void check_fitness_goal(FitnessData data) {
    if (data.steps >= NUM_STEPS_GOAL) {
        printf("You have met your steps goal!\n");
    }

    if (data.calories >= NUM_CALORIES_GOAL) {
        printf("You have met your calories goal!\n");
    }

    if (data.minutes >= NUM_MINUTES_GOAL) {
        printf("You have met your minutes goal!\n");
    }
}

void update_fitness_data(FitnessData *data, int steps, int calories, int minutes) {
    data->steps += steps;
    data->calories += calories;
    data->minutes += minutes;
}