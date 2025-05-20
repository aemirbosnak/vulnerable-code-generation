//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel_t;

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <image file> <flip> <brightness>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse command line arguments
    char *image_file = argv[1];
    int flip = atoi(argv[2]);
    int brightness = atoi(argv[3]);

    // Load image from file
    FILE *fp = fopen(image_file, "rb");
    if (fp == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }

    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    pixel_t *pixels = malloc(width * height * sizeof(pixel_t));
    fread(pixels, sizeof(pixel_t), width * height, fp);
    fclose(fp);

    // Flip image horizontally
    if (flip) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width / 2; x++) {
                pixel_t temp = pixels[y * width + x];
                pixels[y * width + x] = pixels[y * width + width - x - 1];
                pixels[y * width + width - x - 1] = temp;
            }
        }
    }

    // Adjust brightness
    for (int i = 0; i < width * height; i++) {
        pixels[i].red = pixels[i].red + brightness;
        pixels[i].green = pixels[i].green + brightness;
        pixels[i].blue = pixels[i].blue + brightness;

        // Clamp pixel values to [0, 255]
        if (pixels[i].red > 255) pixels[i].red = 255;
        if (pixels[i].green > 255) pixels[i].green = 255;
        if (pixels[i].blue > 255) pixels[i].blue = 255;
    }

    // Save image to file
    fp = fopen("output.bmp", "wb");
    if (fp == NULL) {
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite(pixels, sizeof(pixel_t), width * height, fp);
    fclose(fp);

    free(pixels);
    return EXIT_SUCCESS;
}