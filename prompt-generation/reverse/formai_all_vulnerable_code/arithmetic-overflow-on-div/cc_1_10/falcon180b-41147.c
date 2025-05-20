//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num1, num2, result, operator;
    char op;

    printf("Welcome to the Arithmetic Calculator!\n");

    srand(time(0));
    int random_num1 = rand() % 100;
    int random_num2 = rand() % 100;

    printf("You have been assigned two numbers: %d and %d\n", random_num1, random_num2);

    printf("Enter the arithmetic operator you want to use (+, -, *, /): ");
    scanf("%c", &op);

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    switch(op)
    {
        case '+':
            result = num1 + num2;
            printf("The result is: %d\n", result);
            break;

        case '-':
            result = num1 - num2;
            printf("The result is: %d\n", result);
            break;

        case '*':
            result = num1 * num2;
            printf("The result is: %d\n", result);
            break;

        case '/':
            if(num2 == 0)
            {
                printf("Error: Division by zero!\n");
            }
            else
            {
                result = num1 / num2;
                printf("The result is: %d\n", result);
            }
            break;

        default:
            printf("Error: Invalid operator!\n");
            break;
    }

    return 0;
}