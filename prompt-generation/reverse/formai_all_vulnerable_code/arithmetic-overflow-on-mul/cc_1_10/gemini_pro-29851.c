//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - 1 - j];
            image[i * width + width - 1 - j] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertical(unsigned char *image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[(height - 1 - i) * width + j];
            image[(height - 1 - i) * width + j] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_pixel = image[i * width + j] + brightness;
            if (new_pixel > 255) {
                new_pixel = 255;
            } else if (new_pixel < 0) {
                new_pixel = 0;
            }
            image[i * width + j] = new_pixel;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, int contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_pixel = factor * (image[i * width + j] - 128) + 128;
            if (new_pixel > 255) {
                new_pixel = 255;
            } else if (new_pixel < 0) {
                new_pixel = 0;
            }
            image[i * width + j] = new_pixel;
        }
    }
}

int main() {
    // Read the image from a file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Get the image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Allocate memory for the image data
    unsigned char *image = malloc(width * height);
    if (image == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return -1;
    }

    // Read the image data from the file
    fread(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    // Flip the image horizontally
    flip_horizontal(image, width, height);

    // Change the brightness of the image
    change_brightness(image, width, height, 50);

    // Change the contrast of the image
    change_contrast(image, width, height, 20);

    // Write the modified image to a file
    fp = fopen("modified_image.bmp", "wb");
    if (fp == NULL) {
        perror("Error opening file");
        free(image);
        return -1;
    }

    // Write the image dimensions to the file
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);

    // Write the image data to the file
    fwrite(image, sizeof(unsigned char), width * height, fp);
    fclose(fp);

    // Free the memory allocated for the image data
    free(image);

    return 0;
}