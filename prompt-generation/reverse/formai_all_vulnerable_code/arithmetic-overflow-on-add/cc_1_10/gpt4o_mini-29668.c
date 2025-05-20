//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) // Ensuring no padding is added to the structures
typedef struct {
    unsigned short bfType;
    unsigned int bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int bfOffBits;
} BMPHeader;

typedef struct {
    unsigned int biSize;
    int biWidth;
    int biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int biCompression;
    unsigned int biSizeImage;
    int biXPixelsPerMeter;
    int biYPixelsPerMeter;
    unsigned int biClrUsed;
    unsigned int biClrImportant;
} BMPInfoHeader;
#pragma pack(pop)

unsigned char* readBMP(const char* filename, BMPHeader* bmpHeader, BMPInfoHeader* bmpInfoHeader, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    fread(bmpHeader, sizeof(BMPHeader), 1, file);
    fread(bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);
    
    *width = bmpInfoHeader->biWidth;
    *height = bmpInfoHeader->biHeight;
    
    int padding = (4 - (*width * 3) % 4) % 4;
    unsigned char* data = (unsigned char*)malloc((*height) * (*width) * 3);
    fseek(file, bmpHeader->bfOffBits, SEEK_SET);
    fread(data, sizeof(unsigned char), (*height) * (*width) * 3 + (*height) * padding, file);
    
    fclose(file);
    return data;
}

void writeBMP(const char* filename,BMPHeader bmpHeader, BMPInfoHeader bmpInfoHeader, unsigned char* data) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Error writing file");
        return;
    }
    
    fwrite(&bmpHeader, sizeof(BMPHeader), 1, file);
    fwrite(&bmpInfoHeader, sizeof(BMPInfoHeader), 1, file);
    
    int padding = (4 - (bmpInfoHeader.biWidth * 3) % 4) % 4;
    fwrite(data, sizeof(unsigned char), bmpInfoHeader.biWidth * bmpInfoHeader.biHeight * 3, file);
    for (int i = 0; i < bmpInfoHeader.biHeight; i++) {
        unsigned char pad[3] = {0, 0, 0};
        fwrite(pad, sizeof(unsigned char), padding, file);
    }
    
    fclose(file);
}

void embedWatermark(unsigned char* data, const char* watermark, int width, int height) {
    int wm_len = strlen(watermark);
    for (int i = 0; i < wm_len; i++) {
        int pixel_index = (i * 3) % (width * height * 3);
        data[pixel_index] = (data[pixel_index] & ~1) | ((watermark[i] >> (i % 8)) & 1);
    }
}

void extractWatermark(unsigned char* data, char* watermark, int wm_len, int width, int height) {
    for (int i = 0; i < wm_len; i++) {
        int pixel_index = (i * 3) % (width * height * 3);
        watermark[i] = 0;
        watermark[i] |= (data[pixel_index] & 1) << (i % 8);
    }
    watermark[wm_len] = '\0'; // Null-terminate the string
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_bmp> <output_bmp> <watermark_text>\n", argv[0]);
        return 1;
    }

    BMPHeader bmpHeader;
    BMPInfoHeader bmpInfoHeader;
    int width, height;
    unsigned char* imageData = readBMP(argv[1], &bmpHeader, &bmpInfoHeader, &width, &height);
    if (!imageData) return 1;

    // Embed watermark
    embedWatermark(imageData, argv[3], width, height);
    writeBMP(argv[2], bmpHeader, bmpInfoHeader, imageData);
    
    // For extraction (optional)
    char extractedWatermark[256];
    extractWatermark(imageData, extractedWatermark, strlen(argv[3]), width, height);
    printf("Extracted Watermark: %s\n", extractedWatermark);

    free(imageData);
    return 0;
}