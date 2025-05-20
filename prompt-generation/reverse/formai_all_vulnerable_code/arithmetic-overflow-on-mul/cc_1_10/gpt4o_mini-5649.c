//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: Dennis Ritchie
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
    unsigned short bitCount;
    unsigned int compression;
    unsigned int sizeImage;
    int xPixelsPerMeter;
    int yPixelsPerMeter;
    unsigned int colorsUsed;
    unsigned int colorsImportant;
} BMPInfoHeader;
#pragma pack(pop)

void embedMessageInBMP(const char* inputFileName, const char* outputFileName, const char* message) {
    FILE *bmpFile = fopen(inputFileName, "rb");
    if (!bmpFile) {
        perror("Error opening input BMP file");
        return;
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, bmpFile);
    if (bmpHeader.type != 0x4D42) {
        fprintf(stderr, "Not a BMP file\n");
        fclose(bmpFile);
        return;
    }

    BMPInfoHeader bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, bmpFile);

    // Calculate the size of the message (including null-terminator)
    size_t messageLength = strlen(message) + 1; // +1 for null-terminator

    // Check if there is enough space in the BMP file to embed the message
    int totalPixels = bmpInfoHeader.width * bmpInfoHeader.height;
    if (messageLength > totalPixels) {
        fprintf(stderr, "Message is too long to fit in the image\n");
        fclose(bmpFile);
        return;
    }

    fseek(bmpFile, bmpHeader.offset, SEEK_SET);
    
    unsigned char pixel[3]; // BMP uses 3 bytes per pixel (BGR)
    for (size_t i = 0; i < messageLength; i++) {
        fread(pixel, 1, 3, bmpFile);
        
        // Embed one bit of the message into the least significant bit
        pixel[0] = (pixel[0] & 0xFE) | ((message[i] >> 0) & 0x01);
        pixel[1] = (pixel[1] & 0xFE) | ((message[i] >> 1) & 0x01);
        pixel[2] = (pixel[2] & 0xFE) | ((message[i] >> 2) & 0x01);
        
        // Write the modified pixel back
        fseek(bmpFile, -3, SEEK_CUR); // Move back to the position of the pixel
        fwrite(pixel, 1, 3, bmpFile);
    }

    // Now handle the rest of the image
    for (int i = messageLength; i < totalPixels; i++) {
        fread(pixel, 1, 3, bmpFile);
        fwrite(pixel, 1, 3, bmpFile); // Write unchanged pixel
    }

    fclose(bmpFile);

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error opening output BMP file");
        return;
    }

    bmpFile = fopen(inputFileName, "rb");
    fseek(bmpFile, 0, SEEK_END);
    long bmpSize = ftell(bmpFile);
    fseek(bmpFile, 0, SEEK_SET);
    char *bmpData = malloc(bmpSize);
    fread(bmpData, 1, bmpSize, bmpFile);
    fwrite(bmpData, 1, bmpSize, outputFile);

    free(bmpData);
    fclose(outputFile);
    fclose(bmpFile);
    printf("Message embedded successfully in %s\n", outputFileName);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_bmp_file> <output_bmp_file> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    embedMessageInBMP(argv[1], argv[2], argv[3]);
    return EXIT_SUCCESS;
}