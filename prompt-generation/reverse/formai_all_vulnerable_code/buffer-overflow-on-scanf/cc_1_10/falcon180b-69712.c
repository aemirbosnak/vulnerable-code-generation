//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORKOUTS 10

typedef struct {
    char name[30];
    int duration;
    time_t start_time;
    bool is_active;
} Workout;

void print_workout(Workout w) {
    if (w.is_active) {
        printf("Workout in progress: %s (%d seconds)\n", w.name, (int)difftime(time(NULL), w.start_time));
    } else {
        printf("Workout completed: %s (%d seconds)\n", w.name, w.duration);
    }
}

void start_workout(Workout *workouts, int num_workouts, char *name) {
    for (int i = 0; i < num_workouts; i++) {
        if (workouts[i].is_active == false) {
            strcpy(workouts[i].name, name);
            workouts[i].duration = 0;
            workouts[i].start_time = time(NULL);
            workouts[i].is_active = true;
            printf("Workout started: %s\n", name);
            return;
        }
    }
    printf("Cannot start workout, too many active workouts.\n");
}

void stop_workout(Workout *workouts, int num_workouts) {
    for (int i = 0; i < num_workouts; i++) {
        if (workouts[i].is_active == true) {
            workouts[i].duration = (int)difftime(time(NULL), workouts[i].start_time);
            workouts[i].is_active = false;
            printf("Workout stopped: %s (%d seconds)\n", workouts[i].name, workouts[i].duration);
            return;
        }
    }
    printf("Cannot stop workout, no active workouts.\n");
}

int main() {
    Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    while (true) {
        printf("Enter a command (start, stop, list, exit):\n");
        char command[10];
        scanf("%s", command);

        if (strcmp(command, "start") == 0) {
            char name[30];
            printf("Enter workout name:\n");
            scanf("%s", name);
            start_workout(workouts, MAX_WORKOUTS, name);
        } else if (strcmp(command, "stop") == 0) {
            stop_workout(workouts, MAX_WORKOUTS);
        } else if (strcmp(command, "list") == 0) {
            for (int i = 0; i < MAX_WORKOUTS; i++) {
                if (workouts[i].is_active) {
                    print_workout(workouts[i]);
                }
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}