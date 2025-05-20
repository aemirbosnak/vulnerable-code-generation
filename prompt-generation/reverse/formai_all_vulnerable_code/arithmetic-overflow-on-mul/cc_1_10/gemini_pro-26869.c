//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

int main() {
    // Open the image file
    FILE *image = fopen("image.bmp", "rb");
    if (!image) {
        fprintf(stderr, "Error opening image file\n");
        return EXIT_FAILURE;
    }

    // Read the image header
    unsigned char header[54];
    fread(header, sizeof(header), 1, image);

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    Pixel *data = malloc(width * height * sizeof(Pixel));
    if (!data) {
        fprintf(stderr, "Error allocating memory for image data\n");
        return EXIT_FAILURE;
    }

    // Read the image data
    fread(data, sizeof(Pixel), width * height, image);
    fclose(image);

    // Open the text file
    FILE *text = fopen("text.txt", "rb");
    if (!text) {
        fprintf(stderr, "Error opening text file\n");
        return EXIT_FAILURE;
    }

    // Read the text
    char *message = malloc(1000);
    if (!message) {
        fprintf(stderr, "Error allocating memory for text\n");
        return EXIT_FAILURE;
    }
    fread(message, 1, 1000, text);
    fclose(text);

    // Hide the text in the image
    int i, j, k;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (k = 0; k < 3; k++) {
                if (k == 2) {
                    data[i * width + j].b = message[i * width * 3 + j * 3 + k];
                } else {
                    data[i * width + j].g = message[i * width * 3 + j * 3 + k];
                }
            }
        }
    }

    // Open the output image file
    FILE *output = fopen("output.bmp", "wb");
    if (!output) {
        fprintf(stderr, "Error opening output image file\n");
        return EXIT_FAILURE;
    }

    // Write the image header
    fwrite(header, sizeof(header), 1, output);

    // Write the image data
    fwrite(data, sizeof(Pixel), width * height, output);
    fclose(output);

    // Free the allocated memory
    free(data);
    free(message);

    return EXIT_SUCCESS;
}