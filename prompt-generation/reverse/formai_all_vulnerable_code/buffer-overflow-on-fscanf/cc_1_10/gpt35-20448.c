//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define image structure
typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

// Function to load image
Image *load_image(char *filename) {
    FILE *file;
    Image *image;

    // Open file
    file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Allocate memory for image
    image = malloc(sizeof(Image));
    if (!image) {
        printf("Error allocating memory for image\n");
        return NULL;
    }

    // Read header information
    fscanf(file, "P6\n%d %d\n255\n", &image->width, &image->height);

    // Set number of channels
    image->channels = 3;

    // Allocate memory for image data
    image->data = malloc(image->width * image->height * image->channels);
    if (!image->data) {
        printf("Error allocating memory for image data\n");
        return NULL;
    }

    // Read image data
    fread(image->data, image->width * image->height * image->channels, 1, file);

    // Close file
    fclose(file);

    return image;
}

// Function to save image
void save_image(Image *image, char *filename) {
    FILE *file;

    // Open file
    file = fopen(filename, "wb");
    if (!file) {
        printf("Error opening file %s\n", filename);
        return;
    }

    // Write header information
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);

    // Write image data
    fwrite(image->data, image->width * image->height * image->channels, 1, file);

    // Close file
    fclose(file);
}

// Function to flip image horizontally
void flip_horizontal(Image *image) {
    int row_size = image->width * image->channels;
    int half_row = row_size / 2;
    unsigned char *temp = malloc(row_size);
    int i, j;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < half_row; j++) {
            // Swap pixels
            temp[j] = image->data[i * row_size + j];
            image->data[i * row_size + j] = image->data[(i + 1) * row_size - (j + 1)];
            image->data[(i + 1) * row_size - (j + 1)] = temp[j];
        }
    }

    free(temp);
}

// Function to adjust brightness and contrast
void brightness_contrast(Image *image, int brightness, int contrast) {
    int i;

    for (i = 0; i < image->width * image->height * image->channels; i++) {
        int value = image->data[i] + brightness;

        if (value < 0) {
            value = 0;
        } else if (value > 255) {
            value = 255;
        }

        image->data[i] = (unsigned char)(value + (value - 127) * contrast / 127);
    }
}

int main() {
    // Load image
    Image *image = load_image("input.ppm");
    if (!image) {
        return 1;
    }

    // Flip image horizontally
    flip_horizontal(image);

    // Adjust brightness and contrast
    brightness_contrast(image, 50, 50);

    // Save image
    save_image(image, "output.ppm");

    // Free memory
    free(image->data);
    free(image);

    return 0;
}