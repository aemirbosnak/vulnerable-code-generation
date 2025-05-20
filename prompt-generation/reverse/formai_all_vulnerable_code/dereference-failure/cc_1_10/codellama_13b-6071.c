//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
/*
 * Image Steganography Program
 *
 * This program demonstrates a basic implementation of image
 * steganography using a LSB (Least Significant Bit) method.
 *
 * Usage: ./steganography [input image] [output image] [message]
 *
 * Example: ./steganography input.bmp output.bmp "Hello World"
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the RGB pixel
struct RGB {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

// Function to hide the message in the image
void hide_message(struct RGB *image, char *message, int length) {
    // Iterate through the image pixels
    for (int i = 0; i < length; i++) {
        // Get the current pixel
        struct RGB pixel = image[i];

        // Set the LSB of the red, green, and blue channels to the corresponding
        // character in the message
        pixel.r = pixel.r & 0xFE | (message[i] >> 2);
        pixel.g = pixel.g & 0xFE | (message[i] >> 1);
        pixel.b = pixel.b & 0xFE | (message[i] >> 0);

        // Store the modified pixel back in the image
        image[i] = pixel;
    }
}

// Function to extract the message from the image
char *extract_message(struct RGB *image, int length) {
    // Create a buffer to store the extracted message
    char *message = malloc(length);

    // Iterate through the image pixels
    for (int i = 0; i < length; i++) {
        // Get the current pixel
        struct RGB pixel = image[i];

        // Extract the LSB of the red, green, and blue channels
        int r = pixel.r & 0x01;
        int g = pixel.g & 0x01;
        int b = pixel.b & 0x01;

        // Combine the LSBs to form a single character
        message[i] = (r << 2) | (g << 1) | (b << 0);
    }

    return message;
}

int main(int argc, char *argv[]) {
    // Check the number of command-line arguments
    if (argc != 4) {
        printf("Usage: %s [input image] [output image] [message]\n", argv[0]);
        return 1;
    }

    // Open the input image
    FILE *input = fopen(argv[1], "rb");
    if (!input) {
        printf("Error: Unable to open input image\n");
        return 1;
    }

    // Open the output image
    FILE *output = fopen(argv[2], "wb");
    if (!output) {
        printf("Error: Unable to open output image\n");
        fclose(input);
        return 1;
    }

    // Read the input image into a buffer
    fseek(input, 0, SEEK_END);
    long length = ftell(input);
    fseek(input, 0, SEEK_SET);
    char *image = malloc(length);
    fread(image, 1, length, input);

    // Hide the message in the image
    hide_message((struct RGB *)image, argv[3], strlen(argv[3]));

    // Write the modified image to the output file
    fwrite(image, 1, length, output);

    // Free the memory allocated for the image buffer
    free(image);

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}