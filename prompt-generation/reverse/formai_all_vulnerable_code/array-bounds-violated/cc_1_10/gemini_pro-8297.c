//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: satisfied
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
    FILE *image = fopen("image.bmp", "rb");
    if (image == NULL) {
        printf("Error opening image file\n");
        return 1;
    }

    // Read the image header
    unsigned char header[54];
    fread(header, 54, 1, image);

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    pixel *data = malloc(width * height * sizeof(pixel));
    if (data == NULL) {
        printf("Error allocating memory for image data\n");
        fclose(image);
        return 1;
    }

    // Read the image data
    fread(data, width * height * sizeof(pixel), 1, image);

    // Close the image file
    fclose(image);

    // Get the message to hide
    printf("Enter the message to hide: ");
    char message[1024];
    fgets(message, 1024, stdin);

    // Convert the message to binary
    int messageLength = strlen(message);
    unsigned char binaryMessage[messageLength * 8];
    for (int i = 0; i < messageLength; i++) {
        for (int j = 0; j < 8; j++) {
            binaryMessage[i * 8 + j] = (message[i] >> j) & 1;
        }
    }

    // Hide the message in the image data
    int bitIndex = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Get the current pixel
            pixel *pixel = &data[i * width + j];

            // Set the least significant bit of the red channel to the next bit of the message
            pixel->red = (pixel->red & ~1) | binaryMessage[bitIndex++];

            // Set the least significant bit of the green channel to the next bit of the message
            pixel->green = (pixel->green & ~1) | binaryMessage[bitIndex++];

            // Set the least significant bit of the blue channel to the next bit of the message
            pixel->blue = (pixel->blue & ~1) | binaryMessage[bitIndex++];
        }
    }

    // Open the output image file
    FILE *output = fopen("output.bmp", "wb");
    if (output == NULL) {
        printf("Error opening output image file\n");
        free(data);
        return 1;
    }

    // Write the image header to the output file
    fwrite(header, 54, 1, output);

    // Write the image data to the output file
    fwrite(data, width * height * sizeof(pixel), 1, output);

    // Close the output image file
    fclose(output);

    // Free the memory allocated for the image data
    free(data);

    // Success!
    printf("Message successfully hidden in image\n");
    return 0;
}