//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function to read a BMP file and return its pixel array
uint8_t* read_bmp(const char* filename, int* width, int* height) {
    FILE* f = fopen(filename, "rb");
    if (!f) {
        perror("Unable to open file");
        return NULL;
    }

    fseek(f, 18, SEEK_SET);
    fread(width, sizeof(int), 1, f);
    fread(height, sizeof(int), 1, f);

    int row_padded = (*width * 3 + 3) & (~3);
    uint8_t* data = (uint8_t*)malloc(row_padded * (*height));
    
    fseek(f, 54, SEEK_SET);
    fread(data, sizeof(uint8_t), row_padded * (*height), f);
    fclose(f);
    return data;
}

// Function to write a BMP file from the pixel array
void write_bmp(const char* filename, uint8_t* data, int width, int height) {
    FILE* f = fopen(filename, "wb");
    if (!f) {
        perror("Unable to open file");
        return;
    }

    // BMP header
    uint8_t header[54] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0,
        40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0
    };

    int row_padded = (width * 3 + 3) & (~3);
    *((int*)&header[2]) = 54 + row_padded * height;  // file size
    *((int*)&header[18]) = width;                      // width
    *((int*)&header[22]) = height;                     // height

    fwrite(header, sizeof(uint8_t), 54, f);
    fwrite(data, sizeof(uint8_t), row_padded * height, f);
    fclose(f);
}

// Function to embed watermark into pixel data
void embed_watermark(uint8_t* data, int width, int height, const char* watermark) {
    int watermark_length = strlen(watermark);
    for (int i = 0; i < watermark_length; i++) {
        int pixel_index = (height - 1 - i) * width * 3 + (width - 1) * 3; // Bottom right corner
        data[pixel_index] = (data[pixel_index] & 0xFE) | ((watermark[i] >> 7) & 0x1); // LSB for embedding
        data[pixel_index + 1] = (data[pixel_index + 1] & 0xFE) | ((watermark[i] >> 6) & 0x1);
        data[pixel_index + 2] = (data[pixel_index + 2] & 0xFE) | ((watermark[i] >> 5) & 0x1);
    }
}

// Function to extract watermark from pixel data
void extract_watermark(uint8_t* data, int width, int height, char* watermark, int max_length) {
    for (int i = 0; i < max_length; i++) {
        int pixel_index = (height - 1 - i) * width * 3 + (width - 1) * 3; // Bottom right corner
        watermark[i] = 0;
        watermark[i] |= (data[pixel_index] & 0x1) << 7; // LSB for extraction
        watermark[i] |= (data[pixel_index + 1] & 0x1) << 6;
        watermark[i] |= (data[pixel_index + 2] & 0x1) << 5;
    }
    watermark[max_length] = '\0'; // Null-terminate the extracted string
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: %s <input.bmp> <output.bmp> <watermark>\n", argv[0]);
        return 1;
    }

    int width, height;
    uint8_t* pixel_data = read_bmp(argv[1], &width, &height);
    if (!pixel_data) return 1;

    const char* watermark = argv[3];
    embed_watermark(pixel_data, width, height, watermark);
    write_bmp(argv[2], pixel_data, width, height);
    printf("Watermark embedded successfully!\n");

    char extracted_watermark[256];
    extract_watermark(pixel_data, width, height, extracted_watermark, strlen(watermark));
    printf("Extracted watermark: %s\n", extracted_watermark);

    free(pixel_data);
    return 0;
}