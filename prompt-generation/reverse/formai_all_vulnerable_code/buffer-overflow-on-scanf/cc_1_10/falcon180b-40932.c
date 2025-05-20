//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 50
#define MAX_EXERCISE_LENGTH 30
#define MAX_EXERCISE_COUNT 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char exercises[MAX_EXERCISE_COUNT][MAX_EXERCISE_LENGTH];
    int count;
} FitnessTracker;

void initializeTracker(FitnessTracker* tracker) {
    tracker->count = 0;
}

void addExercise(FitnessTracker* tracker, char* exercise) {
    if (tracker->count >= MAX_EXERCISE_COUNT) {
        printf("Sorry, the exercise list is full.\n");
        return;
    }
    strcpy(tracker->exercises[tracker->count], exercise);
    tracker->count++;
}

void displayTracker(FitnessTracker* tracker) {
    printf("Name: %s\n", tracker->name);
    printf("Exercises:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%s\n", tracker->exercises[i]);
    }
}

int main() {
    FitnessTracker tracker;
    initializeTracker(&tracker);

    printf("Enter your name:\n");
    scanf("%s", tracker.name);

    while (1) {
        printf("Enter an exercise (or type 'quit' to exit):\n");
        char exercise[MAX_EXERCISE_LENGTH];
        scanf("%s", exercise);
        if (strcmp(exercise, "quit") == 0) {
            break;
        }
        addExercise(&tracker, exercise);
    }

    displayTracker(&tracker);

    return 0;
}