//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STEPS_PER_MILE 2000

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Create an array to store the user's steps
    int steps[30];

    // Initialize the array to zero
    for (int i = 0; i < 30; i++) {
        steps[i] = 0;
    }

    // Get the user's weight in pounds
    float weight;
    printf("Enter your weight in pounds: ");
    scanf("%f", &weight);

    // Generate random steps for each day
    for (int i = 0; i < 30; i++) {
        steps[i] = rand() % 10000;
    }

    // Calculate the total number of steps taken
    int total_steps = 0;
    for (int i = 0; i < 30; i++) {
        total_steps += steps[i];
    }

    // Calculate the total distance walked
    float total_distance = total_steps / STEPS_PER_MILE;

    // Calculate the calories burned
    float calories_burned = total_distance * weight * 0.57;

    // Print the results
    printf("Total steps: %d\n", total_steps);
    printf("Total distance: %.2f miles\n", total_distance);
    printf("Calories burned: %.2f\n", calories_burned);

    // Congratulate the user for their hard work!
    printf("Congratulations on your progress! Keep up the great work!\n");

    return 0;
}