//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <jpeglib.h>
#include <unistd.h>

#define ASCII_CHARS "@%#*+=-:. "
#define NUM_ASCII_CHARS (sizeof(ASCII_CHARS) - 1)

unsigned char* read_jpeg_file(const char* filename, int* width, int* height) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);

    FILE* infile = fopen(filename, "rb");
    if (infile == NULL) {
        fprintf(stderr, "Error opening JPEG file %s\n", filename);
        return NULL;
    }

    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;
    unsigned char* buffer = (unsigned char*)malloc(3 * (*width) * (*height));
    
    unsigned char* rowptr[1];
    while (cinfo.output_scanline < cinfo.output_height) {
        rowptr[0] = buffer + 3 * (*width) * cinfo.output_scanline;
        jpeg_read_scanlines(&cinfo, rowptr, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);

    return buffer;
}

void free_image_buffer(unsigned char* buffer) {
    if (buffer != NULL) {
        free(buffer);
    }
}

char get_ascii_char(int gray) {
    return ASCII_CHARS[(int)(gray * (NUM_ASCII_CHARS - 1) / 255)];
}

void create_ascii_art(unsigned char* img, int width, int height) {
    for (int y = 0; y < height; y += 2) {
        for (int x = 0; x < width; x++) {
            int r = img[(y * width + x) * 3 + 0];
            int g = img[(y * width + x) * 3 + 1];
            int b = img[(y * width + x) * 3 + 2];

            int gray = (r + g + b) / 3; // Simple average to convert to grayscale
            char ascii_char = get_ascii_char(gray);
            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <image_file.jpg>\n", prog_name);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    int width, height;
    unsigned char* img = read_jpeg_file(argv[1], &width, &height);
    if (!img) {
        return EXIT_FAILURE;
    }

    create_ascii_art(img, width, height);
    free_image_buffer(img);
    
    return EXIT_SUCCESS;
}