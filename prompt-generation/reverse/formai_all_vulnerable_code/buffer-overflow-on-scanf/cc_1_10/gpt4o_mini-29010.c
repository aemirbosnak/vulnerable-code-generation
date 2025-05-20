//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold fitness activity details
typedef struct {
    char name[50];
    int duration; // in minutes
    int caloriesBurned; 
} Activity;

// Function to display the main menu
void displayMenu() {
    printf("\nFitness Tracker Menu:\n");
    printf("1. Add Activity\n");
    printf("2. View Activities\n");
    printf("3. Calculate Total Calories Burned\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

// Function to add activity
Activity addActivity() {
    Activity activity;
    printf("\nEnter Activity Name: ");
    scanf("%s", activity.name);
    printf("Enter Duration (in minutes): ");
    scanf("%d", &activity.duration);
    printf("Enter Calories Burned: ");
    scanf("%d", &activity.caloriesBurned);
    return activity;
}

// Function to display activities
void viewActivities(Activity activities[], int count) {
    printf("\nActivity List:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - %d minutes, %d Calories\n", 
                i + 1, activities[i].name, activities[i].duration, activities[i].caloriesBurned);
    }
}

// Function to calculate total calories burned
int calculateTotalCalories(Activity activities[], int count) {
    int totalCalories = 0;
    for (int i = 0; i < count; i++) {
        totalCalories += activities[i].caloriesBurned;
    }
    return totalCalories;
}

int main() {
    int choice;
    int count = 0;
    int capacity = 10;
    Activity *activities = malloc(capacity * sizeof(Activity));

    // Check if memory allocation was successful
    if (activities == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Add Activity
                if (count >= capacity) {
                    capacity *= 2;
                    activities = realloc(activities, capacity * sizeof(Activity));
                    if (activities == NULL) {
                        fprintf(stderr, "Memory reallocation failed\n");
                        return 1;
                    }
                }
                activities[count++] = addActivity();
                break;
            case 2:
                // View Activities
                if (count == 0) {
                    printf("No activities to display.\n");
                } else {
                    viewActivities(activities, count);
                }
                break;
            case 3:
                // Calculate Total Calories Burned
                if (count == 0) {
                    printf("No activities recorded yet.\n");
                } else {
                    int totalCalories = calculateTotalCalories(activities, count);
                    printf("Total Calories Burned: %d\n", totalCalories);
                }
                break;
            case 4:
                // Exit
                printf("Exiting the Fitness Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 4);

    // Free allocated memory before exiting
    free(activities);
    return 0;
}