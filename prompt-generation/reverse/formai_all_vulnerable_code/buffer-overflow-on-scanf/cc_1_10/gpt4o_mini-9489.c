//GPT-4o-mini DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXERCISES 100

typedef struct {
    char name[30];
    int duration;  // in minutes
    int calories_burned;
} Exercise;

typedef struct {
    int steps;
    int total_calories;
    Exercise exercises[MAX_EXERCISES];
    int exercise_count;
} FitnessTracker;

void displayMenu() {
    printf("\n=================== Fitness Tracker ===================\n");
    printf("1. Add Exercise\n");
    printf("2. Log Steps\n");
    printf("3. View Summary\n");
    printf("4. Exit\n");
    printf("========================================================\n");
}

void addExercise(FitnessTracker *tracker) {
    if (tracker->exercise_count >= MAX_EXERCISES) {
        printf("Maximum number of exercises reached!\n");
        return;
    }

    Exercise new_exercise;
    printf("Enter exercise name: ");
    scanf("%s", new_exercise.name);
    printf("Enter duration (minutes): ");
    scanf("%d", &new_exercise.duration);
    printf("Enter calories burned in this exercise: ");
    scanf("%d", &new_exercise.calories_burned);

    tracker->exercises[tracker->exercise_count] = new_exercise;
    tracker->total_calories += new_exercise.calories_burned;
    tracker->exercise_count++;

    printf("Exercise '%s' added successfully!\n", new_exercise.name);
}

void logSteps(FitnessTracker *tracker) {
    int steps;
    printf("Enter number of steps: ");
    scanf("%d", &steps);
    tracker->steps += steps;
    printf("Steps logged: %d\n", steps);
}

void viewSummary(const FitnessTracker *tracker) {
    printf("\n=== Fitness Summary ===\n");
    printf("Total Steps: %d\n", tracker->steps);
    printf("Total Calories Burned: %d\n", tracker->total_calories);

    if (tracker->exercise_count > 0) {
        printf("\nExercises Completed:\n");
        for (int i = 0; i < tracker->exercise_count; i++) {
            printf("- %s: %d mins, %d calories\n",
                   tracker->exercises[i].name,
                   tracker->exercises[i].duration,
                   tracker->exercises[i].calories_burned);
        }
    } else {
        printf("No exercises logged yet!\n");
    }
}

int main() {
    FitnessTracker tracker;
    tracker.steps = 0;
    tracker.total_calories = 0;
    tracker.exercise_count = 0;

    int choice;
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExercise(&tracker);
                break;
            case 2:
                logSteps(&tracker);
                break;
            case 3:
                viewSummary(&tracker);
                break;
            case 4:
                printf("Thank you for using the Fitness Tracker! Keep pushing your limits!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}