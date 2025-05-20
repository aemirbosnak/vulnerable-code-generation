//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
/*
 * Simple Image Processing Program
 *
 * This program demonstrates basic image processing techniques
 * such as flipping an image, changing brightness/contrast
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define BYTES_PER_PIXEL 3

/*
 * Function to flip an image horizontally
 */
void flip_horizontally(unsigned char *image, int width, int height) {
    int x, y;
    unsigned char temp;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width / 2; x++) {
            temp = image[(y * width + x) * BYTES_PER_PIXEL];
            image[(y * width + x) * BYTES_PER_PIXEL] = image[(y * width + (width - x - 1)) * BYTES_PER_PIXEL];
            image[(y * width + (width - x - 1)) * BYTES_PER_PIXEL] = temp;
        }
    }
}

/*
 * Function to change brightness and contrast of an image
 */
void change_brightness_contrast(unsigned char *image, int width, int height, int brightness, int contrast) {
    int x, y;
    int new_pixel;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            new_pixel = (image[(y * width + x) * BYTES_PER_PIXEL] * contrast) / 255 + brightness;
            if (new_pixel > 255) {
                new_pixel = 255;
            }
            else if (new_pixel < 0) {
                new_pixel = 0;
            }
            image[(y * width + x) * BYTES_PER_PIXEL] = new_pixel;
        }
    }
}

int main() {
    unsigned char *image = (unsigned char *)malloc(WIDTH * HEIGHT * BYTES_PER_PIXEL);

    // Read image from file
    FILE *fp = fopen("image.ppm", "rb");
    fread(image, 1, WIDTH * HEIGHT * BYTES_PER_PIXEL, fp);
    fclose(fp);

    // Flip image horizontally
    flip_horizontally(image, WIDTH, HEIGHT);

    // Change brightness and contrast of image
    change_brightness_contrast(image, WIDTH, HEIGHT, 100, 200);

    // Write modified image to file
    fp = fopen("modified_image.ppm", "wb");
    fwrite(image, 1, WIDTH * HEIGHT * BYTES_PER_PIXEL, fp);
    fclose(fp);

    free(image);

    return 0;
}