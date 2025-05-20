//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORKOUTS 100
#define WORKOUT_NAME_LENGTH 50
#define WORKOUT_DURATION_LENGTH 10

typedef struct {
    char name[WORKOUT_NAME_LENGTH];
    int duration;
} Workout;

int main() {
    int choice;
    char input[WORKOUT_NAME_LENGTH];
    Workout workouts[MAX_WORKOUTS];
    int num_workouts = 0;

    do {
        printf("Welcome to the Fitness Tracker 3000!\n");
        printf("Please choose an option:\n");
        printf("1. Add a workout\n");
        printf("2. View workout history\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter the name of the workout (up to %d characters): ", WORKOUT_NAME_LENGTH);
                scanf("%s", input);
                printf("Enter the duration of the workout in minutes: ");
                scanf("%d", &workouts[num_workouts].duration);
                strcpy(workouts[num_workouts].name, input);
                num_workouts++;
                break;
            case 2:
                printf("Workout history:\n");
                for(int i = 0; i < num_workouts; i++) {
                    printf("%s - %d minutes\n", workouts[i].name, workouts[i].duration);
                }
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice!= 3);

    return 0;
}