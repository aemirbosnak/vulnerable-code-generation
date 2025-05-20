//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXERCISES 10
#define MAX_WORKOUTS 50

typedef struct {
    char name[50];
    int duration;
    int calories;
} Exercise;

typedef struct {
    int date;
    Exercise exercises[MAX_EXERCISES];
    int num_exercises;
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    int date = tm->tm_yday;

    printf("Enter the name of the exercise:\n");
    scanf("%s", workouts[num_workouts].exercises[0].name);

    printf("Enter the duration of the exercise (in seconds):\n");
    scanf("%d", &workouts[num_workouts].exercises[0].duration);

    printf("Enter the number of calories burned:\n");
    scanf("%d", &workouts[num_workouts].exercises[0].calories);

    workouts[num_workouts].date = date;
    workouts[num_workouts].num_exercises = 1;

    num_workouts++;

    printf("Workout added successfully.\n");
}

void view_workouts() {
    if (num_workouts == 0) {
        printf("No workouts available.\n");
        return;
    }

    printf("Workout history:\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("Date: %d\n", workouts[i].date);

        printf("Exercises:\n");
        for (int j = 0; j < workouts[i].num_exercises; j++) {
            printf(" - %s (%d seconds, %d calories)\n", workouts[i].exercises[j].name, workouts[i].exercises[j].duration, workouts[i].exercises[j].calories);
        }
    }
}

int main() {
    srand(time(NULL));

    int choice;

    while (1) {
        printf("Fitness Tracker\n");
        printf("1. Add a workout\n");
        printf("2. View workout history\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                view_workouts();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}