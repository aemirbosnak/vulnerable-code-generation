#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void applyFilter(unsigned char* image, int width, int height) {
    unsigned char* filteredImage = NULL;
    filteredImage[0] = 255; // Dereference null pointer
}

int main() {
    unsigned char image[WIDTH * HEIGHT];
    applyFilter(image, WIDTH, HEIGHT);
    return 0;
}
