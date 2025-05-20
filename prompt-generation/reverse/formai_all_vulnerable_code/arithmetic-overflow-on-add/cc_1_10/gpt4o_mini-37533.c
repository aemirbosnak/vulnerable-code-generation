//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#pragma pack(1) // Disable padding for struct

// BMP file header structure
typedef struct {
    unsigned short type;      // Magic number for BMP
    unsigned int size;       // Size of BMP file
    unsigned short reserved1; // Reserved, must be 0
    unsigned short reserved2; // Reserved, must be 0
    unsigned int offset;     // Offset to start of pixel data
} BMPHeader;

// BMP info header structure
typedef struct {
    unsigned int size;       // Size of this header (40 bytes)
    int width;               // Width of the image
    int height;              // Height of the image
    unsigned short planes;    // Number of color planes (must be 1)
    unsigned short bitsPerPixel; // Bits per pixel
    unsigned int compression; // Compression type
    unsigned int sizeImage;   // Size of raw bitmap data
    int xPixelsPerMeter;      // Horizontal resolution
    int yPixelsPerMeter;      // Vertical resolution
    unsigned int colorsUsed;  // Number of colors in palette
    unsigned int colorsImportant; // Important colors
} BMPInfoHeader;

// Function to convert the image to grayscale
void convertToGrayscale(unsigned char *pixelData, int width, int height) {
    int padding = (4 - (width * 3) % 4) % 4; // Calculate padding for rows
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * (width * 3 + padding)) + (x * 3);
            unsigned char blue = pixelData[index];
            unsigned char green = pixelData[index + 1];
            unsigned char red = pixelData[index + 2];

            // Calculate average for grayscale
            unsigned char gray = (unsigned char)(0.299 * red + 0.587 * green + 0.114 * blue);

            // Set the pixel to grayscale
            pixelData[index] = gray;        // Blue
            pixelData[index + 1] = gray;    // Green
            pixelData[index + 2] = gray;    // Red
        }
    }
}

int main() {
    FILE *inputFile = fopen("input.bmp", "rb");
    if (inputFile == NULL) {
        printf("Error: Could not open input.bmp\n");
        return 1;
    }

    // Read BMP file header
    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);

    // Verify BMP file type
    if (bmpHeader.type != 0x4D42) {
        printf("Error: Not a valid BMP file.\n");
        fclose(inputFile);
        return 1;
    }

    // Read BMP info header
    BMPInfoHeader bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    // Allocate memory for pixel data
    int width = bmpInfoHeader.width;
    int height = bmpInfoHeader.height;
    int padding = (4 - (width * 3) % 4) % 4;
    int pixelDataSize = (width * 3 + padding) * height;

    unsigned char *pixelData = (unsigned char *)malloc(pixelDataSize);
    if (pixelData == NULL) {
        printf("Error: Could not allocate memory for pixel data.\n");
        fclose(inputFile);
        return 1;
    }

    // Read pixel data
    fseek(inputFile, bmpHeader.offset, SEEK_SET);
    fread(pixelData, 1, pixelDataSize, inputFile);
    fclose(inputFile);

    // Convert the image to grayscale
    convertToGrayscale(pixelData, width, height);

    // Save the new image
    FILE *outputFile = fopen("output.bmp", "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open output.bmp for writing.\n");
        free(pixelData);
        return 1;
    }

    // Write BMP file header
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    // Write BMP info header
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);
    // Write pixel data
    fseek(outputFile, bmpHeader.offset, SEEK_SET);
    fwrite(pixelData, 1, pixelDataSize, outputFile);

    // Clean up
    free(pixelData);
    fclose(outputFile);

    printf("Successfully converted the image to grayscale and saved as output.bmp\n");

    return 0;
}