//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_WORKOUTS 100
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_WORKOUT_DURATION_MINUTES 120 // 2 hours

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration;
    time_t start_time;
    bool is_running;
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }

    printf("Enter workout name (up to %d characters): ", MAX_WORKOUT_NAME_LENGTH - 1);
    scanf("%s", workouts[num_workouts].name);

    printf("Enter workout duration in minutes: ");
    scanf("%d", &workouts[num_workouts].duration);

    workouts[num_workouts].start_time = time(NULL);
    workouts[num_workouts].is_running = true;

    num_workouts++;
}

void stop_workout(int index) {
    if (index < 0 || index >= num_workouts) {
        printf("Error: Invalid workout index.\n");
        return;
    }

    workouts[index].is_running = false;
    workouts[index].duration = difftime(time(NULL), workouts[index].start_time);
}

void display_workouts() {
    printf("Workout Name\tDuration (minutes)\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s\t\t%d\n", workouts[i].name, workouts[i].duration);
    }
}

int main() {
    srand(time(NULL));

    num_workouts = 0;

    while (true) {
        printf("Fitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. Stop workout\n");
        printf("3. Display workouts\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_workout();
            break;
        case 2: {
            printf("Enter workout index to stop: ");
            int index;
            scanf("%d", &index);
            stop_workout(index);
            break;
        }
        case 3:
            display_workouts();
            break;
        case 4:
            exit(0);
        default:
            printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}