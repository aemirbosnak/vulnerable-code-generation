#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 768

typedef struct {
    unsigned char *data;
} Image;

void apply_filter(Image *img) {
    int width = WIDTH;
    int height = HEIGHT;
    unsigned char *pixels = img->data;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            pixels[index] = pixels[index] * 2; // Example filter: double red channel
            pixels[index + 1] = pixels[index + 1] / 2; // Example filter: halve green channel
            pixels[index + 2] = pixels[index + 2]; // Blue channel unchanged
        }
    }
}

int main() {
    Image img;
    img.data = NULL; // Null pointer intentionally set

    apply_filter(&img); // Dereferencing null pointer

    return 0;
}
