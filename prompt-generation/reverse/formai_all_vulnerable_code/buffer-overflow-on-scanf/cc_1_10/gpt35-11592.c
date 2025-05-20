//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Initialization
    float weight, height, bmi;
    int age, steps;
    
    // Input
    printf("Welcome to your fitness tracker!\n");
    printf("Please enter your weight in kilograms:\n");
    scanf("%f", &weight);
    printf("Please enter your height in meters:\n");
    scanf("%f", &height);
    printf("Please enter your age in years:\n");
    scanf("%d", &age);
    printf("Please enter the number of steps you walked today:\n");
    scanf("%d", &steps);
    
    // BMI Calculation
    bmi = weight / (height * height);
    
    // Output
    printf("\n--- Fitness Report ---\n");
    printf("Your BMI: %.1f\n", bmi);
    if (bmi < 18.5)
    {
        printf("You are underweight.\n");
    }
    else if (bmi >= 18.5 && bmi < 25)
    {
        printf("You have a healthy weight.\n");
    }
    else if (bmi >= 25 && bmi < 30)
    {
        printf("You are overweight.\n");
    }
    else
    {
        printf("You are obese.\n");
    }
    
    printf("Your maximum heart rate: %d beats per minute.\n", 220 - age);
    printf("Your target heart rate zone: %.0f - %.0f beats per minute.\n", (220 - age) * 0.6, (220 - age) * 0.8);
    printf("You walked %d steps today.\n", steps);
    
    if (steps >= 10000)
    {
        printf("You achieved your goal for the day. Great job!\n");
    }
    else
    {
        printf("You still need to walk %d more steps to achieve your goal for the day.\n", 10000 - steps);
    }
    
    // End of Program
    printf("\nThank you for using your fitness tracker!\n");
    return 0;
}