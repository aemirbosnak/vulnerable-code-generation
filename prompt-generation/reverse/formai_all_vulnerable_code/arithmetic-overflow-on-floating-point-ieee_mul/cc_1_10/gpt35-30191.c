//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: brave
#include <stdio.h>

// Function to calculate BMI based on height and weight
float calculateBMI(float height, float weight){
    float BMI = weight / (height * height);
    return BMI;
}

// Function to calculate calorie requirement based on BMI, activity level, and weight goal
float calculateCalorieRequirement(float BMI, int activityLevel, float weightGoal){
    float BMR;
    if(BMI < 18.5) {
        BMR = 10 * weightGoal + 6.25 * 175 - 5 * 25 + 5;
    }
    else if(BMI >= 18.5 && BMI <= 24.9) {
        BMR = 10 * weightGoal + 6.25 * 175 - 5 * 25 + 5;
    }
    else if(BMI >= 25 && BMI <= 29.9) {
        BMR = 10 * weightGoal + 6.25 * 175 - 5 * 25 - 161;
    }
    else{
        BMR = 10 * weightGoal + 6.25 * 175 - 5 * 25 - 271;
    }
    float calorieRequirement = BMR * activityLevel;
    return calorieRequirement;
}

int main(){
    printf("Welcome to C Fitness Tracker\n");
    printf("Please enter your height in meters: ");
    float height;
    scanf("%f", &height);
    printf("\nPlease enter your weight in kilograms: ");
    float weight;
    scanf("%f", &weight);
    float BMI = calculateBMI(height, weight);
    printf("Your BMI is %f\n", BMI);

    printf("Please select your activity level:\n");
    printf("1- Sedentary\n");
    printf("2- Lightly Active\n");
    printf("3- Moderately Active\n");
    printf("4- Very Active\n");
    int activityLevel;
    scanf("%d", &activityLevel);

    printf("Please select your weight goal:\n");
    printf("1- Lose Weight\n");
    printf("2- Maintain Weight\n");
    printf("3- Gain Weight\n");
    float weightGoal;
    scanf("%f", &weightGoal);

    float calorieRequirement = calculateCalorieRequirement(BMI, activityLevel, weightGoal);
    printf("Your daily calorie requirement is %f", calorieRequirement);
    return 0;
}