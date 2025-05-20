//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: random
// Simple C Program for Image Processing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Structure to store image data
typedef struct {
    int width;
    int height;
    int **data;
} Image;

// Function to read image data from file
Image* read_image(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Unable to open file %s\n", filename);
        return NULL;
    }

    // Read the header information
    int width, height, maxval;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fread(&maxval, sizeof(int), 1, fp);

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(sizeof(int *) * width);
    for (int i = 0; i < width; i++) {
        image->data[i] = malloc(sizeof(int) * height);
    }

    // Read the pixel data
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            fread(image->data[i] + j, sizeof(int), 1, fp);
        }
    }

    // Close the file
    fclose(fp);

    return image;
}

// Function to write image data to file
void write_image(Image *image, char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: Unable to open file %s\n", filename);
        return;
    }

    // Write the header information
    int width = image->width;
    int height = image->height;
    int maxval = 255;
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);
    fwrite(&maxval, sizeof(int), 1, fp);

    // Write the pixel data
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            fwrite(image->data[i] + j, sizeof(int), 1, fp);
        }
    }

    // Close the file
    fclose(fp);
}

// Function to flip an image horizontally
void flip_image_horizontally(Image *image) {
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            int temp = image->data[i][j];
            image->data[i][j] = image->data[image->width - 1 - i][j];
            image->data[image->width - 1 - i][j] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_image_vertically(Image *image) {
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            int temp = image->data[i][j];
            image->data[i][j] = image->data[i][image->height - 1 - j];
            image->data[i][image->height - 1 - j] = temp;
        }
    }
}

// Function to adjust brightness and contrast
void adjust_brightness_contrast(Image *image, int brightness, int contrast) {
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            image->data[i][j] = (image->data[i][j] + brightness) * contrast;
        }
    }
}

int main() {
    // Load the image
    Image *image = read_image("image.pgm");
    if (!image) {
        printf("Error: Unable to read image file\n");
        return 1;
    }

    // Flip the image horizontally
    flip_image_horizontally(image);

    // Flip the image vertically
    flip_image_vertically(image);

    // Adjust the brightness and contrast
    adjust_brightness_contrast(image, 10, 2);

    // Save the image
    write_image(image, "flipped_image.pgm");

    // Free the image data
    for (int i = 0; i < image->width; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);

    return 0;
}