//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define WIDTH 5
#define HEIGHT 5

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} RGB;

RGB image[HEIGHT][WIDTH];
char ascii_art[HEIGHT][WIDTH];

void rgb_to_ascii(RGB rgb) {
    char ascii;

    if (rgb.r > 127)
        ascii = '@';
    else
        ascii = ' ';

    for (int i = 0; i < 3; i++) {
        rgb.r -= (rgb.r >> 7);
        rgb.g -= (rgb.g >> 7);
        rgb.b -= (rgb.b >> 7);
    }

    if (rgb.b > 127)
        ascii += '@';
    else
        ascii += ' ';

    if (rgb.g > 127)
        ascii += '@';
    else
        ascii += ' ';

    ascii_art[rgb.r / 32][rgb.g / 32] = ascii;
}

int main() {
    int i, j;

    // Set up the image
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i][j].r = image[i][j].g = image[i][j].b = 255;

            if (i == 0 || i == 4 || j == 0 || j == 4)
                image[i][j].r = 0;
        }
    }

    // Convert image to ASCII art
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            rgb_to_ascii(image[i][j]);
        }
    }

    // Print ASCII art
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    return 0;
}