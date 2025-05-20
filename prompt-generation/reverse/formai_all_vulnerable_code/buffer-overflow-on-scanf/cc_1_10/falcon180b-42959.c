//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000
#define MAX_ITERATIONS 1000

// Define the fractal pattern
void fractal(int size, int iterations) {
    int x, y;
    for (y = 0; y < size; y++) {
        for (x = 0; x < size; x++) {
            int count = 0;
            double real = 0, imag = 0;
            while (count < iterations && (real * real + imag * imag) < 4) {
                double temp = real * real - imag * imag + 0.1;
                imag = 2 * real * imag + 0.1;
                real = temp;
                count++;
            }
            if (count == iterations) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    int size, iterations;

    // Get user input for fractal size and iterations
    printf("Enter fractal size: ");
    scanf("%d", &size);

    printf("Enter number of iterations: ");
    scanf("%d", &iterations);

    // Check for invalid input
    if (size <= 0 || size > MAX_SIZE) {
        printf("Invalid fractal size.\n");
        return 1;
    }

    if (iterations <= 0 || iterations > MAX_ITERATIONS) {
        printf("Invalid number of iterations.\n");
        return 1;
    }

    // Generate fractal
    fractal(size, iterations);

    return 0;
}