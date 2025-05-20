//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100

typedef struct {
    char name[50];
    int duration;
    int calories;
} workout;

workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    char name[50];
    int duration, calories;

    printf("Enter workout name: ");
    scanf("%s", name);

    printf("Enter workout duration (in minutes): ");
    scanf("%d", &duration);

    printf("Enter workout calories burned: ");
    scanf("%d", &calories);

    strcpy(workouts[num_workouts].name, name);
    workouts[num_workouts].duration = duration;
    workouts[num_workouts].calories = calories;

    num_workouts++;
}

void display_workouts() {
    int i;

    printf("\nWorkout summary:\n");
    printf("--------------------\n");
    printf("Name\tDuration\tCalories\n");

    for (i = 0; i < num_workouts; i++) {
        printf("%s\t%d\t%d\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
    }
}

void clear_workouts() {
    num_workouts = 0;
}

int main() {
    int choice;

    do {
        printf("\nFitness Tracker\n");
        printf("--------------------\n");
        printf("1. Add workout\n");
        printf("2. Display summary\n");
        printf("3. Clear workouts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                display_workouts();
                break;
            case 3:
                clear_workouts();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}