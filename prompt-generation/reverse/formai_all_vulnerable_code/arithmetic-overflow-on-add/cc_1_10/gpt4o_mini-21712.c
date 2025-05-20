//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    uint8_t Blue;
    uint8_t Green;
    uint8_t Red;
} PIXEL;
#pragma pack(pop)

void encodeMessageInImage(const char *inputImagePath, const char *message, const char *outputImagePath) {
    FILE *inputFile = fopen(inputImagePath, "rb");
    FILE *outputFile = fopen(outputImagePath, "wb");
    if (!inputFile || !outputFile) {
        perror("File cannot be opened");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, inputFile);

    // Calculate the padding for the pixel array
    int rowSize = (bih.biWidth * 3 + 3) & (~3);
    int paddingSize = rowSize - (bih.biWidth * 3);
    int messageLength = strlen(message);

    // Write header to outputFile
    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, outputFile);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, outputFile);

    // Create pixel array to hold the image data
    PIXEL *pixelArray = (PIXEL*)malloc(bih.biWidth * bih.biHeight * sizeof(PIXEL));
    fread(pixelArray, sizeof(PIXEL), bih.biWidth * bih.biHeight, inputFile);

    // Encode message length in the last 4 pixels
    for (int i = 0; i < 4; i++) {
        if (i < sizeof(int)) {
            pixelArray[bih.biWidth * bih.biHeight - 1 - i].Blue = (messageLength >> (i * 8)) & 0xFF;
        } else {
            pixelArray[bih.biWidth * bih.biHeight - 1 - i].Blue = 0;
        }
    }

    // Encode the message
    for (int i = 0; i < messageLength; i++) {
        pixelArray[i].Blue = message[i];
    }

    // Write pixel data to the output file with padding
    for (int i = 0; i < bih.biHeight; i++) {
        fwrite(pixelArray + (i * bih.biWidth), sizeof(PIXEL), bih.biWidth, outputFile);
        for (int p = 0; p < paddingSize; p++) fputc(0, outputFile);
    }

    free(pixelArray);
    fclose(inputFile);
    fclose(outputFile);
}

void decodeMessageFromImage(const char *inputImagePath) {
    FILE *inputFile = fopen(inputImagePath, "rb");
    if (!inputFile) {
        perror("File cannot be opened");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, inputFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, inputFile);

    // Calculate the padding for the pixel array
    int rowSize = (bih.biWidth * 3 + 3) & (~3);
    int paddingSize = rowSize - (bih.biWidth * 3);

    // Create pixel array to hold the image data
    PIXEL *pixelArray = (PIXEL*)malloc(bih.biWidth * bih.biHeight * sizeof(PIXEL));
    fread(pixelArray, sizeof(PIXEL), bih.biWidth * bih.biHeight, inputFile);

    // Decode message length from the last 4 pixels
    int messageLength = 0;
    for (int i = 0; i < 4; i++) {
        messageLength |= (pixelArray[bih.biWidth * bih.biHeight - 1 - i].Blue << (i * 8));
    }

    // Decode the message
    printf("Decoded Message: ");
    for (int i = 0; i < messageLength; i++) {
        putchar(pixelArray[i].Blue);
    }
    putchar('\n');

    free(pixelArray);
    fclose(inputFile);
}

int main() {
    const char *inputImage = "input.bmp";
    const char *message = "Futuristic Steganography!";
    const char *outputImage = "output.bmp";

    encodeMessageInImage(inputImage, message, outputImage);
    decodeMessageFromImage(outputImage);

    return 0;
}