//FormAI DATASET v1.0 Category: Data validation ; Style: excited
#include <stdio.h>

int main()
{
    printf("Welcome to the data validation program in C!\n");

    int age;

    printf("Please enter your age: ");
    scanf("%d", &age);

    if(age >= 18)
    {
        printf("Congratulations! You are old enough to vote!\n");
    }
    else
    {
        printf("Sorry, you are not yet old enough to vote.\n");
    }

    float weight;

    printf("Please enter your weight in kilograms: ");
    scanf("%f", &weight);

    if(weight > 0 && weight < 500)
    {
        printf("Valid weight!\n");
    }
    else
    {
        printf("Invalid weight!\n");
    }

    char gender;

    printf("Please enter your gender (M/F/O): ");
    scanf(" %c", &gender);

    if(gender == 'M' || gender == 'F' || gender == 'O')
    {
        printf("Valid gender!\n");
    }
    else
    {
        printf("Invalid gender!\n");
    }

    printf("Thank you for using the data validation program in C. Have a great day!\n");

    return 0;
}