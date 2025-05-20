//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout(char* name, char* description) {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }

    strcpy(workouts[num_workouts].name, name);
    strcpy(workouts[num_workouts].description, description);

    time(&workouts[num_workouts].start_time);
    workouts[num_workouts].end_time = 0;

    num_workouts++;
}

void print_workouts() {
    printf("Workouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s - %s\n", workouts[i].name, workouts[i].description);
    }
}

void start_workout(int index) {
    if (index >= num_workouts || workouts[index].end_time!= 0) {
        printf("Error: Workout already started or does not exist.\n");
        return;
    }

    time(&workouts[index].start_time);
    workouts[index].end_time = 0;
}

void end_workout(int index) {
    if (index >= num_workouts || workouts[index].end_time!= 0) {
        printf("Error: Workout already ended or does not exist.\n");
        return;
    }

    time(&workouts[index].end_time);
}

void print_workout_summary(int index) {
    if (index >= num_workouts || workouts[index].end_time == 0) {
        printf("Workout not completed.\n");
        return;
    }

    time_t duration = workouts[index].end_time - workouts[index].start_time;
    printf("Workout completed:\n");
    printf("Name: %s\n", workouts[index].name);
    printf("Description: %s\n", workouts[index].description);
    printf("Duration: %ld seconds\n", duration);
}

int main() {
    add_workout("Running", "Jogging around the park");
    add_workout("Swimming", "Laps at the pool");

    print_workouts();

    start_workout(0);

    end_workout(0);

    print_workout_summary(0);

    return 0;
}