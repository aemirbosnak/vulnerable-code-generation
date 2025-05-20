//GPT-4o-mini DATASET v1.0 Category: Arithmetic ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double real;
    double imag;
} Complex;

typedef struct {
    char operator;
    Complex (*operation)(Complex, Complex);
} Operation;

Complex add(Complex a, Complex b) {
    return (Complex){a.real + b.real, a.imag + b.imag};
}

Complex subtract(Complex a, Complex b) {
    return (Complex){a.real - b.real, a.imag - b.imag};
}

Complex multiply(Complex a, Complex b) {
    return (Complex){a.real * b.real - a.imag * b.imag, 
                     a.real * b.imag + a.imag * b.real};
}

Complex divide(Complex a, Complex b) {
    if (b.real == 0 && b.imag == 0) {
        fprintf(stderr, "Error: Division by zero\n");
        exit(EXIT_FAILURE);
    }
    double denominator = b.real * b.real + b.imag * b.imag;
    return (Complex){(a.real * b.real + a.imag * b.imag) / denominator, 
                     (a.imag * b.real - a.real * b.imag) / denominator};
}

void displayComplex(Complex c) {
    if (c.imag >= 0) {
        printf("%.2f + %.2fi\n", c.real, c.imag);
    } else {
        printf("%.2f - %.2fi\n", c.real, -c.imag);
    }
}

void processOperations(Complex a, Complex b) {
    Operation ops[] = {
        {'+', &add},
        {'-', &subtract},
        {'*', &multiply},
        {'/', &divide}
    };
    
    for (int i = 0; i < 4; i++) {
        printf("Result of %.2f %c %.2f: ", a.real, ops[i].operator, b.real);
        displayComplex(ops[i].operation(a, b));
    }
}

int main() {
    int n;
    printf("Enter the number of complex numbers to process: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Error: Invalid input.\n");
        return EXIT_FAILURE;
    }

    Complex *numbers = (Complex *)malloc(n * sizeof(Complex));
    if (numbers == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter real and imaginary parts of complex number %d (e.g., 3.0 4.0): ", i + 1);
        if (scanf("%lf %lf", &numbers[i].real, &numbers[i].imag) != 2) {
            fprintf(stderr, "Error: Invalid complex number input.\n");
            free(numbers);
            return EXIT_FAILURE;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        printf("\nProcessing operations between complex numbers %d and %d:\n", i + 1, i + 2);
        processOperations(numbers[i], numbers[i + 1]);
    }

    free(numbers);
    return EXIT_SUCCESS;
}