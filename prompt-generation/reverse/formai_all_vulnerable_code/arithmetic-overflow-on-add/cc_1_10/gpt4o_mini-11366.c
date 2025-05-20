//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;
    uint32_t bfSize;
    uint16_t bfReserved1;
    uint16_t bfReserved2;
    uint32_t bfOffBits;
} BMPHeader;

typedef struct {
    uint32_t biSize;
    int32_t biWidth;
    int32_t biHeight;
    uint16_t biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    int32_t biXPelsPerMeter;
    int32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t biClrImportant;
} BMPInfoHeader;
#pragma pack(pop)

void invert_colors(unsigned char *data, int width, int height) {
    int row_size = (width * 3 + 3) & (~3); // Each row is a multiple of 4 bytes

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int pos = y * row_size + x * 3;
            data[pos] = 255 - data[pos];       // Blue
            data[pos + 1] = 255 - data[pos + 1]; // Green
            data[pos + 2] = 255 - data[pos + 2]; // Red
        }
    }
}

unsigned char *load_bmp(const char *filename, BMPHeader *header, BMPInfoHeader *infoHeader) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    fread(header, sizeof(BMPHeader), 1, file);
    fread(infoHeader, sizeof(BMPInfoHeader), 1, file);

    if (header->bfType != 0x4D42) { // "BM" in little-endian
        fprintf(stderr, "Not a valid BMP file\n");
        fclose(file);
        return NULL;
    }

    int width = infoHeader->biWidth;
    int height = abs(infoHeader->biHeight);

    unsigned char *data = malloc(height * ((width * 3 + 3) & (~3)));
    fseek(file, header->bfOffBits, SEEK_SET);
    fread(data, 1, height * ((width * 3 + 3) & (~3)), file);
    fclose(file);
    
    return data;
}

void save_bmp(const char *filename, BMPHeader *header, BMPInfoHeader *infoHeader, unsigned char *data) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to create file");
        return;
    }

    fwrite(header, sizeof(BMPHeader), 1, file);
    fwrite(infoHeader, sizeof(BMPInfoHeader), 1, file);
    
    int row_size = (infoHeader->biWidth * 3 + 3) & (~3);
    fwrite(data, 1, abs(infoHeader->biHeight) * row_size, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return 1;
    }

    BMPHeader header;
    BMPInfoHeader infoHeader;

    unsigned char *data = load_bmp(argv[1], &header, &infoHeader);
    if (!data) {
        return 1;
    }

    // Invert colors
    invert_colors(data, infoHeader.biWidth, abs(infoHeader.biHeight));

    // Save the modified image
    save_bmp(argv[2], &header, &infoHeader, data);

    // Clean up
    free(data);
    printf("Image edited and saved as %s\n", argv[2]);

    return 0;
}