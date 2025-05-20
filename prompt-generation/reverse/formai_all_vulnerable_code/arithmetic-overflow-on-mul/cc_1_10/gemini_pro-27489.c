//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte;

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <original_image> <watermark_image> <output_image>\n", argv[0]);
        return 1;
    }

    FILE *original_fp = fopen(argv[1], "rb");
    if (original_fp == NULL) {
        printf("Error opening original image file: %s\n", argv[1]);
        return 1;
    }

    FILE *watermark_fp = fopen(argv[2], "rb");
    if (watermark_fp == NULL) {
        printf("Error opening watermark image file: %s\n", argv[2]);
        return 1;
    }

    FILE *output_fp = fopen(argv[3], "wb");
    if (output_fp == NULL) {
        printf("Error opening output image file: %s\n", argv[3]);
        return 1;
    }

    // Read the headers from the original image
    byte header[54];
    fread(header, sizeof(byte), 54, original_fp);

    // Read the pixel data from the original image
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int pixel_count = width * height;
    byte *original_pixels = (byte *)malloc(pixel_count * 3);
    fread(original_pixels, sizeof(byte), pixel_count * 3, original_fp);

    // Read the headers from the watermark image
    fread(header, sizeof(byte), 54, watermark_fp);

    // Read the pixel data from the watermark image
    width = *(int *)&header[18];
    height = *(int *)&header[22];
    pixel_count = width * height;
    byte *watermark_pixels = (byte *)malloc(pixel_count * 3);
    fread(watermark_pixels, sizeof(byte), pixel_count * 3, watermark_fp);

    // Embed the watermark in the original image
    for (int i = 0; i < pixel_count; i++) {
        for (int j = 0; j < 3; j++) {
            original_pixels[i * 3 + j] = (original_pixels[i * 3 + j] & 0xF0) | (watermark_pixels[i * 3 + j] & 0x0F);
        }
    }

    // Write the headers to the output image
    fwrite(header, sizeof(byte), 54, output_fp);

    // Write the pixel data to the output image
    fwrite(original_pixels, sizeof(byte), pixel_count * 3, output_fp);

    // Free the allocated memory
    free(original_pixels);
    free(watermark_pixels);

    // Close the files
    fclose(original_fp);
    fclose(watermark_fp);
    fclose(output_fp);

    return 0;
}