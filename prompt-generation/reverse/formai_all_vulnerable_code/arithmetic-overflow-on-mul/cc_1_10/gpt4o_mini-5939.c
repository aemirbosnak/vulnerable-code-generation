//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short type;
    unsigned int size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int offset; 
} BMPHeader;

typedef struct {
    unsigned int size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int sizeImage;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int importantColors;
} BMPInfoHeader;
#pragma pack(pop)

void embedMessage(const char* inputImagePath, const char* outputImagePath, const char* message) {
    FILE *inputFile = fopen(inputImagePath, "rb");
    if (!inputFile) {
        perror("Input file opening failed");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    // Read the BMP headers
    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    // Message length and null-terminator
    size_t messageLength = strlen(message);
    if (messageLength > (bmpInfoHeader.width * bmpInfoHeader.height * 3) / 8 - 1) {
        fprintf(stderr, "Message is too long to hide in this image.\n");
        fclose(inputFile);
        return;
    }

    // Create output image
    FILE *outputFile = fopen(outputImagePath, "wb");
    if (!outputFile) {
        perror("Output file opening failed");
        fclose(inputFile);
        return;
    }

    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outputFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outputFile);

    // Copy the image data while embedding the message
    unsigned char pixel[3];
    long long i;
    for (i = 0; i < bmpInfoHeader.width * bmpInfoHeader.height * 3; i += 3) {
        fread(pixel, sizeof(unsigned char), 3, inputFile);

        if (i / 3 < messageLength) {
            // Replace the least significant bit of each color component with the message bits
            unsigned char bit = (message[i / 3] >> (i % 8)) & 1;
            pixel[0] = (pixel[0] & 0xFE) | bit;  // Change LSB of Red
        }

        fwrite(pixel, sizeof(unsigned char), 3, outputFile);
    }

    fclose(inputFile);
    fclose(outputFile);
}

void extractMessage(const char* imagePath) {
    FILE *inputFile = fopen(imagePath, "rb");
    if (!inputFile) {
        perror("File opening failed");
        return;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;

    // Read the BMP headers
    fread(&bmpHeader, sizeof(BMPHeader), 1, inputFile);
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inputFile);

    unsigned char pixel[3];
    char message[256] = {0};  // Predefine the size of the message
    long long i;

    for (i = 0; i < bmpInfoHeader.width * bmpInfoHeader.height * 3; i += 3) {
        fread(pixel, sizeof(unsigned char), 3, inputFile);
        
        if (i / 3 < 256) {
            // Extract LSB of Red to recover the message
            unsigned char bit = pixel[0] & 1; 
            message[i / 3] |= (bit << (i % 8));

            if (message[i / 3] == '\0' && i / 3 != 0) {
                break;  // Stop reading if we encounter null character
            }
        }
    }

    printf("Extracted message: %s\n", message);
    fclose(inputFile);
}

int main() {
    const char* inputImage = "input.bmp"; // The BMP image file must exist in the same directory
    const char* outputImage = "output.bmp";
    const char* secretMessage = "Hello, this is a secret message!";

    embedMessage(inputImage, outputImage, secretMessage);
    printf("Message embedded successfully!\n");

    printf("Extracting message from the output image...\n");
    extractMessage(outputImage);

    return 0;
}