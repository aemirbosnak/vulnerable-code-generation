//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_EXERCISES 5
#define MAX_ROUNDS 3

typedef struct {
    char name[MAX_NAME_LEN];
    int reps[MAX_ROUNDS];
    int sets[MAX_ROUNDS];
} Exercise;

typedef struct {
    Exercise exercises[MAX_EXERCISES];
    int numExercises;
} Workout;

typedef struct {
    Workout workouts[MAX_ROUNDS];
    int numRounds;
} DailyTracker;

void initializeTracker(DailyTracker *tracker) {
    tracker->numRounds = 0;
}

void addWorkout(DailyTracker *tracker) {
    if (tracker->numRounds >= MAX_ROUNDS) {
        printf("Sorry, you can only track %d workouts per day\n", MAX_ROUNDS);
        return;
    }

    Workout newWorkout;
    newWorkout.numExercises = 0;

    printf("Enter the name of the workout: ");
    scanf("%s", newWorkout.exercises[0].name);

    int numSets, numReps;
    for (int i = 0; i < MAX_EXERCISES; i++) {
        printf("Enter the number of sets for exercise %d (or 0 to stop adding exercises): ", i+1);
        scanf("%d", &numSets);

        if (numSets == 0) {
            break;
        }

        printf("Enter the number of reps for exercise %d: ", i+1);
        scanf("%d", &numReps);

        Exercise exercise;
        exercise.reps[0] = numReps;
        exercise.sets[0] = numSets;

        memcpy(exercise.name, newWorkout.exercises[0].name, MAX_NAME_LEN);

        newWorkout.exercises[i] = exercise;
        newWorkout.numExercises++;
    }

    tracker->workouts[tracker->numRounds] = newWorkout;
    tracker->numRounds++;
}

void printTracker(DailyTracker *tracker) {
    printf("DAILY FITNESS TRACKER\n");
    printf("======================\n");

    for (int round = 0; round < tracker->numRounds; round++) {
        printf("ROUND %d\n", round+1);

        for (int exercise = 0; exercise < tracker->workouts[round].numExercises; exercise++) {
            printf("\t%s: ", tracker->workouts[round].exercises[exercise].name);
            for (int set = 0; set < tracker->workouts[round].exercises[exercise].sets[0]; set++) {
                printf("%dx%d  ", tracker->workouts[round].exercises[exercise].reps[0], tracker->workouts[round].exercises[exercise].sets[0]);
            }
            printf("\n");
        }

        printf("\n");
    }
}

int main() {
    DailyTracker tracker;
    initializeTracker(&tracker);

    char option;
    do {
        printf("\n");
        printf("1. Add Workout\n");
        printf("2. View Tracker\n");
        printf("3. Exit\n");
        printf("\n");

        printf("Enter your option: ");
        scanf("%c", &option);

        switch(option) {
            case '1':
                addWorkout(&tracker);
                break;
            case '2':
                printTracker(&tracker);
                break;
            case '3':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid option\n");
                break;
        }
    } while (option != '3');

    return 0;
}