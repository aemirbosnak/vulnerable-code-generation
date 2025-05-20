//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct pixel {
    uint8_t r, g, b;
} pixel_t;

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <image.bmp> <brightness> <contrast>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    fseek(fp, 18, SEEK_SET);
    uint32_t width, height;
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);

    pixel_t *image = malloc(width * height * sizeof(pixel_t));
    fread(image, sizeof(pixel_t), width * height, fp);
    fclose(fp);

    int brightness = atoi(argv[2]);
    int contrast = atoi(argv[3]);

    for (uint32_t i = 0; i < width * height; i++) {
        int r = (int)image[i].r + brightness;
        int g = (int)image[i].g + brightness;
        int b = (int)image[i].b + brightness;

        r = r < 0 ? 0 : r > 255 ? 255 : r;
        g = g < 0 ? 0 : g > 255 ? 255 : g;
        b = b < 0 ? 0 : b > 255 ? 255 : b;

        r = r * contrast / 100;
        g = g * contrast / 100;
        b = b * contrast / 100;

        image[i].r = r;
        image[i].g = g;
        image[i].b = b;
    }

    fp = fopen("output.bmp", "wb");
    if (fp == NULL) {
        perror("Error opening output file");
        free(image);
        return EXIT_FAILURE;
    }

    fseek(fp, 18, SEEK_SET);
    fwrite(&width, 4, 1, fp);
    fwrite(&height, 4, 1, fp);

    fwrite(image, sizeof(pixel_t), width * height, fp);
    fclose(fp);

    free(image);

    return EXIT_SUCCESS;
}