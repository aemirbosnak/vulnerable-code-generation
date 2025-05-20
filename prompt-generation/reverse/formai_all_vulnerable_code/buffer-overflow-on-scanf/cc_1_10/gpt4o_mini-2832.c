//GPT-4o-mini DATASET v1.0 Category: Math exercise ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    double real;
    double imag;
} Complex;

void displayComplex(Complex c) {
    if (c.imag >= 0)
        printf("%.2f + %.2fi", c.real, c.imag);
    else
        printf("%.2f - %.2fi", c.real, -c.imag);
}

Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

Complex subComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

Complex multiplyComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = (c1.real * c2.real) - (c1.imag * c2.imag);
    result.imag = (c1.real * c2.imag) + (c1.imag * c2.real);
    return result;
}

Complex divideComplex(Complex c1, Complex c2) {
    Complex result;
    double denominator = (c2.real * c2.real) + (c2.imag * c2.imag);
    result.real = ((c1.real * c2.real) + (c1.imag * c2.imag)) / denominator;
    result.imag = ((c1.imag * c2.real) - (c1.real * c2.imag)) / denominator;
    return result;
}

void inputComplex(Complex *c) {
    printf("Enter real part: ");
    scanf("%lf", &c->real);
    printf("Enter imaginary part: ");
    scanf("%lf", &c->imag);
}

void computeComplexOperations(int n) {
    Complex complexes[MAX_SIZE];
    
    printf("You will enter %d complex numbers:\n", n);
    
    for (int i = 0; i < n; i++) {
        printf("Complex number %d:\n", i + 1);
        inputComplex(&complexes[i]);
    }
    
    printf("\nOperations on complex numbers:\n");
    
    // Addition
    Complex sum = {0, 0};
    for (int i = 0; i < n; i++) {
        sum = addComplex(sum, complexes[i]);
    }
    printf("Sum of complex numbers: ");
    displayComplex(sum);
    printf("\n");
    
    // Subtraction
    Complex difference = complexes[0]; // Start with the first complex number
    for (int i = 1; i < n; i++) {
        difference = subComplex(difference, complexes[i]);
    }
    printf("Difference of complex numbers: ");
    displayComplex(difference);
    printf("\n");
    
    // Multiplication
    Complex product = {1, 0}; // Start with a complex number representing 1
    for (int i = 0; i < n; i++) {
        product = multiplyComplex(product, complexes[i]);
    }
    printf("Product of complex numbers: ");
    displayComplex(product);
    printf("\n");

    // Division (assuming at least two numbers)
    if (n >= 2) {
        Complex quotient = complexes[0];
        for (int i = 1; i < n; i++) {
            quotient = divideComplex(quotient, complexes[i]);
        }
        printf("Quotient of complex numbers: ");
        displayComplex(quotient);
        printf("\n");
    }
}

int main() {
    int n;

    printf("Welcome to the Magical Complex Number Calculator!\n");
    printf("How many complex numbers would you like to enter (1-%d)? ", MAX_SIZE);
    scanf("%d", &n);
    
    if (n < 1 || n > MAX_SIZE) {
        printf("Invalid number of complex numbers! Please restart the program.\n");
        return 1;
    }
    
    computeComplexOperations(n);
    
    printf("Thank you for using the Magical Complex Number Calculator!\n");
    return 0;
}