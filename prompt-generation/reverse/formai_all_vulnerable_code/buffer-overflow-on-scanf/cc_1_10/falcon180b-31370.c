//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_WORKOUT_NAME_LEN 50

typedef struct {
    char name[MAX_WORKOUT_NAME_LEN];
    int duration;
    int calories;
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout(char* name, int duration, int calories) {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Cannot add more than %d workouts.\n", MAX_WORKOUTS);
        return;
    }

    strncpy(workouts[num_workouts].name, name, MAX_WORKOUT_NAME_LEN - 1);
    workouts[num_workouts].duration = duration;
    workouts[num_workouts].calories = calories;

    num_workouts++;
}

void print_workouts() {
    printf("Workouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s: %d minutes, %d calories\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
    }
}

int main() {
    char input[100];
    int duration, calories;

    srand(time(NULL));

    while (1) {
        printf("Enter a workout (type 'quit' to exit):\n");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        printf("Enter duration (in minutes):\n");
        scanf("%d", &duration);

        printf("Enter calories burned:\n");
        scanf("%d", &calories);

        add_workout(input, duration, calories);
    }

    print_workouts();

    return 0;
}