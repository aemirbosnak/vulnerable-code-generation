//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    // Define variables
    int a = 10;
    int b = 5;
    double c = 3.14;
    double d = 2.71;

    // Perform basic arithmetic operations
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b);

    // Perform floating-point arithmetic operations
    printf("c + d = %f\n", c + d);
    printf("c - d = %f\n", c - d);
    printf("c * d = %f\n", c * d);
    printf("c / d = %f\n", c / d);

    // Perform exponential and logarithmic operations
    printf("pow(a, b) = %f\n", pow(a, b));
    printf("sqrt(c) = %f\n", sqrt(c));
    printf("log(d) = %f\n", log(d));
    printf("log10(d) = %f\n", log10(d));

    // Perform trigonometric operations
    printf("sin(c) = %f\n", sin(c));
    printf("cos(c) = %f\n", cos(c));
    printf("tan(c) = %f\n", tan(c));
    printf("asin(d) = %f\n", asin(d));
    printf("acos(d) = %f\n", acos(d));
    printf("atan(d) = %f\n", atan(d));

    // Perform hyperbolic trigonometric operations
    printf("sinh(c) = %f\n", sinh(c));
    printf("cosh(c) = %f\n", cosh(c));
    printf("tanh(c) = %f\n", tanh(c));
    printf("asinh(d) = %f\n", asinh(d));
    printf("acosh(d) = %f\n", acosh(d));
    printf("atanh(d) = %f\n", atanh(d));

    // Perform miscellaneous mathematical operations
    printf("abs(a) = %d\n", abs(a));
    printf("ceil(c) = %f\n", ceil(c));
    printf("floor(c) = %f\n", floor(c));
    printf("round(c) = %f\n", round(c));
    printf("fmod(a, b) = %d\n", fmod(a, b));
    printf("remainder(a, b) = %d\n", remainder(a, b));
    printf("copysign(c, d) = %f\n", copysign(c, d));
    printf("fmax(c, d) = %f\n", fmax(c, d));
    printf("fmin(c, d) = %f\n", fmin(c, d));

    return 0;
}