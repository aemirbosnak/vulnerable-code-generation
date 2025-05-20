//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <jpeglib.h>

// Function to add watermark to pixel data
void add_watermark(uint8_t *image_data, int width, int height, const char *watermark, int wm_width, int wm_height) {
    for (int y = 0; y < wm_height; y++) {
        for (int x = 0; x < wm_width; x++) {
            // Simple check to place watermark
            if (y < height && x < width) {
                image_data[(y * width + x) * 3] = (image_data[(y * width + x) * 3] + watermark[y * wm_width + x]) / 2; // Red channel
                image_data[(y * width + x) * 3 + 1] = (image_data[(y * width + x) * 3 + 1] + watermark[y * wm_width + x]) / 2; // Green channel
                image_data[(y * width + x) * 3 + 2] = (image_data[(y * width + x) * 3 + 2] + watermark[y * wm_width + x]) / 2; // Blue channel
            }
        }
    }
}

// Function to read JPEG file
uint8_t *read_jpeg_file(const char *filename, int *width, int *height) {
    struct jpeg_decompress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *infile;

    if ((infile = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "cannot open %s\n", filename);
        return NULL;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_decompress(&cinfo);
    jpeg_stdio_src(&cinfo, infile);
    jpeg_read_header(&cinfo, TRUE);
    jpeg_start_decompress(&cinfo);

    *width = cinfo.output_width;
    *height = cinfo.output_height;
    int pixel_count = (*width) * (*height);
    uint8_t *image_data = (uint8_t *)malloc(pixel_count * 3);

    while (cinfo.output_scanline < cinfo.output_height) {
        uint8_t *row_pointer[1];
        row_pointer[0] = image_data + cinfo.output_scanline * (*width) * 3;
        jpeg_read_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_decompress(&cinfo);
    fclose(infile);
    return image_data;
}

// Function to write JPEG file
void write_jpeg_file(const char *filename, uint8_t *image_data, int width, int height) {
    struct jpeg_compress_struct cinfo;
    struct jpeg_error_mgr jerr;
    FILE *outfile;

    if ((outfile = fopen(filename, "wb")) == NULL) {
        fprintf(stderr, "cannot open %s\n", filename);
        return;
    }

    cinfo.err = jpeg_std_error(&jerr);
    jpeg_create_compress(&cinfo);
    jpeg_stdio_dest(&cinfo, outfile);

    cinfo.image_width = width;
    cinfo.image_height = height;
    cinfo.input_components = 3;
    cinfo.in_color_space = JCS_RGB;
    jpeg_set_defaults(&cinfo);
    jpeg_start_compress(&cinfo, TRUE);

    while (cinfo.next_scanline < cinfo.image_height) {
        uint8_t *row_pointer[1];
        row_pointer[0] = image_data + cinfo.next_scanline * width * 3;
        jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }

    jpeg_finish_compress(&cinfo);
    fclose(outfile);
}

// Function to convert watermark string to grayscale image
uint8_t *create_watermark(const char *watermark, int *wm_width, int *wm_height) {
    *wm_width = strlen(watermark);
    *wm_height = 1;
    uint8_t *watermark_image = (uint8_t *)malloc((*wm_width) * (*wm_height));

    for (int x = 0; x < *wm_width; x++) {
        watermark_image[x] = (uint8_t)(watermark[x]); // Simple conversion to grayscale
    }

    return watermark_image;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <watermark_text>\n", argv[0]);
        return 1;
    }

    int width, height, wm_width, wm_height;
    uint8_t *image_data = read_jpeg_file(argv[1], &width, &height);
    if (!image_data) {
        return 1;
    }

    uint8_t *watermark_image = create_watermark(argv[3], &wm_width, &wm_height);
    add_watermark(image_data, width, height, watermark_image, wm_width, wm_height);
    write_jpeg_file(argv[2], image_data, width, height);

    free(image_data);
    free(watermark_image);
    return 0;
}