//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 1000

// Define the colors for the fractal
#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF

// Define the fractal function
int fractal(int x, int y, int max_iterations) {
    int iterations = 0;
    while (iterations < max_iterations && x * x + y * y < 4) {
        double real = x * x - y * y + 0.1;
        double imag = 2 * x * y + 1;
        x = real;
        y = imag;
        iterations++;
    }
    return iterations;
}

int main() {
    // Get the screen size
    int width, height;
    printf("Enter the screen width: ");
    scanf("%d", &width);
    printf("Enter the screen height: ");
    scanf("%d", &height);

    // Set the fractal properties
    int max_iterations = MAX_ITERATIONS;
    double zoom = 1.0;
    int offset_x = -width / 2;
    int offset_y = -height / 2;

    // Initialize the screen
    int screen[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            screen[i][j] = BLACK;
        }
    }

    // Generate the fractal
    srand(time(0));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int iterations = fractal(j * zoom + offset_x, i * zoom + offset_y, max_iterations);
            if (iterations == max_iterations) {
                screen[i][j] = WHITE;
            } else {
                screen[i][j] = iterations % 8 == 0? RED : iterations % 8 == 1? GREEN : BLUE;
            }
        }
    }

    // Print the fractal
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%06X ", screen[i][j]);
        }
        printf("\n");
    }

    return 0;
}