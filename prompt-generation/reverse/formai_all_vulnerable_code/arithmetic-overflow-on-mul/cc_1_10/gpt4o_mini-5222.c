//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t size_image;
    int32_t x_pixels_per_meter;
    int32_t y_pixels_per_meter;
    uint32_t colors_used;
    uint32_t colors_important;
} DIBHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
    uint8_t reserved;
} Pixel;
#pragma pack(pop)

void embed_watermark(const char *input_bmp, const char *output_bmp, const char *watermark) {
    FILE *in_file = fopen(input_bmp, "rb");
    FILE *out_file = fopen(output_bmp, "wb");
    if (!in_file || !out_file) {
        perror("File open error");
        return;
    }

    BMPHeader bmp_header;
    DIBHeader dib_header;

    fread(&bmp_header, sizeof(BMPHeader), 1, in_file);
    fread(&dib_header, sizeof(DIBHeader), 1, in_file);

    fwrite(&bmp_header, sizeof(BMPHeader), 1, out_file);
    fwrite(&dib_header, sizeof(DIBHeader), 1, out_file);

    // Prepare watermark
    int watermark_length = strlen(watermark);
    int pixel_count = dib_header.width * dib_header.height;
    int watermark_pixel_position = 0;

    for (int i = 0; i < pixel_count; ++i) {
        Pixel pixel;
        fread(&pixel, sizeof(Pixel), 1, in_file);

        // Embed watermark in the LSB of the red channel
        if (watermark_pixel_position < watermark_length) {
            pixel.red = (pixel.red & ~1) | (watermark[watermark_pixel_position] & 1);
            watermark_pixel_position++;
        }

        fwrite(&pixel, sizeof(Pixel), 1, out_file);
    }

    fclose(in_file);
    fclose(out_file);
}

void extract_watermark(const char *input_bmp, char *watermark, int watermark_length) {
    FILE *in_file = fopen(input_bmp, "rb");
    if (!in_file) {
        perror("File open error");
        return;
    }

    BMPHeader bmp_header;
    DIBHeader dib_header;
    fread(&bmp_header, sizeof(BMPHeader), 1, in_file);
    fread(&dib_header, sizeof(DIBHeader), 1, in_file);

    int pixel_count = dib_header.width * dib_header.height;
    int watermark_pixel_position = 0;

    for (int i = 0; i < pixel_count && watermark_pixel_position < watermark_length; ++i) {
        Pixel pixel;
        fread(&pixel, sizeof(Pixel), 1, in_file);

        // Extract watermark from the LSB of the red channel
        watermark[watermark_pixel_position] = (pixel.red & 1);
        watermark_pixel_position++;
    }

    watermark[watermark_length] = '\0'; // Null-terminate the string
    fclose(in_file);
}

int main() {
    const char *input_bmp = "input.bmp";
    const char *output_bmp = "output.bmp";
    const char *watermark = "WATERMARK";

    // Embed the watermark
    embed_watermark(input_bmp, output_bmp, watermark);
    printf("Watermark embedded successfully.\n");

    // Prepare to extract it
    char extracted_watermark[100];
    extract_watermark(output_bmp, extracted_watermark, 100);
    printf("Extracted watermark: ");
    for (int i = 0; i < strlen(watermark); i++) {
        printf("%d", extracted_watermark[i]);
    }
    printf("\n");

    return 0;
}