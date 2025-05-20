//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: standalone
// Basic Image Processing in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to hold image data
typedef struct {
    int width;
    int height;
    int channels;
    int *data;
} Image;

// Function to flip an image horizontally
void flip_image_horizontally(Image *image) {
    int i, j;
    int *data = image->data;
    int width = image->width;
    int height = image->height;
    int channels = image->channels;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width / 2; j++) {
            int idx1 = i * width * channels + j * channels;
            int idx2 = i * width * channels + (width - 1 - j) * channels;

            // Swap the pixel values
            int tmp = data[idx1];
            data[idx1] = data[idx2];
            data[idx2] = tmp;
        }
    }
}

// Function to change the brightness and contrast of an image
void adjust_brightness_contrast(Image *image, float brightness, float contrast) {
    int i, j;
    int *data = image->data;
    int width = image->width;
    int height = image->height;
    int channels = image->channels;

    // Calculate the new pixel values
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int idx = i * width * channels + j * channels;

            data[idx] = (int)((data[idx] - 128) * contrast) + 128;
            data[idx] = data[idx] + brightness;
        }
    }
}

// Example usage
int main() {
    // Create an image object
    Image image = {
        .width = 512,
        .height = 512,
        .channels = 3,
        .data = NULL
    };

    // Allocate memory for the image data
    image.data = (int *)malloc(image.width * image.height * image.channels * sizeof(int));

    // Initialize the image data with random values
    for (int i = 0; i < image.width * image.height * image.channels; i++) {
        image.data[i] = rand() % 255;
    }

    // Flip the image horizontally
    flip_image_horizontally(&image);

    // Adjust the brightness and contrast of the image
    adjust_brightness_contrast(&image, 20, 1.5);

    // Save the modified image to a file
    FILE *fp = fopen("modified_image.bmp", "wb");
    fwrite(image.data, sizeof(int), image.width * image.height * image.channels, fp);
    fclose(fp);

    return 0;
}