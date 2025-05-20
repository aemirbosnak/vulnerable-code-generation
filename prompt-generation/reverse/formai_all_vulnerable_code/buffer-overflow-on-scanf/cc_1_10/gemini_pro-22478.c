//GEMINI-pro DATASET v1.0 Category: Fitness Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store user data
typedef struct user {
    char name[50];
    int age;
    float height;
    float weight;
    int goalSteps;
} User;

// Structure to store step data
typedef struct stepData {
    int stepsTaken;
    int distanceTraveled;
    int caloriesBurned;
} StepData;

// Function to create a new user
User* createUser() {
    User* user = (User*)malloc(sizeof(User));

    // Get user input
    printf("Enter your name: ");
    scanf("%s", user->name);

    printf("Enter your age: ");
    scanf("%d", &user->age);

    printf("Enter your height (in inches): ");
    scanf("%f", &user->height);

    printf("Enter your weight (in pounds): ");
    scanf("%f", &user->weight);

    printf("Enter your goal number of steps per day: ");
    scanf("%d", &user->goalSteps);

    return user;
}

// Function to create a new step data entry
StepData* createStepData() {
    StepData* stepData = (StepData*)malloc(sizeof(StepData));

    // Get step data input
    printf("Enter the number of steps you have taken: ");
    scanf("%d", &stepData->stepsTaken);

    stepData->distanceTraveled = stepData->stepsTaken * 2.5; // Assuming an average step length of 2.5 feet
    stepData->caloriesBurned = stepData->stepsTaken * 0.05; // Assuming an average of 0.05 calories burned per step

    return stepData;
}

// Function to print the user's data
void printUserData(User* user) {
    printf("\nUser Data:\n");
    printf("Name: %s\n", user->name);
    printf("Age: %d\n", user->age);
    printf("Height: %.2f inches\n", user->height);
    printf("Weight: %.2f pounds\n", user->weight);
    printf("Goal number of steps per day: %d\n", user->goalSteps);
}

// Function to print the step data
void printStepData(StepData* stepData) {
    printf("\nStep Data:\n");
    printf("Steps taken: %d\n", stepData->stepsTaken);
    printf("Distance traveled: %.2f miles\n", stepData->distanceTraveled);
    printf("Calories burned: %.2f\n", stepData->caloriesBurned);
}

// Main function
int main() {
    // Create a new user
    User* user = createUser();

    // Create a new step data entry
    StepData* stepData = createStepData();

    // Print the user's data
    printUserData(user);

    // Print the step data
    printStepData(stepData);

    return 0;
}