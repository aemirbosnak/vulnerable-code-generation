//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

int main() {
    // Open the image file
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }

    // Read the image header
    unsigned char header[54];
    fread(header, sizeof(header), 1, image_file);

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    unsigned char *image_data = malloc(width * height * 3);
    if (image_data == NULL) {
        perror("Error allocating memory for image data");
        fclose(image_file);
        return EXIT_FAILURE;
    }

    // Read the image data
    fread(image_data, width * height * 3, 1, image_file);

    // Close the image file
    fclose(image_file);

    // Get the message to be hidden
    char *message = "Hello, world!";
    int message_length = strlen(message);

    // Hide the message in the image data
    int i;
    for (i = 0; i < message_length; i++) {
        // Get the ASCII code of the character
        unsigned char character = message[i];

        // Convert the ASCII code to binary
        unsigned char binary[8];
        int j;
        for (j = 0; j < 8; j++) {
            binary[j] = (character >> j) & 1;
        }

        // Hide the binary code in the image data
        for (j = 0; j < 8; j++) {
            image_data[i * 8 + j] &= 0xFE;
            image_data[i * 8 + j] |= binary[j];
        }
    }

    // Open the output image file
    FILE *output_image_file = fopen("output_image.bmp", "wb");
    if (output_image_file == NULL) {
        perror("Error opening output image file");
        free(image_data);
        return EXIT_FAILURE;
    }

    // Write the image header
    fwrite(header, sizeof(header), 1, output_image_file);

    // Write the image data
    fwrite(image_data, width * height * 3, 1, output_image_file);

    // Close the output image file
    fclose(output_image_file);

    // Free the memory allocated for the image data
    free(image_data);

    return EXIT_SUCCESS;
}