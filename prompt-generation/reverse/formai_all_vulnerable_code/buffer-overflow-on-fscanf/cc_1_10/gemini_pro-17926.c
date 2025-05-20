//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Image struct
typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

// Function to read an image from a file
Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the header
    int width, height;
    fscanf(fp, "P5\n%d %d\n255\n", &width, &height);

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    if (image->data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        free(image);
        return NULL;
    }

    // Read the image data
    fread(image->data, sizeof(unsigned char), width * height, fp);

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

    // Write the header
    fprintf(fp, "P5\n%d %d\n255\n", image->width, image->height);

    // Write the image data
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, fp);

    // Close the file
    fclose(fp);
}

// Function to flip an image horizontally
void flip_horizontally(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - x - 1];
            image->data[y * image->width + image->width - x - 1] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertically(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(Image *image, double factor) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->data[y * image->width + x] = (unsigned char) (image->data[y * image->width + x] * factor);
        }
    }
}

// Function to change the contrast of an image
void change_contrast(Image *image, double factor) {
    double mean = 0;
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            mean += image->data[y * image->width + x];
        }
    }
    mean /= image->width * image->height;

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->data[y * image->width + x] = (unsigned char) ((image->data[y * image->width + x] - mean) * factor + mean);
        }
    }
}

int main() {
    // Read the input image
    Image *image = read_image("input.pgm");
    if (image == NULL) {
        return 1;
    }

    // Flip the image horizontally
    flip_horizontally(image);

    // Flip the image vertically
    flip_vertically(image);

    // Change the brightness of the image
    change_brightness(image, 1.5);

    // Change the contrast of the image
    change_contrast(image, 1.2);

    // Write the output image
    write_image("output.pgm", image);

    // Free the memory allocated for the image
    free(image->data);
    free(image);

    return 0;
}