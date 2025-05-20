//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256
#define MAX_VALUE 255

int main(int argc, char** argv) {
    FILE* input_file = fopen("input.bmp", "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    fseek(input_file, 18, SEEK_SET); // Skip BMP header
    int width, height;
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);

    printf("Image dimensions: %dx%d\n", width, height);

    unsigned char* image_data = (unsigned char*) malloc(WIDTH * HEIGHT * 3); // Allocate memory for image data
    fread(image_data, sizeof(unsigned char), WIDTH * HEIGHT * 3, input_file); // Read image data from file

    fclose(input_file);

    // Apply watermarking algorithm
    int watermark_text[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80}; // Watermark text as ASCII values
    int watermark_size = sizeof(watermark_text) / sizeof(watermark_text[0]); // Get size of watermark text

    int watermark_intensity = 50; // Intensity of watermark (0-100)

    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int pixel_value = image_data[y * WIDTH * 3 + x * 3]; // Get pixel value
            int watermark_index = (y * WIDTH + x) % watermark_size; // Get index of watermark character
            int watermark_value = watermark_text[watermark_index]; // Get ASCII value of watermark character

            int new_pixel_value = pixel_value + watermark_value * watermark_intensity / 100; // Apply watermark

            if (new_pixel_value < 0) {
                new_pixel_value = 0;
            } else if (new_pixel_value > MAX_VALUE) {
                new_pixel_value = MAX_VALUE;
            }

            image_data[y * WIDTH * 3 + x * 3] = new_pixel_value; // Set new pixel value
        }
    }

    // Save modified image
    FILE* output_file = fopen("output.bmp", "wb");
    fwrite(&width, sizeof(int), 1, output_file);
    fwrite(&height, sizeof(int), 1, output_file);

    fwrite(image_data, sizeof(unsigned char), WIDTH * HEIGHT * 3, output_file);

    fclose(output_file);

    printf("Watermarking completed.\n");

    return 0;
}