//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 20
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_WORKOUT_DURATION_MINUTES 120

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration;
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }

    printf("Enter workout name (max %d characters): ", MAX_WORKOUT_NAME_LENGTH - 1);
    scanf("%s", workouts[num_workouts].name);

    printf("Enter workout duration (max %d minutes): ", MAX_WORKOUT_DURATION_MINUTES);
    scanf("%d", &workouts[num_workouts].duration);

    num_workouts++;
}

void display_workouts() {
    printf("Workout Name\tDuration (minutes)\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s\t\t%d\n", workouts[i].name, workouts[i].duration);
    }
}

void start_workout(int workout_index) {
    if (workout_index >= num_workouts) {
        printf("Error: Invalid workout index.\n");
        return;
    }

    time_t start_time;
    time(&start_time);

    while (difftime(time(NULL), start_time) < workouts[workout_index].duration * 60) {
        // Do workout code here
    }

    printf("Workout completed: %s\n", workouts[workout_index].name);
}

int main() {
    num_workouts = 0;

    while (1) {
        printf("1. Add workout\n2. Display workouts\n3. Start workout\n4. Exit\n");
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
                printf("Enter workout index (0-%d): ", num_workouts - 1);
                int workout_index;
                scanf("%d", &workout_index);
                start_workout(workout_index);
                break;
            case 4:
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}