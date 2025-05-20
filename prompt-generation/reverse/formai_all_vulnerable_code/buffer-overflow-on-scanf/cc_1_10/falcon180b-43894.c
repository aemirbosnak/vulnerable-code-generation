//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_WORKOUT_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    char description[MAX_WORKOUT_DESCRIPTION_LENGTH];
    time_t start_time;
    time_t end_time;
    int duration;
} workout_t;

workout_t workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: maximum number of workouts reached\n");
        return;
    }

    workout_t new_workout;
    printf("Enter workout name: ");
    scanf("%s", new_workout.name);
    printf("Enter workout description: ");
    scanf("%s", new_workout.description);

    new_workout.start_time = time(NULL);

    workouts[num_workouts] = new_workout;
    num_workouts++;
}

void view_workouts() {
    for (int i = 0; i < num_workouts; i++) {
        printf("Workout %d:\n", i + 1);
        printf("Name: %s\n", workouts[i].name);
        printf("Description: %s\n", workouts[i].description);
        printf("Start time: %s\n", ctime(&workouts[i].start_time));
        if (workouts[i].end_time!= 0) {
            printf("End time: %s\n", ctime(&workouts[i].end_time));
            printf("Duration: %d seconds\n\n", workouts[i].duration);
        } else {
            printf("Duration: still in progress\n\n");
        }
    }
}

void end_workout() {
    if (num_workouts == 0) {
        printf("Error: no workout in progress\n");
        return;
    }

    workouts[num_workouts - 1].end_time = time(NULL);
    workouts[num_workouts - 1].duration = difftime(workouts[num_workouts - 1].end_time, workouts[num_workouts - 1].start_time);

    printf("Workout ended. Press any key to continue...\n");
    getchar();
}

int main() {
    printf("Welcome to the Fitness Tracker!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a workout\n");
        printf("2. View workouts\n");
        printf("3. End current workout\n");
        printf("4. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                view_workouts();
                break;
            case 3:
                end_workout();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}