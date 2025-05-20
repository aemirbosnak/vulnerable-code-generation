//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number within given range
int rand_in_range(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Function to check if given number is prime or not
int is_prime(int num)
{
    if (num <= 1)
        return 0;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

// Function to perform arithmetic operations on two numbers
int arithmetic_operation(int num1, int num2, char operation)
{
    switch (operation)
    {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0)
            {
                printf("Error! Division by zero is not allowed.\n");
                exit(0);
            }
            return num1 / num2;
        default:
            printf("Invalid operation! Please enter correct operation.\n");
            exit(0);
    }
}

int main()
{
    srand(time(NULL));

    // Generating two random numbers between given range
    int num1 = rand_in_range(1, 100);
    int num2 = rand_in_range(1, 100);

    // Performing arithmetic operations on generated numbers
    int result;
    char operation;
    printf("Enter the arithmetic operation you want to perform (+, -, *, /): ");
    scanf("%c", &operation);
    switch (operation)
    {
        case '+':
            result = arithmetic_operation(num1, num2, '+');
            printf("Result: %d\n", result);
            break;
        case '-':
            result = arithmetic_operation(num1, num2, '-');
            printf("Result: %d\n", result);
            break;
        case '*':
            result = arithmetic_operation(num1, num2, '*');
            printf("Result: %d\n", result);
            break;
        case '/':
            result = arithmetic_operation(num1, num2, '/');
            printf("Result: %d\n", result);
            break;
        default:
            printf("Invalid operation! Please enter correct operation.\n");
            exit(0);
    }

    return 0;
}