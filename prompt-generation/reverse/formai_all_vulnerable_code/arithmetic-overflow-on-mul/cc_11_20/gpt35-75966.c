//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int age, weight, height, BMI, BMR, choice;
    char name[20];

    printf("Welcome to the Fitness Tracker! \n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("\nHello %s, please enter your age: ", name);
    scanf("%d", &age);

    printf("\nPlease enter your weight (in kg): ");
    scanf("%d", &weight);

    printf("\nPlease enter your height (in cm): ");
    scanf("%d", &height);

    printf("\nChoose an option: \n");
    printf("1. Calculate BMI\n");
    printf("2. Calculate BMR\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            BMI = weight / ((height/100.0) * (height/100.0));
            printf("\nYour BMI is %d\n", BMI);
            if(BMI < 18.5)
                printf("You are underweight\n");
            else if(BMI >= 18.5 && BMI <= 24.9)
                printf("You are healthy\n");
            else if(BMI >= 25.0 && BMI <= 29.9)
                printf("You are overweight\n");
            else
                printf("You have obesity\n");
            break;

        case 2:
            if(age <= 0 || weight <= 0 || height <= 0)
                printf("\nInvalid input. Please enter valid values for age, weight and height\n");
            else
            {
                if(age < 18)
                    BMR = 10 * weight + 6.25 * height - 5 * age + 5;
                else if(age >= 18 && age <= 30)
                    BMR = 15 * weight + 7.5 * height - 6.8 * age + 450;
                else if(age >= 31 && age <= 60)
                    BMR = 13.5 * weight + 5 * height - 6.8 * age + 660;
                else
                    BMR = 10 * weight + 6.25 * height - 5 * age - 161;

                printf("\nYour BMR is %d calories/day\n", BMR);
                printf("\nTo maintain your weight, you should consume %.2f calories/day.\n", BMR * 1.2);
                printf("\nTo lose weight, you should consume %.2f calories/day.\n", BMR * 0.8);
                printf("\nTo gain weight, you should consume %.2f calories/day.\n", BMR * 1.5);
            }
            break;

        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
    }

    return 0;
}