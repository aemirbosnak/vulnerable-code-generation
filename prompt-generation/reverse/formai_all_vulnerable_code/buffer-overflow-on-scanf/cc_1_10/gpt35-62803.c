//FormAI DATASET v1.0 Category: Math exercise ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function prototypes
int generateRandomNumber(int lowerBound, int upperBound);
int calculateFactorial(int num);

int main()
{
    int num1, num2, choice, result;
    char replay;

    // display welcome message
    printf("Welcome to the visionary Math exercise program!\n");

    do
    {
        // generate two random numbers between 1 and 20
        num1 = generateRandomNumber(1, 20);
        num2 = generateRandomNumber(1, 20);

        // display the menu
        printf("\nChoose the Math problem that you would like to solve:\n");
        printf("1. Addition of %d and %d\n", num1, num2);
        printf("2. Subtraction of %d from %d\n", num1, num2);
        printf("3. Multiplication of %d and %d\n", num1, num2);
        printf("4. Division of %d by %d\n", num1, num2);
        printf("5. Factorial of %d\n", num1);

        // get the user's choice
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // perform the selected operation
        switch(choice)
        {
            case 1:
                result = num1 + num2;
                printf("The sum of %d and %d is %d.\n", num1, num2, result);
                break;

            case 2:
                result = num2 - num1;
                printf("The difference between %d and %d is %d.\n", num2, num1, result);
                break;

            case 3:
                result = num1 * num2;
                printf("The product of %d and %d is %d.\n", num1, num2, result);
                break;

            case 4:
                if(num1 == 0)
                {
                    printf("Cannot divide by zero. Try again.\n");
                }
                else
                {
                    result = num2 / num1;
                    printf("%d divided by %d is %d.\n", num2, num1, result);
                }
                break;

            case 5:
                result = calculateFactorial(num1);
                printf("The factorial of %d is %d.\n", num1, result);
                break;

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }

        // ask the user if they want to play again
        printf("Do you want to play again? [y/n]: ");
        fflush(stdin);
        scanf("%c", &replay);

    }while(replay == 'y' || replay == 'Y');

    // display exit message
    printf("Thank you for playing the visionary Math exercise program. Goodbye!\n");

    return 0;
}

// function to generate a random number between a lower bound and an upper bound
int generateRandomNumber(int lowerBound, int upperBound)
{
    int num;
    srand(time(0));
    num = (rand() % (upperBound - lowerBound + 1)) + lowerBound;
    return num;
}

// function to calculate the factorial of a number
int calculateFactorial(int num)
{
    int result = 1;
    for(int i = 1; i <= num; i++)
    {
        result *= i;
    }
    return result;
}