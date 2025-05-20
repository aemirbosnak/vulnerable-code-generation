//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define structures for user data
typedef struct {
    char name[50];
    int age;
    float height;
    float weight;
    float bmi;
    int steps;
} User;

typedef struct {
    User user;
    float distance;
    float calories;
} Workout;

// Function to calculate BMI
float calculateBMI(float height, float weight) {
    return (weight / (height * height));
}

// Function to calculate distance based on steps and stride length
float calculateDistance(int steps, float strideLength) {
    return (steps * strideLength);
}

// Function to calculate calories burned based on distance and weight
float calculateCalories(float distance, float weight) {
    return (0.0175 * weight * distance);
}

// Function to print user data
void printUserData(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %f\n", user.height);
    printf("Weight: %f\n", user.weight);
    printf("BMI: %f\n", user.bmi);
    printf("Steps: %d\n", user.steps);
}

// Function to print workout data
void printWorkoutData(Workout workout) {
    printf("User Data:\n");
    printUserData(workout.user);
    printf("Distance: %f\n", workout.distance);
    printf("Calories: %f\n", workout.calories);
}

// Main function
int main() {
    // Initialize user data
    User user = {"John", 25, 1.8, 75, 0, 0};

    // Initialize workout data
    Workout workout = {user, 0, 0};

    // Prompt user for step count
    printf("Enter step count: ");
    scanf("%d", &workout.user.steps);

    // Prompt user for stride length
    printf("Enter stride length (in meters): ");
    scanf("%f", &workout.distance);

    // Calculate BMI
    workout.user.bmi = calculateBMI(user.height, user.weight);

    // Calculate calories burned
    workout.calories = calculateCalories(workout.distance, user.weight);

    // Print workout data
    printWorkoutData(workout);

    return 0;
}