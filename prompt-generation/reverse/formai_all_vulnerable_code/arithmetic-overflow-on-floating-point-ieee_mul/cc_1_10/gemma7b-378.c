//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[20];
    int age;
    float height;
    int weight;
    float bmi;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your height (in cm): ");
    scanf("%f", &height);

    printf("Enter your weight (in kg): ");
    scanf("%d", &weight);

    bmi = (weight * 703) / (height * height);

    printf("Your name is: %s\n", name);
    printf("Your age is: %d\n", age);
    printf("Your height is: %.2f cm\n", height);
    printf("Your weight is: %d kg\n", weight);
    printf("Your BMI is: %.2f\n", bmi);

    if (bmi < 18.5)
    {
        printf("You are underweight.\n");
    }
    else if (bmi >= 18.5 && bmi < 25)
    {
        printf("You are at a healthy weight.\n");
    }
    else if (bmi >= 25 && bmi < 30)
    {
        printf("You are overweight.\n");
    }
    else
    {
        printf("You are obese.\n");
    }

    return 0;
}