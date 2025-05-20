//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>

// Define a struct to store workout data
struct Workout {
    float caloriesBurned;
    float distance;
    float duration;
};

// Define a struct to store user information
struct User {
    char name[50];
    int age;
    float weight;
};

// Function to calculate calories burned based on activity and duration
float calculateCaloriesBurned(char activity, float duration) {
    float intensity;
    switch (activity) {
        case 'w':
            intensity = 6.0;
            break;
        case 'j':
            intensity = 8.0;
            break;
        case 'r':
            intensity = 10.0;
            break;
        default:
            intensity = 0.0;
    }
    return intensity * duration;
}

// Function to display workout data for user
void displayWorkoutData(struct Workout w) {
    printf("Calories burned: %0.2f\n", w.caloriesBurned);
    printf("Distance: %0.2f km\n", w.distance);
    printf("Duration: %0.2f minutes\n", w.duration);
}

int main() {
    // Declare variables
    char activity;
    float duration;

    // Get user information
    struct User user;
    printf("Enter your name: ");
    scanf("%[^\n]%*c", user.name);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your weight (in kg): ");
    scanf("%f", &user.weight);

    // Get workout information
    printf("Enter the activity you did (w for walking, j for jogging, r for running): ");
    scanf(" %c", &activity);
    printf("Enter the duration of the workout (in minutes): ");
    scanf("%f", &duration);

    // Calculate workout data and display it to user
    struct Workout workout;
    workout.caloriesBurned = calculateCaloriesBurned(activity, duration);
    workout.distance = (activity == 'w') ? duration * 0.05 : ((activity == 'j') ? duration * 0.1 : duration * 0.15);
    workout.duration = duration;
    printf("\nWorkout data for %s:\n", user.name);
    displayWorkoutData(workout);

    return 0;
}