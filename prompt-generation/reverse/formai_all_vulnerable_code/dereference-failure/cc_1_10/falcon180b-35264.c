//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORKOUTS 100
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_WORKOUT_DURATION 10000 // 10 hours, in seconds
#define MAX_WORKOUT_CALORIES 10000 // 10 kcal

typedef struct {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration;
    int calories;
} Workout;

void print_workout(Workout *workout) {
    printf("Name: %s\n", workout->name);
    printf("Duration: %d seconds\n", workout->duration);
    printf("Calories burned: %d kcal\n", workout->calories);
}

int main() {
    int num_workouts;
    Workout *workouts;

    printf("Enter the number of workouts: ");
    scanf("%d", &num_workouts);

    workouts = malloc(num_workouts * sizeof(Workout));

    for (int i = 0; i < num_workouts; i++) {
        printf("Enter workout %d details:\n", i+1);
        printf("Name: ");
        scanf("%s", workouts[i].name);
        printf("Duration (in seconds): ");
        scanf("%d", &workouts[i].duration);
        printf("Calories burned: ");
        scanf("%d", &workouts[i].calories);

        if (workouts[i].duration > MAX_WORKOUT_DURATION || workouts[i].calories > MAX_WORKOUT_CALORIES) {
            printf("Invalid workout details. Please try again.\n");
            i--;
        }
    }

    printf("Workout log:\n");
    for (int i = 0; i < num_workouts; i++) {
        print_workout(&workouts[i]);
    }

    free(workouts);
    return 0;
}