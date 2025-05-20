//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define FILENAME "workouts.txt"

typedef struct {
    char type[20];
    float duration; // in minutes
    float distance; // in kilometers
    float calories; // calculated
} Workout;

void displayMenu() {
    printf("---- Fitness Tracker ----\n");
    printf("1. Log new workout\n");
    printf("2. View all workouts\n");
    printf("3. Exit\n");
    printf("-------------------------\n");
    printf("Select an option: ");
}

void logWorkout() {
    Workout workout;
    printf("Enter workout type (e.g., Running, Cycling): ");
    scanf("%s", workout.type);
    printf("Enter duration (in minutes): ");
    scanf("%f", &workout.duration);
    printf("Enter distance (in kilometers): ");
    scanf("%f", &workout.distance);

    // Calculate calories burned (approximation)
    workout.calories = (workout.distance * 60) * (workout.duration / 60); // simplistic formula

    // Write the workout to file
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        printf("Could not open file for writing.\n");
        return;
    }
    fprintf(file, "%s %.2f %.2f %.2f\n", workout.type, workout.duration, workout.distance, workout.calories);
    fclose(file);
    printf("Workout logged successfully!\n");
}

void viewWorkouts() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("No workouts logged yet.\n");
        return;
    }
    
    Workout workout;
    printf("---- Your Workouts ----\n");
    while (fscanf(file, "%s %f %f %f", workout.type, &workout.duration, &workout.distance, &workout.calories) != EOF) {
        printf("Type: %s, Duration: %.2f min, Distance: %.2f km, Calories: %.2f\n", 
               workout.type, workout.duration, workout.distance, workout.calories);
    }
    fclose(file);
}

int main() {
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                logWorkout();
                break;
            case 2:
                viewWorkouts();
                break;
            case 3:
                printf("Exiting... Have a great day!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}