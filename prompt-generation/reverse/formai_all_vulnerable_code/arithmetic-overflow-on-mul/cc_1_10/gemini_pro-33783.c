//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to represent an image
typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

// Function to read an image from a file
Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the header information
    int width, height, channels;
    fscanf(fp, "P3\n%d %d\n255\n", &width, &height, &channels);

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->channels = channels;
    image->data = malloc(width * height * channels);

    // Read the image data
    fread(image->data, width * height * channels, 1, fp);

    // Close the file
    fclose(fp);

    return image;
}

// Function to write an image to a file
void write_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header information
    fprintf(fp, "P3\n%d %d\n255\n", image->width, image->height, image->channels);

    // Write the image data
    fwrite(image->data, image->width * image->height * image->channels, 1, fp);

    // Close the file
    fclose(fp);
}

// Function to flip an image vertically
void flip_vertical(Image *image) {
    int i, j, tmp;
    for (i = 0; i < image->height / 2; i++) {
        for (j = 0; j < image->width; j++) {
            for (tmp = 0; tmp < image->channels; tmp++) {
                unsigned char *p1 = &image->data[(i * image->width + j) * image->channels + tmp];
                unsigned char *p2 = &image->data[((image->height - i - 1) * image->width + j) * image->channels + tmp];
                tmp = *p1;
                *p1 = *p2;
                *p2 = tmp;
            }
        }
    }
}

// Function to flip an image horizontally
void flip_horizontal(Image *image) {
    int i, j, tmp;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width / 2; j++) {
            for (tmp = 0; tmp < image->channels; tmp++) {
                unsigned char *p1 = &image->data[(i * image->width + j) * image->channels + tmp];
                unsigned char *p2 = &image->data[(i * image->width + (image->width - j - 1)) * image->channels + tmp];
                tmp = *p1;
                *p1 = *p2;
                *p2 = tmp;
            }
        }
    }
}

// Function to change the brightness and contrast of an image
void adjust_brightness_contrast(Image *image, float brightness, float contrast) {
    int i, j, k;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            for (k = 0; k < image->channels; k++) {
                int value = image->data[(i * image->width + j) * image->channels + k];
                value += (int)(brightness * 255);
                value *= contrast;
                if (value > 255) {
                    value = 255;
                } else if (value < 0) {
                    value = 0;
                }
                image->data[(i * image->width + j) * image->channels + k] = value;
            }
        }
    }
}

// Main function
int main() {
    // Read the input image
    Image *image = read_image("input.ppm");

    // Flip the image vertically
    flip_vertical(image);

    // Flip the image horizontally
    flip_horizontal(image);

    // Adjust the brightness and contrast of the image
    adjust_brightness_contrast(image, 0.5, 1.2);

    // Write the output image
    write_image("output.ppm", image);

    // Free the memory allocated for the image
    free(image->data);
    free(image);

    return 0;
}