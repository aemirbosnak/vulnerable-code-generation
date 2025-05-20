//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 60

// Define the ASCII characters to be used
char ascii_chars[] = {'@', '#', '$', '%', '*', '+', '-', '.', '/'}; 

// Helper function to convert RGB color values to grayscale
int rgb_to_gray_scale(unsigned char r, unsigned char g, unsigned char b) {
    return 0.299 * r + 0.587 * g + 0.114 * b;
}

int main(void) {
    // load image file
    FILE* image_file = fopen("example_image.ppm", "rb");
    if (!image_file) {
        fprintf(stderr, "Error opening image file.");
        return 1;
    }

    // read image dimensions and max color value
    char magic[2];
    int width, height, max_color_val;
    fscanf(image_file, "%s %d %d %d", magic, &width, &height, &max_color_val);

    if (strcmp(magic, "P6") != 0 || max_color_val > 255) {
        fprintf(stderr, "Invalid image format.");
        fclose(image_file);
        return 1;
    }

    // read image data
    unsigned char* image_data = (unsigned char*) malloc(width * height * 3 * sizeof(unsigned char));
    if (!image_data) {
        fprintf(stderr, "Memory allocation failed.");
        fclose(image_file);
        return 1;
    }
    if (fread(image_data, sizeof(unsigned char), width * height * 3, image_file) != width * height * 3) {
        fprintf(stderr, "Error reading image data.");
        fclose(image_file);
        free(image_data);   
        return 1;   
    }
    fclose(image_file);

    // convert image to grayscale and resize
    unsigned char grayscale[WIDTH][HEIGHT];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int sample_x = floor(x * 1.0 * width / WIDTH);
            int sample_y = floor(y * 1.0 * height / HEIGHT);
            int r = image_data[(sample_y * width + sample_x) * 3];
            int g = image_data[(sample_y * width + sample_x) * 3 + 1];
            int b = image_data[(sample_y * width + sample_x) * 3 + 2];
            grayscale[x][y] = rgb_to_gray_scale(r, g, b);
        }
    }
    free(image_data);

    // Convert grayscale values to ASCII art characters
    char ascii_art[WIDTH][HEIGHT];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int gray_value = grayscale[x][y];
            int char_index = floor(gray_value * 1.0 / 255 * (sizeof(ascii_chars) / sizeof(char)));
            ascii_art[x][y] = ascii_chars[char_index];
        }
    }

    // Display ASCII art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", ascii_art[x][y]);
        }
        printf("\n");
    }

    return 0;
}