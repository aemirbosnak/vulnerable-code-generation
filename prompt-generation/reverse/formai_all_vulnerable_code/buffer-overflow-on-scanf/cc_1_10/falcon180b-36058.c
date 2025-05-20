//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_EXERCISES 10
#define MAX_TIME 60

typedef struct {
    char name[50];
    int duration;
} Exercise;

void addExercise(Exercise *exerciseArray, int *numExercises) {
    printf("Enter exercise name: ");
    scanf("%s", exerciseArray[*numExercises].name);
    printf("Enter exercise duration in seconds: ");
    scanf("%d", &exerciseArray[*numExercises].duration);
    (*numExercises)++;
}

void displayExercises(Exercise *exerciseArray, int numExercises) {
    printf("Exercises:\n");
    for (int i = 0; i < numExercises; i++) {
        printf("%s - %d seconds\n", exerciseArray[i].name, exerciseArray[i].duration);
    }
}

void startWorkout(Exercise *exerciseArray, int numExercises) {
    int currentExercise = 0;
    time_t startTime, endTime;
    printf("Workout started.\n");
    time(&startTime);
    while (currentExercise < numExercises) {
        printf("Starting exercise %s...\n", exerciseArray[currentExercise].name);
        time(&startTime);
        sleep(exerciseArray[currentExercise].duration);
        time(&endTime);
        printf("Finished exercise %s. Time taken: %ld seconds.\n", exerciseArray[currentExercise].name, endTime - startTime);
        currentExercise++;
    }
    printf("Workout completed.\n");
}

int main() {
    Exercise exerciseArray[MAX_EXERCISES];
    int numExercises = 0;

    addExercise(exerciseArray, &numExercises);
    displayExercises(exerciseArray, numExercises);

    startWorkout(exerciseArray, numExercises);

    return 0;
}