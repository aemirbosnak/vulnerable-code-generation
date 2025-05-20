//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define variables
    char name[20];
    int age;
    float height;
    int weight;
    float bmi;

    // Get user input
    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your height (in inches): ");
    scanf("%f", &height);

    printf("Enter your weight (in pounds): ");
    scanf("%d", &weight);

    // Calculate BMI
    bmi = (weight * 703) / (height * height);

    // Display results
    printf("Hello, %s! Your BMI is %.2f.", name, bmi);

    if (bmi < 18.5)
    {
        printf("You are underweight.");
    }
    else if (bmi >= 18.5 && bmi < 25)
    {
        printf("You are at a healthy weight.");
    }
    else if (bmi >= 25 && bmi < 30)
    {
        printf("You are overweight.");
    }
    else
    {
        printf("You are obese.");
    }

    // End program
    return 0;
}