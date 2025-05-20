//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the function prototype for the integral function.
double integrate(double (*f)(double), double a, double b, double n);

// Define the function to be integrated.
double f(double x) {
    return x*x;
}

// Define the main function.
int main() {
    // Declare the variables.
    double a, b, n, result;

    // Get the input from the user.
    printf("Enter the lower limit of integration: ");
    scanf("%lf", &a);
    printf("Enter the upper limit of integration: ");
    scanf("%lf", &b);
    printf("Enter the number of subintervals: ");
    scanf("%lf", &n);

    // Call the integrate function to calculate the integral.
    result = integrate(f, a, b, n);

    // Print the result to the console.
    printf("The integral of f(x) from %lf to %lf using %lf subintervals is: %lf\n", a, b, n, result);

    // Return 0 to indicate that the program ran successfully.
    return 0;
}

// Define the function to calculate the integral using the trapezoidal rule.
double integrate(double (*f)(double), double a, double b, double n) {
    // Declare the variables.
    double h, sum, x;

    // Calculate the step size.
    h = (b - a) / n;

    // Calculate the sum of the areas of the trapezoids.
    sum = 0;
    for (x = a + h; x < b; x += h) {
        sum += (f(x) + f(x - h)) / 2 * h;
    }

    // Return the integral.
    return sum;
}