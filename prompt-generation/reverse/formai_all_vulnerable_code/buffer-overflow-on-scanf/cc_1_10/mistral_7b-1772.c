//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef struct Complex {
    double real;
    double imag;
} Complex;

Complex addComplex(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}

Complex subComplex(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

Complex mulComplex(Complex a, Complex b) {
    Complex result;
    result.real = (a.real * b.real) - (a.imag * b.imag);
    result.imag = (a.real * b.imag) + (a.imag * b.real);
    return result;
}

Complex powComplex(Complex a, int power) {
    Complex result;
    double tempReal = 1, tempImag = 0;
    for (int i = 0; i < power; i++) {
        result = mulComplex(result, a);
        tempReal += result.real * result.real;
        tempImag += result.real * result.imag;
        tempImag += result.imag * result.imag;
    }
    result.real = tempReal;
    result.imag = tempImag;
    return result;
}

void printComplex(Complex c) {
    if (c.imag >= 0) {
        printf("%.2lf + %.2lfi", c.real, c.imag);
    } else {
        printf("%.2lf - %.2lfi", c.real, c.imag);
    }
}

int main() {
    Complex a = {3.0, 2.0};
    Complex b = {1.0, 3.0};
    Complex c, d;

    clock_t start = clock();

    c = addComplex(a, b);
    printf("Sum of complex numbers a and b: ");
    printComplex(c);
    printf("\n");

    c = subComplex(a, b);
    printf("Difference of complex numbers a and b: ");
    printComplex(c);
    printf("\n");

    c = mulComplex(a, b);
    printf("Product of complex numbers a and b: ");
    printComplex(c);
    printf("\n");

    int p;
    printf("Enter the power: ");
    scanf("%d", &p);

    d = powComplex(a, p);
    printf("Complex number a raised to the power of %d: ", p);
    printComplex(d);
    printf("\n");

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Program execution time: %.12fs", time_spent);

    return 0;
}