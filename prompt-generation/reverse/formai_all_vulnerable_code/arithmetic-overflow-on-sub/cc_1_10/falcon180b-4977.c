//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 10
#define WORKOUT_NAME_LENGTH 50
#define WORKOUT_DURATION_LENGTH 10

typedef struct {
    char name[WORKOUT_NAME_LENGTH];
    int duration;
} workout;

workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);
    printf("Enter workout duration (in minutes): ");
    scanf("%d", &workouts[num_workouts].duration);
    num_workouts++;
}

void view_workouts() {
    printf("Workout Name\tDuration\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s\t\t%d minutes\n", workouts[i].name, workouts[i].duration);
    }
}

void start_workout(int workout_index) {
    if (workout_index >= 0 && workout_index < num_workouts) {
        time_t start_time = time(NULL);
        while (difftime(time(NULL), start_time) < workouts[workout_index].duration * 60) {
            printf("Working out...\n");
            sleep(1);
        }
        printf("Workout complete!\n");
    } else {
        printf("Invalid workout index.\n");
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Fitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. View workouts\n");
        printf("3. Start workout\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                view_workouts();
                break;
            case 3:
                printf("Enter workout index: ");
                int workout_index;
                scanf("%d", &workout_index);
                start_workout(workout_index - 1);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}