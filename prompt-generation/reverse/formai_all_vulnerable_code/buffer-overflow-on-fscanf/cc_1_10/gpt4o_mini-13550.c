//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WIDTH 512
#define HEIGHT 512
#define WATERMARK_SIZE 100

// Function to encode watermark into image
void encode_watermark(uint8_t image[HEIGHT][WIDTH], const char* watermark) {
    int len = strlen(watermark);
    for (int i = 0; i < len && i < WATERMARK_SIZE; i++) {
        for (int j = 0; j < 8; j++) { // Each character contains 8 bits
            int idx = i * 8 + j;
            if (idx >= HEIGHT * WIDTH) return; // Prevent overflow

            uint8_t bit = (watermark[i] >> (7 - j)) & 1;
            if (bit) {
                image[idx / WIDTH][idx % WIDTH] |= 1; // Set LSB
            } else {
                image[idx / WIDTH][idx % WIDTH] &= 0xFE; // Clear LSB
            }
        }
    }
}

// Function to decode watermark from image
void decode_watermark(uint8_t image[HEIGHT][WIDTH], char* watermark) {
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        watermark[i] = 0;
        for (int j = 0; j < 8; j++) { // Read 8 bits per character
            int idx = i * 8 + j;
            if (idx >= HEIGHT * WIDTH) {
                watermark[i] = '\0'; // Null-terminate if out of bounds
                return;
            }
            watermark[i] <<= 1; // Shift left
            if (image[idx / WIDTH][idx % WIDTH] & 1) {
                watermark[i] |= 1; // Set LSB from image
            }
        }
    }
}

// Function to load an image from a PGM file
int load_image(const char* filename, uint8_t image[HEIGHT][WIDTH]) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return -1;
    }

    // Skip the file header
    char format[3];
    fscanf(file, "%s\n", format);
    fscanf(file, "%*d %*d\n255\n");

    // Read pixel data
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = fgetc(file);
        }
    }
    
    fclose(file);
    return 0;
}

// Function to save an image to a PGM file
void save_image(const char* filename, uint8_t image[HEIGHT][WIDTH]) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P5\n%d %d\n255\n", WIDTH, HEIGHT);
    
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fputc(image[i][j], file);
        }
    }
    
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image.pgm> <watermark_text> <output_image.pgm>\n", argv[0]);
        return 1;
    }

    uint8_t image[HEIGHT][WIDTH] = {0};
    char watermark[WATERMARK_SIZE + 1] = {0}; // +1 for null terminator

    // Load image
    if (load_image(argv[1], image) != 0) return 1;

    // Set watermark text
    snprintf(watermark, WATERMARK_SIZE + 1, "%s", argv[2]);

    // Embed watermark
    encode_watermark(image, watermark);
    
    // Save the watermarked image
    save_image(argv[3], image);
    
    // To decode the watermark (for testing purposes)
    char decoded[WATERMARK_SIZE + 1];
    decode_watermark(image, decoded);
    
    printf("Decoded Watermark: %s\n", decoded);

    return 0;
}