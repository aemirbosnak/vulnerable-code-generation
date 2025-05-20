//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the image structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error loading image %s\n", filename);
        return NULL;
    }

    // Read the header
    char header[1024];
    fscanf(fp, "%s", header);
    if (strcmp(header, "P5") != 0) {
        fprintf(stderr, "Error: unsupported image format %s\n", filename);
        fclose(fp);
        return NULL;
    }

    // Read the width and height
    int width, height;
    fscanf(fp, "%d %d", &width, &height);

    // Read the maximum value
    int max_value;
    fscanf(fp, "%d", &max_value);

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(unsigned char));

    // Read the image data
    fread(image->data, sizeof(unsigned char), width * height, fp);

    // Close the file
    fclose(fp);

    return image;
}

// Save an image to a file
void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error saving image %s\n", filename);
        return;
    }

    // Write the header
    fprintf(fp, "P5\n");
    fprintf(fp, "%d %d\n", image->width, image->height);
    fprintf(fp, "255\n");

    // Write the image data
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, fp);

    // Close the file
    fclose(fp);
}

// Flip an image horizontally
void flip_horizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + (image->width - 1 - x)];
            image->data[y * image->width + (image->width - 1 - x)] = temp;
        }
    }
}

// Flip an image vertically
void flip_vertical(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - 1 - y) * image->width + x];
            image->data[(image->height - 1 - y) * image->width + x] = temp;
        }
    }
}

// Change the brightness and contrast of an image
void adjust_brightness_contrast(Image *image, double brightness, double contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int new_value = (int)(image->data[y * image->width + x] * contrast + brightness);
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image->data[y * image->width + x] = new_value;
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Check the command line arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <operation>\n", argv[0]);
        fprintf(stderr, "Operation can be one of the following:\n");
        fprintf(stderr, "    flip_horizontal\n");
        fprintf(stderr, "    flip_vertical\n");
        fprintf(stderr, "    adjust_brightness_contrast <brightness> <contrast>\n");
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    // Perform the specified operation
    if (strcmp(argv[3], "flip_horizontal") == 0) {
        flip_horizontal(image);
    } else if (strcmp(argv[3], "flip_vertical") == 0) {
        flip_vertical(image);
    } else if (strcmp(argv[3], "adjust_brightness_contrast") == 0) {
        if (argc != 6) {
            fprintf(stderr, "adjust_brightness_contrast requires two additional arguments: brightness and contrast\n");
            return 1;
        }
        double brightness = atof(argv[4]);
        double contrast = atof(argv[5]);
        adjust_brightness_contrast(image, brightness, contrast);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[3]);
        return 1;
    }

    // Save the output image
    save_image(image, argv[2]);

    // Free the memory allocated for the image
    free(image->data);
    free(image);

    return 0;
}