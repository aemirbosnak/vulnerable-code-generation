//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main() {
    int age, height, weight;
    char gender;
    float BMR, TDEE;

    // Greet the user and ask for their details
    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your height in cm: ");
    scanf("%d", &height);
    printf("Please enter your weight in kg: ");
    scanf("%d", &weight);
    printf("Please enter your gender (m/f): ");
    scanf(" %c", &gender);

    // Calculate BMR and TDEE based on user details
    if (gender == 'm') {
        BMR = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    } else {
        BMR = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    }
    printf("Your Basal Metabolic Rate (BMR) is: %.2f\n", BMR);

    // Ask for user's activity level and calculate TDEE
    int activity;
    printf("Please choose your activity level from the following:\n");
    printf("1. Sedentary (little or no exercise)\n");
    printf("2. Lightly active (light exercise/sports 1-3 days/week)\n");
    printf("3. Moderately active (moderate exercise/sports 3-5 days/week)\n");
    printf("4. Very active (hard exercise/sports 6-7 days/week)\n");
    printf("5. Super active (very hard exercise/sports, physical job or training twice a day)\n");
    scanf("%d", &activity);

    switch (activity) {
        case 1:
            TDEE = BMR * 1.2;
            break;
        case 2:
            TDEE = BMR * 1.375;
            break;
        case 3:
            TDEE = BMR * 1.55;
            break;
        case 4:
            TDEE = BMR * 1.725;
            break;
        case 5:
            TDEE = BMR * 1.9;
            break;
        default:
            printf("Invalid input\n");
            exit(0);
    }
    printf("Your Total Daily Energy Expenditure (TDEE) is: %.2f\n", TDEE);

    // Ask user for their calorie goals and recommend calorie deficit/surplus
    int goal;
    printf("Please choose your calorie goal from the following:\n");
    printf("1. Lose weight (calorie deficit)\n");
    printf("2. Maintain weight (no calorie change)\n");
    printf("3. Gain weight (calorie surplus)\n");
    scanf("%d", &goal);

    switch (goal) {
        case 1:
            printf("To lose weight, you should eat %.0f calories per day.\n", TDEE - 500);
            break;
        case 2:
            printf("To maintain weight, you should eat %.0f calories per day.\n", TDEE);
            break;
        case 3:
            printf("To gain weight, you should eat %.0f calories per day.\n", TDEE + 500);
            break;
        default:
            printf("Invalid input\n");
            exit(0);
    }

    return 0;
}