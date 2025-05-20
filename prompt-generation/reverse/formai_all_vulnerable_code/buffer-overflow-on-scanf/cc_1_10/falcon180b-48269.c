//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_WORKOUTS 50
#define MAX_STEPS 10000
#define MAX_CALORIES 1000

typedef struct {
    int steps;
    int caloriesBurned;
} Workout;

void addWorkout(Workout *workoutArray, int index, int steps, int caloriesBurned) {
    if (index >= 0 && index < MAX_WORKOUTS) {
        workoutArray[index].steps += steps;
        workoutArray[index].caloriesBurned += caloriesBurned;
    }
}

int main(void) {
    int numWorkouts = 0;
    Workout workoutArray[MAX_WORKOUTS];
    int choice;
    int steps = 0;
    int caloriesBurned = 0;
    time_t startTime, endTime;
    double duration;

    srand(time(NULL));
    printf("Welcome to the Fitness Tracker!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Start a workout\n");
        printf("2. View workout history\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of steps for this workout: ");
                scanf("%d", &steps);
                printf("Enter the number of calories burned for this workout: ");
                scanf("%d", &caloriesBurned);

                // Check if there is space for a new workout
                if (numWorkouts >= MAX_WORKOUTS) {
                    printf("Error: Workout history is full.\n");
                } else {
                    addWorkout(workoutArray, numWorkouts, steps, caloriesBurned);
                    numWorkouts++;
                    printf("Workout started.\n");
                }

                break;
            case 2:
                if (numWorkouts == 0) {
                    printf("No workouts yet.\n");
                } else {
                    printf("Workout History:\n");
                    for (int i = 0; i < numWorkouts; i++) {
                        printf("Workout %d: %d steps, %d calories burned\n", i + 1, workoutArray[i].steps, workoutArray[i].caloriesBurned);
                    }
                }
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}