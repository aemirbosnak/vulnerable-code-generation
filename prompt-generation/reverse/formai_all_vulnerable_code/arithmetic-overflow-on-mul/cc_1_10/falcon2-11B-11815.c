//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// Function to calculate the Mandelbrot set value for a given x and y coordinate
int mandelbrot(int x, int y, int max_iterations) {
    int x_next = x * x - y;
    int y_next = 2 * x + y;
    int iterations = 0;
    
    while (iterations < max_iterations && (x_next * x_next + y_next * y_next) < 4) {
        x = x_next;
        y = y_next;
        x_next = x * x - y;
        y_next = 2 * x + y;
        iterations++;
    }
    
    return iterations;
}

// Function to generate the Mandelbrot set image
void generate_mandelbrot() {
    int width = SCREEN_WIDTH;
    int height = SCREEN_HEIGHT;
    int pixels[height][width];
    int max_iterations = MAX_ITERATIONS;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i][j] = mandelbrot(j - width / 2, i - height / 2, max_iterations);
        }
    }
    
    // Render the image to the screen
    printf("Mandelbrot Set Image\n");
    printf("Width: %d, Height: %d\n", width, height);
    printf("Max Iterations: %d\n", max_iterations);
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int value = pixels[i][j];
            int color = value * 10;
            
            if (color < 10) {
                color = 0;
            }
            else if (color > 255) {
                color = 255;
            }
            
            printf("(%d, %d) = %d -> #%02X%02X%02X\n", j, i, value, color, color, color);
        }
    }
}

int main() {
    generate_mandelbrot();
    
    return 0;
}