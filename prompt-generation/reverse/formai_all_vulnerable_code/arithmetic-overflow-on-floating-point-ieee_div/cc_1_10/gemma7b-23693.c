//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char name[20];
    int age;
    float height;
    float weight;

    printf("Enter your name:");
    scanf("%s", name);

    printf("Enter your age:");
    scanf("%d", &age);

    printf("Enter your height (in inches):");
    scanf("%f", &height);

    printf("Enter your weight (in pounds):");
    scanf("%f", &weight);

    // Calculate BMI (Body Mass Index)
    float bmi = (weight * 703) / (height * height);

    // Display BMI results
    printf("Your name is: %s", name);
    printf("\nYour age is: %d", age);
    printf("\nYour height is: %.2f inches", height);
    printf("\nYour weight is: %.2f pounds", weight);
    printf("\nYour BMI is: %.2f", bmi);

    // Determine BMI category
    char category;
    if (bmi < 18.5) {
        category = 'Underweight';
    } else if (bmi >= 18.5 && bmi < 25) {
        category = 'Normal';
    } else if (bmi >= 25 && bmi < 30) {
        category = 'Overweight';
    } else {
        category = 'Obese';
    }

    // Display BMI category
    printf("\nYour BMI category is: %s", category);

    return 0;
}