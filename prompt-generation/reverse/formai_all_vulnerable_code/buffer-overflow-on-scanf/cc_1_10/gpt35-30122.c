//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_WORKOUTS 5

struct Workout {
    char name[20];
    int length_minutes;
    int calories_burned;
};

struct FitnessTracker {
    struct Workout workouts[MAX_WORKOUTS];
    int total_calories_burned;
    int num_workouts;
};

void printMainMenu() {
    printf("\n1. Add Workout\n");
    printf("2. View Workouts\n");
    printf("3. View Total Calories Burned\n");
    printf("4. Exit\n");
}

void addWorkout(struct FitnessTracker* tracker) {
    if (tracker->num_workouts == MAX_WORKOUTS) {
        printf("\nCannot add more workouts\n");
        return;
    }

    struct Workout workout;
    printf("\nEnter workout name: ");
    scanf("%s", workout.name);

    printf("Enter workout length (in minutes): ");
    scanf("%d", &workout.length_minutes);

    printf("Enter calories burned: ");
    scanf("%d", &workout.calories_burned);

    tracker->workouts[tracker->num_workouts++] = workout;
    tracker->total_calories_burned += workout.calories_burned;

    printf("\nWorkout added successfully!\n");
}

void printWorkouts(struct FitnessTracker tracker) {
    printf("\nWorkouts:\n");

    for (int i = 0; i < tracker.num_workouts; i++) {
        printf("%d. Name: %s, Length: %d minutes, Calories Burned: %d\n",
               i+1, tracker.workouts[i].name, tracker.workouts[i].length_minutes, tracker.workouts[i].calories_burned);
    }
}

void printTotalCaloriesBurned(struct FitnessTracker tracker) {
    printf("\nTotal Calories Burned: %d\n", tracker.total_calories_burned);
}

int main() {
    struct FitnessTracker tracker = {0};
    int choice;

    printf("Welcome to the Fitness Tracker!\n");

    while (true) {
        printMainMenu();

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkout(&tracker);
                break;
            case 2:
                printWorkouts(tracker);
                break;
            case 3:
                printTotalCaloriesBurned(tracker);
                break;
            case 4:
                printf("\nExiting...\n");
                return 0;
            default:
                printf("\nInvalid choice\n");
        }
    }
}