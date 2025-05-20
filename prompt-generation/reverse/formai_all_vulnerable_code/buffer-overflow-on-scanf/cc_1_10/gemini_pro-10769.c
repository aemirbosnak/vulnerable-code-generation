//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int age;
    float height;
    float weight;
} person_t;

typedef struct {
    person_t person;
    int steps;
    int distance;
    int calories;
} fitness_tracker_t;

int main() {
    fitness_tracker_t tracker;

    // Get user input
    printf("What is your name? ");
    scanf("%s", tracker.person.name);

    printf("How old are you? ");
    scanf("%d", &tracker.person.age);

    printf("How tall are you in meters? ");
    scanf("%f", &tracker.person.height);

    printf("How much do you weigh in kilograms? ");
    scanf("%f", &tracker.person.weight);

    // Initialize fitness tracker
    tracker.steps = 0;
    tracker.distance = 0;
    tracker.calories = 0;

    // Start fitness tracker
    while (1) {
        // Display menu
        printf("Fitness Tracker Menu\n");
        printf("1. Start workout\n");
        printf("2. Stop workout\n");
        printf("3. View progress\n");
        printf("4. Quit\n");

        // Get user choice
        int choice;
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1:
                // Start workout
                printf("Starting workout...\n");
                tracker.steps = 0;
                tracker.distance = 0;
                tracker.calories = 0;
                break;
            case 2:
                // Stop workout
                printf("Stopping workout...\n");
                break;
            case 3:
                // View progress
                printf("Steps: %d\n", tracker.steps);
                printf("Distance: %d meters\n", tracker.distance);
                printf("Calories: %d\n", tracker.calories);
                break;
            case 4:
                // Quit
                printf("Quitting fitness tracker...\n");
                return 0;
            default:
                // Invalid choice
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}