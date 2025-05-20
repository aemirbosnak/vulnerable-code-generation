//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXERCISES 50
#define MAX_NAME_LENGTH 20

typedef struct Exercise {
    char name[MAX_NAME_LENGTH];
    int reps;
    float weight;
} Exercise;

typedef struct Workout {
    char date[11];
    Exercise exercises[MAX_EXERCISES];
    int numExercises;
    float totalWeight;
    float averageWeight;
} Workout;

int main() {
    Workout workouts[MAX_EXERCISES];
    int numWorkouts = 0;

    while (1) {
        char input[20];
        printf("\nAdd workout (a)  View workouts (v)  Exit (x)\n");
        scanf("%s", input);
        if (strcmp(input, "a") == 0) { // Add workout
            Workout workout;
            printf("\nEnter date (mm/dd/yyyy): ");
            scanf("%s", workout.date);
            workout.numExercises = 0;
            workout.totalWeight = 0;

            while (1) {
                if (workout.numExercises == MAX_EXERCISES) {
                    printf("\nMax number of exercises reached!");
                    break;
                }
                Exercise exercise;
                printf("\nEnter exercise name: ");
                scanf("%s", exercise.name);
                printf("Enter number of reps: ");
                scanf("%d", &exercise.reps);
                printf("Enter weight: ");
                scanf("%f", &exercise.weight);

                workout.exercises[workout.numExercises] = exercise;
                workout.numExercises++;
                workout.totalWeight += exercise.weight;

                char addMore[10];
                printf("Add another exercise? (y/n): ");
                scanf("%s", addMore);
                if (strcmp(addMore, "n") == 0) {
                    break;
                }
            }

            workout.averageWeight = workout.totalWeight / workout.numExercises;

            workouts[numWorkouts] = workout;
            numWorkouts++;

        } else if (strcmp(input, "v") == 0) { // View workouts
            if (numWorkouts == 0) {
                printf("\nNo workouts logged!");
            } else {
                printf("\nWorkout history:\n");
                for (int i = 0; i < numWorkouts; i++) {
                    printf("\nWorkout %d\n", i+1);
                    printf("Date: %s\n", workouts[i].date);
                    printf("Exercises:\n");
                    for (int j = 0; j < workouts[i].numExercises; j++) {
                        printf("%s: %d reps, %.2f lbs\n", workouts[i].exercises[j].name,
                                                               workouts[i].exercises[j].reps, 
                                                               workouts[i].exercises[j].weight);
                    }
                    printf("Total weight lifted: %.2f lbs\n", workouts[i].totalWeight);
                    printf("Average weight lifted: %.2f lbs\n", workouts[i].averageWeight);
                }
            }
        } else if (strcmp(input, "x") == 0) { //Exit
            printf("\nGoodbye!");
            break;
        } else { 
            printf("\nInvalid input. Try again!");
        }
    }

    return 0;
}