//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t bfType;      // Magic number for BMP files
    uint32_t bfSize;      // Size of the BMP file
    uint16_t bfReserved1; // Reserved
    uint16_t bfReserved2; // Reserved
    uint32_t bfOffBits;   // Offset to start of pixel data
} BMPFileHeader;

typedef struct {
    uint32_t biSize;          // Size of the structure
    int32_t  biWidth;         // Width of the image
    int32_t  biHeight;        // Height of the image
    uint16_t biPlanes;        // Number of color planes
    uint16_t biBitCount;      // Bits per pixel
    uint32_t biCompression;    // Compression type
    uint32_t biSizeImage;     // Size of image data
    int32_t  biXPelsPerMeter;   // Pixels per meter in x
    int32_t  biYPelsPerMeter;   // Pixels per meter in y
    uint32_t biClrUsed;       // Number of colors
    uint32_t biClrImportant;   // Important colors
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;
#pragma pack(pop)

void flip_image(RGB *pixels, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            RGB temp = pixels[y * width + x];
            pixels[y * width + x] = pixels[y * width + (width - 1 - x)];
            pixels[y * width + (width - 1 - x)] = temp;
        }
    }
}

void adjust_brightness(RGB *pixels, int width, int height, int adjustment) {
    for (int i = 0; i < width * height; i++) {
        int r = pixels[i].red + adjustment;
        int g = pixels[i].green + adjustment;
        int b = pixels[i].blue + adjustment;

        pixels[i].red = (r < 0) ? 0 : (r > 255) ? 255 : r;
        pixels[i].green = (g < 0) ? 0 : (g > 255) ? 255 : g;
        pixels[i].blue = (b < 0) ? 0 : (b > 255) ? 255 : b;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input.bmp> <output_flipped.bmp> <output_bright.bmp>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (!input_file) {
        perror("Failed to open input file");
        return 1;
    }

    BMPFileHeader bmp_file_header;
    BMPInfoHeader bmp_info_header;

    fread(&bmp_file_header, sizeof(BMPFileHeader), 1, input_file);
    fread(&bmp_info_header, sizeof(BMPInfoHeader), 1, input_file);

    int width = bmp_info_header.biWidth;
    int height = bmp_info_header.biHeight;
    int row_padded = (width * 3 + 3) & (~3);

    RGB *pixels = (RGB *)malloc(row_padded * height);
    fseek(input_file, bmp_file_header.bfOffBits, SEEK_SET);
    fread(pixels, sizeof(RGB), width * height, input_file);
    fclose(input_file);

    // Flip the image
    flip_image(pixels, width, height);

    FILE *output_file = fopen(argv[2], "wb");
    fwrite(&bmp_file_header, sizeof(BMPFileHeader), 1, output_file);
    fwrite(&bmp_info_header, sizeof(BMPInfoHeader), 1, output_file);
    fwrite(pixels, sizeof(RGB), width * height, output_file);
    fclose(output_file);
    
    // Adjust brightness
    int brightness_adjustment = 50;  // Example brightness adjustment
    adjust_brightness(pixels, width, height, brightness_adjustment);

    output_file = fopen(argv[3], "wb");
    fwrite(&bmp_file_header, sizeof(BMPFileHeader), 1, output_file);
    fwrite(&bmp_info_header, sizeof(BMPInfoHeader), 1, output_file);
    fwrite(pixels, sizeof(RGB), width * height, output_file);
    fclose(output_file);

    free(pixels);
    printf("Image processing completed: Flipped to %s and Brightness adjusted to %s\n", argv[2], argv[3]);
    return 0;
}