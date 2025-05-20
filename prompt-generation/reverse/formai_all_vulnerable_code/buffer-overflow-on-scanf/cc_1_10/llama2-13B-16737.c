//LLAMA2-13B DATASET v1.0 Category: Arithmetic ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159
#define EULER 2.71828

int main() {

    double a, b, c, d, e, f;
    char op;

    printf("Welcome to the Arithmetic Wonderland!\n");

    // Section 1: Primitive Arithmetic

    printf("Enter two numbers: ");
    scanf("%lf%lf", &a, &b);
    printf("Addition: %lf + %lf = %lf\n", a, b, a + b);
    printf("Subtraction: %lf - %lf = %lf\n", a, b, a - b);
    printf("Multiplication: %lf x %lf = %lf\n", a, b, a * b);
    printf("Division: %lf / %lf = %lf\n", a, b, a / b);

    // Section 2: Advanced Arithmetic

    printf("Enter two complex numbers: ");
    scanf("%lf%lf%c", &a, &b, &op);
    if (op == '+') {
        c = a + b;
    } else if (op == '-') {
        c = a - b;
    } else if (op == '*') {
        c = a * b;
    } else if (op == '/') {
        c = a / b;
    }
    printf("Complex Addition: %lf + %lf = %lf\n", a, b, c);
    printf("Complex Subtraction: %lf - %lf = %lf\n", a, b, c);
    printf("Complex Multiplication: %lf x %lf = %lf\n", a, b, c);
    printf("Complex Division: %lf / %lf = %lf\n", a, b, c);

    // Section 3: Trigonometry

    printf("Enter an angle in degrees: ");
    scanf("%lf", &a);
    c = sin(a);
    printf("Sine of %lf degrees: %lf\n", a, c);
    c = cos(a);
    printf("Cosine of %lf degrees: %lf\n", a, c);
    c = tan(a);
    printf("Tangent of %lf degrees: %lf\n", a, c);

    // Section 4: Exponents and Roots

    printf("Enter a base and an exponent: ");
    scanf("%lf%ld", &b, &e);
    c = pow(b, e);
    printf("Base %lf raised to the power of %ld: %lf\n", b, e, c);
    c = log(b);
    printf("Natural Logarithm of %lf: %lf\n", b, c);

    return 0;
}