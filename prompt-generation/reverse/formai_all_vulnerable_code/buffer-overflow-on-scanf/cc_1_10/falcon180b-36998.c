//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10
#define MAX_EXERCISES 50

typedef struct {
    char name[50];
    int duration;
    int caloriesBurned;
} Workout;

typedef struct {
    char name[50];
    int duration;
    int caloriesBurned;
} Exercise;

void addWorkout(Workout workouts[], int numWorkouts) {
    printf("Enter workout name: ");
    scanf("%s", workouts[numWorkouts].name);
    printf("Enter workout duration (in minutes): ");
    scanf("%d", &workouts[numWorkouts].duration);
    workouts[numWorkouts].caloriesBurned = (int) ((double) workouts[numWorkouts].duration * 100);
    numWorkouts++;
}

void addExercise(Exercise exercises[], int numExercises) {
    printf("Enter exercise name: ");
    scanf("%s", exercises[numExercises].name);
    printf("Enter exercise duration (in minutes): ");
    scanf("%d", &exercises[numExercises].duration);
    exercises[numExercises].caloriesBurned = (int) ((double) exercises[numExercises].duration * 100);
    numExercises++;
}

void displayWorkouts(Workout workouts[], int numWorkouts) {
    printf("\nWorkouts:\n");
    for (int i = 0; i < numWorkouts; i++) {
        printf("%s - %d minutes - %d calories burned\n", workouts[i].name, workouts[i].duration, workouts[i].caloriesBurned);
    }
}

void displayExercises(Exercise exercises[], int numExercises) {
    printf("\nExercises:\n");
    for (int i = 0; i < numExercises; i++) {
        printf("%s - %d minutes - %d calories burned\n", exercises[i].name, exercises[i].duration, exercises[i].caloriesBurned);
    }
}

int main() {
    srand(time(NULL));

    Workout workouts[MAX_WORKOUTS];
    int numWorkouts = 0;

    Exercise exercises[MAX_EXERCISES];
    int numExercises = 0;

    int choice;
    do {
        printf("\nFitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. Add exercise\n");
        printf("3. Display workouts\n");
        printf("4. Display exercises\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (numWorkouts >= MAX_WORKOUTS) {
                printf("Maximum number of workouts reached!\n");
            } else {
                addWorkout(workouts, numWorkouts);
                numWorkouts++;
            }
            break;

        case 2:
            if (numExercises >= MAX_EXERCISES) {
                printf("Maximum number of exercises reached!\n");
            } else {
                addExercise(exercises, numExercises);
                numExercises++;
            }
            break;

        case 3:
            displayWorkouts(workouts, numWorkouts);
            break;

        case 4:
            displayExercises(exercises, numExercises);
            break;

        case 5:
            printf("Thank you for using Fitness Tracker!\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= 5);

    return 0;
}