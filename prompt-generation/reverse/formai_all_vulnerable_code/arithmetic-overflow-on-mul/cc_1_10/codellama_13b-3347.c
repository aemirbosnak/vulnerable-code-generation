//Code Llama-13B DATASET v1.0 Category: Image Steganography ; Style: relaxed
// Example C Image Steganography Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Struct to represent a pixel
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

// Function to embed a secret message in an image
void embedMessage(const char* message, const char* imagePath, const char* outputPath) {
    // Read the image
    FILE* imageFile = fopen(imagePath, "rb");
    if (imageFile == NULL) {
        printf("Error: Could not open image file.\n");
        return;
    }

    // Read the image header
    char header[54];
    fread(header, 54, 1, imageFile);

    // Read the image data
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int pixelCount = width * height;
    Pixel* pixels = malloc(pixelCount * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), pixelCount, imageFile);
    fclose(imageFile);

    // Embed the secret message in the image data
    int messageLength = strlen(message);
    int bitCount = 0;
    for (int i = 0; i < pixelCount; i++) {
        // Get the current pixel
        Pixel* pixel = &pixels[i];

        // Get the current bit
        char bit = message[bitCount / 8] >> (7 - (bitCount % 8));
        bit &= 1;

        // Embed the bit in the pixel data
        if (bit == 0) {
            // Leave the pixel data unchanged
        } else {
            // Flip the red, green, and blue channels
            pixel->r = 255 - pixel->r;
            pixel->g = 255 - pixel->g;
            pixel->b = 255 - pixel->b;
        }

        // Increment the bit count
        bitCount++;

        // Check if we have reached the end of the message
        if (bitCount == messageLength * 8) {
            break;
        }
    }

    // Write the modified image data to a new file
    FILE* outputFile = fopen(outputPath, "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        return;
    }
    fwrite(header, 54, 1, outputFile);
    fwrite(pixels, sizeof(Pixel), pixelCount, outputFile);
    fclose(outputFile);

    // Free the pixel array
    free(pixels);
}

// Function to extract a secret message from an image
void extractMessage(const char* imagePath) {
    // Read the image
    FILE* imageFile = fopen(imagePath, "rb");
    if (imageFile == NULL) {
        printf("Error: Could not open image file.\n");
        return;
    }

    // Read the image header
    char header[54];
    fread(header, 54, 1, imageFile);

    // Read the image data
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int pixelCount = width * height;
    Pixel* pixels = malloc(pixelCount * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), pixelCount, imageFile);
    fclose(imageFile);

    // Extract the secret message from the image data
    char message[1024];
    int messageLength = 0;
    int bitCount = 0;
    for (int i = 0; i < pixelCount; i++) {
        // Get the current pixel
        Pixel* pixel = &pixels[i];

        // Get the current bit
        char bit = 0;
        if (pixel->r == 255 - pixel->r &&
            pixel->g == 255 - pixel->g &&
            pixel->b == 255 - pixel->b) {
            bit = 1;
        }

        // Add the bit to the message
        message[bitCount / 8] |= bit << (7 - (bitCount % 8));

        // Increment the bit count
        bitCount++;

        // Check if we have reached the end of the message
        if (bitCount == messageLength * 8) {
            break;
        }
    }

    // Print the extracted message
    printf("Extracted message: %s\n", message);

    // Free the pixel array
    free(pixels);
}

int main() {
    // Example message to embed
    const char* message = "Hello, world!";

    // Example image to embed the message in
    const char* imagePath = "image.bmp";

    // Example output image
    const char* outputPath = "output.bmp";

    // Embed the message in the image
    embedMessage(message, imagePath, outputPath);

    // Extract the message from the image
    extractMessage(outputPath);

    return 0;
}