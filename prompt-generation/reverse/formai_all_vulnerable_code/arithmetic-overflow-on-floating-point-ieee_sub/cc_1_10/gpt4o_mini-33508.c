//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: scientific
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {
    double real;
    double imag;
} Complex;

void calculateRoots(double a, double b, double c);
Complex computeComplexRoots(double realPart, double imagPart);
void printResults(Complex root1, Complex root2);

int main() {
    double a, b, c;
    
    printf("Quadratic Equation Solver\n");
    printf("Given a quadratic equation in the form: ax^2 + bx + c = 0\n");
    
    printf("Enter coefficient a: ");
    if (scanf("%lf", &a) != 1 || a == 0) {
        fprintf(stderr, "Invalid input or 'a' cannot be zero. Please restart the program.\n");
        return EXIT_FAILURE;
    }

    printf("Enter coefficient b: ");
    if (scanf("%lf", &b) != 1) {
        fprintf(stderr, "Invalid input for 'b'. Please restart the program.\n");
        return EXIT_FAILURE;
    }

    printf("Enter coefficient c: ");
    if (scanf("%lf", &c) != 1) {
        fprintf(stderr, "Invalid input for 'c'. Please restart the program.\n");
        return EXIT_FAILURE;
    }

    calculateRoots(a, b, c);
    
    return EXIT_SUCCESS;
}

void calculateRoots(double a, double b, double c) {
    double discriminant = (b * b) - (4 * a * c);
    Complex root1, root2;
    
    if (discriminant > 0) {
        // Two real and distinct roots
        root1.real = (-b + sqrt(discriminant)) / (2 * a);
        root2.real = (-b - sqrt(discriminant)) / (2 * a);
        root1.imag = root2.imag = 0.0;

        printf("The roots are real and different.\n");
    } else if (discriminant == 0) {
        // One real root (double root)
        root1.real = root2.real = -b / (2 * a);
        root1.imag = root2.imag = 0.0;

        printf("The roots are real and the same.\n");
    } else {
        // Complex roots
        root1 = computeComplexRoots(-b / (2 * a), sqrt(-discriminant) / (2 * a));
        root2 = computeComplexRoots(-b / (2 * a), -sqrt(-discriminant) / (2 * a));

        printf("The roots are complex and different.\n");
    }

    printResults(root1, root2);
}

Complex computeComplexRoots(double realPart, double imagPart) {
    Complex result;
    result.real = realPart;
    result.imag = imagPart;
    return result;
}

void printResults(Complex root1, Complex root2) {
    if (root1.imag == 0 && root2.imag == 0) {
        printf("Root 1: %.2lf\n", root1.real);
        printf("Root 2: %.2lf\n", root2.real);
    } else {
        printf("Root 1: %.2lf + %.2lfi\n", root1.real, root1.imag);
        printf("Root 2: %.2lf + %.2lfi\n", root2.real, root2.imag);
    }
}