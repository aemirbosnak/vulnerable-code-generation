//Code Llama-13B DATASET v1.0 Category: Fitness Tracker ; Style: creative
/*
 * C Fitness Tracker Example Program
 *
 * This program allows the user to track their daily fitness activities
 * such as running, cycling, and weightlifting. It also provides a
 * summary of their activity levels and fitness goals.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the user's fitness data
typedef struct {
    char name[50];
    float weight;
    float height;
    float bmi;
    float running_distance;
    float cycling_distance;
    float weightlifting_weight;
} UserData;

// Function to calculate the BMI of the user
float calculate_bmi(float weight, float height) {
    return weight / (height * height);
}

// Function to calculate the daily calorie intake of the user
int calculate_daily_calories(UserData *user) {
    return (user->weight * 24) + (user->height * 6.25);
}

// Function to calculate the user's activity level
int calculate_activity_level(UserData *user) {
    return (user->running_distance + user->cycling_distance + user->weightlifting_weight) * 5;
}

// Function to display the user's fitness data
void display_fitness_data(UserData *user) {
    printf("Name: %s\n", user->name);
    printf("Weight: %f\n", user->weight);
    printf("Height: %f\n", user->height);
    printf("BMI: %f\n", user->bmi);
    printf("Daily Calories: %d\n", calculate_daily_calories(user));
    printf("Activity Level: %d\n", calculate_activity_level(user));
}

int main() {
    UserData user;

    // Get the user's data
    printf("Enter your name: ");
    scanf("%s", user.name);
    printf("Enter your weight: ");
    scanf("%f", &user.weight);
    printf("Enter your height: ");
    scanf("%f", &user.height);

    // Calculate the user's BMI
    user.bmi = calculate_bmi(user.weight, user.height);

    // Get the user's fitness data
    printf("Enter your running distance: ");
    scanf("%f", &user.running_distance);
    printf("Enter your cycling distance: ");
    scanf("%f", &user.cycling_distance);
    printf("Enter your weightlifting weight: ");
    scanf("%f", &user.weightlifting_weight);

    // Display the user's fitness data
    display_fitness_data(&user);

    return 0;
}