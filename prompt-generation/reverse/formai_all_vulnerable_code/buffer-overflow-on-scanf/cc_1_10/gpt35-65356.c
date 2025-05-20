//FormAI DATASET v1.0 Category: Arithmetic ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));     //to generate a different set of random numbers each time program runs
    int num1 = rand() % 100;    //to generate a random number from 0-99
    int num2 = rand() % 100;

    printf("Welcome to Retro Calculator!\n\n");
    printf("Press 1 for Addition\nPress 2 for Subtraction\nPress 3 for Multiplication\nPress 4 for Division\n\n");

    int choice;
    scanf("%d", &choice);

    switch(choice)
    {
        case 1: //Addition
        {
            printf("\n\nLet's add %d and %d:\n", num1, num2);
            int result = num1 + num2;
            printf("%d + %d = %d", num1, num2, result);
            break;
        }
        case 2: //Subtraction
        {
            printf("\n\nLet's subtract %d from %d:\n", num2, num1);
            int result = num1 - num2;
            printf("%d - %d = %d", num1, num2, result);
            break;
        }
        case 3: //Multiplication
        {
            printf("\n\nLet's multiply %d and %d:\n", num1, num2);
            int result = num1 * num2;
            printf("%d * %d = %d", num1, num2, result);
            break;
        }
        case 4: //Division
        {
            if(num2==0)     //to avoid division by zero error
            {
                printf("\n\nInvalid input: Cannot divide by 0");
                break;
            }
            printf("\n\nLet's divide %d by %d:\n", num1, num2);
            float result = (float)num1 / num2;     //typecasting to float to get decimal values
            printf("%d / %d = %f", num1, num2, result);
            break;
        }
        default:
        {
            printf("\n\nInvalid input: Please choose 1, 2, 3 or 4");
        }
    }

    return 0;
}