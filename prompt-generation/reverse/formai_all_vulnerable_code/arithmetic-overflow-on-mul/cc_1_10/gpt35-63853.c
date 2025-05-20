//FormAI DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>

// Custom functions for optimization
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int divide(int a, int b)
{
    return a / b;
}

int main()
{
    int num1, num2, choice, result;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("Select operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Enter choice (1-4): ");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            result = add(num1, num2);
            printf("%d + %d = %d", num1, num2, result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("%d - %d = %d", num1, num2, result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("%d x %d = %d", num1, num2, result);
            break;
        case 4:
            result = divide(num1, num2);
            printf("%d / %d = %d", num1, num2, result);
            break;
        default:
            printf("Invalid choice!");
    }

    return 0;
}