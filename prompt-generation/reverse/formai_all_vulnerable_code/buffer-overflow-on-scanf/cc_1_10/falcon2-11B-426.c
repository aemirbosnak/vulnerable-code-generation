//Falcon2-11B DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the calories burned based on age, weight and activity level
double calculateCaloriesBurned(int age, double weight, int activityLevel) {
    double bmr = 66.47 + (13.75 * weight) + (5.003 * age) - (6.755 * age * age) + (6.775 * weight * age);
    double caloriesBurned = 0.0;
    if (activityLevel == 1) {
        caloriesBurned = bmr * 1.2;
    } else if (activityLevel == 2) {
        caloriesBurned = bmr * 1.375;
    } else if (activityLevel == 3) {
        caloriesBurned = bmr * 1.55;
    } else if (activityLevel == 4) {
        caloriesBurned = bmr * 1.725;
    } else if (activityLevel == 5) {
        caloriesBurned = bmr * 1.9;
    }
    return caloriesBurned;
}

// Function to calculate the BMI based on weight and height
double calculateBMI(double weight, double height) {
    double bmi = weight / (height * height);
    return bmi;
}

// Function to calculate the target heart rate based on age and activity level
double calculateTargetHeartRate(int age, int activityLevel) {
    double targetHeartRate = 0.0;
    if (activityLevel == 1) {
        targetHeartRate = (220 - age) * 0.85;
    } else if (activityLevel == 2) {
        targetHeartRate = (220 - age) * 0.8;
    } else if (activityLevel == 3) {
        targetHeartRate = (220 - age) * 0.75;
    } else if (activityLevel == 4) {
        targetHeartRate = (220 - age) * 0.65;
    } else if (activityLevel == 5) {
        targetHeartRate = (220 - age) * 0.55;
    }
    return targetHeartRate;
}

// Function to calculate the maximum heart rate based on age and activity level
double calculateMaxHeartRate(int age, int activityLevel) {
    double maxHeartRate = 0.0;
    if (activityLevel == 1) {
        maxHeartRate = (220 - age) * 0.9;
    } else if (activityLevel == 2) {
        maxHeartRate = (220 - age) * 0.85;
    } else if (activityLevel == 3) {
        maxHeartRate = (220 - age) * 0.8;
    } else if (activityLevel == 4) {
        maxHeartRate = (220 - age) * 0.75;
    } else if (activityLevel == 5) {
        maxHeartRate = (220 - age) * 0.7;
    }
    return maxHeartRate;
}

// Function to calculate the resting heart rate
double calculateRestingHeartRate(int age) {
    double restingHeartRate = 0.0;
    if (age >= 61 && age <= 70) {
        restingHeartRate = 60.0;
    } else if (age >= 51 && age <= 60) {
        restingHeartRate = 64.0;
    } else if (age >= 41 && age <= 50) {
        restingHeartRate = 70.0;
    } else if (age >= 31 && age <= 40) {
        restingHeartRate = 76.0;
    } else if (age >= 21 && age <= 30) {
        restingHeartRate = 83.0;
    } else if (age >= 11 && age <= 20) {
        restingHeartRate = 91.0;
    } else if (age >= 1 && age <= 10) {
        restingHeartRate = 105.0;
    } else {
        restingHeartRate = 85.0;
    }
    return restingHeartRate;
}

// Main function
int main() {
    // Input variables
    int age;
    double weight, height, activityLevel;

    // Get user input for age
    printf("Enter your age: ");
    scanf("%d", &age);

    // Get user input for weight and height
    printf("Enter your weight: ");
    scanf("%lf", &weight);
    printf("Enter your height: ");
    scanf("%lf", &height);

    // Get user input for activity level
    printf("Enter your activity level (1-5): ");
    scanf("%d", &activityLevel);

    // Calculate calories burned
    double caloriesBurned = calculateCaloriesBurned(age, weight, activityLevel);

    // Calculate BMI
    double bmi = calculateBMI(weight, height);

    // Calculate target heart rate
    double targetHeartRate = calculateTargetHeartRate(age, activityLevel);

    // Calculate max heart rate
    double maxHeartRate = calculateMaxHeartRate(age, activityLevel);

    // Calculate resting heart rate
    double restingHeartRate = calculateRestingHeartRate(age);

    // Display results
    printf("Age: %d\n", age);
    printf("Weight: %.2f\n", weight);
    printf("Height: %.2f\n", height);
    printf("Calories burned: %.2f\n", caloriesBurned);
    printf("BMI: %.2f\n", bmi);
    printf("Target heart rate: %.2f\n", targetHeartRate);
    printf("Max heart rate: %.2f\n", maxHeartRate);
    printf("Resting heart rate: %.2f\n", restingHeartRate);

    return 0;
}