//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: immersive
#include <stdio.h>

// Function to calculate Body Mass Index (BMI)
float calculateBMI(float height, float weight) {
    float bmi = weight / (height * height);
    return bmi;
}

// Function to calculate daily calories requirement based on activity level
float calculateDailyCalorieRequirement(float bmr, int activityLevel) {
    float dailyCalorieRequirement;
    switch(activityLevel) {
        case 1:
            dailyCalorieRequirement = bmr * 1.2;
            break;
        case 2:
            dailyCalorieRequirement = bmr * 1.375;
            break;
        case 3:
            dailyCalorieRequirement = bmr * 1.55;
            break;
        case 4:
            dailyCalorieRequirement = bmr * 1.725;
            break;
        case 5:
            dailyCalorieRequirement = bmr * 1.9;
            break;
        default:
            printf("Please enter a valid activity level\n");
            dailyCalorieRequirement = -1;
            break;
    }
    return dailyCalorieRequirement;
}

int main() {
    float height, weight, bmi, bmr, dailyCalorieRequirement;
    int age, gender, activityLevel;

    printf("Welcome to your Fitness Tracker!\n\n");
    printf("Please enter your height in meters: ");
    scanf("%f", &height);

    printf("\nPlease enter your weight in kilograms: ");
    scanf("%f", &weight);

    printf("\nPlease enter your age in years: ");
    scanf("%d", &age);

    printf("\nPlease enter your gender (1 for male, 2 for female): ");
    scanf("%d", &gender);

    printf("\nPlease enter your activity level (1 for sedentary, 2 for light exercise, 3 for moderate exercise, 4 for heavy exercise, 5 for very heavy exercise): ");
    scanf("%d", &activityLevel);

    // Calculate BMI
    bmi = calculateBMI(height, weight);
    printf("\nYour BMI is: %.2f\n", bmi);

    // Calculate Basal Metabolic Rate (BMR)
    if(gender == 1) {
        bmr = 88.362 + (13.397 * weight) + (4.799 * height * 100) - (5.677 * age);
    }
    else if(gender == 2) {
        bmr = 447.593 + (9.247 * weight) + (3.098 * height * 100) - (4.33 * age);
    }
    else {
        printf("Please enter a valid gender number\n");
        return 0;
    }

    printf("Your BMR is: %.2f\n", bmr);

    // Calculate Daily Calorie Requirement
    dailyCalorieRequirement = calculateDailyCalorieRequirement(bmr, activityLevel);

    if(dailyCalorieRequirement != -1) {
        printf("Your daily calorie requirement is: %.2f calories\n", dailyCalorieRequirement);
    }

    return 0;
}