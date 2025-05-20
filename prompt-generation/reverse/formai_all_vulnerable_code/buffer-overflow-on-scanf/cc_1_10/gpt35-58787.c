//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness tracker
typedef struct {
    char name[50];
    int age;
    double height;
    double weight;
    double maxHeartRate;
    double targetHeartRate;
    double bmi;
} FitnessTracker;

// Function to calculate the maximum heart rate
double calculateMaxHeartRate(int age) {
    return 220 - age;
}

// Function to calculate the target heart rate
double calculateTargetHeartRate(double maxHeartRate) {
    return 0.5 * maxHeartRate;
}

// Function to calculate the BMI
double calculateBMI(double height, double weight) {
    return weight / (height * height);
}

int main() {
    FitnessTracker user;

    printf("Welcome to the Fitness Tracker Program!\n\n");

    // Get user's personal information
    printf("Please enter your name: ");
    fgets(user.name, 50, stdin);
    printf("Please enter your age: ");
    scanf("%d", &user.age);
    printf("Please enter your height (m): ");
    scanf("%lf", &user.height);
    printf("Please enter your weight (kg): ");
    scanf("%lf", &user.weight);

    // Calculate the max heart rate, target heart rate, and BMI
    user.maxHeartRate = calculateMaxHeartRate(user.age);
    user.targetHeartRate = calculateTargetHeartRate(user.maxHeartRate);
    user.bmi = calculateBMI(user.height, user.weight);

    // Output the results
    printf("\n\n");
    printf("------------------------------------------------------\n");
    printf("PERSONAL INFORMATION\n");
    printf("Name: %s", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %.2lf m\n", user.height);
    printf("Weight: %.2lf kg\n", user.weight);
    printf("\n");
    printf("FITNESS TRACKER RESULTS\n");
    printf("Max Heart Rate: %.2lf bpm\n", user.maxHeartRate);
    printf("Target Heart Rate: %.2lf bpm\n", user.targetHeartRate);
    printf("BMI: %.2lf\n", user.bmi);
    printf("------------------------------------------------------\n");

    return 0;
}