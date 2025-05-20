//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Ensuring the correct packing of structures

typedef struct {
    unsigned char bfType[2];
    unsigned long bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned long bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned long biSize;
    long biWidth;
    long biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned long biCompression;
    unsigned long biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
} BITMAPINFOHEADER;

#pragma pack(pop)

// Function Prototypes
void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark);
void applyWatermark(unsigned char *pixelData, const char *watermark, int width, int height);

int main() {
    const char *inputFile = "input.bmp"; // Make sure to have the input.bmp in the same directory
    const char *outputFile = "output.bmp";
    const char *watermark = "Watermark";

    printf("Starting Digital Watermarking...\n");
    embedWatermark(inputFile, outputFile, watermark);
    printf("Watermark has been successfully embedded!\n");
    return 0;
}

void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    FILE *input = fopen(inputFile, "rb");
    if (!input) {
        fprintf(stderr, "Error opening file %s\n", inputFile);
        exit(1);
    }

    BITMAPFILEHEADER fileHeader;
    fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, input);

    BITMAPINFOHEADER infoHeader;
    fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, input);

    // Calculating padding for 4-byte alignment
    int rowSize = (infoHeader.biWidth * (infoHeader.biBitCount / 8) + 3) & ~3;
    int padding = rowSize - (infoHeader.biWidth * (infoHeader.biBitCount / 8));
    int pixelDataSize = rowSize * abs(infoHeader.biHeight);

    unsigned char *pixelData = malloc(pixelDataSize);
    fseek(input, fileHeader.bfOffBits, SEEK_SET);
    fread(pixelData, sizeof(unsigned char), pixelDataSize, input);
    fclose(input);

    // Applying the watermark into the pixel data
    applyWatermark(pixelData, watermark, infoHeader.biWidth, abs(infoHeader.biHeight));

    // Writing to the output file
    FILE *output = fopen(outputFile, "wb");
    if (!output) {
        free(pixelData);
        fprintf(stderr, "Error creating file %s\n", outputFile);
        exit(1);
    }

    fwrite(&fileHeader, sizeof(BITMAPFILEHEADER), 1, output);
    fwrite(&infoHeader, sizeof(BITMAPINFOHEADER), 1, output);
    fseek(output, fileHeader.bfOffBits, SEEK_SET);
    fwrite(pixelData, sizeof(unsigned char), pixelDataSize, output);
    fclose(output);

    free(pixelData);
}

void applyWatermark(unsigned char *pixelData, const char *watermark, int width, int height) {
    int length = strlen(watermark);
    int margin = 10; // Margin from the edge of image
    int index = 0;

    for (int i = margin; i < height - margin; i++) {
        for (int j = margin; j < width - margin; j++) {
            // Only apply watermark on diagonal pixels
            if (i == j && index < length) {
                // Embedding watermark onto the red channel (assuming 24bits BMP)
                int pixelOffset = (i * width + j) * 3; // RGB
                pixelData[pixelOffset] = (unsigned char)(watermark[index] % 256);
                index++;
            }
            if (index >= length) {
                return; // Watermark is completely embedded
            }
        }
    }
}