//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Load an image from a file into an array
void load_image(char *filename, unsigned char **image, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Read the header information
    unsigned char header[14];
    fread(header, sizeof(header), 1, file);

    // Ensure that the file is a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: File is not a BMP file\n");
        exit(1);
    }

    // Read the width and height of the image
    *width = header[18] + (header[19] << 8);
    *height = header[22] + (header[23] << 8);

    // Allocate memory for the image data
    *image = malloc(*width * *height * sizeof(unsigned char));
    if (*image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        exit(1);
    }

    // Read the image data
    fread(*image, *width * *height * sizeof(unsigned char), 1, file);

    // Close the file
    fclose(file);
}

// Save an image to a file from an array
void save_image(char *filename, unsigned char *image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    // Write the header information
    unsigned char header[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    header[2] = (unsigned char) ((width * height * 3) % 256);
    header[3] = (unsigned char) ((width * height * 3) / 256);
    fwrite(header, sizeof(header), 1, file);

    // Write the width and height of the image
    unsigned char width_bytes[4] = {(unsigned char) (width % 256), (unsigned char) (width / 256), 0, 0};
    fwrite(width_bytes, sizeof(width_bytes), 1, file);
    unsigned char height_bytes[4] = {(unsigned char) (height % 256), (unsigned char) (height / 256), 0, 0};
    fwrite(height_bytes, sizeof(height_bytes), 1, file);

    // Write the image data
    fwrite(image, width * height * sizeof(unsigned char), 1, file);

    // Close the file
    fclose(file);
}

// Flip an image horizontally
void flip_horizontally(unsigned char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - j - 1];
            image[i * width + width - j - 1] = temp;
        }
    }
}

// Flip an image vertically
void flip_vertically(unsigned char *image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[(height - i - 1) * width + j];
            image[(height - i - 1) * width + j] = temp;
        }
    }
}

// Change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = image[i * width + j] + brightness;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image[i * width + j] = (unsigned char) new_value;
        }
    }
}

// Change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, float contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = (image[i * width + j] - 128) * contrast + 128;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image[i * width + j] = (unsigned char) new_value;
        }
    }
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_image> <output_image>\n", argv[0]);
        exit(1);
    }

    // Load the image
    unsigned char *image;
    int width, height;
    load_image(argv[1], &image, &width, &height);

    // Flip the image horizontally
    flip_horizontally(image, width, height);

    // Change the brightness of the image
    change_brightness(image, width, height, 50);

    // Change the contrast of the image
    change_contrast(image, width, height, 1.5);

    // Save the image
    save_image(argv[2], image, width, height);

    // Free the memory allocated for the image
    free(image);

    return 0;
}