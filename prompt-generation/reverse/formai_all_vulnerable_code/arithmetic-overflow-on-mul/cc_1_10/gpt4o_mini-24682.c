//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_FILENAME_LEN 255
#define WATERMARK_SIZE 64 // Number of bits in the watermark
#define PIXEL_DEPTH 255    // Maximum pixel depth for grayscale

// Function to embed a watermark into a pixel
uint8_t embed_watermark(uint8_t pixel, uint8_t watermark_bit) {
    // Clear the least significant bit (LSB) and then embed the watermark bit
    return (pixel & ~1) | (watermark_bit & 1);
}

// Function to extract a watermark bit from a pixel
uint8_t extract_watermark(uint8_t pixel) {
    return pixel & 1; // Return the last bit
}

// Function to handle BMP file reading
void read_bmp(const char *filename, uint8_t **image_data, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    fseek(file, 18, SEEK_SET);
    fread(width, sizeof(int), 1, file);
    fread(height, sizeof(int), 1, file);

    fseek(file, 54, SEEK_SET);
    size_t image_size = (*width) * (*height);
    *image_data = (uint8_t *)malloc(image_size);
    fread(*image_data, sizeof(uint8_t), image_size, file);
    
    fclose(file);
}

// Function to handle BMP file writing
void write_bmp(const char *filename, const uint8_t *image_data, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }

    // Write BMP header
    fwrite("BM", 1, 2, file);
    uint32_t file_size = 54 + width * height;
    fwrite(&file_size, sizeof(uint32_t), 1, file);
    fwrite("\0\0\0\0", 1, 4, file); // reserved
    uint32_t data_offset = 54;
    fwrite(&data_offset, sizeof(uint32_t), 1, file);
    uint32_t header_size = 40;
    fwrite(&header_size, sizeof(uint32_t), 1, file);
    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);
    uint16_t planes = 1;
    fwrite(&planes, sizeof(uint16_t), 1, file);
    uint16_t bpp = 8; // For grayscale
    fwrite(&bpp, sizeof(uint16_t), 1, file);
    fwrite("\0\0\0\0", 1, 4, file); // compression
    fwrite("\0\0\0\0", 1, 4, file); // image size
    fwrite("\0\0\0\0", 1, 4, file); // x pixels per meter
    fwrite("\0\0\0\0", 1, 4, file); // y pixels per meter
    fwrite("\0\0\0\0", 1, 4, file); // total colors
    fwrite("\0\0\0\0", 1, 4, file); // important colors

    fwrite(image_data, sizeof(uint8_t), width * height, file);
    
    fclose(file);
}

// Function to embed watermark
void embed_watermark_in_image(uint8_t *image_data, const uint8_t *watermark, int width, int height) {
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        int pixel_index = i; // Simplistic approach: directly mapping watermark to pixels
        if (pixel_index < width * height) {
            image_data[pixel_index] = embed_watermark(image_data[pixel_index], watermark[i]);
        }
    }
}

// Function to extract watermark from image
void extract_watermark_from_image(const uint8_t *image_data, uint8_t *watermark, int width, int height) {
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        int pixel_index = i; // Simplistic approach for extraction
        if (pixel_index < width * height) {
            watermark[i] = extract_watermark(image_data[pixel_index]);
        }
    }
}

// Function to print the watermark
void print_watermark(const uint8_t *watermark) {
    printf("Extracted Watermark: ");
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        printf("%d ", watermark[i]);
    }
    printf("\n");
}

// Main function demonstrating watermarking
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_bmp_file> <output_bmp_file> <watermark_bits>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *input_filename = argv[1];
    char *output_filename = argv[2];
    uint8_t watermark[WATERMARK_SIZE] = {0};

    // Convert the watermark_bits from string to uint8_t array
    size_t watermark_length = strlen(argv[3]);
    for (int i = 0; i < WATERMARK_SIZE && i < watermark_length; i++) {
        watermark[i] = argv[3][i] - '0'; // Convert char to int (0 or 1)
    }

    uint8_t *image_data = NULL;
    int width, height;

    read_bmp(input_filename, &image_data, &width, &height);
    embed_watermark_in_image(image_data, watermark, width, height);
    write_bmp(output_filename, image_data, width, height);

    uint8_t extracted_watermark[WATERMARK_SIZE] = {0};
    extract_watermark_from_image(image_data, extracted_watermark, width, height);
    print_watermark(extracted_watermark);

    free(image_data);
    return 0;
}