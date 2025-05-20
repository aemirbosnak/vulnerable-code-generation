//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t file_type;     // File type, always "BM" 
    uint32_t file_size;     // Size of the file in bytes
    uint16_t reserved1;     // Always 0
    uint16_t reserved2;     // Always 0
    uint32_t offset_data;   // Offset to the pixel data
} BMPHeader;

typedef struct {
    uint32_t size;              // Size of the BMPHeader
    int32_t width;              // Width of the bitmap in pixels
    int32_t height;             // Height of the bitmap in pixels
    uint16_t planes;            // Number of color planes, must be 1
    uint16_t bit_count;         // Bits per pixel
    uint32_t compression;       // Compression type
    uint32_t size_image;        // Size of the image data
    int32_t x_pixels_per_meter; // Pixels per meter in x
    int32_t y_pixels_per_meter; // Pixels per meter in y
    uint32_t colors_used;       // Number of colors used
    uint32_t colors_important;  // Important colors
} BMPInfoHeader;

#pragma pack(pop)

typedef struct {
    uint8_t r, g, b; // RGB components
} Pixel;

Pixel** load_bmp(const char* filename, BMPHeader* bmp_header, BMPInfoHeader* bmp_info_header);
void save_bmp(const char* filename, Pixel** pixels, BMPHeader bmp_header, BMPInfoHeader bmp_info_header);
void free_image(Pixel** pixels, int height);
void flip_image(Pixel** pixels, int width, int height);
void adjust_brightness(Pixel** pixels, int width, int height, int brightness);
void adjust_contrast(Pixel** pixels, int width, int height, float contrast);

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input.bmp> <output.bmp> <brightness> <contrast>\n", argv[0]);
        return 1;
    }
    
    const char* input_filename = argv[1];
    const char* output_filename = argv[2];
    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    BMPHeader bmp_header;
    BMPInfoHeader bmp_info_header;
    Pixel** pixels = load_bmp(input_filename, &bmp_header, &bmp_info_header);

    if (!pixels) {
        printf("Failed to load image.\n");
        return 1;
    }

    flip_image(pixels, bmp_info_header.width, bmp_info_header.height);
    adjust_brightness(pixels, bmp_info_header.width, bmp_info_header.height, brightness);
    adjust_contrast(pixels, bmp_info_header.width, bmp_info_header.height, contrast);
    
    save_bmp(output_filename, pixels, bmp_header, bmp_info_header);

    free_image(pixels, bmp_info_header.height);
    return 0;
}

Pixel** load_bmp(const char* filename, BMPHeader* bmp_header, BMPInfoHeader* bmp_info_header) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    fread(bmp_header, sizeof(BMPHeader), 1, file);
    fread(bmp_info_header, sizeof(BMPInfoHeader), 1, file);

    if (bmp_header->file_type != 0x4D42) { // Check "BM"
        fclose(file);
        printf("Not a BMP file.\n");
        return NULL;
    }

    // Allocate memory for pixel array
    int width = bmp_info_header->width;
    int height = abs(bmp_info_header->height);
    Pixel** pixels = malloc(height * sizeof(Pixel*));
    for (int i = 0; i < height; i++) {
        pixels[i] = malloc(width * sizeof(Pixel));
    }

    fseek(file, bmp_header->offset_data, SEEK_SET);
    for (int i = height - 1; i >= 0; i--) { // BMP stores pixels from bottom to top
        fread(pixels[i], sizeof(Pixel), width, file);
    }

    fclose(file);
    return pixels;
}

void save_bmp(const char* filename, Pixel** pixels, BMPHeader bmp_header, BMPInfoHeader bmp_info_header) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Could not open file to write");
        return;
    }

    fwrite(&bmp_header, sizeof(BMPHeader), 1, file);
    fwrite(&bmp_info_header, sizeof(BMPInfoHeader), 1, file);

    fseek(file, bmp_header.offset_data, SEEK_SET);
    for (int i = abs(bmp_info_header.height) - 1; i >= 0; i--) {
        fwrite(pixels[i], sizeof(Pixel), bmp_info_header.width, file);
    }

    fclose(file);
}

void free_image(Pixel** pixels, int height) {
    for (int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);
}

void flip_image(Pixel** pixels, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            Pixel temp = pixels[i][j];
            pixels[i][j] = pixels[i][width - j - 1];
            pixels[i][width - j - 1] = temp;
        }
    }
}

void adjust_brightness(Pixel** pixels, int width, int height, int brightness) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i][j].r = (uint8_t) fmin(fmax(pixels[i][j].r + brightness, 0), 255);
            pixels[i][j].g = (uint8_t) fmin(fmax(pixels[i][j].g + brightness, 0), 255);
            pixels[i][j].b = (uint8_t) fmin(fmax(pixels[i][j].b + brightness, 0), 255);
        }
    }
}

void adjust_contrast(Pixel** pixels, int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i][j].r = (uint8_t) fmin(fmax(factor * (pixels[i][j].r - 128) + 128, 0), 255);
            pixels[i][j].g = (uint8_t) fmin(fmax(factor * (pixels[i][j].g - 128) + 128, 0), 255);
            pixels[i][j].b = (uint8_t) fmin(fmax(factor * (pixels[i][j].b - 128) + 128, 0), 255);
        }
    }
}