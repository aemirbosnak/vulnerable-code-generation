//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Structure to hold the BMP file header
typedef struct {
    uint16_t bfType;       // File type
    uint32_t bfSize;       // Size of the file
    uint16_t bfReserved1;  // Reserved
    uint16_t bfReserved2;  // Reserved
    uint32_t bfOffBits;    // Offset to start of pixel data
} BMPFileHeader;

// Structure to hold the BMP information header
typedef struct {
    uint32_t biSize;       // Size of this header
    int32_t  biWidth;      // Width of the bitmap
    int32_t  biHeight;     // Height of the bitmap
    uint16_t biPlanes;     // Number of color planes
    uint16_t biBitCount;   // Bits per pixel
    uint32_t biCompression; // Compression type
    uint32_t biSizeImage;  // Size of image data
    int32_t  biXPelsPerMeter; // Horizontal resolution
    int32_t  biYPelsPerMeter; // Vertical resolution
    uint32_t biClrUsed;     // Number of colors
    uint32_t biClrImportant; // Important colors
} BMPInfoHeader;

// Function to read BMP file headers
int readBMPHeaders(FILE *file, BMPFileHeader *fileHeader, BMPInfoHeader *infoHeader) {
    fread(fileHeader, sizeof(BMPFileHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);
    return fileHeader->bfType == 0x4D42; // Check if file type is 'BM'
}

// Function to hide a message in the least significant bits of pixels
void encodeMessage(unsigned char *imageData, const char *message, int width, int height) {
    int messageLength = strlen(message);
    int messageIndex = 0;
    int totalPixels = width * height;

    for (int i = 0; i < totalPixels && messageIndex < messageLength; i++) {
        // Replace the least significant bit of the pixel with message bit
        imageData[i * 3] = (imageData[i * 3] & ~1) | ((message[messageIndex] >> (i % 8)) & 1);
        if ((i + 1) % 8 == 0) {
            messageIndex++;
        }
    }
}

// Function to extract a hidden message from the image
void decodeMessage(unsigned char *imageData, char *message, int width, int height) {
    int totalPixels = width * height;
    for (int i = 0; i < totalPixels; i++) {
        message[i / 8] |= (imageData[i * 3] & 1) << (i % 8);
    }
    message[totalPixels / 8] = '\0'; // Null-terminate the string
}

// Main function to demonstrate BMP image steganography
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_bmp> <output_bmp> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFileName = argv[1];
    const char *outputFileName = argv[2];
    const char *message = argv[3];

    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input BMP file");
        return EXIT_FAILURE;
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    if (!readBMPHeaders(inputFile, &fileHeader, &infoHeader)) {
        fprintf(stderr, "Not a valid BMP file.\n");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    int width = infoHeader.biWidth;
    int height = infoHeader.biHeight;
    int totalPixels = width * height;

    unsigned char *imageData = (unsigned char *)malloc(totalPixels * 3);
    if (!imageData) {
        fprintf(stderr, "Memory allocation error.\n");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    fseek(inputFile, fileHeader.bfOffBits, SEEK_SET);
    fread(imageData, 3, totalPixels, inputFile);
    fclose(inputFile);

    encodeMessage(imageData, message, width, height);

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error opening output BMP file");
        free(imageData);
        return EXIT_FAILURE;
    }

    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, outputFile);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, outputFile);
    fseek(outputFile, fileHeader.bfOffBits, SEEK_SET);
    fwrite(imageData, 3, totalPixels, outputFile);

    fclose(outputFile);
    free(imageData);

    printf("Message encoded successfully!\n");
    return EXIT_SUCCESS;
}