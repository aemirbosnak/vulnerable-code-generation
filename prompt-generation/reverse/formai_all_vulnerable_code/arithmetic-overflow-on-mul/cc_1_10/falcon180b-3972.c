//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 10
#define MAX_WORKOUT_NAME_LEN 50

typedef struct {
    char name[MAX_WORKOUT_NAME_LEN];
    int duration;
    int calories;
} workout_t;

workout_t workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }

    printf("Enter workout name (max %d characters): ", MAX_WORKOUT_NAME_LEN - 1);
    scanf("%s", workouts[num_workouts].name);

    printf("Enter workout duration in seconds: ");
    scanf("%d", &workouts[num_workouts].duration);

    printf("Enter workout calories burned: ");
    scanf("%d", &workouts[num_workouts].calories);

    num_workouts++;
}

void print_workouts() {
    printf("\nWorkouts:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s\n", workouts[i].name);
    }
}

void track_workout(int workout_index) {
    if (workout_index >= num_workouts) {
        printf("Error: Workout not found.\n");
        return;
    }

    time_t start_time, end_time;
    time(&start_time);

    printf("Starting workout...\n");

    while (1) {
        printf("Press enter to stop workout...\n");
        getchar();

        time(&end_time);
        int duration = difftime(end_time, start_time);

        workouts[workout_index].calories += (duration * 5);
        printf("Workout completed. Calories burned: %d\n", workouts[workout_index].calories);

        break;
    }
}

int main() {
    printf("Welcome to the Fitness Tracker!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add workout\n");
        printf("2. Print workouts\n");
        printf("3. Track workout\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_workout();
            break;
        case 2:
            print_workouts();
            break;
        case 3:
            printf("Enter workout index: ");
            int workout_index;
            scanf("%d", &workout_index);
            track_workout(workout_index);
            break;
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}