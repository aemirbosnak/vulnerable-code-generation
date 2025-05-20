//FormAI DATASET v1.0 Category: Math exercise ; Style: imaginative
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
int generateRandomNumber(int, int);
int calculateFactorial(int);
int main(void)
{
    int num1, num2, choice, result, answer, max, min, factorial;

    printf("Welcome to C Math Exercise Program!\n");

    while (1) // loop until exit
    {
        printf("\n** Main Menu **\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Factorial\n");
        printf("6. Random Number\n");
        printf("7. Exit\n");

        printf("\nEnter your choice (1-7): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter two numbers for addition: ");
            scanf("%d%d", &num1, &num2);
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;

        case 2:
            printf("\nEnter two numbers for subtraction: ");
            scanf("%d%d", &num1, &num2);
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;

        case 3:
            printf("\nEnter two numbers for multiplication: ");
            scanf("%d%d", &num1, &num2);
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;

        case 4:
            printf("\nEnter two numbers for division: ");
            scanf("%d%d", &num1, &num2);
            result = num1 / num2;
            printf("Result: %d\n", result);
            break;

        case 5:
            printf("\nEnter a number for factorial: ");
            scanf("%d", &num1);
            factorial = calculateFactorial(num1);
            printf("Result: %d\n", factorial);
            break;

        case 6:
            printf("\nEnter the minimum and maximum value for the random number: ");
            scanf("%d%d", &min, &max);
            result = generateRandomNumber(min, max);
            printf("Random Number: %d\n", result);
            break;

        case 7:
            printf("\nThanks for using our program\n");
            exit(0);
            break;

        default:
            printf("\nInvalid choice!\n");
        }
    }
    return 0;
}

// function to generate random number
int generateRandomNumber(int min, int max)
{
    srand(time(NULL)); // seed rand() with time
    return (rand() % (max - min + 1)) + min;
}

// function to calculate factorial
int calculateFactorial(int num)
{
    if (num == 0)
        return 1;

    int factorial = 1;
    for (int i = 1; i <= num; i++)
        factorial *= i;

    return factorial;
}