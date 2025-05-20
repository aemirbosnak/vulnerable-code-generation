//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 50

typedef struct {
    unsigned char r, g, b;
} pixel;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    char header[3];
    if (fread(header, sizeof(header), 1, fp) != 1) {
        fprintf(stderr, "fread failed\n");
        return EXIT_FAILURE;
    }

    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Invalid image format\n");
        return EXIT_FAILURE;
    }

    int width, height;
    if (fscanf(fp, "%d %d", &width, &height) != 2) {
        fprintf(stderr, "fscanf failed\n");
        return EXIT_FAILURE;
    }

    if (width > WIDTH || height > HEIGHT) {
        fprintf(stderr, "Image too large\n");
        return EXIT_FAILURE;
    }

    int maxval;
    if (fscanf(fp, "%d", &maxval) != 1) {
        fprintf(stderr, "fscanf failed\n");
        return EXIT_FAILURE;
    }

    if (maxval != 255) {
        fprintf(stderr, "Invalid maxval\n");
        return EXIT_FAILURE;
    }

    pixel pixels[WIDTH * HEIGHT];
    if (fread(pixels, sizeof(pixel), WIDTH * HEIGHT, fp) != WIDTH * HEIGHT) {
        fprintf(stderr, "fread failed\n");
        return EXIT_FAILURE;
    }

    fclose(fp);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            pixel p = pixels[y * WIDTH + x];
            double brightness = (p.r + p.g + p.b) / 3.0 / 255.0;
            char c = ".,:;+*#@@$%&"[(int)(brightness * 15)];
            printf("%c", c);
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}