//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Exercise {
    char name[50];
    int duration;
    int calories;
} Exercise;

typedef struct FitnessTracker {
    char name[50];
    Exercise exercises[10];
    int num_exercises;
    int total_calories;
    int total_duration;
} FitnessTracker;

void addExercise(FitnessTracker* tracker, char name[], int duration, int calories) {
    Exercise new_exercise;
    strcpy(new_exercise.name, name);
    new_exercise.duration = duration;
    new_exercise.calories = calories;
    tracker->exercises[tracker->num_exercises] = new_exercise;
    tracker->num_exercises++;
    tracker->total_duration += duration;
    tracker->total_calories += calories;
}

void printTracker(FitnessTracker* tracker) {
    printf("=====================\n");
    printf("FITNESS TRACKER FOR %s\n", tracker->name);
    printf("=====================\n");
    printf("TOTAL DURATION: %d minutes\n", tracker->total_duration);
    printf("TOTAL CALORIES BURNED: %d\n", tracker->total_calories);
    printf("EXERCISES:\n");
    for(int i = 0; i < tracker->num_exercises; i++) {
        printf("%s: %d minutes, %d calories\n", tracker->exercises[i].name, tracker->exercises[i].duration, tracker->exercises[i].calories);
    }
}

int main() {
    FitnessTracker tracker;
    strcpy(tracker.name, "John Doe");

    addExercise(&tracker, "Running", 30, 300);
    addExercise(&tracker, "Weightlifting", 60, 400);
    addExercise(&tracker, "Yoga", 45, 200);

    printTracker(&tracker);

    return 0;
}