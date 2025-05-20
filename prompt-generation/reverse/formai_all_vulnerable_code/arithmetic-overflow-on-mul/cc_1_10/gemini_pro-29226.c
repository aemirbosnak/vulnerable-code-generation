//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - 1 - j];
            image[i * width + width - 1 - j] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertical(unsigned char *image, int width, int height) {
    int i, j;
    for (i = 0; i < height / 2; i++) {
        for (j = 0; j < width; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[(height - 1 - i) * width + j];
            image[(height - 1 - i) * width + j] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i * width + j] += brightness;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, int contrast) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            image[i * width + j] *= contrast;
        }
    }
}

// Main function
int main() {
    // Read image from file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }

    // Get image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Allocate memory for image data
    unsigned char *image = malloc(width * height);
    if (image == NULL) {
        perror("Error allocating memory for image data");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Read image data from file
    fread(image, width * height, 1, fp);

    fclose(fp);

    // Flip image horizontally
    flip_horizontal(image, width, height);

    // Flip image vertically
    flip_vertical(image, width, height);

    // Change image brightness
    change_brightness(image, width, height, 50);

    // Change image contrast
    change_contrast(image, width, height, 1.5);

    // Write modified image to file
    fp = fopen("modified_image.bmp", "wb");
    if (fp == NULL) {
        perror("Error opening modified image file");
        free(image);
        return EXIT_FAILURE;
    }

    // Write image dimensions to file
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);

    // Write image data to file
    fwrite(image, width * height, 1, fp);

    fclose(fp);

    free(image);

    return EXIT_SUCCESS;
}