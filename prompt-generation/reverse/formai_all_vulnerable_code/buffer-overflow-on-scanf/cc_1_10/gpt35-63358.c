//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_OPERATIONS 100

double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double a, double b);
double square_root(double a);
double logarithm(double a);
double sine(double a);
double cosine(double a);
double tangent(double a);
void execute_operations(char operation, double *result);

int main()
{
    double result = 0;
    int num_operations = 0;
    char operation[MAX_OPERATIONS];

    printf("\nWelcome to the C Scientific Calculator!\n\n");
    printf("You can perform the following operations:\n");
    printf("+ : Addition\n");
    printf("- : Subtraction\n");
    printf("* : Multiplication\n");
    printf("/ : Division\n");
    printf("^ : Power\n");
    printf("sqrt : Square Root\n");
    printf("log : Natural Logarithm\n");
    printf("sin : Sine\n");
    printf("cos : Cosine\n");
    printf("tan : Tangent\n\n");

    while (1)
    {
        printf("Enter an operation (or q to quit): ");
        scanf("%s", operation);

        if (*operation == 'q')
        {
            printf("\nThank you for using the C Scientific Calculator!\n\n");
            break;
        }

        execute_operations(*operation, &result);
        num_operations++;
        printf("Result after %d operations: %lf\n\n", num_operations, result);
    }

    return 0;
}

double add(double a, double b)
{
    return a + b;
}

double subtract(double a, double b)
{
    return a - b;
}

double multiply(double a, double b)
{
    return a * b;
}

double divide(double a, double b)
{
    return a / b;
}

double power(double a, double b)
{
    return pow(a, b);
}

double square_root(double a)
{
    return sqrt(a);
}

double logarithm(double a)
{
    return log(a);
}

double sine(double a)
{
    return sin(a);
}

double cosine(double a)
{
    return cos(a);
}

double tangent(double a)
{
    return tan(a);
}

void execute_operations(char operation, double *result)
{
    double operand;

    switch (operation)
    {
        case '+':
            printf("Enter the number to add: ");
            scanf("%lf", &operand);
            *result = add(*result, operand);
            break;
        case '-':
            printf("Enter the number to subtract: ");
            scanf("%lf", &operand);
            *result = subtract(*result, operand);
            break;
        case '*':
            printf("Enter the number to multiply: ");
            scanf("%lf", &operand);
            *result = multiply(*result, operand);
            break;
        case '/':
            printf("Enter the number to divide: ");
            scanf("%lf", &operand);
            *result = divide(*result, operand);
            break;
        case '^':
            printf("Enter the power to raise by: ");
            scanf("%lf", &operand);
            *result = power(*result, operand);
            break;
        case 's':
            printf("Enter the number to find the square root of: ");
            scanf("%lf", &operand);
            *result = square_root(operand);
            break;
        case 'l':
            printf("Enter the number to find the natural logarithm of: ");
            scanf("%lf", &operand);
            *result = logarithm(operand);
            break;
        case 'n':
            printf("Enter the number to find the sine of: ");
            scanf("%lf", &operand);
            *result = sine(operand);
            break;
        case 'o':
            printf("Enter the number to find the cosine of: ");
            scanf("%lf", &operand);
            *result = cosine(operand);
            break;
        case 'a':
            printf("Enter the number to find the tangent of: ");
            scanf("%lf", &operand);
            *result = tangent(operand);
            break;
        default:
            printf("Invalid operation, please try again.\n");
    }
}