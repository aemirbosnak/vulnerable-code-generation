//GEMINI-pro DATASET v1.0 Category: Scientific Calculator Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Function to calculate the power of a number
double power(double base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else if (exponent > 0) {
        return base * power(base, exponent - 1);
    } else {
        return 1.0 / power(base, -exponent);
    }
}

// Function to calculate the logarithm of a number
double logarithm(double base, double x) {
    if (x <= 0 || base <= 0 || base == 1) {
        return NAN;
    } else {
        return log(x) / log(base);
    }
}

// Function to calculate the trigonometric sine of an angle
double sine(double angle) {
    return sin(angle);
}

// Function to calculate the trigonometric cosine of an angle
double cosine(double angle) {
    return cos(angle);
}

// Function to calculate the trigonometric tangent of an angle
double tangent(double angle) {
    return tan(angle);
}

// Main function
int main() {
    // Print a welcome message
    printf("Welcome to the Scientific Calculator!\n");

    // Print a list of the available operations
    printf("Available operations:\n");
    printf("- Factorial: factorial(n)\n");
    printf("- Power: power(base, exponent)\n");
    printf("- Logarithm: logarithm(base, x)\n");
    printf("- Sine: sine(angle)\n");
    printf("- Cosine: cosine(angle)\n");
    printf("- Tangent: tangent(angle)\n");

    // Prompt the user to enter an operation
    printf("Enter an operation: ");
    char operation[256];
    scanf("%s", operation);

    // Parse the operation
    if (strcmp(operation, "factorial") == 0) {
        // Prompt the user to enter a number
        printf("Enter a number: ");
        int n;
        scanf("%d", &n);

        // Calculate the factorial of the number
        int result = factorial(n);

        // Print the result
        printf("The factorial of %d is %d.\n", n, result);
    } else if (strcmp(operation, "power") == 0) {
        // Prompt the user to enter a base and an exponent
        printf("Enter a base: ");
        double base;
        scanf("%lf", &base);
        printf("Enter an exponent: ");
        int exponent;
        scanf("%d", &exponent);

        // Calculate the power of the base
        double result = power(base, exponent);

        // Print the result
        printf("The power of %lf to the exponent %d is %lf.\n", base, exponent, result);
    } else if (strcmp(operation, "logarithm") == 0) {
        // Prompt the user to enter a base and a number
        printf("Enter a base: ");
        double base;
        scanf("%lf", &base);
        printf("Enter a number: ");
        double x;
        scanf("%lf", &x);

        // Calculate the logarithm of the number
        double result = logarithm(base, x);

        // Print the result
        printf("The logarithm of %lf to the base %lf is %lf.\n", x, base, result);
    } else if (strcmp(operation, "sine") == 0) {
        // Prompt the user to enter an angle
        printf("Enter an angle (in degrees): ");
        double angle;
        scanf("%lf", &angle);

        // Convert the angle to radians
        angle = angle * M_PI / 180;

        // Calculate the sine of the angle
        double result = sine(angle);

        // Print the result
        printf("The sine of %lf degrees is %lf.\n", angle * 180 / M_PI, result);
    } else if (strcmp(operation, "cosine") == 0) {
        // Prompt the user to enter an angle
        printf("Enter an angle (in degrees): ");
        double angle;
        scanf("%lf", &angle);

        // Convert the angle to radians
        angle = angle * M_PI / 180;

        // Calculate the cosine of the angle
        double result = cosine(angle);

        // Print the result
        printf("The cosine of %lf degrees is %lf.\n", angle * 180 / M_PI, result);
    } else if (strcmp(operation, "tangent") == 0) {
        // Prompt the user to enter an angle
        printf("Enter an angle (in degrees): ");
        double angle;
        scanf("%lf", &angle);

        // Convert the angle to radians
        angle = angle * M_PI / 180;

        // Calculate the tangent of the angle
        double result = tangent(angle);

        // Print the result
        printf("The tangent of %lf degrees is %lf.\n", angle * 180 / M_PI, result);
    } else {
        // Print an error message
        printf("Invalid operation.\n");
    }

    return 0;
}