//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 720
#define HEIGHT 480

int main() {
    // Read the image data
    unsigned char* image_data = malloc(WIDTH * HEIGHT);
    FILE* image_file = fopen("image.bmp", "rb");
    fread(image_data, 1, WIDTH * HEIGHT, image_file);
    fclose(image_file);

    // Convert the image data to ASCII art
    char* ascii_art = malloc(WIDTH * HEIGHT * 3);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        // Calculate the average color of the pixel
        unsigned char r = image_data[i * 3 + 2];
        unsigned char g = image_data[i * 3 + 1];
        unsigned char b = image_data[i * 3];
        int avg = (r + g + b) / 3;

        // Convert the average color to an ASCII character
        char c;
        if (avg < 32) {
            c = '#';
        } else if (avg < 64) {
            c = '&';
        } else if (avg < 96) {
            c = '@';
        } else if (avg < 128) {
            c = '%';
        } else if (avg < 160) {
            c = '*';
        } else if (avg < 192) {
            c = '+';
        } else if (avg < 224) {
            c = '-';
        } else {
            c = ' ';
        }

        // Add the ASCII character to the string
        ascii_art[i * 3] = c;
        ascii_art[i * 3 + 1] = c;
        ascii_art[i * 3 + 2] = c;
    }

    // Print the ASCII art to the console
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        printf("%c", ascii_art[i]);
        if (i % WIDTH == WIDTH - 1) {
            printf("\n");
        }
    }

    // Free the memory
    free(image_data);
    free(ascii_art);

    return 0;
}