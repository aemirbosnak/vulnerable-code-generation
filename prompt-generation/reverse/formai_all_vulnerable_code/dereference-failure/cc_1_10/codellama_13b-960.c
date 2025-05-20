//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: standalone
// C Image Steganography Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_MSG_LENGTH 100

// Struct to store an image
typedef struct {
    int width;
    int height;
    int channels;
    int stride;
    unsigned char *data;
} Image;

// Function to read an image from a file
Image readImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    // Read the image header
    int width, height, channels;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    fread(&channels, sizeof(int), 1, file);

    // Allocate memory for the image data
    int stride = width * channels;
    unsigned char *data = (unsigned char *)malloc(stride * height * sizeof(unsigned char));

    // Read the image data
    fread(data, stride, height, file);

    // Close the file
    fclose(file);

    // Return the image
    Image image;
    image.width = width;
    image.height = height;
    image.channels = channels;
    image.stride = stride;
    image.data = data;
    return image;
}

// Function to write an image to a file
void writeImage(const char *filename, Image image) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    // Write the image header
    fwrite(&image.width, sizeof(int), 1, file);
    fwrite(&image.height, sizeof(int), 1, file);
    fwrite(&image.channels, sizeof(int), 1, file);

    // Write the image data
    fwrite(image.data, image.stride, image.height, file);

    // Close the file
    fclose(file);
}

// Function to embed a message in an image
void embedMessage(Image image, char *message, int length) {
    // Calculate the number of pixels needed to store the message
    int pixels = (length + 7) / 8;

    // Calculate the starting position of the message in the image
    int x = 0, y = 0;
    while (x < image.width && y < image.height) {
        // Check if the pixel at (x, y) is black
        int index = y * image.stride + x * image.channels;
        if (image.data[index] == 0 && image.data[index + 1] == 0 && image.data[index + 2] == 0) {
            // Embed the message in the pixel
            for (int i = 0; i < length; i++) {
                // Calculate the index of the pixel to embed the message
                int pixelIndex = y * image.stride + x * image.channels + i / 8;

                // Embed the message bit in the pixel
                if (message[i] == '1') {
                    image.data[pixelIndex] |= 1 << (7 - i % 8);
                } else {
                    image.data[pixelIndex] &= ~(1 << (7 - i % 8));
                }
            }

            // Increment the starting position of the message
            x++;
            if (x >= image.width) {
                x = 0;
                y++;
            }

            // Break the loop if the message has been fully embedded
            if (x == 0 && y == 0) {
                break;
            }
        }

        // Increment the starting position of the message
        x++;
        if (x >= image.width) {
            x = 0;
            y++;
        }
    }
}

// Function to extract a message from an image
void extractMessage(Image image, char *message, int length) {
    // Calculate the number of pixels needed to store the message
    int pixels = (length + 7) / 8;

    // Initialize the message
    memset(message, 0, length);

    // Extract the message from the image
    int x = 0, y = 0;
    for (int i = 0; i < length; i++) {
        // Calculate the index of the pixel to extract the message
        int pixelIndex = y * image.stride + x * image.channels + i / 8;

        // Extract the message bit from the pixel
        if (image.data[pixelIndex] & (1 << (7 - i % 8))) {
            message[i] = '1';
        } else {
            message[i] = '0';
        }

        // Increment the starting position of the message
        x++;
        if (x >= image.width) {
            x = 0;
            y++;
        }
    }
}

int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 4) {
        printf("Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    // Read the input image
    Image inputImage = readImage(argv[1]);

    // Embed the message in the image
    char message[MAX_MSG_LENGTH];
    strncpy(message, argv[3], MAX_MSG_LENGTH);
    embedMessage(inputImage, message, strlen(argv[3]));

    // Write the output image
    writeImage(argv[2], inputImage);

    // Extract the message from the output image
    extractMessage(inputImage, message, strlen(argv[3]));

    // Print the extracted message
    printf("Extracted message: %s\n", message);

    return 0;
}