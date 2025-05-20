#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char pixel;

#define WIDTH 500
#define HEIGHT 500

pixel *image;

void applyFilter() {
    pixel *dest = image;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            dest[x] = dest[x] * 2;
            dest += WIDTH; // move to next row after processing current row
        }
    }
}

int main() {
    image = (pixel *)malloc(WIDTH * HEIGHT);

    // Load image data (not shown for brevity)

    applyFilter();

    // Save filtered image data (not shown for brevity)

    free(image); // forget to free memory allocated for image data

    return 0;
}
