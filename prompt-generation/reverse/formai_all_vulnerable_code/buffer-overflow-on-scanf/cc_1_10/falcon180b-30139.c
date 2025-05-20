//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define MAX_DAYS 365
#define MAX_DURATION 60

typedef struct {
    char name[50];
    int duration;
    time_t date;
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout(char* name, int duration) {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Maximum number of workouts reached.\n");
        return;
    }
    strcpy(workouts[num_workouts].name, name);
    workouts[num_workouts].duration = duration;
    time(&workouts[num_workouts].date);
    num_workouts++;
}

void print_workouts() {
    printf("Workout Log:\n");
    printf("--------------------\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s - %d minutes - %s\n", workouts[i].name, workouts[i].duration, ctime(&workouts[i].date));
    }
}

int main() {
    int choice;
    char name[50];

    do {
        printf("Fitness Tracker Menu:\n");
        printf("--------------------\n");
        printf("1. Add workout\n");
        printf("2. Print workout log\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter workout name: ");
                scanf("%s", name);
                printf("Enter workout duration (in minutes): ");
                scanf("%d", &workouts[num_workouts].duration);
                add_workout(name, workouts[num_workouts].duration);
                break;
            case 2:
                print_workouts();
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice!= 3);

    return 0;
}