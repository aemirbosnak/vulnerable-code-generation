//GEMINI-pro DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

// Define a custom data type for complex numbers
typedef struct {
    double real;
    double imag;
} complex;

// Declare functions
complex add_complex(complex a, complex b);
complex sub_complex(complex a, complex b);
complex mult_complex(complex a, complex b);
complex div_complex(complex a, complex b);
complex conj_complex(complex a);
double abs_complex(complex a);

// Main function
int main() {
    // Declare variables
    complex a, b, c;

    // Get input from the user
    printf("Enter the real and imaginary parts of the first complex number (a+bi): ");
    scanf("%lf %lf", &a.real, &a.imag);
    printf("Enter the real and imaginary parts of the second complex number (c+di): ");
    scanf("%lf %lf", &b.real, &b.imag);

    // Perform arithmetic operations on the complex numbers
    c = add_complex(a, b);
    printf("The sum of the two complex numbers is: %.2f+%.2fi\n", c.real, c.imag);
    c = sub_complex(a, b);
    printf("The difference of the two complex numbers is: %.2f+%.2fi\n", c.real, c.imag);
    c = mult_complex(a, b);
    printf("The product of the two complex numbers is: %.2f+%.2fi\n", c.real, c.imag);
    c = div_complex(a, b);
    printf("The quotient of the two complex numbers is: %.2f+%.2fi\n", c.real, c.imag);

    // Print the conjugate of the first complex number
    c = conj_complex(a);
    printf("The conjugate of the first complex number is: %.2f-%.2fi\n", c.real, c.imag);

    // Print the absolute value of the second complex number
    printf("The absolute value of the second complex number is: %.2f\n", abs_complex(b));

    return 0;
}

// Function to add two complex numbers
complex add_complex(complex a, complex b) {
    complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

// Function to subtract two complex numbers
complex sub_complex(complex a, complex b) {
    complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

// Function to multiply two complex numbers
complex mult_complex(complex a, complex b) {
    complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

// Function to divide two complex numbers
complex div_complex(complex a, complex b) {
    complex c;
    double denom = b.real * b.real + b.imag * b.imag;
    c.real = (a.real * b.real + a.imag * b.imag) / denom;
    c.imag = (a.imag * b.real - a.real * b.imag) / denom;
    return c;
}

// Function to take the conjugate of a complex number
complex conj_complex(complex a) {
    complex c;
    c.real = a.real;
    c.imag = -a.imag;
    return c;
}

// Function to calculate the absolute value of a complex number
double abs_complex(complex a) {
    return sqrt(a.real * a.real + a.imag * a.imag);
}