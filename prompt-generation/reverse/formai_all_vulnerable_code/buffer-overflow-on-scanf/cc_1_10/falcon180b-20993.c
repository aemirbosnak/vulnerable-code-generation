//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_EXERCISES 100
#define MAX_DURATION 1000

typedef struct {
    char name[MAX_NAME];
    int duration;
} Exercise;

typedef struct {
    int num_exercises;
    Exercise exercises[MAX_EXERCISES];
} Workout;

void add_exercise(Workout* workout, char* name, int duration) {
    if (workout->num_exercises >= MAX_EXERCISES) {
        printf("Error: workout is full.\n");
        return;
    }

    strcpy(workout->exercises[workout->num_exercises].name, name);
    workout->exercises[workout->num_exercises].duration = duration;
    workout->num_exercises++;
}

void print_workout(Workout* workout) {
    printf("Workout: %s\n", workout->exercises[0].name);
    for (int i = 1; i < workout->num_exercises; i++) {
        printf("%s (%d minutes)\n", workout->exercises[i].name, workout->exercises[i].duration);
    }
}

int main() {
    Workout workout;
    workout.num_exercises = 0;

    char input[MAX_NAME];
    while (1) {
        printf("Enter an exercise (or type 'done' to finish): ");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        int duration;
        printf("Enter the duration in minutes: ");
        scanf("%d", &duration);

        add_exercise(&workout, input, duration);
    }

    print_workout(&workout);

    return 0;
}