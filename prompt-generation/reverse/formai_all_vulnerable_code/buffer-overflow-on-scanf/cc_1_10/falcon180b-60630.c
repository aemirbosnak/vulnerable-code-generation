//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORKOUTS 10
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_WORKOUT_DURATION 1000 // 1000 seconds = 16 minutes 40 seconds

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration; // in seconds
} Workout;

Workout workouts[MAX_WORKOUTS];
int numWorkouts = 0;

void addWorkout() {
    printf("Enter a name for your workout: ");
    scanf("%s", workouts[numWorkouts].name);

    printf("Enter the duration of your workout (in seconds): ");
    scanf("%d", &workouts[numWorkouts].duration);

    numWorkouts++;
}

void displayWorkouts() {
    printf("Your workouts:\n");
    for (int i = 0; i < numWorkouts; i++) {
        printf("%s - %d seconds\n", workouts[i].name, workouts[i].duration);
    }
}

void startWorkout(Workout workout) {
    time_t startTime = time(NULL);
    while (difftime(time(NULL), startTime) < workout.duration) {
        printf("Keep going! You've got %d seconds left.\n", workout.duration - difftime(time(NULL), startTime));
        fflush(stdout); // make sure the message is printed immediately
    }
    printf("Workout complete!\n");
}

int main() {
    srand(time(NULL)); // seed the random number generator with the current time

    int choice;
    do {
        printf("Welcome to the Fitness Tracker!\n\n");
        printf("1. Add a workout\n");
        printf("2. Display workouts\n");
        printf("3. Start a workout\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addWorkout();
                break;
            case 2:
                displayWorkouts();
                break;
            case 3:
                if (numWorkouts == 0) {
                    printf("You don't have any workouts yet.\n");
                } else {
                    int workoutIndex;
                    printf("Enter the index of the workout you want to start (0-%d): ", numWorkouts - 1);
                    scanf("%d", &workoutIndex);
                    startWorkout(workouts[workoutIndex]);
                }
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}