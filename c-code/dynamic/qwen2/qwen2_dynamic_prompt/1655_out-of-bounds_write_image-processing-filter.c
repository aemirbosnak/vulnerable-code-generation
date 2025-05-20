#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256

void apply_filter(unsigned char *image) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;
            // Intentional out-of-bounds write
            image[index + WIDTH] += 100;
        }
    }
}

int main() {
    unsigned char *image = (unsigned char *)malloc(WIDTH * HEIGHT);
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    apply_filter(image);

    free(image);
    return 0;
}
