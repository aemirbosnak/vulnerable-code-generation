//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 20
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    int duration;
    int calories;
} Workout;

int main() {
    int choice, num_workouts = 0;
    Workout workouts[MAX_WORKOUTS];

    // Seed random number generator with current time
    srand(time(NULL));

    do {
        printf("Welcome to the Fitness Tracker!\n");
        printf("Please choose an option:\n");
        printf("1. Add a workout\n");
        printf("2. View workout history\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_workouts >= MAX_WORKOUTS) {
                printf("Sorry, you can only have %d workouts.\n", MAX_WORKOUTS);
            } else {
                printf("Enter the name of the workout (up to %d characters):\n", MAX_LENGTH - 1);
                scanf("%s", workouts[num_workouts].name);
                printf("Enter the duration of the workout in minutes:\n");
                scanf("%d", &workouts[num_workouts].duration);
                workouts[num_workouts].calories = rand() % 500; // Randomly generate calories burned
                num_workouts++;
            }
            break;
        case 2:
            if (num_workouts == 0) {
                printf("No workouts to display.\n");
            } else {
                printf("Workout history:\n");
                for (int i = 0; i < num_workouts; i++) {
                    printf("%s: %d minutes, %d calories\n", workouts[i].name, workouts[i].duration, workouts[i].calories);
                }
            }
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}