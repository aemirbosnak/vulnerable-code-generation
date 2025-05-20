//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: immersive
// Immersive C Image Steganography Example Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Struct to store the pixel data of an image
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
} Pixel;

// Function to hide a message in an image
void hideMessage(char *message, char *imagePath, char *outputPath) {
    // Open the image file
    FILE *imageFile = fopen(imagePath, "r");
    if (imageFile == NULL) {
        printf("Error: Unable to open image file.\n");
        return;
    }

    // Read the image header
    unsigned char header[54];
    fread(header, sizeof(char), 54, imageFile);

    // Get the width and height of the image
    unsigned int width = *(unsigned int *)&header[18];
    unsigned int height = *(unsigned int *)&header[22];

    // Calculate the number of pixels in the image
    unsigned int numPixels = width * height;

    // Read the image data
    Pixel *pixels = malloc(numPixels * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), numPixels, imageFile);

    // Close the image file
    fclose(imageFile);

    // Hide the message in the image
    unsigned int messageLength = strlen(message);
    unsigned int messageIndex = 0;
    for (unsigned int i = 0; i < numPixels; i++) {
        // Get the current pixel
        Pixel pixel = pixels[i];

        // Check if the pixel is a valid pixel
        if (pixel.red != 0 && pixel.green != 0 && pixel.blue != 0) {
            // Hide the message in the pixel
            pixel.red = message[messageIndex];
            pixel.green = message[messageIndex];
            pixel.blue = message[messageIndex];
            pixel.alpha = 255;

            // Increment the message index
            messageIndex++;

            // Check if we have reached the end of the message
            if (messageIndex == messageLength) {
                break;
            }
        }

        // Update the pixel
        pixels[i] = pixel;
    }

    // Create a new image file
    FILE *outputFile = fopen(outputPath, "w");
    if (outputFile == NULL) {
        printf("Error: Unable to create output file.\n");
        return;
    }

    // Write the image header
    fwrite(header, sizeof(char), 54, outputFile);

    // Write the image data
    fwrite(pixels, sizeof(Pixel), numPixels, outputFile);

    // Close the output file
    fclose(outputFile);
}

// Function to retrieve the hidden message from an image
void retrieveMessage(char *imagePath, char *message) {
    // Open the image file
    FILE *imageFile = fopen(imagePath, "r");
    if (imageFile == NULL) {
        printf("Error: Unable to open image file.\n");
        return;
    }

    // Read the image header
    unsigned char header[54];
    fread(header, sizeof(char), 54, imageFile);

    // Get the width and height of the image
    unsigned int width = *(unsigned int *)&header[18];
    unsigned int height = *(unsigned int *)&header[22];

    // Calculate the number of pixels in the image
    unsigned int numPixels = width * height;

    // Read the image data
    Pixel *pixels = malloc(numPixels * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), numPixels, imageFile);

    // Close the image file
    fclose(imageFile);

    // Retrieve the hidden message
    unsigned int messageLength = 0;
    for (unsigned int i = 0; i < numPixels; i++) {
        // Get the current pixel
        Pixel pixel = pixels[i];

        // Check if the pixel is a valid pixel
        if (pixel.red != 0 && pixel.green != 0 && pixel.blue != 0) {
            // Retrieve the message from the pixel
            message[messageLength] = pixel.red;
            message[messageLength] = pixel.green;
            message[messageLength] = pixel.blue;

            // Increment the message length
            messageLength++;
        }
    }

    // Add a null terminator to the message
    message[messageLength] = '\0';
}

int main() {
    // Hide the message in the image
    char *message = "Hello, World!";
    char *imagePath = "image.bmp";
    char *outputPath = "output.bmp";
    hideMessage(message, imagePath, outputPath);

    // Retrieve the hidden message from the image
    char *message2 = malloc(strlen(message) + 1);
    char *imagePath2 = "output.bmp";
    retrieveMessage(imagePath2, message2);

    // Print the retrieved message
    printf("Retrieved message: %s\n", message2);

    // Free the memory allocated for the message
    free(message2);

    return 0;
}