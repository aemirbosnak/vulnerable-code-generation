//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} RGB;

typedef struct {
    uint16_t file_type;
    uint32_t file_size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset_data;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bit_count;
    uint32_t compression;
    uint32_t size_image;
    int32_t x_pixels_per_meter;
    int32_t y_pixels_per_meter;
    uint32_t colors_used;
    uint32_t colors_important;   
} DIBHeader;

void print_ascii_art(const RGB image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    char ascii_chars[] = "@%#*+=-:. "; // ASCII characters from dark to light
    int num_chars = sizeof(ascii_chars) - 1; 

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            RGB pixel = image[y][x];
            // Calculate luminance (grayscale)
            uint8_t gray = (pixel.red * 0.299 + pixel.green * 0.587 + pixel.blue * 0.114);
            // Get ASCII character index based on grayscale value
            int char_index = (gray * num_chars) / 255;
            putchar(ascii_chars[char_index]);
        }
        putchar('\n');
    }
}

void load_bmp(const char *filename, RGB image[MAX_HEIGHT][MAX_WIDTH], int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    BMPHeader bmp_header;
    DIBHeader dib_header;

    fread(&bmp_header, sizeof(BMPHeader), 1, file);
    fread(&dib_header, sizeof(DIBHeader), 1, file);

    *width = dib_header.width;
    *height = dib_header.height;

    printf("Width: %d, Height: %d\n", *width, *height);

    // Move file pointer to the pixel data
    fseek(file, bmp_header.offset_data, SEEK_SET);
    
    for (int y = 0; y < *height; y++) {
        for (int x = 0; x < *width; x++) {
            RGB pixel;
            fread(&pixel, sizeof(RGB), 1, file);
            image[y][x] = pixel;
        }
        // BMP files are stored bottom-to-top
        fseek(file, (3 * (*width)) % 4, SEEK_CUR); // Padding for row
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    RGB image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;

    load_bmp(argv[1], image, &width, &height);
    print_ascii_art(image, width, height);

    return EXIT_SUCCESS;
}