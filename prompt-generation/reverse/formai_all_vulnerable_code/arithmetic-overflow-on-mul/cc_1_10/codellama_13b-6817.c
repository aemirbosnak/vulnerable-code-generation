//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: creative
/*
 * Basic Image Processing in C
 *
 * Simple tasks like flipping an image, changing brightness/contrast example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IMG_SIZE 1000 // Size of the image
#define MAX_BRIGHTNESS 255 // Maximum brightness value
#define MAX_CONTRAST 100 // Maximum contrast value

typedef struct {
    int r, g, b;
} pixel;

// Function to flip an image horizontally
void flip_horizontal(pixel *img, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            int temp = img[i * width + j].r;
            img[i * width + j].r = img[i * width + (width - j - 1)].r;
            img[i * width + (width - j - 1)].r = temp;

            temp = img[i * width + j].g;
            img[i * width + j].g = img[i * width + (width - j - 1)].g;
            img[i * width + (width - j - 1)].g = temp;

            temp = img[i * width + j].b;
            img[i * width + j].b = img[i * width + (width - j - 1)].b;
            img[i * width + (width - j - 1)].b = temp;
        }
    }
}

// Function to change brightness of an image
void change_brightness(pixel *img, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img[i * width + j].r += brightness;
            img[i * width + j].g += brightness;
            img[i * width + j].b += brightness;
        }
    }
}

// Function to change contrast of an image
void change_contrast(pixel *img, int width, int height, int contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img[i * width + j].r = (int)(((img[i * width + j].r - 128) * contrast / 100) + 128);
            img[i * width + j].g = (int)(((img[i * width + j].g - 128) * contrast / 100) + 128);
            img[i * width + j].b = (int)(((img[i * width + j].b - 128) * contrast / 100) + 128);
        }
    }
}

// Main function
int main() {
    // Load image from file
    FILE *fp = fopen("image.ppm", "r");
    char buffer[100];
    fgets(buffer, 100, fp); // Skip PPM header
    int width, height;
    fscanf(fp, "%d %d", &width, &height);
    pixel *img = malloc(width * height * sizeof(pixel));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(fp, "%d %d %d", &img[i * width + j].r, &img[i * width + j].g, &img[i * width + j].b);
        }
    }
    fclose(fp);

    // Flip image horizontally
    flip_horizontal(img, width, height);

    // Change brightness of image
    change_brightness(img, width, height, 50);

    // Change contrast of image
    change_contrast(img, width, height, 150);

    // Save modified image to file
    fp = fopen("modified_image.ppm", "w");
    fprintf(fp, "P3\n%d %d\n255\n", width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(fp, "%d %d %d ", img[i * width + j].r, img[i * width + j].g, img[i * width + j].b);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);

    return 0;
}