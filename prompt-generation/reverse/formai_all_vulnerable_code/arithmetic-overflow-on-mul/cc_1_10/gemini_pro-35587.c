//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: irregular
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
        perror("Error opening image file");
        return -1;
    }

    // Read the image header
    unsigned char header[54];
    fread(header, 1, 54, image);

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    pixel *data = malloc(width * height * sizeof(pixel));
    if (data == NULL) {
        perror("Error allocating memory for image data");
        fclose(image);
        return -1;
    }

    // Read the image data
    fread(data, sizeof(pixel), width * height, image);

    // Close the image file
    fclose(image);

    // Open the text file containing the message
    FILE *text = fopen("message.txt", "rb");
    if (text == NULL) {
        perror("Error opening text file");
        free(data);
        return -1;
    }

    // Read the message
    char *message = malloc(1024);
    if (message == NULL) {
        perror("Error allocating memory for message");
        fclose(text);
        free(data);
        return -1;
    }

    fread(message, 1, 1024, text);

    // Close the text file
    fclose(text);

    // Hide the message in the image
    int index = 0;
    for (int i = 0; i < width * height; i++) {
        if (index < strlen(message)) {
            data[i].red &= 0xFE;
            data[i].red |= (message[index] >> 7) & 0x01;
            data[i].green &= 0xFE;
            data[i].green |= (message[index] >> 6) & 0x01;
            data[i].blue &= 0xFE;
            data[i].blue |= (message[index] >> 5) & 0x01;
            index++;
        }
    }

    // Open the output image file
    FILE *output = fopen("output.bmp", "wb");
    if (output == NULL) {
        perror("Error opening output image file");
        free(data);
        free(message);
        return -1;
    }

    // Write the image header
    fwrite(header, 1, 54, output);

    // Write the image data
    fwrite(data, sizeof(pixel), width * height, output);

    // Close the output image file
    fclose(output);

    // Free the allocated memory
    free(data);
    free(message);

    return 0;
}