//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

struct ascii_image {
    int width;
    int height;
    char pixels[MAX_WIDTH * MAX_HEIGHT];
};

void convert_image(struct ascii_image *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    // Read the image header
    unsigned char header[18];
    fread(header, 1, 18, fp);

    // Check if the image is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Invalid BMP file\n");
        exit(1);
    }

    // Get the image width and height
    image->width = *(unsigned int *)&header[18];
    image->height = *(unsigned int *)&header[22];

    // Check if the image is too large
    if (image->width > MAX_WIDTH || image->height > MAX_HEIGHT) {
        fprintf(stderr, "Image is too large\n");
        exit(1);
    }

    // Read the image data
    fread(image->pixels, 1, image->width * image->height, fp);
    fclose(fp);

    // Convert the image data to ASCII art
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            // Get the pixel value
            unsigned char pixel = image->pixels[y * image->width + x];

            // Convert the pixel value to an ASCII character
            char c;
            if (pixel < 64) {
                c = ' ';
            } else if (pixel < 128) {
                c = '.';
            } else if (pixel < 192) {
                c = ':';
            } else {
                c = '#';
            }

            // Print the ASCII character
            printf("%c", c);
        }

        // Print a newline character
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    struct ascii_image image;
    convert_image(&image, argv[1]);

    return 0;
}