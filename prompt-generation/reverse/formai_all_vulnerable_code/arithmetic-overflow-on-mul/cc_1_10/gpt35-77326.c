//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Function to calculate body mass index (BMI)
float calcBMI(float weight, float height)
{
    float bmi = weight / (height * height);
    return bmi;
}

// Function to calculate daily calorie intake
int calcCalorieIntake(int age, char gender, float weight, float height, int activityLevel)
{
    int calorieIntake;

    if (gender == 'M') 
    {
        calorieIntake = (int)((10 * weight) + (6.25 * height * 100) - (5 * age) + 5) * activityLevel;
    }
    else if (gender == 'F')
    {
        calorieIntake = (int)((10 * weight) + (6.25 * height * 100) - (5 * age) - 161) * activityLevel;
    }

    return calorieIntake;
}

int main()
{
    float weight, height;
    int age, activityLevel, calorieIntake;
    char gender;

    printf("Welcome to the Fitness Tracker!\n");

    printf("Please enter your weight in kilograms (kg): ");
    scanf("%f", &weight);

    printf("Please enter your height in meters (m): ");
    scanf("%f", &height);

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your gender (M/F): ");
    scanf(" %c", &gender);

    printf("Please enter your activity level (1 = sedentary, 2 = lightly active, 3 = moderately active, 4 = very active): ");
    scanf("%d", &activityLevel);

    // Calculate BMI
    float bmi = calcBMI(weight, height);
    printf("Your BMI is %.1f\n", bmi);

    // Calculate daily calorie intake
    calorieIntake = calcCalorieIntake(age, gender, weight, height, activityLevel);

    printf("Your daily calorie intake should be %d calories.\n", calorieIntake);

    printf("Thank you for using the Fitness Tracker!\n");

    return 0;
}