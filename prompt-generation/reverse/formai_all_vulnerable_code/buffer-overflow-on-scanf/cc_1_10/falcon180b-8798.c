//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Function to generate random numbers
int randnum(int max)
{
    return rand() % max;
}

int main()
{
    int num1, num2, result;
    char operator;

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Prompt the user to enter two numbers
    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Prompt the user to enter an arithmetic operator
    printf("Enter an arithmetic operator (+, -, *, /): ");
    scanf(" %c", &operator);

    // Perform the arithmetic operation based on the user's input
    switch(operator)
    {
        case '+':
            result = num1 + num2;
            break;

        case '-':
            result = num1 - num2;
            break;

        case '*':
            result = num1 * num2;
            break;

        case '/':
            if(num2 == 0)
            {
                printf("Error: Division by zero is not allowed.\n");
                exit(0);
            }
            else
            {
                result = num1 / num2;
            }
            break;

        default:
            printf("Error: Invalid operator entered.\n");
            exit(0);
    }

    // Display the result of the arithmetic operation
    printf("The result is: %d\n", result);

    return 0;
}