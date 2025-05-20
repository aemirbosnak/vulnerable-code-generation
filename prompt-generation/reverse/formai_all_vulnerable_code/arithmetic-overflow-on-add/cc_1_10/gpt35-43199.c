//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 80 // Maximum width of output
#define MAX_PIXEL 255 // Maximum value of a pixel

// Returns the average brightness of an input image
int get_brightness(unsigned char* data, int width, int height) {
    int total_brightness = 0;
    int pixels = width * height;

    for (int i = 0; i < pixels; i++) {
        total_brightness += data[i];
    }

    int avg_brightness = total_brightness / pixels;
    return avg_brightness;
}

// Converts an input image to ASCII art
char* convert_to_ascii(unsigned char* data, int width, int height) {
    char* ascii = (char*)malloc((width + 1) * height * sizeof(char));
    int brightness_range = MAX_PIXEL / 10;
    char ascii_chars[11] = "@#MHQO=!*^,. ";

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = data[i * width + j];
            int brightness = pixel / brightness_range;
            ascii[i * (width + 1) + j] = ascii_chars[brightness];
        }
        ascii[(i + 1) * (width + 1) - 1] = '\n';
    }

    ascii[height * (width + 1)] = '\0';
    return ascii;
}

int main() {
    // Open input image file in binary mode
    FILE* file = fopen("input_image.bmp", "rb");
    if (file == NULL) {
        printf("Error: Unable to open input file\n");
        return 1;
    }

    // Read and validate BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    if (header[0] != 'B' || header[1] != 'M') {
        printf("Error: Invalid BMP header\n");
        return 1;
    }

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bpp = *(int*)&header[28];

    if (bpp != 24) {
        printf("Error: Only 24-bit BMP images are supported\n");
        return 1;
    }

    // Allocate memory for input image
    int padding = (4 - (width * 3) % 4) % 4;
    int image_size = height * (width * 3 + padding);
    unsigned char* image_data = (unsigned char*)malloc(image_size * sizeof(unsigned char));

    // Read input image data
    fread(image_data, sizeof(unsigned char), image_size, file);
    fclose(file);

    // Convert input image to ASCII art
    int brightness = get_brightness(image_data, width, height);
    char* ascii_art = convert_to_ascii(image_data, width, height);

    // Output ASCII art to console
    printf("%s", ascii_art);

    // Save ASCII art to file
    FILE* output_file = fopen("output.txt", "w");
    fprintf(output_file, "Input image brightness: %d\n\n", brightness);
    fprintf(output_file, "%s", ascii_art);
    fclose(output_file);

    // Free allocated memory
    free(image_data);
    free(ascii_art);

    return 0;
}