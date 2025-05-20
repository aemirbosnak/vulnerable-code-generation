//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function prototypes
int findRoot(double a, double b, double epsilon);
double f(double x);
double df(double x);

int main() {
    double a = -5.0, b = 5.0, x;
    int iterations;

    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);

    x = findRoot(a, b, 0.0001);
    printf("The root is %.10f\n", x);

    return 0;
}

// Bisection method to find the root of a function
int findRoot(double a, double b, double epsilon) {
    double fa, fb, fc;
    double c = (a + b) / 2.0;
    int iterations = 0;

    while (fabs(b - a) > epsilon) {
        fa = f(a);
        fb = f(b);

        if (fa * fb >= 0.0) {
            printf("Error: Function does not cross the x-axis\n");
            exit(1);
        }

        if (fb < fa) {
            a = b;
        }
        else {
            b = a;
        }

        c = (a + b) / 2.0;
        fc = f(c);

        if (fabs(fc) < epsilon) {
            printf("Error: Function is too small\n");
            exit(1);
        }

        if (iterations >= 1000) {
            printf("Error: Maximum number of iterations exceeded\n");
            exit(1);
        }

        iterations++;
    }

    return c;
}

// Function to be solved
double f(double x) {
    return sin(x) - x * cos(x);
}

// Derivative of the function
double df(double x) {
    return cos(x) - x * sin(x);
}