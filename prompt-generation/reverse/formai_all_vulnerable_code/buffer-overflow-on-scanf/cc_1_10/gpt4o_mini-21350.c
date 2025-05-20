//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int duration; // in minutes
    int calories; // calories burned
} Workout;

Workout workouts[MAX_WORKOUTS];
int workout_count = 0;

void addWorkout() {
    if (workout_count >= MAX_WORKOUTS) {
        printf("Workout limit reached! Cannot add more.\n");
        return;
    }

    Workout new_workout;

    printf("Enter workout name: ");
    scanf("%s", new_workout.name);
    printf("Enter duration (in minutes): ");
    scanf("%d", &new_workout.duration);
    printf("Enter calories burned: ");
    scanf("%d", &new_workout.calories);

    workouts[workout_count] = new_workout;
    workout_count++;

    printf("Workout added successfully!\n\n");
}

void viewWorkouts() {
    if (workout_count == 0) {
        printf("No workouts recorded yet!\n\n");
        return;
    }

    printf("Your Workouts:\n");
    for (int i = 0; i < workout_count; i++) {
        printf("%d. %s | Duration: %d mins | Calories: %d\n",
               i + 1, workouts[i].name, workouts[i].duration, workouts[i].calories);
    }
    printf("\n");
}

void saveWorkoutsToFile() {
    FILE *file = fopen("workouts.txt", "w");
    if (!file) {
        printf("Error opening file for saving workouts!\n\n");
        return;
    }

    for (int i = 0; i < workout_count; i++) {
        fprintf(file, "%s %d %d\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
    }

    fclose(file);
    printf("Workouts saved to workouts.txt!\n\n");
}

void loadWorkoutsFromFile() {
    FILE *file = fopen("workouts.txt", "r");
    if (!file) {
        printf("No previous workouts found!\n\n");
        return;
    }

    while (fscanf(file, "%s %d %d", workouts[workout_count].name,
                  &workouts[workout_count].duration,
                  &workouts[workout_count].calories) != EOF) {
        workout_count++;
    }

    fclose(file);
    printf("Workouts loaded successfully!\n\n");
}

void displayMenu() {
    printf("Welcome to the Fitness Tracker!\n");
    printf("1. Add Workout\n");
    printf("2. View Workouts\n");
    printf("3. Save Workouts\n");
    printf("4. Load Workouts\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    // Load previous workouts
    loadWorkoutsFromFile();

    while (1) {
        displayMenu();
        
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkout();
                break;
            case 2:
                viewWorkouts();
                break;
            case 3:
                saveWorkoutsToFile();
                break;
            case 4:
                loadWorkoutsFromFile();
                break;
            case 5:
                printf("Thanks for using the Fitness Tracker! Stay fit and healthy!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }

    return 0;
}