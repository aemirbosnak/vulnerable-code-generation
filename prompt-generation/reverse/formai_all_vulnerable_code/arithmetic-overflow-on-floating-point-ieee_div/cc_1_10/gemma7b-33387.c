//Gemma-7B DATASET v1.0 Category: Scientific Calculator Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ComplexNumber
{
    double real;
    double imag;
} ComplexNumber;

ComplexNumber complex_number_add(ComplexNumber a, ComplexNumber b)
{
    ComplexNumber c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

ComplexNumber complex_number_subtract(ComplexNumber a, ComplexNumber b)
{
    ComplexNumber c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

ComplexNumber complex_number_multiply(ComplexNumber a, ComplexNumber b)
{
    ComplexNumber c;
    c.real = (a.real * b.real - a.imag * b.imag) / 2.0;
    c.imag = (a.real * b.imag + a.imag * b.real) / 2.0;
    return c;
}

ComplexNumber complex_number_divide(ComplexNumber a, ComplexNumber b)
{
    ComplexNumber c;
    c.real = (a.real * b.real + a.imag * b.imag) / (b.real * b.real + b.imag * b.imag);
    c.imag = (a.imag * b.real - a.real * b.imag) / (b.real * b.real + b.imag * b.imag);
    return c;
}

int main()
{
    char buffer[MAX_BUFFER_SIZE];
    double real, imag;
    ComplexNumber a, b, c;

    printf("Enter the real part of the first complex number: ");
    scanf("%lf", &real);

    printf("Enter the imaginary part of the first complex number: ");
    scanf("%lf", &imag);

    a.real = real;
    a.imag = imag;

    printf("Enter the real part of the second complex number: ");
    scanf("%lf", &real);

    printf("Enter the imaginary part of the second complex number: ");
    scanf("%lf", &imag);

    b.real = real;
    b.imag = imag;

    c = complex_number_add(a, b);
    printf("The sum of the two complex numbers is: %.2lf + %.2lfi\n", c.real, c.imag);

    c = complex_number_subtract(a, b);
    printf("The difference of the two complex numbers is: %.2lf + %.2lfi\n", c.real, c.imag);

    c = complex_number_multiply(a, b);
    printf("The product of the two complex numbers is: %.2lf + %.2lfi\n", c.real, c.imag);

    c = complex_number_divide(a, b);
    printf("The quotient of the two complex numbers is: %.2lf + %.2lfi\n", c.real, c.imag);

    return 0;
}