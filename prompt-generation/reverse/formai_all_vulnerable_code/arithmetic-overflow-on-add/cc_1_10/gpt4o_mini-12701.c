//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>
#include <jpeglib.h>
#include <getopt.h>

#define ASCII_CHARS "@%#*+=-:. "
#define CHAR_COUNT (strlen(ASCII_CHARS))

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

// Function to load a JPEG image
Image* load_jpeg(const char *filename) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;

    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        fprintf(stderr, "Error opening JPEG file %s\n", filename);
        return NULL;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    Image *img = (Image *)malloc(sizeof(Image));
    img->width = cinfo.output_width;
    img->height = cinfo.output_height;
    img->pixels = (Pixel *)malloc(sizeof(Pixel) * img->width * img->height);

    unsigned char *buffer = (unsigned char *)malloc(cinfo.output_width * cinfo.output_components);
    size_t row_stride = cinfo.output_width * cinfo.output_components;

    int row = 0;
    while (cinfo.output_scanline < cinfo.output_height) {
        jpeg_read_scanlines(&cinfo, &buffer, 1);
        for (int i = 0; i < cinfo.output_width; i++) {
            img->pixels[row * img->width + i].r = buffer[i * 3];
            img->pixels[row * img->width + i].g = buffer[i * 3 + 1];
            img->pixels[row * img->width + i].b = buffer[i * 3 + 2];
        }
        row++;
    }

    free(buffer);
    jpeg_finish_decompress(&cinfo);
    fclose(infile);
    return img;
}

// Function to convert pixel to grayscale
int pixel_to_grayscale(Pixel pixel) {
    return (int)(0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b);
}

// Function to convert image to ASCII art
void image_to_ascii(Image *img) {
    for (int y = 0; y < img->height; y += 2) {
        for (int x = 0; x < img->width; x += 2) {
            int gray1 = pixel_to_grayscale(img->pixels[y * img->width + x]);
            int gray2 = pixel_to_grayscale(img->pixels[y * img->width + (x + 1)]);
            int gray3 = pixel_to_grayscale(img->pixels[(y + 1) * img->width + x]);
            int gray4 = pixel_to_grayscale(img->pixels[(y + 1) * img->width + (x + 1)]);

            int avg_gray = (gray1 + gray2 + gray3 + gray4) / 4;
            int char_index = (avg_gray * (CHAR_COUNT - 1)) / 255;

            putchar(ASCII_CHARS[CHAR_COUNT - char_index - 1]);  // Invert for better contrast
        }
        putchar('\n');
    }
}

// Main function to handle command-line arguments and run the program
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.jpg>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    Image *img = load_jpeg(argv[1]);
    if (!img) {
        return EXIT_FAILURE;
    }

    printf("ASCII Art Representation:\n");
    image_to_ascii(img);

    free(img->pixels);
    free(img);
    return EXIT_SUCCESS;
}