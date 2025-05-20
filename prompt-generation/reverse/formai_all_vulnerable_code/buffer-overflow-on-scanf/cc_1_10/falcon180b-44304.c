//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 1000000

// Define the precision threshold
#define THRESHOLD 0.0001

// Define the function to calculate the square root
double sqrt(double x)
{
    double result = 1.0;
    double temp;
    int iterations = 0;

    // Newton's method for calculating the square root
    while (iterations < MAX_ITERATIONS && fabs(result * result - x) > THRESHOLD)
    {
        temp = (result + x / result) / 2.0;
        result = temp;
        iterations++;
    }

    return result;
}

int main()
{
    double num;

    // Get the input number from the user
    printf("Enter a positive number: ");
    scanf("%lf", &num);

    // Check if the input number is positive
    if (num <= 0)
    {
        printf("Error: Input number must be positive.\n");
        return 1;
    }

    // Calculate the square root of the input number
    double result = sqrt(num);

    // Print the result
    printf("Square root of %.2lf is %.2lf\n", num, result);

    return 0;
}