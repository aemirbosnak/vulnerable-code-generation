//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MIN_VALUE 1e-9
#define PI 3.14159
#define EULER 2.71828

int main() {
    int num1, num2, sum, diff, mult, div;
    float avg, max, min, temp;
    char str[10];

    // Initialize variables
    num1 = 0;
    num2 = 0;
    sum = 0;
    diff = 0;
    mult = 0;
    div = 0;
    avg = 0;
    max = 0;
    min = 0;

    // Get two numbers from user
    printf("Enter two numbers: ");
    scanf("%d%d", &num1, &num2);

    // Calculate sum, difference, product, and quotient
    sum = num1 + num2;
    diff = num1 - num2;
    mult = num1 * num2;
    div = num1 / num2;

    // Calculate average
    avg = (sum + diff) / 2;

    // Calculate maximum and minimum values
    max = (num1 > num2) ? num1 : num2;
    min = (num1 < num2) ? num1 : num2;

    // Print results
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
    printf("Product: %f\n", mult);
    printf("Quotient: %f\n", div);
    printf("Average: %f\n", avg);
    printf("Maximum: %d\n", max);
    printf("Minimum: %d\n", min);

    // Get user input to convert to floating-point numbers
    printf("Enter a floating-point number (e.g. 3.14): ");
    scanf("%f", &temp);

    // Convert user input to floating-point number
    avg = (float) temp;

    // Print results in floating-point format
    printf("Average: %f\n", avg);

    // Get user input to check for Euler's identity
    printf("Enter a number (e.g. 2): ");
    scanf("%d", &num2);

    // Check for Euler's identity
    if (num2 == 2) {
        printf("Euler's identity is true\n");
    } else {
        printf("Euler's identity is false\n");
    }

    // Get user input to check for Pi
    printf("Enter a number (e.g. 3.14): ");
    scanf("%f", &temp);

    // Check for Pi
    if (temp == PI) {
        printf("Pi is correct\n");
    } else {
        printf("Pi is incorrect\n");
    }

    return 0;
}