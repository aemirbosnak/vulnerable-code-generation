//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1) // Ensure structure packing
typedef struct {
    uint16_t bfType;      // File type
    uint32_t bfSize;      // Size of the file
    uint16_t bfReserved1; // Reserved
    uint16_t bfReserved2; // Reserved
    uint32_t bfOffBits;   // Offset to start of pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the image
    int32_t  biHeight;        // Height of the image
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;      // Size of the image data
    int32_t  biXPelsPerMeter;   // Pixels per meter in X
    int32_t  biYPelsPerMeter;   // Pixels per meter in Y
    uint32_t biClrUsed;        // Number of colors used
    uint32_t biClrImportant;   // Important colors
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

#pragma pack(pop)

void embed_watermark(const char *input_file, const char *output_file, const char *watermark) {
    FILE *input = fopen(input_file, "rb");
    if (!input) {
        fprintf(stderr, "Error: Could not open input file.\n");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, input);
    if (bfh.bfType != 0x4D42) { // Check for 'BM' in the file header
        fprintf(stderr, "Error: Not a BMP file.\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, input);

    // Move the file pointer to the beginning of the pixel data
    fseek(input, bfh.bfOffBits, SEEK_SET);

    // Calculate the size of the pixel data
    int width = bih.biWidth;
    int height = abs(bih.biHeight);
    int padding = (4 - (width * sizeof(RGB)) % 4) % 4;
    RGB *pixels = malloc(width * height * sizeof(RGB));
    fread(pixels, sizeof(RGB), width * height, input);
    fclose(input);

    // Embed the watermark
    for (int i = 0; watermark[i] != '\0' && i < (width * height); i++) {
        pixels[i].blue = (pixels[i].blue & 0xFE) | ((watermark[i] >> 0) & 0x01); // Embed LSB
        pixels[i].green = (pixels[i].green & 0xFE) | ((watermark[i] >> 1) & 0x01); // Embed LSB
        pixels[i].red = (pixels[i].red & 0xFE) | ((watermark[i] >> 2) & 0x01); // Embed LSB
    }

    // Save the modified image
    FILE *output = fopen(output_file, "wb");
    if (!output) {
        fprintf(stderr, "Error: Could not open output file.\n");
        free(pixels);
        exit(EXIT_FAILURE);
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, output);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, output);
    for (int i = 0; i < height; i++) {
        fwrite(pixels + (i * width), sizeof(RGB), width, output);
        for (int j = 0; j < padding; j++) {
            fputc(0, output); // Add padding bytes
        }
    }

    fclose(output);
    free(pixels);
    printf("Watermark embedded successfully!\n");
}

void extract_watermark(const char *input_file) {
    FILE *input = fopen(input_file, "rb");
    if (!input) {
        fprintf(stderr, "Error: Could not open input file.\n");
        exit(EXIT_FAILURE);
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, input);
    if (bfh.bfType != 0x4D42) {
        fprintf(stderr, "Error: Not a BMP file.\n");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, input);
    fseek(input, bfh.bfOffBits, SEEK_SET);

    int width = bih.biWidth;
    int height = abs(bih.biHeight);
    RGB *pixels = malloc(width * height * sizeof(RGB));
    fread(pixels, sizeof(RGB), width * height, input);
    fclose(input);

    printf("Extracted watermark: ");
    for (int i = 0; i < (width * height); i++) {
        uint8_t watermark_char = (pixels[i].blue & 0x01) |
                                 ((pixels[i].green & 0x01) << 1) |
                                 ((pixels[i].red & 0x01) << 2);
        if (watermark_char == 0) break; // Stop if we reach null character
        putchar(watermark_char);
    }
    printf("\n");
    free(pixels);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_bmp> <output_bmp> <watermark_string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    embed_watermark(argv[1], argv[2], argv[3]);
    printf("Now let's extract the watermark...\n");
    extract_watermark(argv[2]);

    return 0;
}