//FormAI DATASET v1.0 Category: Scientific Calculator Implementation ; Style: multiplayer
// Include necessary libraries
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define function prototypes
double add(double x, double y);
double subtract(double x, double y);
double multiply(double x, double y);
double divide(double x, double y);

// Define main function
int main()
{
    // Initialize variables
    double x, y, result;
    char operator;

    // Get input from players
    printf("Player 1, enter a mathematical expression: ");
    scanf("%lf %c %lf", &x, &operator, &y);
    printf("Player 2, enter a mathematical expression: ");
    scanf("%lf %c %lf", &x, &operator, &y);

    // Perform calculations
    switch(operator)
    {
        case '+':
            result = add(x, y);
            break;
        case '-':
            result = subtract(x, y);
            break;
        case '*':
            result = multiply(x, y);
            break;
        case '/':
            result = divide(x, y);
            break;
        default:
            printf("Error: Invalid operator");
            break;
    }

    // Display results to all players
    printf("Result: %lf\n", result);

    // End program
    return 0;
}

// Define function for addition
double add(double x, double y)
{
    return x + y;
}

// Define function for subtraction
double subtract(double x, double y)
{
    return x - y;
}

// Define function for multiplication
double multiply(double x, double y)
{
    return x * y;
}

// Define function for division
double divide(double x, double y)
{
    return x / y;
}