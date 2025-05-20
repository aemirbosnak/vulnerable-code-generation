//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void main()
{
    int num1, num2, operator, result;
    char again, choice;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    switch (operator)
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
            if (num2 == 0)
            {
                printf("Cannot divide by zero.\n");
            }
            else
            {
                result = num1 / num2;
            }
            break;
        default:
            printf("Invalid operator.\n");
    }

    printf("The result is: %d\n", result);

    printf("Would you like to calculate again? (Y/N): ");
    scanf(" %c", &again);

    if (again == 'Y')
    {
        main();
    }
    else
    {
        printf("Thank you for using the calculator.\n");
    }
}