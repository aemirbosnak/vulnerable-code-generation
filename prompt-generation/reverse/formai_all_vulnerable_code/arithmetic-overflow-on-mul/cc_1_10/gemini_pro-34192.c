//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multivariable
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Structure to represent an image
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Function to load an image from a file
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the header information
    unsigned char header[54];
    fread(header, sizeof(header), 1, file);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a valid BMP file\n", filename);
        fclose(file);
        return NULL;
    }

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    unsigned char *data = malloc(width * height * 3);
    if (data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(file);
        return NULL;
    }

    // Read the image data
    fread(data, width * height * 3, 1, file);

    // Close the file
    fclose(file);

    // Create the image struct
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image struct\n");
        free(data);
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

// Function to free the memory allocated for an image
void free_image(Image *image) {
    if (image != NULL) {
        free(image->data);
        free(image);
    }
}

// Function to flip an image horizontally
void flip_image_horizontal(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width / 2; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - j - 1];
            image->data[i * image->width + image->width - j - 1] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_image_vertical(Image *image) {
    int i, j;
    for (i = 0; i < image->height / 2; i++) {
        for (j = 0; j < image->width; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - i - 1) * image->width + j];
            image->data[(image->height - i - 1) * image->width + j] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_image_brightness(Image *image, double brightness) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->data[i * image->width + j] = (unsigned char)fmin(255, image->data[i * image->width + j] * brightness);
        }
    }
}

// Function to change the contrast of an image
void change_image_contrast(Image *image, double contrast) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            double temp = ((double)image->data[i * image->width + j] / 255 - 0.5) * contrast + 0.5;
            image->data[i * image->width + j] = (unsigned char)fmin(255, fmax(0, temp * 255));
        }
    }
}

// Function to save an image to a file
void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header information
    unsigned char header[54] = {
        0x42, 0x4D, 0x36, 0x8C, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
        0x00, 0x00, 0xC0, 0x3E, 0x00, 0x00, 0xC0, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };

    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;

    fwrite(header, sizeof(header), 1, file);

    // Write the image data
    fwrite(image->data, image->width * image->height * 3, 1, file);

    // Close the file
    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input.bmp output.bmp\n", argv[0]);
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (image == NULL) {
        fprintf(stderr, "Error loading input image %s\n", argv[1]);
        return 1;
    }

    // Flip the image horizontally
    flip_image_horizontal(image);

    // Flip the image vertically
    flip_image_vertical(image);

    // Change the image brightness
    change_image_brightness(image, 1.5);

    // Change the image contrast
    change_image_contrast(image, 2.0);

    // Save the output image
    save_image(argv[2], image);

    // Free the memory allocated for the image
    free_image(image);

    return 0;
}