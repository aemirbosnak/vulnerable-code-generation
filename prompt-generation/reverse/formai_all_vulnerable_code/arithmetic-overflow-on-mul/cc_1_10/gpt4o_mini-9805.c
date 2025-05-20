//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bitCount;
    uint32_t compression;
    uint32_t sizeImage;
    int32_t xPixelsPerMeter;
    int32_t yPixelsPerMeter;
    uint32_t colorsUsed;
    uint32_t colorsImportant;
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;
#pragma pack(pop)

// Function prototypes
void embedMessage(const char* inputImage, const char* outputImage, const char* message);
char* extractMessage(const char* inputImage);

int main() {
    const char* inputImage = "input.bmp";
    const char* outputImage = "output.bmp";
    const char* message = "Hello, Peaceful World!";

    printf("Embedding message into image...\n");
    embedMessage(inputImage, outputImage, message);
    printf("Message embedded successfully!\n");

    printf("Extracting message from image...\n");
    char* extractedMessage = extractMessage(outputImage);
    printf("Extracted message: %s\n", extractedMessage);

    free(extractedMessage);
    return 0;
}

void embedMessage(const char* inputImage, const char* outputImage, const char* message) {
    FILE* inFile = fopen(inputImage, "rb");
    if (!inFile) {
        fprintf(stderr, "Error: Could not open input image.\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, inFile);

    BMPInfoHeader bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inFile);

    // Ensure the image is 24-bit BMP
    if (bmpInfoHeader.bitCount != 24) {
        fprintf(stderr, "Error: Only 24-bit BMP images are supported.\n");
        fclose(inFile);
        exit(1);
    }

    Pixel* pixels = (Pixel*)malloc(bmpInfoHeader.width * bmpInfoHeader.height * sizeof(Pixel));
    fseek(inFile, bmpHeader.offset, SEEK_SET);
    fread(pixels, sizeof(Pixel), bmpInfoHeader.width * bmpInfoHeader.height, inFile);
    fclose(inFile);

    // Embed the message into the pixels
    int messageLength = strlen(message);
    int totalPixels = bmpInfoHeader.width * bmpInfoHeader.height;

    for (int i = 0; i < messageLength; i++) {
        // Modify the least significant bit of the pixel's blue value
        pixels[i].blue = (pixels[i].blue & ~1) | (message[i] & 1);
    }
    // Embed the length of the message in the next few pixels
    for (int i = 0; i < sizeof(int); i++) {
        pixels[messageLength + i].blue = (pixels[messageLength + i].blue & ~1) | ((messageLength >> i) & 1);
    }

    FILE* outFile = fopen(outputImage, "wb");
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, outFile);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, outFile);
    fseek(outFile, bmpHeader.offset, SEEK_SET);
    fwrite(pixels, sizeof(Pixel), totalPixels, outFile);
    fclose(outFile);
    free(pixels);
}

char* extractMessage(const char* inputImage) {
    FILE* inFile = fopen(inputImage, "rb");
    if (!inFile) {
        fprintf(stderr, "Error: Could not open input image.\n");
        exit(1);
    }

    BMPHeader bmpHeader;
    fread(&bmpHeader, sizeof(BMPHeader), 1, inFile);

    BMPInfoHeader bmpInfoHeader;
    fread(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, inFile);

    Pixel* pixels = (Pixel*)malloc(bmpInfoHeader.width * bmpInfoHeader.height * sizeof(Pixel));
    fseek(inFile, bmpHeader.offset, SEEK_SET);
    fread(pixels, sizeof(Pixel), bmpInfoHeader.width * bmpInfoHeader.height, inFile);
    fclose(inFile);

    // Read the message length from the next few pixels
    int messageLength = 0;
    for (int i = 0; i < sizeof(int); i++) {
        messageLength |= (pixels[sizeof(Pixel) * (strlen(pixels) + i)].blue & 1) << i;
    }

    char* message = (char*)malloc(messageLength + 1);
    for (int i = 0; i < messageLength; i++) {
        message[i] = 0;
        for (int j = 0; j < 8; j++) {
            message[i] |= (pixels[i].blue & 1) << j;
            pixels[i].blue >>= 1;
        }
    }
    message[messageLength] = '\0';

    free(pixels);
    return message;
}