//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 10
#define MAX_WORKOUT_NAME_LENGTH 50

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    time_t start_time;
    time_t end_time;
    int duration;
} workout_t;

workout_t workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout(char *name) {
    if (num_workouts == MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }

    strcpy(workouts[num_workouts].name, name);
    workouts[num_workouts].start_time = time(NULL);
    workouts[num_workouts].end_time = 0;
    workouts[num_workouts].duration = 0;

    num_workouts++;
}

void end_workout() {
    if (num_workouts == 0) {
        printf("Error: No workout in progress.\n");
        return;
    }

    workouts[num_workouts - 1].end_time = time(NULL);
    workouts[num_workouts - 1].duration = difftime(workouts[num_workouts - 1].end_time, workouts[num_workouts - 1].start_time);
}

void print_workouts() {
    if (num_workouts == 0) {
        printf("No workouts recorded.\n");
        return;
    }

    printf("Workout History:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s: %d seconds\n", workouts[i].name, workouts[i].duration);
    }
}

int main() {
    char input[100];

    while (1) {
        printf("Enter command (add_workout <name>, end_workout, print_workouts, quit): ");
        scanf("%s", input);

        if (strcmp(input, "add_workout") == 0) {
            char name[MAX_WORKOUT_NAME_LENGTH];
            printf("Enter workout name: ");
            scanf("%s", name);
            add_workout(name);
        } else if (strcmp(input, "end_workout") == 0) {
            end_workout();
        } else if (strcmp(input, "print_workouts") == 0) {
            print_workouts();
        } else if (strcmp(input, "quit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}