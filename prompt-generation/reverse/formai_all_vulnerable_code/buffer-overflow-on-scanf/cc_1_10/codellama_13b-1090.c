//Code Llama-13B DATASET v1.0 Category: Error handling ; Style: protected
// Error handling example program in a protected style
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the factorial of a number
int factorial(int num)
{
    int result = 1;
    for (int i = 1; i <= num; i++)
        result *= i;
    return result;
}

// Function to handle errors
void handle_error(int error_code)
{
    switch (error_code)
    {
        case 0:
            printf("Error: Invalid input\n");
            break;
        case 1:
            printf("Error: Input out of range\n");
            break;
        case 2:
            printf("Error: Memory allocation failed\n");
            break;
        default:
            printf("Error: Unknown error\n");
            break;
    }
    exit(1);
}

int main()
{
    int num, result;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Check if the input is valid
    if (num < 0)
        handle_error(0);

    // Check if the input is within range
    if (num > 12)
        handle_error(1);

    // Calculate the factorial
    result = factorial(num);

    // Check if memory allocation failed
    if (result == -1)
        handle_error(2);

    // Print the result
    printf("Factorial of %d is %d\n", num, result);

    return 0;
}