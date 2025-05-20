//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_SIZE 256
#define HEADER_SIZE 54 // Bitmap header size

// Function to read the bitmap file
FILE *read_bmp(const char *filename, uint8_t **image_data, int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, file);

    *width = *(int *)&header[18];
    *height = *(int *)&header[22];

    int size = (*width) * (*height) * 3; // Assuming 24-bit bitmap (3 bytes for RGB)
    *image_data = (uint8_t *)malloc(size);
    fread(*image_data, sizeof(uint8_t), size, file);
    
    fclose(file);
    return file;
}

// Function to write the watermark into the bitmap
void embed_watermark(uint8_t *image_data, const char *watermark, int width, int height) {
    int watermark_length = strlen(watermark);
    
    for (int i = 0; i < watermark_length; i++) {
        // Place a character from watermark into the least significant bit of the pixel
        int pixel_index = (i * width * height / watermark_length) * 3; // Get pixel's starting index in RGB
        if (pixel_index < width * height * 3) { 
            // Embed character into the least significant bit of red
            image_data[pixel_index] = (image_data[pixel_index] & 0xFE) | ((watermark[i] >> 7) & 0x01);
            image_data[pixel_index + 1] = (image_data[pixel_index + 1] & 0xFE) | ((watermark[i] >> 6) & 0x01);
            image_data[pixel_index + 2] = (image_data[pixel_index + 2] & 0xFE) | ((watermark[i] >> 5) & 0x01);
        }
    }
}

// Function to save the modified image to a new bitmap file
void save_bmp(const char *filename, uint8_t *image_data, int width, int height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error creating file");
        return;
    }

    // Bitmap file header
    unsigned char header[HEADER_SIZE] = {
        'B', 'M', // Signature
        0, 0, 0, 0, // File size (to be filled later)
        0, 0, // Reserved1
        0, 0, // Reserved2
        HEADER_SIZE, 0, 0, 0, // Offset to start of pixel array
        40, 0, 0, 0, // Header size
        0, 0, 0, 0, // Width (to be filled later)
        0, 0, 0, 0, // Height (to be filled later)
        1, 0, // Number of color planes
        24, 0, // Bits per pixel
        0, 0, 0, 0, // Compression
        0, 0, 0, 0, // Image size (can be 0 for uncompressed)
        0, 0, 0, 0, // Horizontal resolution
        0, 0, 0, 0, // Vertical resolution
        0, 0, 0, 0, // Colors in color palette
        0, 0, 0, 0  // Important color index
    };

    // Fill in width and height
    *(int *)&header[18] = width;
    *(int *)&header[22] = height;

    // Calculate file size
    int size = HEADER_SIZE + width * height * 3;
    *(int *)&header[2] = size;

    fwrite(header, sizeof(unsigned char), HEADER_SIZE, file);
    fwrite(image_data, sizeof(uint8_t), width * height * 3, file);
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_bmp> <output_bmp> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }

    uint8_t *image_data = NULL;
    int width = 0, height = 0;

    // Read the input BMP
    if (read_bmp(argv[1], &image_data, &width, &height) == NULL) {
        return EXIT_FAILURE;
    }

    // Embed the watermark
    embed_watermark(image_data, argv[3], width, height);

    // Save the modified image
    save_bmp(argv[2], image_data, width, height);

    free(image_data); // Clean up memory
    printf("Watermark embedded successfully!\n");

    return EXIT_SUCCESS;
}