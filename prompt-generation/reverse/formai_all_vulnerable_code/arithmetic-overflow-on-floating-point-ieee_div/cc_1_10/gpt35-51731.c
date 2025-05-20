//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Function to calculate BMI
float calculate_bmi(float weight, float height) {
    float bmi = (weight / (height * height)) * 703.0;
    return bmi;
}

// Function to calculate calories burned based on activity type and duration in minutes
float calculate_calories_burned(int activity_type, int duration) {
    float calories_burned;
    switch(activity_type) {
        case 1:
            // Running - 10 calories burned per minute
            calories_burned = 10.0 * duration;
            break;
        case 2:
            // Cycling - 8 calories burned per minute
            calories_burned = 8.0 * duration;
            break;
        case 3:
            // Swimming - 12 calories burned per minute
            calories_burned = 12.0 * duration;
            break;
        default:
            calories_burned = 0.0;
            break;
    }
    return calories_burned;
}

int main() {
    // Accept user input for weight and height
    float weight, height;
    printf("Enter your weight in pounds: ");
    scanf("%f", &weight);
    printf("Enter your height in inches: ");
    scanf("%f", &height);

    // Calculate BMI
    float bmi = calculate_bmi(weight, height);
    printf("Your BMI is %.1f\n", bmi);

    // Accept user input for activity type and duration
    int activity_type, duration;
    printf("Enter activity type:\n1. Running\n2. Cycling\n3. Swimming\n");
    scanf("%d", &activity_type);
    printf("Enter duration in minutes: ");
    scanf("%d", &duration);

    // Calculate calories burned
    float calories_burned = calculate_calories_burned(activity_type, duration);
    printf("You burned %.1f calories\n", calories_burned);

    return 0;
}