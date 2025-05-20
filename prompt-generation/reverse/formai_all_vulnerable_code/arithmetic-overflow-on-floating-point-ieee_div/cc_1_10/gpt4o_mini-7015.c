//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <stdint.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

const char* ascii_chars = "@%#*+=-:. "; // Characters used for ASCII art representation

void convert_to_ascii(uint8_t *image_data, int width, int height, int max_width) {
    float scale_factor = (float)width / max_width;
    int max_height = (int)(height / scale_factor);

    for (int y = 0; y < max_height; y++) {
        for (int x = 0; x < max_width; x++) {
            int orig_x = (int)(x * scale_factor);
            int orig_y = (int)(y * scale_factor);
            uint8_t r = image_data[(orig_y * width + orig_x) * 3 + 0];
            uint8_t g = image_data[(orig_y * width + orig_x) * 3 + 1];
            uint8_t b = image_data[(orig_y * width + orig_x) * 3 + 2];
            int gray_value = (r + g + b) / 3; // Simple average for grayscale
            int index = (gray_value * (strlen(ascii_chars) - 1)) / 255; 
            putchar(ascii_chars[index]);
        }
        putchar('\n');
    }
}

uint8_t* load_jpeg(const char *filename, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);

    jpeg_stdio_src(&cinfo, file);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;

    uint8_t *image_data = malloc(cinfo.output_width * cinfo.output_height * 3);
    if (!image_data) {
        perror("Error allocating memory for image");
        exit(EXIT_FAILURE);
    }

    while (cinfo.output_scanline < cinfo.output_height) {
        uint8_t *row_pointer[1];
        row_pointer[0] = image_data + cinfo.output_scanline * cinfo.output_width * 3;
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(file);
    return image_data;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <jpeg_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    uint8_t *image_data = load_jpeg(argv[1], &width, &height);

    if (width > MAX_WIDTH) {
        fprintf(stderr, "Warning: Image width exceeds maximum allowed. Resizing...\n");
    }

    convert_to_ascii(image_data, width, height, MAX_WIDTH);
    
    free(image_data);
    return EXIT_SUCCESS;
}