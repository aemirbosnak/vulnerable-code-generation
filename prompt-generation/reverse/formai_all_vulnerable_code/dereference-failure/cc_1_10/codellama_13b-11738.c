//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cyberpunk
/*
 * Cyberpunk-style image processing in C
 *
 * This program demonstrates simple image processing tasks such as
 * flipping an image and changing brightness/contrast.
 *
 * Usage:
 * 1. Compile the program with a C compiler.
 * 2. Run the program with the following arguments:
 *    <input image file> <output image file> <operation>
 *    where <operation> is one of the following:
 *    - flip (flip the image horizontally)
 *    - brightness (change brightness of the image)
 *    - contrast (change contrast of the image)
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMAGE_WIDTH 640
#define IMAGE_HEIGHT 480
#define IMAGE_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT)

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel_t;

pixel_t *image;

void read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: unable to open file '%s'\n", filename);
        exit(1);
    }

    image = malloc(sizeof(pixel_t) * IMAGE_SIZE);
    if (!image) {
        printf("Error: unable to allocate memory for image\n");
        exit(1);
    }

    fread(image, sizeof(pixel_t), IMAGE_SIZE, fp);
    fclose(fp);
}

void write_image(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: unable to open file '%s'\n", filename);
        exit(1);
    }

    fwrite(image, sizeof(pixel_t), IMAGE_SIZE, fp);
    fclose(fp);
}

void flip_image() {
    pixel_t temp;
    for (int i = 0; i < IMAGE_SIZE; i++) {
        temp = image[i];
        image[i] = image[IMAGE_SIZE - i - 1];
        image[IMAGE_SIZE - i - 1] = temp;
    }
}

void adjust_brightness(float brightness) {
    for (int i = 0; i < IMAGE_SIZE; i++) {
        image[i].r += brightness;
        image[i].g += brightness;
        image[i].b += brightness;
    }
}

void adjust_contrast(float contrast) {
    for (int i = 0; i < IMAGE_SIZE; i++) {
        image[i].r = (image[i].r - 128) * contrast + 128;
        image[i].g = (image[i].g - 128) * contrast + 128;
        image[i].b = (image[i].b - 128) * contrast + 128;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input image file> <output image file> <operation>\n", argv[0]);
        printf("Operations: flip, brightness, contrast\n");
        exit(1);
    }

    read_image(argv[1]);

    if (strcmp(argv[3], "flip") == 0) {
        flip_image();
    } else if (strcmp(argv[3], "brightness") == 0) {
        adjust_brightness(atof(argv[4]));
    } else if (strcmp(argv[3], "contrast") == 0) {
        adjust_contrast(atof(argv[4]));
    } else {
        printf("Error: invalid operation '%s'\n", argv[3]);
        exit(1);
    }

    write_image(argv[2]);

    return 0;
}