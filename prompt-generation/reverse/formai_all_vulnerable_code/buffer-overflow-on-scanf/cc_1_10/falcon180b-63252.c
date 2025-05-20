//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

#define MAX_WORKOUTS 100
#define MAX_WORKOUT_NAME_LEN 50
#define MAX_WORKOUT_DESCRIPTION_LEN 100
#define MAX_WORKOUT_DURATION 120
#define MAX_WORKOUT_CALORIES 500
#define MAX_WORKOUT_STEPS 10000

typedef struct {
    char name[MAX_WORKOUT_NAME_LEN];
    char description[MAX_WORKOUT_DESCRIPTION_LEN];
    int duration;
    int calories;
    int steps;
} workout;

workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Cannot add more workouts.\n");
        return;
    }

    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts].name);

    printf("Enter workout description: ");
    scanf("%s", workouts[num_workouts].description);

    printf("Enter workout duration in seconds: ");
    scanf("%d", &workouts[num_workouts].duration);

    printf("Enter workout calories burned: ");
    scanf("%d", &workouts[num_workouts].calories);

    printf("Enter workout steps taken: ");
    scanf("%d", &workouts[num_workouts].steps);

    num_workouts++;
}

void display_workouts() {
    printf("Workout Name | Description | Duration | Calories Burned | Steps Taken\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%s | %s | %d seconds | %d calories | %d steps\n", workouts[i].name, workouts[i].description, workouts[i].duration, workouts[i].calories, workouts[i].steps);
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        printf("Fitness Tracker\n");
        printf("1. Add workout\n2. Display workouts\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_workout();
                break;
            case 2:
                display_workouts();
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