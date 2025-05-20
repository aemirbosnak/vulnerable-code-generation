//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    // Variables to hold user input
    int age, weight, height;

    // Variable to hold user's gender
    char gender;

    // Variables to store calculated values
    int bmr, tdee, recommended_calories;

    // Prompt user for input
    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your weight in kg: ");
    scanf("%d", &weight);

    printf("Enter your height in cm: ");
    scanf("%d", &height);

    printf("Enter your gender (M/F): ");
    scanf(" %c", &gender);

    // Calculate basal metabolic rate (BMR)
    if (gender == 'M') 
    {
        bmr = 88.362 + (13.397 * weight) + (4.799 * height) - (5.677 * age);
    } 
    else if (gender == 'F')
    {
        bmr = 447.593 + (9.247 * weight) + (3.098 * height) - (4.330 * age);
    }

    // Calculate total daily energy expenditure (TDEE)
    int activity_level;
    printf("\nSelect your activity level:\n1. Sedentary (little or no exercise)\n2. Lightly active (exercise 1-2 times/week)\n3. Moderately active (exercise 3-4 times/week)\n4. Very active (exercise 5-7 times/week)\n5. Super active (very hard exercise or sports)\n");
    scanf("%d", &activity_level);

    switch (activity_level)
    {
        case 1:
            tdee = bmr * 1.2;
            break;
        case 2:
            tdee = bmr * 1.375;
            break;
        case 3:
            tdee = bmr * 1.55;
            break;
        case 4:
            tdee = bmr * 1.725;
            break;
        case 5:
            tdee = bmr * 1.9;
            break;
        default:
            printf("Invalid input. Please select an activity level between 1-5.\n");
            return 1;
    }

    // Generate recommended calorie intake for weight gain or loss
    int goal;
    printf("\nSelect your goal:\n1. Lose weight\n2. Maintain weight\n3. Gain weight\n");
    scanf("%d", &goal);

    switch (goal)
    {
        case 1:
            recommended_calories = tdee - 500;
            break;
        case 2:
            recommended_calories = tdee;
            break;
        case 3:
            recommended_calories = tdee + 500;
            break;
        default:
            printf("Invalid input. Please select a goal between 1-3.\n");
            return 1;
    }

    // Generate a sample workout plan
    printf("\nHere is a sample workout plan:\n");

    // Seed random number generator
    srand(time(NULL));

    // Generate 5 random exercises
    char exercises[5][20] = {"Push-ups", "Squats", "Lunges", "Burpees", "Sit-ups"};
    for (int i = 0; i < 5; i++)
    {
        printf("%d. %s - %d sets of %d reps\n", i+1, exercises[rand() % 5], rand() % 4 + 2, rand() % 10 + 6);
    }

    // Print out recommended calorie intake
    printf("\nYour recommended calorie intake is: %d calories/day\n", recommended_calories);

    return 0;
}