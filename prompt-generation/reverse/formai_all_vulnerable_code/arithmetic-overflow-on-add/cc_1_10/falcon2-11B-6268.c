//Falcon2-11B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>

// Function to add two numbers
int add(int a, int b) {
    return a + b;
}

// Function to subtract two numbers
int subtract(int a, int b) {
    return a - b;
}

// Function to multiply two numbers
int multiply(int a, int b) {
    return a * b;
}

// Function to divide two numbers
int divide(int a, int b) {
    if (b == 0) {
        return 0;
    }
    return a / b;
}

// Function to calculate sine
double sin(double x) {
    return sin(x);
}

// Function to calculate cosine
double cos(double x) {
    return cos(x);
}

// Function to calculate tangent
double tan(double x) {
    return tan(x);
}

// Function to calculate arcsine
double asin(double x) {
    return asin(x);
}

// Function to calculate arccosine
double acos(double x) {
    return acos(x);
}

// Function to calculate arctangent
double atan(double x) {
    return atan(x);
}

// Function to calculate square root
double sqrt(double x) {
    return sqrt(x);
}

int main() {
    // Ask the user for two numbers
    printf("Enter two numbers: ");
    int a = 0;
    int b = 0;
    scanf("%d %d", &a, &b);

    // Calculate the sum
    int sum = add(a, b);
    printf("Sum: %d\n", sum);

    // Calculate the difference
    int difference = subtract(a, b);
    printf("Difference: %d\n", difference);

    // Calculate the product
    int product = multiply(a, b);
    printf("Product: %d\n", product);

    // Calculate the quotient
    int quotient = divide(a, b);
    printf("Quotient: %d\n", quotient);

    // Calculate the sine
    double sine = sin(a);
    printf("Sine: %.2f\n", sine);

    // Calculate the cosine
    double cosine = cos(a);
    printf("Cosine: %.2f\n", cosine);

    // Calculate the tangent
    double tangent = tan(a);
    printf("Tangent: %.2f\n", tangent);

    // Calculate the arcsine
    double arcsine = asin(a);
    printf("Arcsine: %.2f\n", arcsine);

    // Calculate the arccosine
    double arccosine = acos(a);
    printf("Arccosine: %.2f\n", arccosine);

    // Calculate the arctangent
    double arctangent = atan(a);
    printf("Arctangent: %.2f\n", arctangent);

    // Calculate the square root
    double squareRoot = sqrt(a);
    printf("Square Root: %.2f\n", squareRoot);

    return 0;
}