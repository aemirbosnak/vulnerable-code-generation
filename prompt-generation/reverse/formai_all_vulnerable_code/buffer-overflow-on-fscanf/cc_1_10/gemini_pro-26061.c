//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the image structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Read an image from a file
Image *readImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the image header
    int width, height;
    if (fscanf(file, "P5 %d %d\n", &width, &height) != 2) {
        fprintf(stderr, "Error: could not read image header\n");
        fclose(file);
        return NULL;
    }

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(file);
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(unsigned char));
    if (!image->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        free(image);
        fclose(file);
        return NULL;
    }

    // Read the image data
    if (fread(image->data, sizeof(unsigned char), width * height, file) != width * height) {
        fprintf(stderr, "Error: could not read image data\n");
        free(image->data);
        free(image);
        fclose(file);
        return NULL;
    }

    fclose(file);

    return image;
}

// Write an image to a file
void writeImage(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the image header
    fprintf(file, "P5 %d %d\n", image->width, image->height);

    // Write the image data
    if (fwrite(image->data, sizeof(unsigned char), image->width * image->height, file) != image->width * image->height) {
        fprintf(stderr, "Error: could not write image data\n");
        fclose(file);
        return;
    }

    fclose(file);
}

// Flip an image horizontally
void flipHorizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - x - 1];
            image->data[y * image->width + image->width - x - 1] = temp;
        }
    }
}

// Flip an image vertically
void flipVertical(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

// Change the brightness of an image
void changeBrightness(Image *image, int delta) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int value = image->data[y * image->width + x] + delta;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image->data[y * image->width + x] = value;
        }
    }
}

// Change the contrast of an image
void changeContrast(Image *image, float factor) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int value = (image->data[y * image->width + x] - 127.5) * factor + 127.5;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image->data[y * image->width + x] = value;
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <operation>\n", argv[0]);
        return 1;
    }

    // Read the input image
    Image *image = readImage(argv[1]);
    if (!image) {
        return 1;
    }

    // Perform the specified operation on the image
    const char *operation = argv[3];
    if (strcmp(operation, "flip-horizontal") == 0) {
        flipHorizontal(image);
    } else if (strcmp(operation, "flip-vertical") == 0) {
        flipVertical(image);
    } else if (strcmp(operation, "change-brightness") == 0) {
        int delta = atoi(argv[4]);
        changeBrightness(image, delta);
    } else if (strcmp(operation, "change-contrast") == 0) {
        float factor = atof(argv[4]);
        changeContrast(image, factor);
    } else {
        fprintf(stderr, "Error: unknown operation %s\n", operation);
        free(image->data);
        free(image);
        return 1;
    }

    // Write the output image
    writeImage(image, argv[2]);

    // Free the memory allocated for the image
    free(image->data);
    free(image);

    return 0;
}