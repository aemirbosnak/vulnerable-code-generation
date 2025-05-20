//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54 // BMP header size
#define WIDTH_OFFSET 18
#define HEIGHT_OFFSET 22
#define BITS_PER_PIXEL_OFFSET 28

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;

void embedWatermark(const char *inputFile, const char *outputFile, const char *watermark) {
    FILE *bmpFile = fopen(inputFile, "rb");
    FILE *outFile = fopen(outputFile, "wb");
    if (!bmpFile || !outFile) {
        fprintf(stderr, "Error: Cannot open input or output file.\n");
        return;
    }
    
    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, bmpFile);
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, outFile);
    
    int width = *(int*)&header[WIDTH_OFFSET];
    int height = *(int*)&header[HEIGHT_OFFSET];
    int bitsPerPixel = *(short*)&header[BITS_PER_PIXEL_OFFSET];

    if (bitsPerPixel != 24) {
        fprintf(stderr, "Error: Unsupported BMP format. Only 24-bit BMP files are supported.\n");
        fclose(bmpFile);
        fclose(outFile);
        return;
    }

    // Start reading pixels
    Pixel *pixels = (Pixel*)malloc(width * height * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), width * height, bmpFile);
    
    // Embed watermark
    for (int i = 0; i < strlen(watermark); i++) {
        if (i >= width * height) break; // Prevent out of bounds
        int index = i * 3; // RGB
        
        // Modifying the pixel color to include the watermark
        // Using the modulo operator to manipulate only the blue channel (or others)
        pixels[i].blue = (pixels[i].blue & 0xFE) | (watermark[i] & 0x01);
    }
    
    // Write modified pixels to output file
    fwrite(pixels, sizeof(Pixel), width * height, outFile);

    free(pixels);
    fclose(bmpFile);
    fclose(outFile);
}

void extractWatermark(const char *inputFile, char *watermark, int watermarkLength) {
    FILE *bmpFile = fopen(inputFile, "rb");
    if (!bmpFile) {
        fprintf(stderr, "Error: Cannot open input file for extraction.\n");
        return;
    }

    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, bmpFile);

    int width = *(int*)&header[WIDTH_OFFSET];
    
    // Start reading pixels
    Pixel *pixels = (Pixel*)malloc(width * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), width * sizeof(Pixel), bmpFile);
    
    // Extract watermark
    for (int i = 0; i < watermarkLength; i++) {
        if (i >= width) break; // Prevent out of bounds
        watermark[i] = (pixels[i].blue & 0x01) + '0'; // Simple extraction
    }
    watermark[watermarkLength] = '\0'; // Null-terminate the string

    free(pixels);
    fclose(bmpFile);
}

int main() {
    const char *inputBmp = "input.bmp";
    const char *watermark = "hello";
    const char *outputBmp = "output.bmp";
    const int watermarkLength = 5;

    // Embed watermark
    embedWatermark(inputBmp, outputBmp, watermark);
    printf("Watermark embedded successfully!\n");

    // Extract watermark
    char extracted[watermarkLength + 1];
    extractWatermark(outputBmp, extracted, watermarkLength);
    printf("Extracted watermark: %s\n", extracted);

    return 0;
}