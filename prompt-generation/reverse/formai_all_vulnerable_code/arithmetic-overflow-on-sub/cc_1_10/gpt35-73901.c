//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to calculate maximum heart rate based on age
int max_heart_rate(int age) {
    return 220 - age;
}

// Function to calculate target heart rate range
void target_heart_rate(int age, int* low, int* high) {
    int max_hr = max_heart_rate(age);
    *low = max_hr * 0.6;
    *high = max_hr * 0.8;
}

// Function to display fitness tracker options
void display_options() {
    printf("\nFitness Tracker Options\n");
    printf("1. Record workout\n");
    printf("2. View workout history\n");
    printf("3. Calculate target heart rate\n");
    printf("4. Exit\n");
}

// Function to record a workout
void record_workout(int* workouts, int* total_time, int* total_calories) {
    int duration, calories;
    printf("\nEnter duration of workout (in minutes): ");
    scanf("%d", &duration);
    printf("Enter total calories burned: ");
    scanf("%d", &calories);
    
    (*workouts)++;
    (*total_time) += duration;
    (*total_calories) += calories;
}

// Function to view workout history
void view_workout_history(int workouts, int total_time, int total_calories) {
    printf("\nWorkout History\n");
    printf("Number of workouts: %d\n", workouts);
    printf("Total time exercised: %d minutes\n", total_time);
    printf("Total calories burned: %d\n", total_calories);
}

int main() {
    int age, option, workouts = 0, total_time = 0, total_calories = 0, low_hr, high_hr, heart_rate;
    time_t current_time;
    char* c_time_string;
    
    // Get user's age
    printf("Please enter your age: ");
    scanf("%d", &age);
    
    // Main program loop
    do {
        display_options();
        printf("\nEnter option number: ");
        scanf("%d", &option);
        
        switch(option) {
            // Record workout
            case 1:
                record_workout(&workouts, &total_time, &total_calories);
                break;
            // View workout history
            case 2:
                view_workout_history(workouts, total_time, total_calories);
                break;
            // Calculate target heart rate range
            case 3:
                target_heart_rate(age, &low_hr, &high_hr);
                printf("\nTarget heart rate range: %d - %d beats per minute\n", low_hr, high_hr);
                break;
            // Exit program
            case 4:
                printf("\nThank you for using the fitness tracker!\n");
                break;
            // Invalid option
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
        
        // Simulate heart rate measurement every iteration
        heart_rate = rand() % 70 + 70; // random number between 70 and 140 beats per minute
        printf("Heart rate: %d beats per minute\n", heart_rate);
        
        // Get current time and display
        current_time = time(NULL);
        c_time_string = ctime(&current_time);
        printf("Current time: %s\n", c_time_string);
        
    } while(option != 4);
    
    return 0;
}