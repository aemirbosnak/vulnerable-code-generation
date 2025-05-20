//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Embed a secret message into an image
void embedMessage(char *imageFile, char *message) {
    FILE *image = fopen(imageFile, "rb+");
    if (image == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Read the image header
    unsigned char header[54];
    fread(header, 54, 1, image);

    // Get the image width and height
    int width = header[18] | (header[19] << 8);
    int height = header[22] | (header[23] << 8);

    // Get the message length
    int messageLength = strlen(message);

    // Check if the message is too long to fit in the image
    if (messageLength > width * height * 3) {
        fprintf(stderr, "Error: Message is too long to fit in the image\n");
        exit(1);
    }

    // Embed the message in the image
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (k = 0; k < 3; k++) {
                // Get the current pixel value
                unsigned char pixel = fgetc(image);

                // Embed the message bit in the least significant bit of the pixel value
                pixel = (pixel & ~1) | ((message[i * width * 3 + j * 3 + k] >> k) & 1);

                // Write the modified pixel value back to the image
                fseek(image, -1, SEEK_CUR);
                fputc(pixel, image);
            }
        }
    }

    // Close the image file
    fclose(image);
}

// Extract the secret message from an image
char *extractMessage(char *imageFile) {
    FILE *image = fopen(imageFile, "rb");
    if (image == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Read the image header
    unsigned char header[54];
    fread(header, 54, 1, image);

    // Get the image width and height
    int width = header[18] | (header[19] << 8);
    int height = header[22] | (header[23] << 8);

    // Allocate memory for the message
    char *message = malloc(width * height * 3 + 1);
    if (message == NULL) {
        perror("Error allocating memory for message");
        exit(1);
    }

    // Extract the message from the image
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            for (k = 0; k < 3; k++) {
                // Get the current pixel value
                unsigned char pixel = fgetc(image);

                // Extract the message bit from the least significant bit of the pixel value
                message[i * width * 3 + j * 3 + k] = (pixel & 1) << k;
            }
        }
    }

    // Null-terminate the message
    message[width * height * 3] = '\0';

    // Close the image file
    fclose(image);

    // Return the message
    return message;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        exit(1);
    }

    // Embed the message in the image
    embedMessage(argv[1], argv[3]);

    // Extract the message from the image
    char *message = extractMessage(argv[2]);

    // Print the message
    printf("%s\n", message);

    // Free the memory allocated for the message
    free(message);

    return 0;
}