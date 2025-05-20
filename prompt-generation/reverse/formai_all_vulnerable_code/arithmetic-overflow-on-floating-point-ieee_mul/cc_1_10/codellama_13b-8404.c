//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: ultraprecise
/*
 * Fitness Tracker Example Program
 *
 * This program tracks the user's fitness progress by
 * prompting the user to enter their daily workouts and
 * calculating their total daily calorie burn.
 *
 * The program also allows the user to view their progress
 * over time and adjust their daily calorie intake.
 */

#include <stdio.h>
#include <stdlib.h>

// Struct to store user data
struct User {
    int age;
    float weight;
    float height;
    float daily_calories;
    float total_calories;
};

// Function to calculate the user's daily calorie burn
float calculate_calories(struct User user) {
    float met_value = 0;

    // Calculate the user's metabolic rate
    if (user.age >= 18 && user.age <= 40) {
        met_value = 1.2 * user.weight + 0.23 * user.height - 5.4;
    } else if (user.age > 40 && user.age <= 65) {
        met_value = 1.9 * user.weight + 0.32 * user.height - 1.5;
    } else {
        met_value = 1.9 * user.weight + 0.32 * user.height - 1.5;
    }

    // Calculate the user's daily calorie burn
    float daily_calories = met_value * 3500 / 24;

    return daily_calories;
}

// Function to prompt the user for their workout
void prompt_workout(struct User *user) {
    printf("Enter your workout (e.g. running, swimming, etc.): ");
    char workout[100];
    scanf("%s", workout);

    // Update the user's total calorie burn based on the workout
    if (strcmp(workout, "running") == 0) {
        user->total_calories += 120;
    } else if (strcmp(workout, "swimming") == 0) {
        user->total_calories += 180;
    } else {
        user->total_calories += 90;
    }
}

// Function to display the user's progress
void display_progress(struct User user) {
    printf("Age: %d\n", user.age);
    printf("Weight: %f\n", user.weight);
    printf("Height: %f\n", user.height);
    printf("Daily calories: %f\n", user.daily_calories);
    printf("Total calories: %f\n", user.total_calories);
}

// Function to adjust the user's daily calorie intake
void adjust_calories(struct User *user) {
    printf("Enter the number of calories you want to adjust by: ");
    int adjustment;
    scanf("%d", &adjustment);

    // Update the user's daily calorie intake
    user->daily_calories += adjustment;
}

int main() {
    // Create a new user
    struct User user;
    user.age = 0;
    user.weight = 0;
    user.height = 0;
    user.daily_calories = 0;
    user.total_calories = 0;

    // Prompt the user for their age, weight, and height
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your weight: ");
    scanf("%f", &user.weight);
    printf("Enter your height: ");
    scanf("%f", &user.height);

    // Calculate the user's daily calorie burn
    user.daily_calories = calculate_calories(user);

    // Prompt the user for their workout
    prompt_workout(&user);

    // Display the user's progress
    display_progress(user);

    // Adjust the user's daily calorie intake
    adjust_calories(&user);

    // Display the user's progress again
    display_progress(user);

    return 0;
}