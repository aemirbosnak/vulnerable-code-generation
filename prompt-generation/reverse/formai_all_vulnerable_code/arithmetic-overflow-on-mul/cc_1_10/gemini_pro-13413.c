//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 320
#define HEIGHT 240
#define MAX_VALUE 255

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel_t;

void print_ascii(const pixel_t *pixels, int width, int height) {
    int i, j;
    char *ascii_values = " .,:;#@%";

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int index = (pixels[i * width + j].red + pixels[i * width + j].green + pixels[i * width + j].blue) / (3 * MAX_VALUE);
            printf("%c", ascii_values[index]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    pixel_t *pixels;

    fp = fopen("image.ppm", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read the header information
    char header[256];
    fgets(header, sizeof(header), fp);
    if (strcmp(header, "P6\n") != 0) {
        fprintf(stderr, "Error: Invalid file format\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Read the width and height of the image
    int width, height;
    fscanf(fp, "%d %d\n", &width, &height);

    // Read the maximum value
    int max_value;
    fscanf(fp, "%d\n", &max_value);

    // Allocate memory for the pixel data
    pixels = malloc(sizeof(pixel_t) * width * height);
    if (pixels == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Read the pixel data
    fread(pixels, sizeof(pixel_t), width * height, fp);

    // Close the file
    fclose(fp);

    // Print the ASCII art representation of the image
    print_ascii(pixels, width, height);

    // Free the memory allocated for the pixel data
    free(pixels);

    return EXIT_SUCCESS;
}