//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define MAX_WORKOUTS 10
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_WORKOUT_TIME_LENGTH 10
#define MAX_WORKOUT_DISTANCE_LENGTH 10
#define MAX_WORKOUT_CALORIES_LENGTH 10

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    char time[MAX_WORKOUT_TIME_LENGTH];
    char distance[MAX_WORKOUT_DISTANCE_LENGTH];
    char calories[MAX_WORKOUT_CALORIES_LENGTH];
} Workout;

Workout workouts[MAX_WORKOUTS];
int num_workouts = 0;

void add_workout() {
    if (num_workouts >= MAX_WORKOUTS) {
        printf("Sorry, you cannot add any more workouts.\n");
        return;
    }
    printf("Enter the name of the workout: ");
    scanf("%s", workouts[num_workouts].name);
    printf("Enter the time of the workout (in minutes): ");
    scanf("%s", workouts[num_workouts].time);
    printf("Enter the distance of the workout (in miles): ");
    scanf("%s", workouts[num_workouts].distance);
    printf("Enter the calories burned during the workout: ");
    scanf("%s", workouts[num_workouts].calories);
    num_workouts++;
    printf("Workout added successfully!\n");
}

void view_workouts() {
    printf("Workout Name | Time (in minutes) | Distance (in miles) | Calories Burned\n");
    for (int i = 0; i < num_workouts; i++) {
        printf("%-50s | %-10s | %-10s | %-10s\n", workouts[i].name, workouts[i].time, workouts[i].distance, workouts[i].calories);
    }
}

int main() {
    srand(time(NULL));
    int choice;
    while (true) {
        printf("Welcome to the Fitness Tracker!\n");
        printf("1. Add a workout\n");
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
                printf("Goodbye, and keep up the good work!\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}