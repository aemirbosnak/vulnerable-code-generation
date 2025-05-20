//FormAI DATASET v1.0 Category: Image Editor ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BMP_HEADER_SIZE 54

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} pixel_t;

void sepia_filter(pixel_t *pixels, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        uint8_t r = pixels[i].red;
        uint8_t g = pixels[i].green;
        uint8_t b = pixels[i].blue;
        pixels[i].red = 0.393 * r + 0.769 * g + 0.189 * b;
        pixels[i].green = 0.349 * r + 0.686 * g + 0.168 * b;
        pixels[i].blue = 0.272 * r + 0.534 * g + 0.131 * b;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s input.bmp output.bmp\n", argv[0]);
        return 1;
    }

    char *input_path = argv[1];
    char *output_path = argv[2];

    FILE *input_file = fopen(input_path, "rb");
    if (!input_file) {
        printf("Error: could not open file %s\n", input_path);
        return 1;
    }

    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    rewind(input_file);

    uint8_t *input_data = (uint8_t*)malloc(input_file_size);
    fread(input_data, sizeof(uint8_t), input_file_size, input_file);

    // Verify that the input file is a BMP file by checking the header
    if (input_data[0] != 'B' || input_data[1] != 'M') {
        printf("%s is not a valid BMP file\n", input_path);
        return 1;
    }

    // Parse the header
    int width = *(int*)&input_data[18];
    int height = *(int*)&input_data[22];
    int bits_per_pixel = *(int*)&input_data[28];

    if (bits_per_pixel != 24) {
        printf("Error: only 24-bit BMP files are supported\n");
        return 1;
    }

    // Allocate memory for the pixel data
    size_t pixel_count = width * height;
    pixel_t *pixels = (pixel_t*)malloc(pixel_count * sizeof(pixel_t));

    // Copy the pixel data from the input file into the pixel array
    for (size_t i = 0; i < pixel_count; i++) {
        int pixel_offset = BMP_HEADER_SIZE + i * 3;
        pixels[i].red = input_data[pixel_offset + 2];
        pixels[i].green = input_data[pixel_offset + 1];
        pixels[i].blue = input_data[pixel_offset];
    }

    fclose(input_file);
    free(input_data);

    // Apply the sepia filter
    sepia_filter(pixels, width, height);

    // Write the output to a new file
    FILE *output_file = fopen(output_path, "wb");
    if (!output_file) {
        printf("Error: could not create file %s\n", output_path);
        return 1;
    }

    // Write the header
    fwrite(input_data, sizeof(uint8_t), BMP_HEADER_SIZE, output_file);

    // Write the pixel data
    for (size_t i = 0; i < pixel_count; i++) {
        fputc(pixels[i].blue, output_file);
        fputc(pixels[i].green, output_file);
        fputc(pixels[i].red, output_file);
    }

    fclose(output_file);
    free(pixels);

    printf("Successfully processed %s and wrote result to %s\n", input_path, output_path);

    return 0;
}