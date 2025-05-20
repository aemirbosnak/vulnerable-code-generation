//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to calculate BMI
float calculate_bmi(float weight, float height) {
    float bmi = (weight / (height * height)) * 703;
    return bmi;
}

int main() {
    float weight, height, bmi;
    int age, steps, goal;
    bool is_goal_achieved = false;
    
    printf("Input your weight in pounds: ");
    scanf("%f", &weight);
    
    printf("Input your height in inches: ");
    scanf("%f", &height);
    
    printf("Input your age in years: ");
    scanf("%d", &age);
    
    printf("Input the number of steps you have taken today: ");
    scanf("%d", &steps);
    
    printf("Input your daily step goal: ");
    scanf("%d", &goal);
    
    bmi = calculate_bmi(weight, height);
    
    // Print user's BMI
    printf("\nYour BMI is %.2f\n", bmi);
    
    // Print user's fitness level based on BMI
    if (bmi < 18.5) {
        printf("You are underweight.\n");
    } else if (bmi >= 18.5 && bmi <= 24.9) {
        printf("You are normal weight.\n");
    } else if (bmi >= 25 && bmi <= 29.9) {
        printf("You are overweight.\n");
    } else {
        printf("You are obese.\n");
    }
    
    // Print user's progress towards their daily step goal
    printf("You have taken %d steps towards your goal of %d.\n", steps, goal);
    if (steps >= goal) {
        printf("Congratulations! You have achieved your goal for the day!\n");
        is_goal_achieved = true;
    } else {
        printf("Keep going! You still have %d steps to go to reach your goal.\n", goal - steps);
    }
    
    // Print user's recommended daily calorie intake
    int recommended_calories = 0;
    if (age >= 18 && age <= 30) {
        recommended_calories = 2400;
    } else if (age >= 31 && age <= 50) {
        recommended_calories = 2200;
    } else {
        recommended_calories = 2000;
    }
    printf("Your recommended daily calorie intake is %d calories.\n", recommended_calories);
    
    // Print user's progress towards their daily calorie intake goal
    int calories_consumed = 0;
    printf("Input the number of calories you have consumed today: ");
    scanf("%d", &calories_consumed);
    if (calories_consumed > recommended_calories) {
        printf("You have exceeded your recommended daily calorie intake.\n");
    } else {
        printf("You are still under your recommended daily calorie intake.\n");
    }
    
    // Print user's summary of today's fitness activities
    printf("\n----------------------\n");
    printf("Today's Summary\n");
    printf("----------------------\n");
    printf("BMI: %.2f\n", bmi);
    printf("Steps taken: %d\n", steps);
    printf("Calories consumed: %d\n", calories_consumed);
    if (is_goal_achieved) {
        printf("Congratulations! You have achieved your step goal for the day!\n");
    } else {
        printf("Keep going! You still have %d steps to go to reach your goal.\n", goal - steps);
    }
    if (calories_consumed > recommended_calories) {
        printf("You have exceeded your recommended daily calorie intake.\n");
    } else {
        printf("You are still under your recommended daily calorie intake.\n");
    }
    
    return 0;
}