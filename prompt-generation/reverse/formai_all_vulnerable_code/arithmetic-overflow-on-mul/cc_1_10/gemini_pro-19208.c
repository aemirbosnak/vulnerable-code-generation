//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to flip an image vertically
void flip_vertical(unsigned char *image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[(height - i - 1) * width + j];
            image[(height - i - 1) * width + j] = temp;
        }
    }
}

// Function to flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[i * width + (width - j - 1)];
            image[i * width + (width - j - 1)] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = image[i * width + j] + brightness;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image[i * width + j] = new_value;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, int contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = factor * (image[i * width + j] - 128) + 128;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image[i * width + j] = new_value;
        }
    }
}

// Main function
int main() {
    // Read the input image from a file
    FILE *input_file = fopen("image.bmp", "rb");
    if (input_file == NULL) {
        printf("Error opening the input image file.\n");
        return -1;
    }

    // Get the image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);

    // Allocate memory for the image data
    unsigned char *image = malloc(width * height * sizeof(unsigned char));

    // Read the image data from the file
    fread(image, sizeof(unsigned char), width * height, input_file);

    // Close the input image file
    fclose(input_file);

    // Flip the image vertically
    flip_vertical(image, width, height);

    // Flip the image horizontally
    flip_horizontal(image, width, height);

    // Change the brightness of the image
    change_brightness(image, width, height, 50);

    // Change the contrast of the image
    change_contrast(image, width, height, 20);

    // Write the output image to a file
    FILE *output_file = fopen("output_image.bmp", "wb");
    if (output_file == NULL) {
        printf("Error opening the output image file.\n");
        return -1;
    }

    // Write the image dimensions to the file
    fwrite(&width, sizeof(int), 1, output_file);
    fwrite(&height, sizeof(int), 1, output_file);

    // Write the image data to the file
    fwrite(image, sizeof(unsigned char), width * height, output_file);

    // Close the output image file
    fclose(output_file);

    // Free the memory allocated for the image data
    free(image);

    return 0;
}