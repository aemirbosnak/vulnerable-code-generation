//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    time_t timestamp;
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Sorry, you have reached the maximum number of workouts.\n");
        return;
    }

    printf("Enter the name of the workout: ");
    scanf("%s", workouts[num_workouts].name);

    printf("Enter a description of the workout: ");
    scanf("%[^\n]", workouts[num_workouts].description);

    time(&workouts[num_workouts].timestamp);
    printf("Workout added at %s\n", ctime(&workouts[num_workouts].timestamp));

    num_workouts++;
}

void view_workouts() {
    printf("Workout log:\n");

    for (int i = 0; i < num_workouts; i++) {
        printf("%s - %s\n", workouts[i].name, workouts[i].description);
    }
}

void main() {
    srand(time(NULL));

    int choice;

    do {
        printf("Fitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. View workouts\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                view_workouts();
                break;
            case 3:
                printf("Thank you for using Fitness Tracker!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("\nPress enter to continue...");
        getchar();
    } while (1);
}