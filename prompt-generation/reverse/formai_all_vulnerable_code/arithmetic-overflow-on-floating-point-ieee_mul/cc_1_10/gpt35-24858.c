//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length for user inputs
#define MAX_INPUT_LENGTH 100

// Declare the struct for the fitness tracker
typedef struct {
    char name[MAX_INPUT_LENGTH];
    int age;
    float weight;
    float height;
    char gender[MAX_INPUT_LENGTH];
    float bmi;
    float calories_per_day;
} fitness_tracker;

// Function to calculate the BMI of the user
void calculate_bmi(fitness_tracker *user) {
    user->bmi = user->weight / ((user->height / 100) * (user->height / 100));
}

// Main function
int main() {
    fitness_tracker user;

    // Get user inputs
    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name: ");
    fgets(user.name, MAX_INPUT_LENGTH, stdin);
    printf("Please enter your age: ");
    scanf("%d", &user.age);
    printf("Please enter your weight in kg: ");
    scanf("%f", &user.weight);
    printf("Please enter your height in cm: ");
    scanf("%f", &user.height);
    printf("Please enter your gender (male/female): ");
    scanf("%s", user.gender);

    // Calculate BMI and calories per day
    calculate_bmi(&user);
    if(strcmp(user.gender, "male") == 0) {
        user.calories_per_day = (10 * user.weight) + (6.25 * user.height) - (5 * user.age) + 5;
    } else {
        user.calories_per_day = (10 * user.weight) + (6.25 * user.height) - (5 * user.age) - 161;
    }

    // Print summary to user
    printf("\nThank you for providing your information. Here is a summary:\n");
    printf("Name: %s", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %.2f kg\n", user.weight);
    printf("Height: %.2f cm\n", user.height);
    printf("Gender: %s\n", user.gender);
    printf("BMI: %.2f\n", user.bmi);
    printf("Calories per day: %.2f\n", user.calories_per_day);

    return 0;
}