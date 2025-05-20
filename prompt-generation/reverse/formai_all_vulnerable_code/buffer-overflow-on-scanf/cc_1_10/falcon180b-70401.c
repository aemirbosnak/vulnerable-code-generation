//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000
#define MAX_WORKOUTS 10

typedef struct {
    char name[MAX_SIZE];
    int duration;
    int calories;
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    char name[MAX_SIZE];
    int duration;
    int calories;

    printf("Enter the name of the workout: ");
    scanf("%s", name);

    printf("Enter the duration of the workout in minutes: ");
    scanf("%d", &duration);

    printf("Enter the number of calories burned during the workout: ");
    scanf("%d", &calories);

    strcpy(workouts[num_workouts].name, name);
    workouts[num_workouts].duration = duration;
    workouts[num_workouts].calories = calories;

    num_workouts++;
}

void display_workouts() {
    printf("\nWorkout Summary:\n");
    printf("--------------------\n");

    for (int i = 0; i < num_workouts; i++) {
        printf("%s\t%d minutes\t%d calories\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
    }
}

int main() {
    char choice;

    do {
        printf("\nFitness Tracker\n");
        printf("--------------------\n");
        printf("1. Add a workout\n");
        printf("2. Display workouts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch(choice) {
            case '1':
                add_workout();
                break;
            case '2':
                display_workouts();
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice!= '3');

    return 0;
}