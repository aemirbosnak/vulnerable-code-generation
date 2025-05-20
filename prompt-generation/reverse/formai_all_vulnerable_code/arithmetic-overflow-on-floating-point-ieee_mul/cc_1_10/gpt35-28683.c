//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: cheerful
#include <stdio.h>
#include <stdbool.h>

int main()
{
    float weight, height, bmi;
    int age;
    bool isMale;

    printf("Welcome to the C Fitness Tracker!\n");
    printf("\nLet's log some fitness data!\n\n");

    printf("Please enter your weight in kilograms: ");
    scanf("%f", &weight);

    printf("Please enter your height in meters: ");
    scanf("%f", &height);

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your gender (0 for female and 1 for male): ");
    scanf("%d", &isMale);

    bmi = weight / (height * height);

    printf("\nYour BMI is: %f\n", bmi);

    if (bmi < 18.5)
    {
        printf("You are underweight.\n");
    }
    else if (bmi >= 18.5 && bmi <= 24.9)
    {
        printf("You are healthy.\n");
    }
    else if (bmi >= 25 && bmi <= 29.9)
    {
        printf("You are overweight.\n");
    }
    else
    {
        printf("You are obese.\n");
    }

    if (isMale)
    {
        int bmr = 66 + (13.7 * weight) + (5 * height * 100) - (6.8 * age);
        printf("\nYour Basal Metabolic Rate (BMR) is: %d calories/day\n", bmr);
    }
    else
    {
        int bmr = 655 + (9.6 * weight) + (1.8 * height * 100) - (4.7 * age);
        printf("\nYour Basal Metabolic Rate (BMR) is: %d calories/day\n", bmr);
    }

    printf("\nThank you for using the C Fitness Tracker!\n");

    return 0;
}