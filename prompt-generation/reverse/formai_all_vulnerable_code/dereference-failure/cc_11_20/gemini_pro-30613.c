//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct pixel {
    unsigned char r, g, b;
};

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <operation>\n", argv[0]);
        return 1;
    }

    // Read the input image
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL) {
        fprintf(stderr, "Error: could not open input image %s\n", argv[1]);
        return 1;
    }

    // Get the image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, input);
    fread(&height, sizeof(int), 1, input);

    // Allocate memory for the input and output images
    struct pixel **input_image = malloc(height * sizeof(struct pixel *));
    struct pixel **output_image = malloc(height * sizeof(struct pixel *));
    for (int i = 0; i < height; i++) {
        input_image[i] = malloc(width * sizeof(struct pixel));
        output_image[i] = malloc(width * sizeof(struct pixel));
    }

    // Read the input image data
    fread(input_image, sizeof(struct pixel), width * height, input);
    fclose(input);

    // Perform the specified operation on the image
    if (strcmp(argv[3], "flip") == 0) {
        // Flip the image vertically
        for (int i = 0; i < height / 2; i++) {
            for (int j = 0; j < width; j++) {
                struct pixel tmp = input_image[i][j];
                input_image[i][j] = input_image[height - i - 1][j];
                input_image[height - i - 1][j] = tmp;
            }
        }
    } else if (strcmp(argv[3], "brighten") == 0) {
        // Brighten the image by 50%
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                input_image[i][j].r = (unsigned char) (input_image[i][j].r * 1.5);
                input_image[i][j].g = (unsigned char) (input_image[i][j].g * 1.5);
                input_image[i][j].b = (unsigned char) (input_image[i][j].b * 1.5);
            }
        }
    } else if (strcmp(argv[3], "contrast") == 0) {
        // Increase the contrast of the image by 50%
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                input_image[i][j].r = (unsigned char) ((input_image[i][j].r - 128) * 1.5 + 128);
                input_image[i][j].g = (unsigned char) ((input_image[i][j].g - 128) * 1.5 + 128);
                input_image[i][j].b = (unsigned char) ((input_image[i][j].b - 128) * 1.5 + 128);
            }
        }
    } else {
        fprintf(stderr, "Error: unknown operation %s\n", argv[3]);
        return 1;
    }

    // Write the output image
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL) {
        fprintf(stderr, "Error: could not open output image %s\n", argv[2]);
        return 1;
    }

    // Write the image dimensions
    fwrite(&width, sizeof(int), 1, output);
    fwrite(&height, sizeof(int), 1, output);

    // Write the image data
    fwrite(output_image, sizeof(struct pixel), width * height, output);
    fclose(output);

    // Free the memory allocated for the images
    for (int i = 0; i < height; i++) {
        free(input_image[i]);
        free(output_image[i]);
    }
    free(input_image);
    free(output_image);

    return 0;
}