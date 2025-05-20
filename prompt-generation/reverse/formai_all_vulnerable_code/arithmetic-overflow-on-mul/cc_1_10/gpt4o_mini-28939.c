//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <jpeglib.h>
#include <stdint.h>

#define ASCII_CHARS "@%#*+=-:. "
#define ASCII_LEN (sizeof(ASCII_CHARS) - 1)

void convert_to_ascii(uint8_t *image_data, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int idx = (i * width + j) * 3;
            uint8_t r = image_data[idx];
            uint8_t g = image_data[idx + 1];
            uint8_t b = image_data[idx + 2];

            // Convert pixel to grayscale using the luminosity method
            uint8_t gray = (uint8_t)(0.299 * r + 0.587 * g + 0.114 * b);
            int char_index = (gray * ASCII_LEN) / 256;
            putchar(ASCII_CHARS[char_index]);
        }
        putchar('\n');
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return 1;
    }

    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    int width = cinfo.output_width;
    int height = cinfo.output_height;
    int pixel_size = 3; // RGB

    // Allocate memory for the image data
    uint8_t *image_data = (uint8_t *)malloc(width * height * pixel_size);
    if (!image_data) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        jpeg_destroy_decompress(&cinfo);
        fclose(infile);
        return 1;
    }

    while (cinfo.output_scanline < cinfo.output_height) {
        uint8_t *row_pointer[1];
        row_pointer[0] = image_data + (cinfo.output_scanline) * width * pixel_size;
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    jpeg_destroy_decompress(&cinfo);
    fclose(infile);

    // Convert the image to ASCII
    convert_to_ascii(image_data, width, height);

    // Free the allocated memory
    free(image_data);
    return 0;
}