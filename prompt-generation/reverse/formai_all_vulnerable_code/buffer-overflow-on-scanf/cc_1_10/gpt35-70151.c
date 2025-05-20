//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Sherlock Holmes
/* 
SHERLOCK'S FITNESS TRACKER PROGRAM
by Sherlock Holmes
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize variables
    int daily_step_goal = 10000;
    float distance_goal = 5.0;
    int current_steps = 0;
    float total_distance = 0.0;
    float current_speed = 0.0;
    float max_speed = 0.0;
    float average_speed = 0.0;

    // Get user's name
    char name[20];
    printf("Greetings, my good friend! What is your name? ");
    scanf("%s", name);

    // Display instructions
    printf("\nWelcome to Sherlock's Fitness Tracker, %s!\n\n", name);
    printf("You are currently set to a daily step goal of %d and a distance goal of %.1f km.\n", daily_step_goal, distance_goal);
    printf("Please make sure to wear your fitness tracker throughout the day so the data can be logged automatically.\n\n");

    // Calculate and track progress
    srand(time(0));
    for (int i = 1; i <= 24; i++) { // Loop through 24 hours in a day
        int hourly_steps = rand() % (200 - 50 + 1) + 50; // Randomly generate hourly steps between 50 and 200
        current_steps += hourly_steps;

        float hourly_distance = hourly_steps * 0.000762; // Convert steps to distance in km
        total_distance += hourly_distance;

        if (hourly_steps > 0) {
            current_speed = hourly_distance / (1.0 / 60.0); // Convert km/min to km/hour
            if (current_speed > max_speed) {
                max_speed = current_speed;
            }
        }

        printf("Hour %d: %d steps taken, %.2f km travelled at %.1f km/hour\n", i, hourly_steps, hourly_distance, current_speed);
    }

    average_speed = total_distance / 24.0; // Calculate average speed for the day

    // Determine if user met daily goals and display results
    printf("\nAt the end of the day, your total step count was %d and you travelled a total distance of %.2f km.\n", current_steps, total_distance);
    printf("Your maximum speed was %.1f km/hour and your average speed for the day was %.1f km/hour.\n", max_speed, average_speed);

    if (current_steps >= daily_step_goal && total_distance >= distance_goal) {
        printf("Congratulations, %s! You have met both your daily step and distance goals!\n", name);
    } else if (current_steps >= daily_step_goal) {
        printf("Good job, %s! You have met your daily step goal!\n", name);
    } else if (total_distance >= distance_goal) {
        printf("Well done, %s! You have met your daily distance goal!\n", name);
    } else {
        printf("Keep pushing, %s! You can do it!\n", name);
    }

    return 0;
}