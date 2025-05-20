//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUT_TIME 60

typedef struct Workout {
    char name[20];
    int duration;
    int repetitions;
    int sets;
    double target_heart_rate;
    double average_heart_rate;
} Workout;

int main() {
    Workout workout_log[10] = {
        {"Super Squats", 20, 10, 3, 120, 80},
        {"Mountain Climbers", 15, 20, 2, 110, 70},
        {"Jumping Jacks", 10, 25, 3, 100, 60},
        {"Push-Ups", 12, 15, 3, 90, 50},
        {"Planks", 25, 0, 3, 80, 40},
        {"Burpees", 20, 12, 2, 105, 75},
        {"Mountain Pose", 30, 0, 1, 85, 65},
        {"Leg Lifts", 18, 18, 3, 100, 60},
        {"High Knees", 12, 20, 3, 90, 50},
        {"Walking Lunges", 16, 20, 2, 80, 40}
    };

    time_t start_time, end_time;
    int current_time = 0;
    char status = 'A';

    printf("Welcome to the C Fitness Tracker!\n");

    // Start the workout timer
    start_time = time(NULL);

    // Loop through the workout log and perform each exercise
    for (int i = 0; i < 10; i++) {
        Workout workout = workout_log[i];

        // Display the exercise name and set the target heart rate
        printf("Starting exercise: %s\n", workout.name);
        printf("Target heart rate: %.2lf\n", workout.target_heart_rate);

        // Perform the exercise for the specified duration and repetitions
        for (int j = 0; j < workout.duration; j++) {
            printf("Current time: %d seconds\n", current_time);
            printf("Status: %c\n", status);

            // Calculate the average heart rate for the set
            double average_heart_rate = (workout.average_heart_rate * j) / workout.sets;

            // Display the average heart rate
            printf("Average heart rate: %.2lf\n", average_heart_rate);

            // Increment the current time
            current_time++;
        }

        // Take a break between sets
        printf("Taking a break...\n");
    }

    // End the workout timer
    end_time = time(NULL);

    // Calculate the total time spent working out
    int total_time = end_time - start_time;

    // Display the total time spent working out
    printf("Total time spent working out: %d seconds\n", total_time);

    return 0;
}