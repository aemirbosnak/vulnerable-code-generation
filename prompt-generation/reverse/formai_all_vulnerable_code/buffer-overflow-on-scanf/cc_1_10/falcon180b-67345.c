//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10

struct workout {
    char name[50];
    int duration;
    int caloriesBurned;
    time_t date;
};

void addWorkout(struct workout *workouts, int numWorkouts) {
    printf("Enter workout name: ");
    scanf("%s", workouts[numWorkouts].name);
    printf("Enter workout duration in minutes: ");
    scanf("%d", &workouts[numWorkouts].duration);
    printf("Enter calories burned: ");
    scanf("%d", &workouts[numWorkouts].caloriesBurned);
    time(&workouts[numWorkouts].date);
    numWorkouts++;
}

void displayWorkout(struct workout workout) {
    printf("Workout Name: %s\n", workout.name);
    printf("Duration: %d minutes\n", workout.duration);
    printf("Calories Burned: %d\n", workout.caloriesBurned);
    printf("Date: %s\n", ctime(&workout.date));
}

void displayAllWorkouts(struct workout workouts[], int numWorkouts) {
    printf("All Workouts:\n");
    for (int i = 0; i < numWorkouts; i++) {
        displayWorkout(workouts[i]);
    }
}

int main() {
    struct workout workouts[MAX_WORKOUTS];
    int numWorkouts = 0;

    while (numWorkouts < MAX_WORKOUTS) {
        addWorkout(workouts, numWorkouts);
        printf("Do you want to add another workout? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice == 'n') {
            break;
        }
    }

    displayAllWorkouts(workouts, numWorkouts);

    return 0;
}