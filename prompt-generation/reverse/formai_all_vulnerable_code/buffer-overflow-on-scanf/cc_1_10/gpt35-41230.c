//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: unmistakable
#include <stdio.h>

// Function to calculate BMI
float calculate_BMI(float weight, float height) {
    float BMI = weight / (height * height);
    return BMI;
}

// Function to calculate BMR
float calculate_BMR(float weight, float height, int age, char gender) {
    float BMR;
    
    if (gender == 'M') {
        BMR = 88.36 + (13.4 * weight) + (4.8 * height * 100) - (5.7 * age);
    } else {
        BMR = 447.6 + (9.2 * weight) + (3.1 * height * 100) - (4.3 * age);
    }
    
    return BMR;
}

// Function to calculate daily calorie requirement
float calculate_daily_calorie_requirement(float BMR, char activity_level) {
    float daily_calorie_requirement;
    
    if (activity_level == 'S') {
        daily_calorie_requirement = BMR * 1.2;
    } else if (activity_level == 'L') {
        daily_calorie_requirement = BMR * 1.55;
    } else {
        daily_calorie_requirement = BMR * 1.9;
    }
    
    return daily_calorie_requirement;
}

int main() {
    float weight, height, BMI, BMR, daily_calorie_requirement;
    int age;
    char gender, activity_level;
    
    // Get user input
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    printf("Enter your age in years: ");
    scanf("%d", &age);
    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);
    printf("Select your activity level\n");
    printf("S - Sedentary\t L - Lightly Active\t A - Active: ");
    scanf(" %c", &activity_level);
    
    // Calculate BMI
    BMI = calculate_BMI(weight, height);
    printf("Your BMI is %.2f\n", BMI);
    
    // Calculate BMR
    BMR = calculate_BMR(weight, height, age, gender);
    printf("Your BMR is %.2f\n", BMR);
    
    // Calculate daily calorie requirement
    daily_calorie_requirement = calculate_daily_calorie_requirement(BMR, activity_level);
    printf("Your daily calorie requirement is %.2f calories\n", daily_calorie_requirement);
    
    return 0;
}