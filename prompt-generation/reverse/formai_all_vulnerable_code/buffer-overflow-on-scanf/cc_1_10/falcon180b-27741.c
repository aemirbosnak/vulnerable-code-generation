//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

// Function to generate Fibonacci sequence
void fibonacci(int n) {
    int a = 0, b = 1, c;
    printf("Fibonacci sequence up to %d terms:\n", n);
    printf("0 1 ");
    for (int i = 2; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        printf("%d ", c);
    }
}

// Function to draw the Mandelbrot set
void mandelbrot(int x, int y, int max_iterations) {
    double real = (double)x / MAX_COLS;
    double imaginary = (double)y / MAX_ROWS;
    int iterations = 0;
    while (iterations < max_iterations && pow(real, 2) + pow(imaginary, 2) < 4) {
        double temp_real = real * real - imaginary * imaginary + (double)x / MAX_COLS;
        imaginary = 2 * real * imaginary + (double)y / MAX_ROWS;
        real = temp_real;
        iterations++;
    }
    if (iterations == max_iterations) {
        printf("*");
    } else {
        printf(" ");
    }
}

// Function to draw the Mandelbrot set
void draw_mandelbrot(int max_iterations) {
    int x, y;
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            x = j - MAX_COLS / 2;
            y = i - MAX_ROWS / 2;
            mandelbrot(x, y, max_iterations);
        }
        printf("\n");
    }
}

int main() {
    int max_iterations;

    // Prompt user for maximum iterations
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    // Generate Fibonacci sequence
    fibonacci(max_iterations);

    // Draw Mandelbrot set
    draw_mandelbrot(max_iterations);

    return 0;
}