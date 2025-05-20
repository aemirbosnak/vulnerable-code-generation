//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Pixel;

int main() {
    // Load the image from a file
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error: could not open image file\n");
        return EXIT_FAILURE;
    }

    // Read the image header
    uint8_t header[54];
    if (fread(header, sizeof(header), 1, image_file) != 1) {
        fprintf(stderr, "Error: could not read image header\n");
        return EXIT_FAILURE;
    }

    // Check if the image is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: invalid BMP file\n");
        return EXIT_FAILURE;
    }

    // Get the image dimensions
    uint32_t width = *(uint32_t *)&header[18];
    uint32_t height = *(uint32_t *)&header[22];

    // Allocate memory for the image data
    Pixel *image_data = malloc(width * height * sizeof(Pixel));
    if (image_data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        return EXIT_FAILURE;
    }

    // Read the image data
    if (fread(image_data, sizeof(Pixel), width * height, image_file) != width * height) {
        fprintf(stderr, "Error: could not read image data\n");
        return EXIT_FAILURE;
    }

    // Close the image file
    fclose(image_file);

    // Load the message from a file
    FILE *message_file = fopen("message.txt", "rb");
    if (message_file == NULL) {
        fprintf(stderr, "Error: could not open message file\n");
        return EXIT_FAILURE;
    }

    // Get the message length
    fseek(message_file, 0, SEEK_END);
    long message_length = ftell(message_file);
    rewind(message_file);

    // Allocate memory for the message
    char *message = malloc(message_length + 1);
    if (message == NULL) {
        fprintf(stderr, "Error: could not allocate memory for message\n");
        return EXIT_FAILURE;
    }

    // Read the message
    if (fread(message, 1, message_length, message_file) != message_length) {
        fprintf(stderr, "Error: could not read message\n");
        return EXIT_FAILURE;
    }

    // Close the message file
    fclose(message_file);

    // Convert the message to binary
    char *binary_message = malloc(message_length * 8 + 1);
    if (binary_message == NULL) {
        fprintf(stderr, "Error: could not allocate memory for binary message\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            binary_message[i * 8 + j] = (message[i] >> j) & 1;
        }
    }

    // Embed the binary message in the image data
    int message_index = 0;
    for (int i = 0; i < width * height; i++) {
        // Get the pixel
        Pixel *pixel = &image_data[i];

        // Modify the least significant bit of each color channel
        pixel->r = (pixel->r & ~1) | binary_message[message_index++];
        pixel->g = (pixel->g & ~1) | binary_message[message_index++];
        pixel->b = (pixel->b & ~1) | binary_message[message_index++];

        // Check if the message has been fully embedded
        if (message_index >= message_length * 8) {
            break;
        }
    }

    // Save the modified image to a file
    FILE *stego_image_file = fopen("stego_image.bmp", "wb");
    if (stego_image_file == NULL) {
        fprintf(stderr, "Error: could not open stego image file\n");
        return EXIT_FAILURE;
    }

    // Write the image header
    if (fwrite(header, sizeof(header), 1, stego_image_file) != 1) {
        fprintf(stderr, "Error: could not write image header\n");
        return EXIT_FAILURE;
    }

    // Write the image data
    if (fwrite(image_data, sizeof(Pixel), width * height, stego_image_file) != width * height) {
        fprintf(stderr, "Error: could not write image data\n");
        return EXIT_FAILURE;
    }

    // Close the stego image file
    fclose(stego_image_file);

    // Free the allocated memory
    free(image_data);
    free(message);
    free(binary_message);

    return EXIT_SUCCESS;
}