//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1) // Align structure to single byte
typedef struct {
    uint16_t bfType; // Bitmap identifier
    uint32_t bfSize; // File size in bytes
    uint16_t bfReserved1; // Reserved; must be 0
    uint16_t bfReserved2; // Reserved; must be 0
    uint32_t bfOffBits; // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize; // Size of this header
    int32_t biWidth; // Width of the bitmap in pixels
    int32_t biHeight; // Height of the bitmap in pixels
    uint16_t biPlanes; // Number of color planes
    uint16_t biBitCount; // Number of bits per pixel
    uint32_t biCompression; // Compression method
    uint32_t biSizeImage; // Image size
    int32_t biXPelsPerMeter; // Horizontal resolution
    int32_t biYPelsPerMeter; // Vertical resolution
    uint32_t biClrUsed; // Number of colors used
    uint32_t biClrImportant; // Important colors
} BITMAPINFOHEADER;
#pragma pack(pop)

const char *asciiChars = "@%#*+=-:. "; // Characters from dark to light

void printUsage() {
    printf("Usage: ./image_to_ascii <input.bmp> <output.txt>\n");
}

int brightness(uint8_t r, uint8_t g, uint8_t b) {
    return (r + g + b) / 3; // Average for grayscale
}

void convertToAscii(const char *inputFile, const char *outputFile) {
    FILE *bmpFile = fopen(inputFile, "rb");
    if (!bmpFile) {
        printf("Error: Unable to open input file.\n");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, bmpFile);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, bmpFile);

    // Check for a valid BMP file
    if (bfh.bfType != 0x4D42) {
        printf("Error: Not a valid BMP file.\n");
        fclose(bmpFile);
        exit(EXIT_FAILURE);
    }

    fseek(bmpFile, bfh.bfOffBits, SEEK_SET);
    
    // Prepare for output file
    FILE *outFile = fopen(outputFile, "w");
    if (!outFile) {
        printf("Error: Unable to open output file.\n");
        fclose(bmpFile);
        exit(EXIT_FAILURE);
    }

    // Process the image
    for (int y = bih.biHeight - 1; y >= 0; y--) { // BMP is bottom-up
        for (int x = 0; x < bih.biWidth; x++) {
            uint8_t bgr[3]; // To hold blue, green, red
            fread(bgr, sizeof(uint8_t), 3, bmpFile); // Read pixel data

            // Convert to brightness
            int bright = brightness(bgr[2], bgr[1], bgr[0]); // RGB to grayscale
            int index = (int)(bright * (strlen(asciiChars) - 1) / 255); // Map to ASCII chars
            fputc(asciiChars[index], outFile);
        }
        fputc('\n', outFile); // Newline for next row
    }

    fclose(bmpFile);
    fclose(outFile);
    printf("ASCII art generated in %s\n", outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage();
        return EXIT_FAILURE;
    }

    convertToAscii(argv[1], argv[2]);
    return EXIT_SUCCESS;
}