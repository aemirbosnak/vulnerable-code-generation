//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

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
    int32_t biXPixPerMeter;
    int32_t biYPixPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;
#pragma pack(pop)

void embed_watermark(const char *input_file, const char *output_file, const char *watermark) {
    FILE *fp = fopen(input_file, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", input_file);
        exit(1);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, fp);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, fp);

    if (bfh.bfType != 0x4D42) { // Check if the file is a BMP file
        fprintf(stderr, "Not a BMP file!\n");
        fclose(fp);
        exit(1);
    }

    // Allocate memory for pixel array
    size_t pixel_array_size = bih.biWidth * bih.biHeight * 3; // 3 bytes per pixel (RGB)
    RGB *pixels = (RGB*)malloc(pixel_array_size);
    fseek(fp, bfh.bfOffBits, SEEK_SET);
    fread(pixels, pixel_array_size, 1, fp);
    fclose(fp);

    // Embed watermark
    size_t watermark_length = strlen(watermark);
    for (size_t i = 0; i < watermark_length; i++) {
        for (size_t bit = 0; bit < 8; bit++) {
            if ((i * 8 + bit) >= pixel_array_size) {
                break; // Don't write outside the pixel array bounds
            }
            int pixel_index = i * 8 + bit;
            uint8_t bit_value = (watermark[i] >> (7 - bit)) & 1;
            pixels[pixel_index].red = (pixels[pixel_index].red & ~1) | bit_value; // Modify LSB of the red component
        }
    }

    // Write output BMP file
    fp = fopen(output_file, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error creating file %s\n", output_file);
        free(pixels);
        exit(1);
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, fp);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, fp);
    fseek(fp, bfh.bfOffBits, SEEK_SET);
    fwrite(pixels, pixel_array_size, 1, fp);

    free(pixels);
    fclose(fp);
}

void extract_watermark(const char *input_file, size_t watermark_length) {
    FILE *fp = fopen(input_file, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", input_file);
        exit(1);
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;

    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, fp);
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, fp);

    size_t pixel_array_size = bih.biWidth * bih.biHeight * 3; // 3 bytes per pixel (RGB)
    RGB *pixels = (RGB*)malloc(pixel_array_size);
    fseek(fp, bfh.bfOffBits, SEEK_SET);
    fread(pixels, pixel_array_size, 1, fp);
    fclose(fp);

    char *watermark = (char*)malloc(watermark_length + 1);
    memset(watermark, 0, watermark_length + 1);

    // Extract watermark
    for (size_t i = 0; i < watermark_length; i++) {
        for (size_t bit = 0; bit < 8; bit++) {
            int pixel_index = i * 8 + bit;
            if (pixel_index >= pixel_array_size) {
                break; // Don't read outside the pixel array bounds
            }
            watermark[i] |= (pixels[pixel_index].red & 1) << (7 - bit); // Read LSB of the red component
        }
    }

    printf("Extracted Watermark: %s\n", watermark);
    free(watermark);
    free(pixels);
}

int main() {
    const char *input_file = "input.bmp";
    const char *output_file = "output.bmp";
    const char *watermark = "WATERMARK";

    embed_watermark(input_file, output_file, watermark);
    printf("Watermark embedded successfully!\n");

    extract_watermark(output_file, strlen(watermark));
    return 0;
}