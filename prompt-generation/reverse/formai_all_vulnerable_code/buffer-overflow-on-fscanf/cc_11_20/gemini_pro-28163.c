//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    unsigned char r, g, b;
} pixel;

pixel image[WIDTH][HEIGHT];

char *ascii = " .,-~:;=-ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int main() {
    FILE *fp = fopen("image.ppm", "rb");
    if (fp == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }

    char header[100];
    if (fscanf(fp, "%s", header) != 1) {
        perror("Error reading image header");
        return EXIT_FAILURE;
    }

    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Error: unsupported image format\n");
        return EXIT_FAILURE;
    }

    int width, height, maxval;
    if (fscanf(fp, "%d %d %d", &width, &height, &maxval) != 3) {
        perror("Error reading image size and maxval");
        return EXIT_FAILURE;
    }

    if (width != WIDTH || height != HEIGHT) {
        fprintf(stderr, "Error: unsupported image size\n");
        return EXIT_FAILURE;
    }

    if (maxval != 255) {
        fprintf(stderr, "Error: unsupported maxval\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fread(&image[i][j], sizeof(pixel), 1, fp);
        }
    }

    fclose(fp);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            float gray = (image[i][j].r + image[i][j].g + image[i][j].b) / 3.0;
            int index = (int)roundf(gray / 255.0 * (strlen(ascii) - 1));
            printf("%c", ascii[index]);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}