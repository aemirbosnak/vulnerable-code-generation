//Code Llama-13B DATASET v1.0 Category: Fractal Generation ; Style: optimized
// Fractal Generation Example Program

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITER 1000
#define COLOR_COUNT 100

// Structure to store a color
typedef struct {
    int r;
    int g;
    int b;
} color;

// Function to generate a random color
color random_color() {
    color c;
    c.r = rand() % 256;
    c.g = rand() % 256;
    c.b = rand() % 256;
    return c;
}

// Function to calculate the mandelbrot set
int mandelbrot(double x, double y, int max_iter) {
    double cx = x;
    double cy = y;
    int iter = 0;
    while (iter < max_iter && (cx * cx + cy * cy) <= 4.0) {
        double tmp = cx * cx - cy * cy + x;
        cy = 2.0 * cx * cy + y;
        cx = tmp;
        iter++;
    }
    return iter;
}

// Function to generate a color palette
color * generate_palette(int num_colors) {
    color * palette = (color *)malloc(num_colors * sizeof(color));
    for (int i = 0; i < num_colors; i++) {
        palette[i] = random_color();
    }
    return palette;
}

// Function to draw the mandelbrot set
void draw_mandelbrot(int width, int height, int max_iter, color * palette) {
    double x_scale = (double)width / 4.0;
    double y_scale = (double)height / 3.0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int iter = mandelbrot((x - width / 2) * x_scale, (y - height / 2) * y_scale, max_iter);
            if (iter < max_iter) {
                printf("%c[38;2;%d;%d;%dm@", 0x1B, palette[iter % COLOR_COUNT].r, palette[iter % COLOR_COUNT].g, palette[iter % COLOR_COUNT].b);
            } else {
                printf("%c[38;2;0;0;0m@", 0x1B);
            }
        }
        printf("\n");
    }
}

int main() {
    // Generate a color palette
    color * palette = generate_palette(COLOR_COUNT);
    // Draw the mandelbrot set
    draw_mandelbrot(WIDTH, HEIGHT, MAX_ITER, palette);
    // Free the color palette
    free(palette);
    return 0;
}