//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Function to embed watermark into a pixel
void embed_watermark(uint8_t *pixel, uint8_t watermark) {
    pixel[0] = (pixel[0] & 0xFE) | (watermark & 0x01); // modify LSB to embed watermark bit
}

// Function to extract watermark from a pixel
uint8_t extract_watermark(uint8_t *pixel) {
    return pixel[0] & 0x01; // read LSB to retrieve watermark bit
}

// Function to convert a text watermark to a binary array
void text_to_binary(const char *text, uint8_t *binary, size_t *length) {
    size_t text_length = strlen(text);
    *length = text_length * 8; // 8 bits for each character
    for (size_t i = 0; i < text_length; i++) {
        for (int j = 0; j < 8; j++) {
            binary[i * 8 + j] = (text[i] >> (7 - j)) & 0x01; // extract individual bits
        }
    }
}

// Function to embed a binary watermark into a pixel array
void embed_watermark_in_image(uint8_t *image, size_t width, size_t height, const char *watermark) {
    size_t watermark_bits_length;
    uint8_t binary_watermark[256] = {0};
    
    text_to_binary(watermark, binary_watermark, &watermark_bits_length);
    
    size_t index = 0;
    for (size_t y = 0; y < height && index < watermark_bits_length; y++) {
        for (size_t x = 0; x < width && index < watermark_bits_length; x++) {
            embed_watermark(&image[(y * width + x) * 3], binary_watermark[index++]);
        }
    }
}

// Function to extract watermark from a pixel array
void extract_watermark_from_image(uint8_t *image, size_t width, size_t height, char *watermark, size_t watermark_length) {
    size_t index = 0;
    for (size_t y = 0; y < height && index < watermark_length * 8; y++) {
        for (size_t x = 0; x < width && index < watermark_length * 8; x++) {
            uint8_t bit = extract_watermark(&image[(y * width + x) * 3]);
            if (index % 8 == 0) {
                watermark[index / 8] = 0; // start new byte
            }
            watermark[index / 8] |= (bit << (7 - (index % 8))); // set appropriate bit
            index++;
        }
    }
    watermark[watermark_length] = '\0'; // Null-terminate the extracted string
}

// Function to simulate loading a PPM image
uint8_t *load_image(const char *filename, size_t *width, size_t *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    // Read PPM header
    char header[3];
    fscanf(file, "%s\n", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported file format: %s\n", filename);
        fclose(file);
        return NULL;
    }

    fscanf(file, "%zu %zu\n255\n", width, height);
    
    size_t image_size = 3 * (*width) * (*height);
    uint8_t *image = (uint8_t *)malloc(image_size);
    if (!image) {
        fprintf(stderr, "Memory allocation failed!\n");
        fclose(file);
        return NULL;
    }

    fread(image, sizeof(uint8_t), image_size, file);
    fclose(file);
    return image;
}

// Function to simulate saving a PPM image
void save_image(const char *filename, uint8_t *image, size_t width, size_t height) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%zu %zu\n255\n", width, height);
    fwrite(image, sizeof(uint8_t), 3 * width * height, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image.ppm> <output_image.ppm> <watermark_text>\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t width, height;
    uint8_t *image = load_image(argv[1], &width, &height);
    if (!image) {
        return EXIT_FAILURE;
    }

    embed_watermark_in_image(image, width, height, argv[3]);

    save_image(argv[2], image, width, height);
    free(image);

    // Extracting watermark for verification
    uint8_t extracted_watermark[256] = {0};
    extract_watermark_from_image(image, width, height, (char *)extracted_watermark, strlen(argv[3]));

    printf("Extracted Watermark: %s\n", extracted_watermark);

    return EXIT_SUCCESS;
}