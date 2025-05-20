//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - 1 - j];
            image[i * width + width - 1 - j] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertical(unsigned char *image, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            unsigned char temp = image[i * width + j];
            image[i * width + j] = image[(height - 1 - i) * width + j];
            image[(height - 1 - i) * width + j] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = image[i * width + j] + brightness;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image[i * width + j] = new_value;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, float contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int new_value = (image[i * width + j] - 128) * contrast + 128;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image[i * width + j] = new_value;
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Check if the user has provided the correct number of arguments
    if (argc != 5) {
        printf("Usage: %s <input_image> <output_image> <operation> <parameter>\n", argv[0]);
        printf("Where <operation> can be one of the following: flip_horizontal, flip_vertical, change_brightness, change_contrast\n");
        return 1;
    }

    // Read the input image
    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input image file\n");
        return 1;
    }

    // Get the dimensions of the input image
    int width, height;
    fscanf(input_file, "%d %d\n", &width, &height);

    // Allocate memory for the input image
    unsigned char *image = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    if (image == NULL) {
        printf("Error allocating memory for input image\n");
        return 1;
    }

    // Read the input image data
    fread(image, sizeof(unsigned char), width * height, input_file);
    fclose(input_file);

    // Perform the specified operation on the input image
    if (strcmp(argv[3], "flip_horizontal") == 0) {
        flip_horizontal(image, width, height);
    } else if (strcmp(argv[3], "flip_vertical") == 0) {
        flip_vertical(image, width, height);
    } else if (strcmp(argv[3], "change_brightness") == 0) {
        int brightness = atoi(argv[4]);
        change_brightness(image, width, height, brightness);
    } else if (strcmp(argv[3], "change_contrast") == 0) {
        float contrast = atof(argv[4]);
        change_contrast(image, width, height, contrast);
    } else {
        printf("Invalid operation specified\n");
        return 1;
    }

    // Write the output image
    FILE *output_file = fopen(argv[2], "wb");
    if (output_file == NULL) {
        printf("Error opening output image file\n");
        return 1;
    }

    // Write the dimensions of the output image
    fprintf(output_file, "%d %d\n", width, height);

    // Write the output image data
    fwrite(image, sizeof(unsigned char), width * height, output_file);
    fclose(output_file);

    // Free the memory allocated for the input image
    free(image);

    return 0;
}