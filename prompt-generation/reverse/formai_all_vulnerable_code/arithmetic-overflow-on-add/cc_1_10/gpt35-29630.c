//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 500 /* Maximum size of input image */
#define ASCII_GRADIENT_SIZE 10 /* Number of ASCII gradient shades */
#define ASCII_GRADIENT "@W#%xo:;," /* ASCII gradient shades */

/* Function signatures */
int find_closest_match(int, int, int);
void grayscale(int*, int, int);
void print_ascii(int*, int, int);

/* Find the closest match between RGB values and the gradient shades */
int find_closest_match(int r, int g, int b) {
    int i, distances[ASCII_GRADIENT_SIZE], min_index = 0, min_distance = INT_MAX;
    for (i = 0; i < ASCII_GRADIENT_SIZE; i++) {
        int shade_r = (ASCII_GRADIENT[i] & 0xff0000) >> 16;
        int shade_g = (ASCII_GRADIENT[i] & 0x00ff00) >> 8;
        int shade_b = (ASCII_GRADIENT[i] & 0x0000ff);
        distances[i] = (r - shade_r) * (r - shade_r)
                     + (g - shade_g) * (g - shade_g)
                     + (b - shade_b) * (b - shade_b);
        if (distances[i] < min_distance) {
            min_index = i;
            min_distance = distances[i];
        }
    }
    return min_index;
}

/* Convert input image to grayscale */
void grayscale(int* image, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int r = (image[i * width + j] & 0xff0000) >> 16;
            int g = (image[i * width + j] & 0x00ff00) >> 8;
            int b = (image[i * width + j] & 0x0000ff);
            image[i * width + j] = (r + g + b) / 3;
        }
    }
}

/* Print the ASCII art */
void print_ascii(int* image, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int intensity = image[i * width + j];
            int shade_index = find_closest_match(intensity, intensity, intensity);
            putchar(ASCII_GRADIENT[shade_index]);
        }
        putchar('\n');
    }
}

/* Main function */
int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s input_image_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE* fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file %s: %s\n", argv[1], strerror(errno));
        exit(EXIT_FAILURE);
    }

    /* Read the input image */
    int image[MAX_SIZE * MAX_SIZE], width, height;
    int bytes_read = fread(&width, sizeof(int), 1, fp);
    bytes_read += fread(&height, sizeof(int), 1, fp);
    bytes_read += fread(image, sizeof(int), width * height, fp);
    if (bytes_read != width * height + 2) {
        fprintf(stderr, "Failed to read input image from file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Convert the input image to grayscale */
    grayscale(image, width, height);

    /* Print the ASCII art */
    print_ascii(image, width, height);

    fclose(fp);
    return 0;
}