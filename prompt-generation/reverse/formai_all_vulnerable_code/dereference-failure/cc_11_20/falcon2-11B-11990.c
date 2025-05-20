//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int width = 1000;
    int height = 1000;
    int xmin = -2.0;
    int xmax = 1.0;
    int ymin = -1.0;
    int ymax = 1.0;
    int max_iterations = 100;
    float max_color = 1.0;
    float min_color = 0.0;
    int color_scale = 256;
    int border = 1;
    int *image = (int*)malloc(width * height * sizeof(int));
    for (int i = 0; i < width * height; i++) {
        image[i] = 0;
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            float xc = (xmax - xmin) * (float)x / (float)width + xmin;
            float yc = (ymax - ymin) * (float)y / (float)height + ymin;
            int iteration = 0;
            float complex_z = 0;
            float real = 0.0;
            float imag = 0.0;
            while (complex_z!= 0 && iteration < max_iterations) {
                complex_z = complex_z * complex_z + real * real - imag * imag;
                real = 2.0 * real * complex_z;
                imag = 2.0 * imag * complex_z;
                iteration++;
            }
            if (iteration == max_iterations) {
                image[y * width + x] = color_scale - 1;
            } else {
                float color = (float)iteration / max_iterations * (max_color - min_color) + min_color;
                image[y * width + x] = color * color_scale;
            }
        }
    }
    for (int y = 0; y < height - border; y++) {
        for (int x = 0; x < width - border; x++) {
            image[y * width + x] = color_scale - 1;
        }
    }
    for (int y = 0; y < height - border; y++) {
        for (int x = width - border; x < width; x++) {
            image[y * width + x] = color_scale - 1;
        }
    }
    for (int y = 0; y < height - border; y++) {
        for (int x = 0; x < width - border; x++) {
            image[y * width + x] = color_scale - 1;
        }
    }
    for (int y = 0; y < height - border; y++) {
        for (int x = width - border; x < width; x++) {
            image[y * width + x] = color_scale - 1;
        }
    }
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d ", image[y * width + x]);
        }
        printf("\n");
    }
    free(image);
    return 0;
}