//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_EXERCISES 10
#define MAX_DURATION 60 * 60 * 24 // 1 day

typedef struct {
    char name[50];
    int duration; // in seconds
} Exercise;

typedef struct {
    Exercise exercises[MAX_EXERCISES];
    int num_exercises;
    time_t start_time;
} FitnessTracker;

void init_fitness_tracker(FitnessTracker* tracker) {
    tracker->num_exercises = 0;
    tracker->start_time = 0;
}

void add_exercise(FitnessTracker* tracker, char* name, int duration) {
    if (tracker->num_exercises >= MAX_EXERCISES) {
        printf("Cannot add more than %d exercises.\n", MAX_EXERCISES);
        return;
    }

    strcpy(tracker->exercises[tracker->num_exercises].name, name);
    tracker->exercises[tracker->num_exercises].duration = duration;
    tracker->num_exercises++;
}

void start_fitness_tracker(FitnessTracker* tracker) {
    if (tracker->num_exercises == 0) {
        printf("No exercises added.\n");
        return;
    }

    time(&tracker->start_time);
}

void stop_fitness_tracker(FitnessTracker* tracker) {
    if (tracker->start_time == 0) {
        printf("Fitness tracker not started.\n");
        return;
    }

    time_t end_time;
    time(&end_time);

    printf("Fitness tracker stopped.\n");

    for (int i = 0; i < tracker->num_exercises; i++) {
        int duration = tracker->exercises[i].duration;
        int seconds_elapsed = end_time - tracker->start_time;

        if (seconds_elapsed > duration) {
            printf("Exercise '%s' completed.\n", tracker->exercises[i].name);
        } else {
            printf("Exercise '%s' in progress...\n", tracker->exercises[i].name);
        }
    }
}

int main() {
    FitnessTracker tracker;
    init_fitness_tracker(&tracker);

    add_exercise(&tracker, "Running", 300);
    add_exercise(&tracker, "Cycling", 600);

    start_fitness_tracker(&tracker);

    // Simulate some time passing
    sleep(10);

    stop_fitness_tracker(&tracker);

    return 0;
}