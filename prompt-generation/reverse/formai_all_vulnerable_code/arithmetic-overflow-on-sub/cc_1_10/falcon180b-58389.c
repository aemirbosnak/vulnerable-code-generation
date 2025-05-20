//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_WORKOUT_DURATION 120 // in seconds

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration;
} workout;

workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }

    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);

    printf("Enter workout duration (in seconds): ");
    scanf("%d", &workouts[num_workouts].duration);

    num_workouts++;
}

void display_workouts() {
    printf("Workouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s - %d seconds\n", workouts[i].name, workouts[i].duration);
    }
}

void start_workout(int workout_index) {
    if (workout_index < 0 || workout_index >= num_workouts) {
        printf("Error: Invalid workout index.\n");
        return;
    }

    printf("Starting %s...\n", workouts[workout_index].name);
    int duration = workouts[workout_index].duration;
    int seconds_left = duration;

    while (seconds_left > 0) {
        printf("%d seconds left...\n", seconds_left);
        sleep(1);
        seconds_left--;
    }

    printf("Workout completed!\n");
}

int main() {
    printf("Welcome to the Fitness Tracker!\n");

    while (1) {
        printf("Options:\n");
        printf("1. Add workout\n");
        printf("2. Display workouts\n");
        printf("3. Start workout\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_workout();
            break;
        case 2:
            display_workouts();
            break;
        case 3:
            printf("Enter workout index: ");
            int workout_index;
            scanf("%d", &workout_index);
            start_workout(workout_index - 1);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}