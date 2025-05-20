//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define NAME_LENGTH 50

typedef struct {
    char workout_name[NAME_LENGTH];
    int duration; // in minutes
    int calories; // estimated calories burned
} Workout;

Workout workouts[MAX_WORKOUTS];
int workout_count = 0;

void add_workout() {
    if (workout_count >= MAX_WORKOUTS) {
        printf("Workout log is full!\n");
        return;
    }
    
    printf("Enter workout name: ");
    scanf("%s", workouts[workout_count].workout_name);
    
    printf("Enter duration (in minutes): ");
    scanf("%d", &workouts[workout_count].duration);
    
    printf("Enter calories burned: ");
    scanf("%d", &workouts[workout_count].calories);

    workout_count++;
    printf("Workout added successfully!\n");
}

void view_workouts() {
    if (workout_count == 0) {
        printf("No workouts logged yet.\n");
        return;
    }
    
    printf("\nLogged Workouts:\n");
    printf("---------------------------------------------------\n");
    printf("%-25s %-10s %-10s\n", "Workout Name", "Duration", "Calories");
    printf("---------------------------------------------------\n");
    
    for (int i = 0; i < workout_count; i++) {
        printf("%-25s %-10d %-10d\n", workouts[i].workout_name, workouts[i].duration, workouts[i].calories);
    }
    printf("---------------------------------------------------\n");
}

void view_statistics() {
    if (workout_count == 0) {
        printf("No workouts logged yet.\n");
        return;
    }
    
    int total_duration = 0;
    int total_calories = 0;
    
    for (int i = 0; i < workout_count; i++) {
        total_duration += workouts[i].duration;
        total_calories += workouts[i].calories;
    }
    
    printf("\nFitness Statistics:\n");
    printf("---------------------------------------------------\n");
    printf("Total Workouts: %d\n", workout_count);
    printf("Total Duration: %d minutes\n", total_duration);
    printf("Total Calories Burned: %d\n", total_calories);
    printf("Average Duration per Workout: %.2f minutes\n", (float)total_duration / workout_count);
    printf("Average Calories Burned per Workout: %.2f\n", (float)total_calories / workout_count);
    printf("---------------------------------------------------\n");
}

int main() {
    int choice;
    
    do {
        printf("Fitness Tracker\n");
        printf("1. Add Workout\n");
        printf("2. View Workouts\n");
        printf("3. View Statistics\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                view_workouts();
                break;
            case 3:
                view_statistics();
                break;
            case 4:
                printf("Exiting the Fitness Tracker. Stay healthy!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}