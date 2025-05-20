//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int weight, height, age, gender, activity, bmr, tdee, choice, goal, protein, carbs, fat, cal_goal, cal_diff;
    char name[20];
    float bmr_multipliers[5] = {1.2, 1.375, 1.55, 1.725, 1.9}; // Activity Multiplier values

    printf("Welcome to the Fitness Tracker program!\n");
    printf("Please enter your name: ");
    scanf("%s", &name);

    // Getting user input for weight, height, age, gender and activity
    printf("Hello %s! Please enter your weight in pounds: ", name);
    scanf("%d", &weight);

    printf("Please enter your height in inches: ");
    scanf("%d", &height);

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your gender (Male = 1, Female = 2): ");
    scanf("%d", &gender);

    printf("Please enter your activity level: \n");
    printf("1. Sedentary\n");
    printf("2. Light Activity\n");
    printf("3. Moderate Activity\n");
    printf("4. Very Active\n");
    printf("5. Super Active\n");
    scanf("%d", &activity);

    // Calculating Basal Metabolic Rate (BMR) and Total Daily Energy Expenditure (TDEE)
    if (gender == 1) // Men Formula
    {
        bmr = 66 + (6.2 * weight) + (12.7 * height) - (6.76 * age);
        tdee = bmr * bmr_multipliers[activity - 1];
    }
    else if (gender == 2) // Women Formula
    {
        bmr = 655 + (4.35 * weight) + (4.7 * height) - (4.7 * age);
        tdee = bmr * bmr_multipliers[activity - 1];
    }

    // Displaying calculated BMR and TDEE values
    printf("\nYour Basal Metabolic Rate (BMR) is: %d Calories/day\n", bmr);
    printf("Your Total Daily Energy Expenditure (TDEE) is: %d Calories/day\n", tdee);

    // Letting user choose between gaining, losing or maintaining weight
    printf("\nWhat is your goal?\n");
    printf("1. I want to lose weight\n");
    printf("2. I want to maintain my weight\n");
    printf("3. I want to gain weight\n");
    scanf("%d", &goal);

    // Calculating macro-nutrient requirements based on user's goal
    if (goal == 1) // Losing weight
    {
        cal_goal = tdee - 500;
        protein = (weight * 0.8);
        fat = (weight * 0.3);
        carbs = (cal_goal - ((protein * 4) + (fat * 9))) / 4;
    }
    else if (goal == 2) // Maintaining weight
    {
        cal_goal = tdee;
        protein = (weight * 0.8);
        fat = (weight * 0.4);
        carbs = (cal_goal - ((protein * 4) + (fat * 9))) / 4;
    }
    else if (goal == 3) // Gaining weight
    {
        cal_goal = tdee + 500;
        protein = (weight * 0.8);
        fat = (weight * 0.5);
        carbs = (cal_goal - ((protein * 4) + (fat * 9))) / 4;
    }

    // Displaying calculated macro-nutrient requirements and goal calories
    printf("\nBased on your goal, you need to consume:\n");
    printf("Protein: %d grams\n", protein);
    printf("Fat: %d grams\n", fat);
    printf("Carbohydrates: %d grams\n", carbs);
    printf("Total daily calories to achieve your goal: %d\n", cal_goal);

    // Letting user input consumed calories and calculating calorie difference
    printf("\nDid you eat anything today? Please enter how many calories you consumed: ");
    scanf("%d", &choice);

    if (choice > 0)
    {
        cal_diff = cal_goal - choice;

        if (cal_diff > 0) // User is below goal
        {
            printf("\nYou have consumed %d calories today. You still need to consume %d more calories to reach your goal.\n", choice, cal_diff);
        }
        else if (cal_diff < 0) // User exceeded their goal
        {
            printf("\nYou have consumed %d calories today. You have exceeded your daily intake by %d calories.\n", choice, abs(cal_diff));
        }
        else // User reached their goal exactly
        {
            printf("\nCongratulations! You have reached your daily calorie goal.\n");
        }
    }
    else // User hasn't eaten yet
    {
        printf("You haven't eaten anything today. You need to consume %d more calories to reach your goal.\n", cal_goal);
    }

    return 0;
}