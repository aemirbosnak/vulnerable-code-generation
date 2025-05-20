//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

double ultraprecise_calculator(double num1, double num2, char operator)
{
    double result = 0.0;
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
                printf("Error: Divide by zero is not allowed.\n");
                return -1;
            }
            result = num1 / num2;
            break;
    }

    return result;
}

int main()
{
    double num1 = 0.0;
    double num2 = 0.0;
    char operator = '\0';

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    double result = ultraprecise_calculator(num1, num2, operator);

    if (result == -1)
    {
        printf("Error: Invalid input.\n");
    }
    else
    {
        printf("The result is: %.10lf\n", result);
    }

    return 0;
}