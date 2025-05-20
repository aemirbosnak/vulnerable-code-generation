//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256

int main() {
    int i, j;
    unsigned char *image = (unsigned char *)malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Set the image to a gradient
            int value = (i * j) % 256;
            image[j * WIDTH + i] = value;
        }
    }

    // Flip the image
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH / 2; j++) {
            int temp = image[i * WIDTH + j];
            image[i * WIDTH + j] = image[i * WIDTH + WIDTH - j - 1];
            image[i * WIDTH + WIDTH - j - 1] = temp;
        }
    }

    // Change the brightness
    int brightness = 50;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int value = image[i * WIDTH + j] + brightness;
            if (value > 255) {
                value = 255;
            } else if (value < 0) {
                value = 0;
            }
            image[i * WIDTH + j] = value;
        }
    }

    // Change the contrast
    int contrast = 50;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int value = (image[i * WIDTH + j] * contrast) / 100;
            if (value > 255) {
                value = 255;
            } else if (value < 0) {
                value = 0;
            }
            image[i * WIDTH + j] = value;
        }
    }

    // Save the modified image
    FILE *fp = fopen("modified_image.bmp", "wb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    free(image);

    return 0;
}