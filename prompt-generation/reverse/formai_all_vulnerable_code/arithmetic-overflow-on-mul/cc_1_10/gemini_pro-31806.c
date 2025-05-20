//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to represent an image
typedef struct {
    unsigned char *data;
    int width, height, channels;
} Image;

// Function to load an image from a file
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[14];
    fread(header, sizeof(header), 1, file);
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: not a valid BMP file\n");
        fclose(file);
        return NULL;
    }

    // Read the dimensions
    unsigned int size = *(unsigned int *)&header[2];
    unsigned int offset = *(unsigned int *)&header[10];
    unsigned int width = *(unsigned int *)&header[18];
    unsigned int height = *(unsigned int *)&header[22];

    // Read the data
    Image *image = malloc(sizeof(Image));
    image->data = malloc(size - offset);
    fseek(file, offset, SEEK_SET);
    fread(image->data, size - offset, 1, file);
    fclose(file);

    // Set the image's dimensions and channels
    image->width = width;
    image->height = height;
    image->channels = 3;

    return image;
}

// Function to save an image to a file
void save_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[14] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0
    };
    *(unsigned int *)&header[2] = sizeof(header) + image->width * image->height * image->channels;
    *(unsigned int *)&header[10] = sizeof(header);
    *(unsigned int *)&header[18] = image->width;
    *(unsigned int *)&header[22] = image->height;
    fwrite(header, sizeof(header), 1, file);

    // Write the data
    fwrite(image->data, image->width * image->height * image->channels, 1, file);
    fclose(file);
}

// Function to flip an image vertically
void flip_vertical(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                unsigned char temp = image->data[i * image->width * image->channels + j * image->channels + k];
                image->data[i * image->width * image->channels + j * image->channels + k] = image->data[(image->height - i - 1) * image->width * image->channels + j * image->channels + k];
                image->data[(image->height - i - 1) * image->width * image->channels + j * image->channels + k] = temp;
            }
        }
    }
}

// Function to flip an image horizontally
void flip_horizontal(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            for (int k = 0; k < image->channels; k++) {
                unsigned char temp = image->data[i * image->width * image->channels + j * image->channels + k];
                image->data[i * image->width * image->channels + j * image->channels + k] = image->data[i * image->width * image->channels + (image->width - j - 1) * image->channels + k];
                image->data[i * image->width * image->channels + (image->width - j - 1) * image->channels + k] = temp;
            }
        }
    }
}

// Function to change the brightness and contrast of an image
void adjust_brightness_contrast(Image *image, float brightness, float contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                int value = image->data[i * image->width * image->channels + j * image->channels + k] + (brightness * 255);
                value = fmax(0, fmin(255, value * contrast));
                image->data[i * image->width * image->channels + j * image->channels + k] = value;
            }
        }
    }
}

int main() {
    // Load the image
    Image *image = load_image("image.bmp");
    if (!image) {
        return 1;
    }

    // Flip the image vertically
    flip_vertical(image);

    // Flip the image horizontally
    flip_horizontal(image);

    // Adjust the image's brightness and contrast
    adjust_brightness_contrast(image, 0.5, 1.2);

    // Save the image
    save_image(image, "output.bmp");

    // Free the image
    free(image->data);
    free(image);

    return 0;
}