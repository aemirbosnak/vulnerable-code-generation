//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10
#define MAX_WORKOUT_NAME_LENGTH 50
#define MAX_WORKOUT_DURATION_MINUTES 120
#define MAX_WORKOUT_DURATION_SECONDS (MAX_WORKOUT_DURATION_MINUTES * 60)

// Number of workouts completed today
int num_workouts_today = 0;

// Total time spent working out today
int total_workout_time_today = 0;

// Array to store info about each workout
struct workout {
    char name[MAX_WORKOUT_NAME_LENGTH];
    int duration;
};

struct workout workouts[MAX_WORKOUTS];

// Function to add a new workout to the array
void add_workout() {
    if (num_workouts_today >= MAX_WORKOUTS) {
        printf("Error: Cannot add more than %d workouts per day.\n", MAX_WORKOUTS);
        return;
    }

    printf("Enter workout name: ");
    scanf("%s", workouts[num_workouts_today].name);

    printf("Enter workout duration in minutes: ");
    scanf("%d", &workouts[num_workouts_today].duration);

    // Convert duration from minutes to seconds
    workouts[num_workouts_today].duration *= 60;

    num_workouts_today++;
}

// Function to display the summary of the day's workouts
void display_summary() {
    if (num_workouts_today == 0) {
        printf("No workouts completed today.\n");
        return;
    }

    printf("Today's workouts:\n");
    for (int i = 0; i < num_workouts_today; i++) {
        printf("%s - %d minutes\n", workouts[i].name, workouts[i].duration / 60);
    }

    printf("\nTotal time spent working out today: %d minutes\n", total_workout_time_today);
}

// Main function
int main() {
    srand(time(NULL));

    // Initialize the array
    for (int i = 0; i < MAX_WORKOUTS; i++) {
        workouts[i].duration = 0;
    }

    // Simulate some workouts
    add_workout();
    add_workout();
    add_workout();

    // Display the summary
    display_summary();

    return 0;
}