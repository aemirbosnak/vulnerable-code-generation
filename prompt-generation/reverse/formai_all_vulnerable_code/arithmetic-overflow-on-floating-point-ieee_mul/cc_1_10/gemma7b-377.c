//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include <stdio.h>
#include <math.h>

double calculate(double num1, double num2, char operator)
{
    switch (operator)
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
                printf("Cannot divide by zero\n");
                return -1;
            }
            return num1 / num2;
        default:
            printf("Invalid operator\n");
            return -1;
    }
}

int main()
{
    double num1, num2;
    char operator;

    printf("Enter operator (+, -, *, /): ");
    scanf("%c", &operator);

    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    double result = calculate(num1, num2, operator);

    if (result == -1)
    {
        printf("Error\n");
    }
    else
    {
        printf("The result is: %.10lf\n", result);
    }

    return 0;
}