//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WORKOUTS 5
#define MAX_TIME 60

typedef struct {
    char name[50];
    int duration;
    int calories;
} workout_t;

workout_t workouts[NUM_WORKOUTS] = {
    {"Running", 30, 300},
    {"Cycling", 45, 450},
    {"Swimming", 60, 600},
    {"Yoga", 30, 150},
    {"Weightlifting", 45, 400}
};

int main() {
    int choice;
    int total_calories = 0;
    time_t start_time, end_time;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please choose a workout:\n");

    for (int i = 0; i < NUM_WORKOUTS; i++) {
        printf("%d. %s (%d calories)\n", i + 1, workouts[i].name, workouts[i].calories);
    }

    scanf("%d", &choice);

    if (choice < 1 || choice > NUM_WORKOUTS) {
        printf("Invalid choice. Exiting...\n");
        return 1;
    }

    time(&start_time);

    while (difftime(time(NULL), start_time) < workouts[choice - 1].duration) {
        printf("You have been working out for %d seconds.\n", workouts[choice - 1].duration);
        fflush(stdout);
        total_calories += workouts[choice - 1].calories;
    }

    printf("Workout complete! You burned %d calories.\n", total_calories);

    return 0;
}