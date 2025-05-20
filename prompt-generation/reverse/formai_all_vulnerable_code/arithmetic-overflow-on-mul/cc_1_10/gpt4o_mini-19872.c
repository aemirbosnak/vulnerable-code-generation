//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;     // File type always "BM"
    uint32_t bfSize;     // Size of the file in bytes
    uint16_t bfReserved1; 
    uint16_t bfReserved2; 
    uint32_t bfOffBits;  // Offset to the pixel data
} BITMAPFILEHEADER;

typedef struct {
    uint32_t biSize;          // Size of this header
    int32_t  biWidth;         // Width of the bitmap in pixels
    int32_t  biHeight;        // Height of the bitmap in pixels
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Size of the pixel data
    int32_t  biXPelsPerMeter;  // Horizontal resolution
    int32_t  biYPelsPerMeter;  // Vertical resolution
    uint32_t biClrUsed;       // Number of colors in the palette
    uint32_t biClrImportant;   // Important colors
} BITMAPINFOHEADER;

#pragma pack(pop)

void apply_grayscale(uint8_t *pixel_data, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_index = (y * width + x) * 3; // Each pixel has 3 bytes (RGB)
            uint8_t blue = pixel_data[pixel_index];
            uint8_t green = pixel_data[pixel_index + 1];
            uint8_t red = pixel_data[pixel_index + 2];

            // Calculate the grayscale value
            uint8_t gray = (uint8_t)(0.299 * red + 0.587 * green + 0.114 * blue);
            pixel_data[pixel_index] = gray;        // Set blue channel
            pixel_data[pixel_index + 1] = gray;    // Set green channel
            pixel_data[pixel_index + 2] = gray;    // Set red channel
        }
    }
}

void save_bmp(char *filename, BITMAPFILEHEADER bfh, BITMAPINFOHEADER bih, uint8_t *pixel_data) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("Failed to open file for writing");
        exit(1);
    }

    fwrite(&bfh, sizeof(bfh), 1, f);
    fwrite(&bih, sizeof(bih), 1, f);
    fwrite(pixel_data, bih.biSizeImage, 1, f);
    fclose(f);
}

void load_bmp(char *filename, BITMAPFILEHEADER *bfh, BITMAPINFOHEADER *bih, uint8_t **pixel_data) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Failed to open file for reading");
        exit(1);
    }

    fread(bfh, sizeof(BITMAPFILEHEADER), 1, f);
    fread(bih, sizeof(BITMAPINFOHEADER), 1, f);
    
    if (bfh->bfType != 0x4D42) {
        printf("Not a valid BMP file\n");
        fclose(f);
        exit(1);
    }

    int width = bih->biWidth;
    int height = abs(bih->biHeight);
    int row_pad = (4 - (width * 3) % 4) % 4; // Row padding for BMP files
    bih->biSizeImage = ((width * 3 + row_pad) * height);
    
    *pixel_data = (uint8_t *)malloc(bih->biSizeImage);
    fseek(f, bfh->bfOffBits, SEEK_SET);
    fread(*pixel_data, bih->biSizeImage, 1, f);
    
    fclose(f);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return 1;
    }

    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    uint8_t *pixel_data = NULL;

    load_bmp(argv[1], &bfh, &bih, &pixel_data);
    
    apply_grayscale(pixel_data, bih.biWidth, abs(bih.biHeight));

    save_bmp(argv[2], bfh, bih, pixel_data);

    free(pixel_data);
    printf("Grayscale image saved as: %s\n", argv[2]);
    
    return 0;
}