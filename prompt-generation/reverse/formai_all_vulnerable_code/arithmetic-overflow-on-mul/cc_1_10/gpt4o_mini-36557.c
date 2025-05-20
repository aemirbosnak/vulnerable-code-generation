//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIZE 1024

void print_usage() {
    printf("Usage: ./watermark <input_image> <output_image> <watermark_text>\n");
}

void embed_watermark(uint8_t *image, int width, int height, const char *watermark, int wm_length) {
    for (int i = 0; i < wm_length; i++) {
        // Simple LSB algorithm: Embed watermark text into the least significant bit of the image pixels
        if (i < width * height * 3) {
            image[i * 3 + 2] = (image[i * 3 + 2] & 0xFE) | ((watermark[i] >> 7) & 0x01); // Red channel
            image[i * 3 + 1] = (image[i * 3 + 1] & 0xFE) | ((watermark[i] >> 6) & 0x01); // Green channel
            image[i * 3]     = (image[i * 3]     & 0xFE) | ((watermark[i] >> 5) & 0x01); // Blue channel
        } else {
            break;
        }
    }
}

void save_image(const char *filename, uint8_t *image, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open output file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Writing a simple BMP header (without considering padding for this example)
    fwrite("BM", 2, 1, file);
    uint32_t file_size = 54 + width * height * 3;
    fwrite(&file_size, sizeof(uint32_t), 1, file);
    fwrite("\0\0\0\0", 4, 1, file); // Reserved
    uint32_t offset = 54;
    fwrite(&offset, sizeof(uint32_t), 1, file);

    // DIB Header
    uint32_t dib_size = 40;
    fwrite(&dib_size, sizeof(uint32_t), 1, file);
    fwrite(&width, sizeof(int32_t), 1, file);
    fwrite(&height, sizeof(int32_t), 1, file);
    uint16_t planes = 1;
    fwrite(&planes, sizeof(uint16_t), 1, file);
    uint16_t bpp = 24;
    fwrite(&bpp, sizeof(uint16_t), 1, file);
    fwrite("\0\0\0\0", 4, 1, file); // Compression
    fwrite("\0\0\0\0", 4, 1, file); // Image size (0 for uncompressed)
    fwrite("\0\0\0\0", 4, 1, file); // Horizontal resolution
    fwrite("\0\0\0\0", 4, 1, file); // Vertical resolution
    fwrite("\0\0\0\0", 4, 1, file); // Colors in palette
    fwrite("\0\0\0\0", 4, 1, file); // Important colors

    // Write image data
    fwrite(image, 3, width * height, file);

    fclose(file);
}

int read_image(const char *filename, uint8_t **image, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open input file %s\n", filename);
        return 0; // Failed to open file
    }

    fseek(file, 18, SEEK_SET); // Move to width and height
    fread(width, sizeof(int), 1, file);
    fread(height, sizeof(int), 1, file);
    fseek(file, 54, SEEK_SET); // Move to pixel data

    *image = (uint8_t *)malloc((*width) * (*height) * 3);
    fread(*image, 3, (*width) * (*height), file);
    fclose(file);
    
    return 1; // Success
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *watermark_text = argv[3];

    uint8_t *image = NULL;
    int width, height;

    if (!read_image(input_file, &image, &width, &height)) {
        return EXIT_FAILURE;
    }

    int wm_length = strlen(watermark_text);
    embed_watermark(image, width, height, watermark_text, wm_length);

    save_image(output_file, image, width, height);

    free(image);
    printf("Watermark embedded successfully into %s\n", output_file);
    return EXIT_SUCCESS;
}