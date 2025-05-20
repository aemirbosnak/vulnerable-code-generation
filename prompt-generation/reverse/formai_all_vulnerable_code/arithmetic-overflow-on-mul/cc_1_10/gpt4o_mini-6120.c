//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(1) // Align structures on byte boundaries

typedef struct {
    uint16_t bfType;      // Magic number for the BMP file
    uint32_t bfSize;      // Size of the BMP file in bytes
    uint16_t bfReserved1; // Reserved; must be zero
    uint16_t bfReserved2; // Reserved; must be zero
    uint32_t bfOffBits;   // Offset to the pixel data
} BMPFileHeader;

typedef struct {
    uint32_t biSize;         // Size of this header
    int32_t  biWidth;        // Width of the bitmap in pixels
    int32_t  biHeight;       // Height of the bitmap in pixels
    uint16_t biPlanes;       // Number of color planes; must be set to 1
    uint16_t biBitCount;     // Number of bits per pixel
    uint32_t biCompression;   // Type of compression to use
    uint32_t biSizeImage;     // Size of the image data
    int32_t  biXPelsPerMeter;   // Horizontal resolution in pixels per meter
    int32_t  biYPelsPerMeter;   // Vertical resolution in pixels per meter
    uint32_t biClrUsed;       // Number of colors in the palette
    uint32_t biClrImportant;   // Number of important colors
} BMPInfoHeader;

void embed_watermark(const char *input_file, const char *output_file, const char *watermark) {
    FILE *inFile = fopen(input_file, "rb");
    FILE *outFile = fopen(output_file, "wb");
    if (!inFile || !outFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, inFile);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, inFile);

    fwrite(&fileHeader, sizeof(BMPFileHeader), 1, outFile);
    fwrite(&infoHeader, sizeof(BMPInfoHeader), 1, outFile);

    int width = infoHeader.biWidth;
    int height = infoHeader.biHeight;
    int padding = (4 - (width % 4)) % 4; // BMP row padding

    uint8_t *pixels = malloc(height * (width + padding));
    fseek(inFile, fileHeader.bfOffBits, SEEK_SET);
    fread(pixels, height * (width + padding), 1, inFile);

    size_t watermark_len = strlen(watermark);
    for (size_t i = 0; i < watermark_len; i++) {
        for (int j = 0; j < 8; j++) { // Embed each bit of the character
            int bit = (watermark[i] >> (7 - j)) & 1;
            int pixel_index = (i * 8 + j) % (height * width); // Loop through pixels

            // Modify the least significant bit
            if (bit) {
                pixels[pixel_index] |= 1; // Set LSB to 1
            } else {
                pixels[pixel_index] &= ~1; // Set LSB to 0
            }
        }
    }

    fwrite(pixels, height * (width + padding), 1, outFile);

    free(pixels);
    fclose(inFile);
    fclose(outFile);
}

void extract_watermark(const char *input_file, char *output_watermark, size_t max_length) {
    FILE *inFile = fopen(input_file, "rb");
    if (!inFile) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fread(&fileHeader, sizeof(BMPFileHeader), 1, inFile);
    fread(&infoHeader, sizeof(BMPInfoHeader), 1, inFile);

    int width = infoHeader.biWidth;
    int height = infoHeader.biHeight;

    uint8_t *pixels = malloc(height * width);
    fseek(inFile, fileHeader.bfOffBits, SEEK_SET);
    fread(pixels, height * width, 1, inFile);

    size_t watermark_index = 0;
    for (size_t i = 0; i < max_length; i++) {
        int character = 0;
        for (int j = 0; j < 8; j++) { // Extract each bit to form the character
            int pixel_index = (i * 8 + j) % (height * width);
            character |= (pixels[pixel_index] & 1) << (7 - j);
        }
        output_watermark[i] = character;

        // Stop extracting if we've reached a null character
        if (character == 0) break;
    }

    free(pixels);
    fclose(inFile);
}

int main() {
    const char *input_image = "input.bmp";
    const char *output_image = "watermarked_output.bmp";
    const char *watermark_message = "Hello";

    embed_watermark(input_image, output_image, watermark_message);
    printf("Watermark embedded successfully!\n");

    char extracted_watermark[100] = {0};
    extract_watermark(output_image, extracted_watermark, sizeof(extracted_watermark));
    
    printf("Extracted watermark: %s\n", extracted_watermark);
    return 0;
}