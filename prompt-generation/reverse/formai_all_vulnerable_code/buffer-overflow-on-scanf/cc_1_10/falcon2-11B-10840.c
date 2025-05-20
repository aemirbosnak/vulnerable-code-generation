//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORKOUTS 100
#define MAX_EXERCISES 50

struct Workout {
    char name[50];
    int duration;
    int calories;
};

struct Exercise {
    char name[50];
    int duration;
    int calories;
};

struct FitnessTracker {
    struct Workout workouts[MAX_WORKOUTS];
    struct Exercise exercises[MAX_EXERCISES];
    int numWorkouts;
    int numExercises;
};

void addWorkout(struct FitnessTracker* tracker) {
    if (tracker->numWorkouts == MAX_WORKOUTS) {
        printf("Workout limit reached. Cannot add more workouts.\n");
        return;
    }

    printf("Enter workout name: ");
    scanf("%s", tracker->workouts[tracker->numWorkouts].name);
    printf("Enter workout duration (in minutes): ");
    scanf("%d", &tracker->workouts[tracker->numWorkouts].duration);
    printf("Enter workout calories burned: ");
    scanf("%d", &tracker->workouts[tracker->numWorkouts].calories);

    tracker->numWorkouts++;
}

void addExercise(struct FitnessTracker* tracker) {
    if (tracker->numExercises == MAX_EXERCISES) {
        printf("Exercise limit reached. Cannot add more exercises.\n");
        return;
    }

    printf("Enter exercise name: ");
    scanf("%s", tracker->exercises[tracker->numExercises].name);
    printf("Enter exercise duration (in minutes): ");
    scanf("%d", &tracker->exercises[tracker->numExercises].duration);
    printf("Enter exercise calories burned: ");
    scanf("%d", &tracker->exercises[tracker->numExercises].calories);

    tracker->numExercises++;
}

void displayWorkouts(struct FitnessTracker* tracker) {
    printf("\nWorkouts:\n");
    for (int i = 0; i < tracker->numWorkouts; i++) {
        printf("Name: %s\n", tracker->workouts[i].name);
        printf("Duration: %d minutes\n", tracker->workouts[i].duration);
        printf("Calories burned: %d\n", tracker->workouts[i].calories);
    }
}

void displayExercises(struct FitnessTracker* tracker) {
    printf("\nExercises:\n");
    for (int i = 0; i < tracker->numExercises; i++) {
        printf("Name: %s\n", tracker->exercises[i].name);
        printf("Duration: %d minutes\n", tracker->exercises[i].duration);
        printf("Calories burned: %d\n", tracker->exercises[i].calories);
    }
}

int main() {
    struct FitnessTracker tracker;
    srand(time(0));

    printf("Welcome to the Fitness Tracker!\n");

    printf("1. Add a workout\n");
    printf("2. Add an exercise\n");
    printf("3. Display workouts\n");
    printf("4. Display exercises\n");
    printf("5. Quit\n");

    while (true) {
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkout(&tracker);
                break;
            case 2:
                addExercise(&tracker);
                break;
            case 3:
                displayWorkouts(&tracker);
                break;
            case 4:
                displayExercises(&tracker);
                break;
            case 5:
                printf("Thank you for using the Fitness Tracker!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}