//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for BMP file header
#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;       // BMP file type
    unsigned int bfSize;        // Size of the BMP file
    unsigned short bfReserved1;  // Reserved
    unsigned short bfReserved2;  // Reserved
    unsigned int bfOffBits;      // Offset to start of pixel data
} BMPHeader;

// Define a structure for BMP info header
typedef struct {
    unsigned int biSize;         // Size of the BMP info header
    int biWidth;                 // Width of the image
    int biHeight;                // Height of the image
    unsigned short biPlanes;      // Number of color planes
    unsigned short biBitCount;    // Bits per pixel
    unsigned int biCompression;   // Compression type
    unsigned int biSizeImage;     // Size of the image data
    int biXPelsPerMeter;          // Horizontal resolution
    int biYPelsPerMeter;          // Vertical resolution
    unsigned int biClrUsed;       // Number of colors in the palette
    unsigned int biClrImportant;   // Important colors
} BMPInfoHeader;

// Function to encode the message into the BMP image
void encodeMessage(const char *inputBMP, const char *outputBMP, const char *message) {
    FILE *inputFile = fopen(inputBMP, "rb");
    if (!inputFile) {
        perror("Error opening input BMP file");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    // Ensure the BMP is 24 bits per pixel
    if (bmpInfoHeader.biBitCount != 24) {
        printf("Only 24-bit BMP images are supported.\n");
        fclose(inputFile);
        return;
    }

    fseek(inputFile, bmpHeader.bfOffBits, SEEK_SET);

    // Prepare the message for encoding
    int messageLength = strlen(message);
    int messageBitLength = messageLength * 8;
    if (messageBitLength > (bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * 3)) {
        printf("Message is too long to encode in the image.\n");
        fclose(inputFile);
        return;
    }

    // Mark the end of the message
    char terminator = '\0';
    int index = 0;
    unsigned char pixel[3];

    // Encode message into the image
    while (index < messageLength) {
        fread(pixel, sizeof(unsigned char), 3, inputFile);
        for (int j = 0; j < 3; j++) {
            if (index < messageLength * 8) {
                pixel[j] = (pixel[j] & 0xFE) | ((message[index / 8] >> (7 - (index % 8))) & 1);
                index++;
            }
        }
        fseek(inputFile, -3, SEEK_CUR); // Go back
        fwrite(pixel, sizeof(unsigned char), 3, inputFile);
    }
    
    // Encode the null terminator
    while (index < messageBitLength + 8) {
        fread(pixel, sizeof(unsigned char), 3, inputFile);
        for (int j = 0; j < 3 && index < messageBitLength + 8; j++) {
            pixel[j] = (pixel[j] & 0xFE) | ((terminator >> (7 - (index % 8))) & 1);
            index++;
        }
        fseek(inputFile, -3, SEEK_CUR);
        fwrite(pixel, sizeof(unsigned char), 3, inputFile);
    }

    fclose(inputFile);
    
    // Write the modified image to output file
    inputFile = fopen(inputBMP, "rb");
    FILE *outputFile = fopen(outputBMP, "wb");
    if (!outputFile) {
        perror("Error creating output BMP file");
        fclose(inputFile);
        return;
    }

    // Copy the BMP header and info header
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);
    
    // Write modified pixel data
    fseek(inputFile, bmpHeader.bfOffBits, SEEK_SET);
    int pixelCount = bmpInfoHeader.biWidth * bmpInfoHeader.biHeight;
    for (int i = 0; i < pixelCount; i++) {
        fread(pixel, sizeof(unsigned char), 3, inputFile);
        fwrite(pixel, sizeof(unsigned char), 3, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Message encoded successfully in '%s'.\n", outputBMP);
}

// Main function to execute the program
int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_bmp> <output_bmp> <message>\n", argv[0]);
        return 1;
    }

    encodeMessage(argv[1], argv[2], argv[3]);

    return 0;
}