//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BITMAPFILEHEADER;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPelsPerMeter;
    int biYPelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biCirImportant;
} BITMAPINFOHEADER;
#pragma pack(pop)

void embed_watermark(const char* input_file, const char* output_file, const char* watermark) {
    FILE *bmp_file = fopen(input_file, "rb");
    if (!bmp_file) {
        perror("Could not open input file");
        return;
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, bmp_file);

    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, bmp_file);

    int width = bih.biWidth;
    int height = bih.biHeight;
    int padding = (4 - (width * 3) % 4) % 4;
    
    // Allocate memory for pixel data
    unsigned char *pixel_data = malloc(height * (width * 3 + padding));
    fseek(bmp_file, bfh.bfOffBits, SEEK_SET);
    fread(pixel_data, 1, height * (width * 3 + padding), bmp_file);
    fclose(bmp_file);

    // Embedding the watermark one bit per pixel (LSB)
    for (int i = 0; i < strlen(watermark) * 8; i++) {
        int pixel_index = (i / 8) * 3; // 3 bytes (RGB) per pixel
        unsigned char bit = (watermark[i / 8] >> (7 - (i % 8))) & 1;

        // Modify the least significant bit of the blue channel
        if (bit == 1) {
            pixel_data[pixel_index] |= 1; // Set the LSB to 1
        } else {
            pixel_data[pixel_index] &= 0xFE; // Set the LSB to 0
        }
    }

    // Write modified pixel data to new BMP file
    FILE *output_bmp = fopen(output_file, "wb");
    if (!output_bmp) {
        perror("Could not open output file");
        free(pixel_data);
        return;
    }

    fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, output_bmp);
    fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, output_bmp);
    fwrite(pixel_data, 1, height * (width * 3 + padding), output_bmp);

    fclose(output_bmp);
    free(pixel_data);
}

void extract_watermark(const char* input_file, char* extracted_watermark, int watermark_length) {
    FILE *bmp_file = fopen(input_file, "rb");
    if (!bmp_file) {
        perror("Could not open input file");
        return;
    }

    BITMAPFILEHEADER bfh;
    fread(&bfh, sizeof(BITMAPFILEHEADER), 1, bmp_file);

    BITMAPINFOHEADER bih;
    fread(&bih, sizeof(BITMAPINFOHEADER), 1, bmp_file);

    int width = bih.biWidth;
    int height = bih.biHeight;
    int padding = (4 - (width * 3) % 4) % 4;

    unsigned char *pixel_data = malloc(height * (width * 3 + padding));
    fseek(bmp_file, bfh.bfOffBits, SEEK_SET);
    fread(pixel_data, 1, height * (width * 3 + padding), bmp_file);
    fclose(bmp_file);

    // Extracting the watermark
    for (int i = 0; i < watermark_length * 8; i++) {
        int pixel_index = (i / 8) * 3; // 3 bytes (RGB) per pixel
        extracted_watermark[i / 8] <<= 1; // Shift left
        extracted_watermark[i / 8] |= (pixel_data[pixel_index] & 1); // Get LSB
    }

    // NULL-terminate the extracted string for better readability
    extracted_watermark[watermark_length] = '\0';
    free(pixel_data);
}

int main() {
    const char* input_file = "input.bmp";
    const char* output_file = "output.bmp";
    const char* watermark = "Hello!"; // Your watermark message

    printf("Embedding watermark...\n");
    embed_watermark(input_file, output_file, watermark);

    printf("Extracting watermark...\n");
    char extracted_watermark[256];
    extract_watermark(output_file, extracted_watermark, strlen(watermark));

    printf("Extracted Watermark: %s\n", extracted_watermark);
    return 0;
}