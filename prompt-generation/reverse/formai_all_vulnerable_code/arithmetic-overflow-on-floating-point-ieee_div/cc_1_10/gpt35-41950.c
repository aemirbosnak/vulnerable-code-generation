//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age, gender;
    float height, weight, bmi;

    printf("Welcome to the Fitness Tracker! Please answer the following questions.\n");
    printf("What is your age? ");
    scanf("%d", &age);
    printf("What is your gender? (1 for male, 2 for female): ");
    scanf("%d", &gender);
    printf("What is your height (in meters)? ");
    scanf("%f", &height);
    printf("What is your weight (in kilograms)? ");
    scanf("%f", &weight);

    bmi = weight / (height * height);

    printf("\nYour BMI is: %.2f\n", bmi);

    if (bmi < 18.5)
    {
        printf("You are underweight.\n");
    }
    else if (bmi >= 18.5 && bmi < 24.9)
    {
        printf("You are at a healthy weight.\n");
    }
    else if (bmi >= 24.9 && bmi < 29.9)
    {
        printf("You are overweight.\n");
    }
    else
    {
        printf("You are obese.\n");
    }

    if (gender == 1)
    {
        float bmr1 = 88.362 + (13.397 * weight) + (4.799 * height * 100) - (5.677 * age);
        printf("Your Basal Metabolic Rate (BMR) is: %.2f\n", bmr1);
    }
    else if(gender == 2)
    {
        float bmr2 = 447.593 + (9.247 * weight) + (3.098 * height * 100) - (4.330 * age);
        printf("Your Basal Metabolic Rate (BMR) is: %.2f\n", bmr2);
    }

    return 0;
}