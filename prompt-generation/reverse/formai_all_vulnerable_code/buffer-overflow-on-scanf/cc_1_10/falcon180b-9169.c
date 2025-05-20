//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>

// Define the fitness tracker struct
typedef struct {
    char name[50];
    int age;
    float weight;
    int steps;
} fitness_tracker_t;

// Define the main function
int main() {
    // Initialize the fitness tracker
    fitness_tracker_t tracker = {
       .name = "John Doe",
       .age = 30,
       .weight = 80.0,
       .steps = 0
    };

    // Print the initial fitness tracker data
    printf("Initial fitness tracker data:\n");
    printf("Name: %s\n", tracker.name);
    printf("Age: %d\n", tracker.age);
    printf("Weight: %.2f\n", tracker.weight);
    printf("Steps: %d\n\n", tracker.steps);

    // Start tracking fitness data
    while (1) {
        // Print the current fitness tracker data
        printf("Current fitness tracker data:\n");
        printf("Name: %s\n", tracker.name);
        printf("Age: %d\n", tracker.age);
        printf("Weight: %.2f\n", tracker.weight);
        printf("Steps: %d\n\n", tracker.steps);

        // Get user input for steps taken
        printf("Enter the number of steps taken: ");
        scanf("%d", &tracker.steps);

        // Calculate the distance traveled based on steps taken
        float distance = tracker.steps * 0.5; // Distance in meters

        // Calculate the calories burned based on distance traveled
        float calories_burned = distance * 0.0175 * tracker.weight; // Calories burned in kcal

        // Print the distance traveled and calories burned
        printf("Distance traveled: %.2f meters\n", distance);
        printf("Calories burned: %.2f kcal\n\n", calories_burned);

        // Check if the user wants to exit the program
        char choice;
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    // Print the final fitness tracker data
    printf("Final fitness tracker data:\n");
    printf("Name: %s\n", tracker.name);
    printf("Age: %d\n", tracker.age);
    printf("Weight: %.2f\n", tracker.weight);
    printf("Steps: %d\n", tracker.steps);

    return 0;
}