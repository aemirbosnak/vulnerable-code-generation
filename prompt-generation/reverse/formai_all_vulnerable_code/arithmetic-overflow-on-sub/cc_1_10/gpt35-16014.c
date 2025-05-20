//FormAI DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Function to perform addition with overflow check
int safe_addition(int x, int y)
{
    if (y > 0 && x > INT_MAX - y)
    {
        printf("Error: Addition would cause overflow!\n");
        exit(EXIT_FAILURE);
    }
    return x + y;
}

// Function to perform subtraction with overflow check
int safe_subtraction(int x, int y)
{
    if (y < 0 && x < INT_MIN - y)
    {
        printf("Error: Subtraction would cause overflow!\n");
        exit(EXIT_FAILURE);
    }
    return x - y;
}

// Function to perform multiplication with overflow check
int safe_multiplication(int x, int y)
{
    if (y > 0 && x > INT_MAX / y || y < 0 && x < INT_MAX / y)
    {
        printf("Error: Multiplication would cause overflow!\n");
        exit(EXIT_FAILURE);
    }
    return x * y;
}

// Function to perform division with check for division by zero
int safe_division(int x, int y)
{
    if (y == 0)
    {
        printf("Error: Division by zero attempted!\n");
        exit(EXIT_FAILURE);
    }
    return x / y;
}

int main()
{
    int num1, num2, sum, difference, product, quotient;

    printf("Enter two numbers to perform arithmetic operations (separated by spaces): ");
    scanf("%d %d", &num1, &num2);

    // Perform arithmetic operations with overflow and division checks
    sum = safe_addition(num1, num2);
    difference = safe_subtraction(num1, num2);
    product = safe_multiplication(num1, num2);
    quotient = safe_division(num1, num2);

    // Display the results
    printf("\nResults of arithmetic operations:\n");
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);
    printf("Quotient: %d\n", quotient);

    return 0;
}