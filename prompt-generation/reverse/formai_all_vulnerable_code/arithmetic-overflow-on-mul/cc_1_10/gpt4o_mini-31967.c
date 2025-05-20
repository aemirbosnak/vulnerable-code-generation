//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: multivariable
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
    int32_t  biWidth;
    int32_t  biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t  biXPelsPerMeter;
    int32_t  biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} PIXEL;
#pragma pack(pop)

void embedMessage(PIXEL *pixels, const char *message, int width, int height) {
    int messageLength = strlen(message);
    int totalPixels = width * height;

    if (messageLength * 8 > totalPixels) {
        printf("Error: Message is too long to be embedded in the image!\n");
        return;
    }

    // Embed message length
    for (int i = 0; i < messageLength; i++) {
        for (int bit = 0; bit < 8; bit++) {
            int pixelIndex = (i * 8) + bit;
            int byteValue = (message[i] >> (7 - bit)) & 1;
            pixels[pixelIndex].red = (pixels[pixelIndex].red & 0xFE) | byteValue;
        }
    }

    // Embed null terminator
    for (int bit = 0; bit < 8; bit++) {
        int pixelIndex = (messageLength * 8) + bit;
        int byteValue = (0 >> (7 - bit)) & 1; // Null character
        pixels[pixelIndex].red = (pixels[pixelIndex].red & 0xFE) | byteValue;
    }

    printf("Message embedded successfully!\n");
}

void saveBMP(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, PIXEL *pixels) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file for writing");
        return;
    }

    fwrite(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fwrite(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);
    fwrite(pixels, sizeof(PIXEL), infoHeader->biWidth * infoHeader->biHeight, file);

    fclose(file);
    printf("Image saved successfully as %s\n", filename);
}

void loadBMP(const char *filename, BITMAPFILEHEADER *fileHeader, BITMAPINFOHEADER *infoHeader, PIXEL **pixels) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file for reading");
        return;
    }

    fread(fileHeader, sizeof(BITMAPFILEHEADER), 1, file);
    fread(infoHeader, sizeof(BITMAPINFOHEADER), 1, file);

    *pixels = (PIXEL *)malloc(infoHeader->biWidth * infoHeader->biHeight * sizeof(PIXEL));
    if (*pixels == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        fclose(file);
        return;
    }

    fread(*pixels, sizeof(PIXEL), infoHeader->biWidth * infoHeader->biHeight, file);
    fclose(file);
    printf("Image loaded successfully from %s\n", filename);
}

void extractMessage(PIXEL *pixels, char *message, int maxLength) {
    int messageIndex = 0;
    for (int i = 0; i < maxLength * 8; i++) {
        int pixelIndex = i;
        int bit = pixels[pixelIndex].red & 1;
        message[messageIndex] = (message[messageIndex] << 1) | bit;

        if ((i + 1) % 8 == 0) { // New byte
            if (message[messageIndex] == '\0') break;
            messageIndex++;
        }
    }
    message[messageIndex] = '\0';
    printf("Extracted message: %s\n", message);
}

int main() {
    const char *inputBMP = "input.bmp";
    const char *outputBMP = "output.bmp";
    const char *hiddenMessage = "Hello, Steganography!";

    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;
    PIXEL *pixels = NULL;

    loadBMP(inputBMP, &fileHeader, &infoHeader, &pixels);
    if (pixels == NULL) return 1;

    embedMessage(pixels, hiddenMessage, infoHeader.biWidth, infoHeader.biHeight);
    saveBMP(outputBMP, &fileHeader, &infoHeader, pixels);

    // Extracting message from the modified image
    char extractedMessage[256] = {0};
    extractMessage(pixels, extractedMessage, sizeof(extractedMessage));

    free(pixels);
    return 0;
}