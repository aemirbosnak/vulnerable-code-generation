//Code Llama-13B DATASET v1.0 Category: Fractal Generation ; Style: retro
/*
 * Fractal Generation Program
 *
 * Generates a fractal image using a retro style.
 *
 * Usage:
 *  ./fractal_retro [image_width] [image_height] [iterations] [output_filename]
 *
 * Example:
 *  ./fractal_retro 512 512 10 fractal.bmp
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define ITERATIONS 10
#define OUTPUT_FILENAME "fractal.bmp"

typedef struct {
    int r;
    int g;
    int b;
} Pixel;

void generate_fractal(int width, int height, int iterations, char *filename) {
    Pixel *image = malloc(width * height * sizeof(Pixel));
    srand(time(NULL));

    for (int i = 0; i < width * height; i++) {
        image[i].r = rand() % 256;
        image[i].g = rand() % 256;
        image[i].b = rand() % 256;
    }

    for (int i = 0; i < iterations; i++) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                int idx = y * width + x;
                int new_r = image[idx].r;
                int new_g = image[idx].g;
                int new_b = image[idx].b;

                if (x > 0) {
                    new_r = (new_r + image[idx - 1].r) / 2;
                    new_g = (new_g + image[idx - 1].g) / 2;
                    new_b = (new_b + image[idx - 1].b) / 2;
                }
                if (x < width - 1) {
                    new_r = (new_r + image[idx + 1].r) / 2;
                    new_g = (new_g + image[idx + 1].g) / 2;
                    new_b = (new_b + image[idx + 1].b) / 2;
                }
                if (y > 0) {
                    new_r = (new_r + image[idx - width].r) / 2;
                    new_g = (new_g + image[idx - width].g) / 2;
                    new_b = (new_b + image[idx - width].b) / 2;
                }
                if (y < height - 1) {
                    new_r = (new_r + image[idx + width].r) / 2;
                    new_g = (new_g + image[idx + width].g) / 2;
                    new_b = (new_b + image[idx + width].b) / 2;
                }

                image[idx].r = new_r;
                image[idx].g = new_g;
                image[idx].b = new_b;
            }
        }
    }

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", filename);
        return;
    }

    fwrite(image, sizeof(Pixel), width * height, fp);
    fclose(fp);

    free(image);
}

int main(int argc, char **argv) {
    int width = IMAGE_WIDTH;
    int height = IMAGE_HEIGHT;
    int iterations = ITERATIONS;
    char *filename = OUTPUT_FILENAME;

    if (argc > 1) {
        width = atoi(argv[1]);
    }
    if (argc > 2) {
        height = atoi(argv[2]);
    }
    if (argc > 3) {
        iterations = atoi(argv[3]);
    }
    if (argc > 4) {
        filename = argv[4];
    }

    generate_fractal(width, height, iterations, filename);

    return 0;
}