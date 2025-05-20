//FormAI DATASET v1.0 Category: Image Steganography ; Style: random
/* A unique implementation of Image Steganography in C */
#include <stdio.h>

// Function to set the least significant bit to a specified value
void setLSB(unsigned char *byte, int bit) {
    int mask = 1;
    *byte = (*byte & ~(mask)) | (bit & mask);
}

// Function to extract the least significant bit from a byte
int getLSB(unsigned char byte) {
    return byte & 1;
}

int main() {
    // Open the input image file
    FILE *inputFile = fopen("input.bmp", "rb");
    if (!inputFile) {
        printf("Error: failed to open input file.\n");
        return 1;
    }

    // Open the output image file
    FILE *outputFile = fopen("output.bmp", "wb");
    if (!outputFile) {
        printf("Error: failed to open output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Read the image header data
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, inputFile);

    // Write the image header data to the output file
    fwrite(header, sizeof(unsigned char), 54, outputFile);

    // Determine the number of pixels in the image
    int numPixels = ((header[18] << 24) | (header[19] << 16) | (header[20] << 8) | header[21]) / 3;

    // Read and write one pixel at a time, hiding message data in the least significant bit of each color component
    int i, j;
    unsigned char pixel[3];
    unsigned char messageByte;
    for (i = 0; i < numPixels; i++) {
        // Read one pixel from the input file
        fread(pixel, sizeof(unsigned char), 3, inputFile);

        // Read one byte of message data from the user
        printf("Enter one character of message data: ");
        scanf("%c", &messageByte);

        // Hide the message data in the least significant bit of each color component
        setLSB(&pixel[0], messageByte & 1);
        setLSB(&pixel[1], (messageByte >> 1) & 1);
        setLSB(&pixel[2], (messageByte >> 2) & 1);

        // Write the modified pixel to the output file
        fwrite(pixel, sizeof(unsigned char), 3, outputFile);
    }

    // Close the input and output files and exit
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}