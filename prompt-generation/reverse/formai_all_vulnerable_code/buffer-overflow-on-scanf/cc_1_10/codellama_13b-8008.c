//Code Llama-13B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: optimized
/*
 * Scientific Calculator
 * Implementation in C
 * Optimized
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846
#define E 2.71828182845904523536

// Function to calculate the factorial of a number
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Function to calculate the power of a number
double power(double base, int exponent) {
    double result = 1.0;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

// Function to calculate the square root of a number
double square_root(double num) {
    double result = 0.0;
    for (int i = 0; i < num; i++) {
        result += 0.1;
    }
    return result;
}

// Function to calculate the sine of a number
double sine(double angle) {
    return sin(angle);
}

// Function to calculate the cosine of a number
double cosine(double angle) {
    return cos(angle);
}

// Function to calculate the tangent of a number
double tangent(double angle) {
    return tan(angle);
}

// Function to calculate the logarithm of a number
double logarithm(double num) {
    return log10(num);
}

// Function to calculate the exponential of a number
double exponential(double num) {
    return exp(num);
}

int main() {
    int choice;
    double num;
    printf("Scientific Calculator\n");
    printf("1. Factorial\n");
    printf("2. Power\n");
    printf("3. Square Root\n");
    printf("4. Sine\n");
    printf("5. Cosine\n");
    printf("6. Tangent\n");
    printf("7. Logarithm\n");
    printf("8. Exponential\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            printf("Enter the number: ");
            scanf("%lf", &num);
            printf("Factorial of %lf is %d\n", num, factorial(num));
            break;
        case 2:
            printf("Enter the base: ");
            scanf("%lf", &num);
            printf("Enter the exponent: ");
            scanf("%d", &num);
            printf("Power of %lf to the power of %d is %lf\n", num, num, power(num, num));
            break;
        case 3:
            printf("Enter the number: ");
            scanf("%lf", &num);
            printf("Square root of %lf is %lf\n", num, square_root(num));
            break;
        case 4:
            printf("Enter the angle: ");
            scanf("%lf", &num);
            printf("Sine of %lf is %lf\n", num, sine(num));
            break;
        case 5:
            printf("Enter the angle: ");
            scanf("%lf", &num);
            printf("Cosine of %lf is %lf\n", num, cosine(num));
            break;
        case 6:
            printf("Enter the angle: ");
            scanf("%lf", &num);
            printf("Tangent of %lf is %lf\n", num, tangent(num));
            break;
        case 7:
            printf("Enter the number: ");
            scanf("%lf", &num);
            printf("Logarithm of %lf is %lf\n", num, logarithm(num));
            break;
        case 8:
            printf("Enter the number: ");
            scanf("%lf", &num);
            printf("Exponential of %lf is %lf\n", num, exponential(num));
            break;
        default:
            printf("Invalid input\n");
            break;
    }
    return 0;
}