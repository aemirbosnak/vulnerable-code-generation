//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024 * 1024 * 3
#define MAX_MESSAGE_SIZE 1024 * 1024

// Hides a secret message in an image.
int main(int argc, char *argv[]) {
    // Check arguments.
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the input image.
    FILE *input_image = fopen(argv[1], "rb");
    if (input_image == NULL) {
        fprintf(stderr, "Error opening input image: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Read the input image into memory.
    unsigned char *image_data = malloc(MAX_IMAGE_SIZE);
    if (image_data == NULL) {
        fprintf(stderr, "Error allocating memory for input image\n");
        return EXIT_FAILURE;
    }
    size_t image_size = fread(image_data, 1, MAX_IMAGE_SIZE, input_image);
    fclose(input_image);

    // Check the image size.
    if (image_size > MAX_IMAGE_SIZE) {
        fprintf(stderr, "Error: Input image is too large\n");
        return EXIT_FAILURE;
    }

    // Get the message to hide.
    char *message = argv[3];

    // Check the message size.
    size_t message_size = strlen(message);
    if (message_size > MAX_MESSAGE_SIZE) {
        fprintf(stderr, "Error: Message is too large\n");
        return EXIT_FAILURE;
    }

    // Hide the message in the image.
    for (size_t i = 0; i < message_size; i++) {
        // Get the next byte of the message.
        unsigned char byte = message[i];

        // Convert the byte to a binary string.
        char binary_string[8];
        for (int j = 0; j < 8; j++) {
            binary_string[j] = (byte >> (7 - j)) & 1;
        }

        // Hide the binary string in the image.
        for (int j = 0; j < 8; j++) {
            // Get the least significant bit of the pixel.
            unsigned char lsb = image_data[i * 8 + j] & 1;

            // Set the least significant bit to the value of the binary string.
            image_data[i * 8 + j] = (image_data[i * 8 + j] & ~1) | (binary_string[j] & 1);

            // Shift the binary string to the right.
            for (int k = j + 1; k < 8; k++) {
                binary_string[k - 1] = binary_string[k];
            }
            binary_string[7] = lsb;
        }
    }

    // Open the output image.
    FILE *output_image = fopen(argv[2], "wb");
    if (output_image == NULL) {
        fprintf(stderr, "Error opening output image: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    // Write the output image to disk.
    fwrite(image_data, 1, image_size, output_image);
    fclose(output_image);

    // Free the memory.
    free(image_data);

    return EXIT_SUCCESS;
}