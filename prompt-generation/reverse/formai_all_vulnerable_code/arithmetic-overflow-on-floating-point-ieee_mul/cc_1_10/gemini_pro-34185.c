//GEMINI-pro DATASET v1.0 Category: Math exercise ; Style: mathematical
#include <stdio.h>
#include <math.h>

// Define the complex number structure
typedef struct {
    double real;
    double imaginary;
} complex;

// Define the complex number functions
complex add_complex(complex a, complex b) {
    complex c;
    c.real = a.real + b.real;
    c.imaginary = a.imaginary + b.imaginary;
    return c;
}

complex subtract_complex(complex a, complex b) {
    complex c;
    c.real = a.real - b.real;
    c.imaginary = a.imaginary - b.imaginary;
    return c;
}

complex multiply_complex(complex a, complex b) {
    complex c;
    c.real = a.real * b.real - a.imaginary * b.imaginary;
    c.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return c;
}

complex divide_complex(complex a, complex b) {
    complex c;
    double denominator = b.real * b.real + b.imaginary * b.imaginary;
    c.real = (a.real * b.real + a.imaginary * b.imaginary) / denominator;
    c.imaginary = (a.imaginary * b.real - a.real * b.imaginary) / denominator;
    return c;
}

// Define the main function
int main() {
    // Declare the complex numbers
    complex a, b, c;

    // Read the complex numbers from the user
    printf("Enter the first complex number (a + bi): ");
    scanf("%lf %lf", &a.real, &a.imaginary);
    printf("Enter the second complex number (c + di): ");
    scanf("%lf %lf", &b.real, &b.imaginary);

    // Add the complex numbers
    c = add_complex(a, b);
    printf("The sum of the complex numbers is: %.2f + %.2fi\n", c.real, c.imaginary);

    // Subtract the complex numbers
    c = subtract_complex(a, b);
    printf("The difference of the complex numbers is: %.2f + %.2fi\n", c.real, c.imaginary);

    // Multiply the complex numbers
    c = multiply_complex(a, b);
    printf("The product of the complex numbers is: %.2f + %.2fi\n", c.real, c.imaginary);

    // Divide the complex numbers
    c = divide_complex(a, b);
    printf("The quotient of the complex numbers is: %.2f + %.2fi\n", c.real, c.imaginary);

    return 0;
}