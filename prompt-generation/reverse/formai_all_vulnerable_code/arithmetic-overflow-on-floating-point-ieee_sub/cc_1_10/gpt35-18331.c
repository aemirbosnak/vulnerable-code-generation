//FormAI DATASET v1.0 Category: Fractal Generation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 640       // Width of the output image
#define HEIGHT 480      // Height of the output image
#define MAX_ITERATIONS 1000   // Maximum number of iterations for the fractal algorithm

// Struct to store the complex number used in the fractal calculation
typedef struct {
    double real;
    double imag;
} complex_t;

// Function to create a new complex number
complex_t new_complex(double real, double imag) {
    complex_t c;
    c.real = real;
    c.imag = imag;
    return c;
}

// Function to perform the Mandelbrot iteration for a given point c
int mandelbrot_iteration(complex_t c) {
    complex_t z = new_complex(0, 0);
    int iterations = 0;
    
    while (iterations < MAX_ITERATIONS && z.real*z.real + z.imag*z.imag < 4) {
        double temp = z.real*z.real - z.imag*z.imag + c.real;
        z.imag = 2*z.real*z.imag + c.imag;
        z.real = temp;
        iterations++;
    }
    
    return iterations;
}

// Function to render the fractal
void render_fractal(FILE* fp, double x_min, double x_max, double y_min, double y_max) {
    double x_range = x_max - x_min;
    double y_range = y_max - y_min;
    double x_step = x_range / WIDTH;
    double y_step = y_range / HEIGHT;
    
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double cx = x_min + x*x_step;
            double cy = y_max - y*y_step;
            complex_t c = new_complex(cx, cy);
            int iterations = mandelbrot_iteration(c);
            unsigned char r = iterations % 256;
            unsigned char g = (iterations/256) % 256;
            unsigned char b = (iterations/65536) % 256;
            fprintf(fp, "%c%c%c", r, g, b);
        }
    }
}

int main(int argc, char** argv) {
    double x_min = -2.0;
    double x_max = 1.0;
    double y_min = -1.5;
    double y_max = 1.5;
    
    if (argc >= 2) {
        x_min = atof(argv[1]);
    }
    
    if (argc >= 3) {
        x_max = atof(argv[2]);
    }
    
    if (argc >= 4) {
        y_min = atof(argv[3]);
    }
    
    if (argc >= 5) {
        y_max = atof(argv[4]);
    }
    
    FILE* fp = fopen("fractal.ppm", "wb");
    
    if (fp == NULL) {
        printf("Error: Failed to open output file\n");
        return 1;
    }
    
    render_fractal(fp, x_min, x_max, y_min, y_max);
    
    fclose(fp);
    
    return 0;
}