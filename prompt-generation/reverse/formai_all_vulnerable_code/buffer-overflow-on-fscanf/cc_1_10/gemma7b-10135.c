//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

typedef struct ImageData {
    int width;
    int height;
    unsigned char **pixels;
} ImageData;

ImageData *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return NULL;
    }

    ImageData *image = malloc(sizeof(ImageData));
    image->width = 0;
    image->height = 0;
    image->pixels = NULL;

    // Read image header
    fscanf(fp, "PBM %d %d ", &image->width, &image->height);

    // Allocate pixels
    image->pixels = (unsigned char **)malloc(image->height * sizeof(unsigned char *));
    for (int i = 0; i < image->height; i++) {
        image->pixels[i] = (unsigned char *)malloc(image->width * sizeof(unsigned char));
    }

    // Read image data
    fread(image->pixels, image->width * image->height * 3, 1, fp);

    fclose(fp);
    return image;
}

void convert_image_to_ascii(ImageData *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int r = image->pixels[y][x] & 0xFF;
            int g = (image->pixels[y][x] & 0xFF00) >> 8;
            int b = (image->pixels[y][x] & 0xFF0000) >> 16;

            // Convert RGB to ASCII
            int ascii_value = (r * 299 + g * 587 + b * 114) / 1000 + 32;

            // Print ASCII character
            printf("%c ", ascii_value);
        }
        printf("\n");
    }
}

int main() {
    ImageData *image = load_image("image.pbm");
    convert_image_to_ascii(image);
    free(image);

    return 0;
}