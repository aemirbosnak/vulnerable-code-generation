//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char *name;
    int steps;
    int calories;
} activity_t;

int main() {
    // Initialize variables
    int num_activities = 0;
    activity_t *activities = NULL;

    // Get user input
    printf("How many activities did you do today? ");
    scanf("%d", &num_activities);

    // Allocate memory for activities
    activities = malloc(sizeof(activity_t) * num_activities);

    // Get activity information
    for (int i = 0; i < num_activities; i++) {
        // Get activity name
        char name[50];
        printf("Enter the name of activity %d: ", i + 1);
        scanf("%s", name);

        // Allocate memory for activity name
        activities[i].name = malloc(strlen(name) + 1);
        strcpy(activities[i].name, name);

        // Get activity steps
        printf("Enter the number of steps taken during activity %d: ", i + 1);
        scanf("%d", &activities[i].steps);

        // Get activity calories
        printf("Enter the number of calories burned during activity %d: ", i + 1);
        scanf("%d", &activities[i].calories);
    }

    // Calculate total steps and calories
    int total_steps = 0;
    int total_calories = 0;
    for (int i = 0; i < num_activities; i++) {
        total_steps += activities[i].steps;
        total_calories += activities[i].calories;
    }

    // Print fitness tracker report
    printf("\nFitness Tracker Report\n");
    printf("---------------------\n");
    printf("Total Steps: %d\n", total_steps);
    printf("Total Calories Burned: %d\n", total_calories);

    // Free memory
    for (int i = 0; i < num_activities; i++) {
        free(activities[i].name);
    }
    free(activities);

    return 0;
}