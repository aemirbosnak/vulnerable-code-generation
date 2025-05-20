//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_WORKOUT_NAME_SIZE 50
#define MAX_WORKOUT_DURATION_MINUTES 120
#define MAX_WORKOUT_DISTANCE_METERS 10000
#define MAX_WORKOUT_CALORIES_BURNED 1000

typedef struct {
    char name[MAX_WORKOUT_NAME_SIZE];
    int duration_minutes;
    int distance_meters;
    int calories_burned;
} Workout;

int num_workouts = 0;
Workout workouts[MAX_WORKOUTS];

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Error: Cannot add more than %d workouts.\n", MAX_WORKOUTS);
        return;
    }

    char name[MAX_WORKOUT_NAME_SIZE];
    printf("Enter workout name: ");
    scanf("%s", name);

    int duration_minutes;
    printf("Enter workout duration (minutes): ");
    scanf("%d", &duration_minutes);

    int distance_meters;
    printf("Enter workout distance (meters): ");
    scanf("%d", &distance_meters);

    int calories_burned;
    printf("Enter workout calories burned: ");
    scanf("%d", &calories_burned);

    strcpy(workouts[num_workouts].name, name);
    workouts[num_workouts].duration_minutes = duration_minutes;
    workouts[num_workouts].distance_meters = distance_meters;
    workouts[num_workouts].calories_burned = calories_burned;

    num_workouts++;
}

void display_workouts() {
    if (num_workouts == 0) {
        printf("No workouts added yet.\n");
        return;
    }

    for (int i = 0; i < num_workouts; i++) {
        printf("%s\n", workouts[i].name);
        printf("Duration: %d minutes\n", workouts[i].duration_minutes);
        printf("Distance: %d meters\n", workouts[i].distance_meters);
        printf("Calories burned: %d\n\n", workouts[i].calories_burned);
    }
}

void main() {
    srand(time(0));

    int choice;
    do {
        printf("Fitness Tracker\n");
        printf("1. Add workout\n");
        printf("2. Display workouts\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
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
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 3);
}