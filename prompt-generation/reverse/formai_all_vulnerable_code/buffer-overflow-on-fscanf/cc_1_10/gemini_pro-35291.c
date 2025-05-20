//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an image
typedef struct Image {
    unsigned char *data;
    int width;
    int height;
} Image;

// Function to load an image from a file
Image *load_image(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    char header[5];
    fread(header, 1, 5, file);
    if (strncmp(header, "P5", 2) != 0) {
        printf("Error: Invalid file format\n");
        fclose(file);
        return NULL;
    }

    // Read the width and height
    int width, height;
    fscanf(file, "%d %d", &width, &height);

    // Read the maximum value
    int max_value;
    fscanf(file, "%d", &max_value);

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height);

    // Read the image data
    fread(image->data, 1, width * height, file);

    // Close the file
    fclose(file);

    // Set the image width and height
    image->width = width;
    image->height = height;

    // Return the image
    return image;
}

// Function to save an image to a file
void save_image(const char *filename, Image *image) {
    // Open the file
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // Write the header
    fprintf(file, "P5\n%d %d\n%d\n", image->width, image->height, 255);

    // Write the image data
    fwrite(image->data, 1, image->width * image->height, file);

    // Close the file
    fclose(file);
}

// Function to flip an image horizontally
void flip_horizontal(Image *image) {
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
void flip_vertical(Image *image) {
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
void change_brightness(Image *image, int brightness) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->data[i * image->width + j] += brightness;
            if (image->data[i * image->width + j] > 255) {
                image->data[i * image->width + j] = 255;
            } else if (image->data[i * image->width + j] < 0) {
                image->data[i * image->width + j] = 0;
            }
        }
    }
}

// Function to change the contrast of an image
void change_contrast(Image *image, int contrast) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->data[i * image->width + j] = (image->data[i * image->width + j] - 128) * contrast + 128;
            if (image->data[i * image->width + j] > 255) {
                image->data[i * image->width + j] = 255;
            } else if (image->data[i * image->width + j] < 0) {
                image->data[i * image->width + j] = 0;
            }
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user has provided enough arguments
    if (argc < 2) {
        printf("Error: Please provide an input image file\n");
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Flip the image horizontally
    flip_horizontal(image);

    // Flip the image vertically
    flip_vertical(image);

    // Change the brightness of the image
    change_brightness(image, 50);

    // Change the contrast of the image
    change_contrast(image, 150);

    // Save the output image
    save_image("output.pgm", image);

    // Free the memory allocated for the image
    free(image->data);
    free(image);

    return 0;
}