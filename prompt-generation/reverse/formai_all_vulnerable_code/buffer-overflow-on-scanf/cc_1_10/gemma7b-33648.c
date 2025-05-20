//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_CHAR 1024

int main()
{
    // System Variables
    char username[MAX_CHAR];
    char workout_type[MAX_CHAR];
    int duration;
    int intensity;
    int heart_rate;

    // Time Variables
    time_t start_time;
    time_t end_time;

    // Menu Options
    int option;

    // Interface
    system("clear");
    printf("Welcome to the Cybernetic Fitness Tracker!\n");

    // User Input
    printf("Please enter your username: ");
    scanf("%s", username);

    // Workout Type Selection
    printf("Select your workout type:\n");
    printf("1. Cardio\n");
    printf("2. Strength Training\n");
    printf("3. Yoga\n");
    scanf("%s", workout_type);

    // Duration and Intensity Input
    printf("Enter the duration of your workout (in minutes): ");
    scanf("%d", &duration);

    printf("Enter the intensity of your workout (1-10): ");
    scanf("%d", &intensity);

    // Heart Rate Measurement
    printf("Please insert your heart rate monitor and press enter: ");
    scanf("%d", &heart_rate);

    // Start Time
    start_time = time(NULL);

    // Simulate workout
    printf("Starting your workout... \n");
    sleep(duration);

    // End Time
    end_time = time(NULL);

    // Calculate Time Spent
    int time_spent = (end_time - start_time) / 60;

    // Display Results
    system("clear");
    printf("Congratulations, %s! You have completed your workout!\n", username);

    printf("Total time spent: %d minutes\n", time_spent);

    printf("Average heart rate: %d bpm\n", heart_rate);

    printf("Your workout type: %s\n", workout_type);

    printf("Thank you for using the Cybernetic Fitness Tracker!\n");

    return 0;
}