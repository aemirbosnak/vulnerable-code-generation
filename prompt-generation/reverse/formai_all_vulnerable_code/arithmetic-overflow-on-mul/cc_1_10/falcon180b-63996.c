//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 50

#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define BLUE 0x0000FF

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} Color;

void draw_pixel(uint32_t* buffer, int x, int y, Color color) {
    int index = (y * WIDTH + x) * 4;
    buffer[index] = color.b;
    buffer[index + 1] = color.g;
    buffer[index + 2] = color.r;
    buffer[index + 3] = 0xFF;
}

int main() {
    FILE* fp;
    uint32_t* buffer;
    int width, height, bytes_per_pixel;
    Color pixel;

    // Open image file
    fp = fopen("image.png", "rb");
    if (fp == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    // Read image header
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);
    fread(&bytes_per_pixel, sizeof(int), 1, fp);

    // Allocate buffer for image data
    buffer = (uint32_t*) malloc(width * height * bytes_per_pixel);

    // Read image data
    fread(buffer, width * height * bytes_per_pixel, 1, fp);

    // Convert image to ASCII art
    printf("P6\n%d %d\n%d\n", width, height, 255);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * bytes_per_pixel;
            pixel.r = buffer[index] >> 16;
            pixel.g = buffer[index + 1] >> 16;
            pixel.b = buffer[index + 2] >> 16;
            if (pixel.r < 128) {
                printf(" ");
            } else if (pixel.r < 255) {
                printf(".");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }

    // Free memory
    free(buffer);
    fclose(fp);

    return 0;
}