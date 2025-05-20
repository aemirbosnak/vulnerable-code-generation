//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

typedef struct {
    int width;
    int height;
    pixel *data;
} image;

image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    image *img = malloc(sizeof(image));
    if (!img) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(file);
        return NULL;
    }

    // Read header
    fread(&img->width, sizeof(int), 1, file);
    fread(&img->height, sizeof(int), 1, file);

    // Allocate memory for data
    img->data = malloc(img->width * img->height * sizeof(pixel));
    if (!img->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(file);
        free(img);
        return NULL;
    }

    // Read data
    fread(img->data, sizeof(pixel), img->width * img->height, file);

    fclose(file);

    return img;
}

void free_image(image *img) {
    free(img->data);
    free(img);
}

void convert_to_ascii(image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            // Calculate brightness
            int brightness = (img->data[y * img->width + x].red + img->data[y * img->width + x].green + img->data[y * img->width + x].blue) / 3;

            // Convert brightness to ASCII character
            char c;
            if (brightness < 32) {
                c = '#';
            } else if (brightness < 64) {
                c = '@';
            } else if (brightness < 96) {
                c = '8';
            } else if (brightness < 128) {
                c = '&';
            } else if (brightness < 160) {
                c = '$';
            } else if (brightness < 192) {
                c = '%';
            } else if (brightness < 224) {
                c = '*';
            } else {
                c = ' ';
            }

            // Print character
            printf("%c", c);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    image *img = load_image(argv[1]);
    if (!img) {
        return 1;
    }

    convert_to_ascii(img);

    free_image(img);

    return 0;
}