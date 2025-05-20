#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 768

void applyFilter(int* input, int* output) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;
            int r = input[index] & 0xFF;
            int g = (input[index] >> 8) & 0xFF;
            int b = (input[index] >> 16) & 0xFF;

            // Integer overflow vulnerability
            int new_r = r + 256;
            int new_g = g - 256;
            int new_b = b * 2;

            output[index] = (new_r << 16) | (new_g << 8) | new_b;
        }
    }
}

int main() {
    int* input = (int*)malloc(WIDTH * HEIGHT * sizeof(int));
    int* output = (int*)malloc(WIDTH * HEIGHT * sizeof(int));

    if (!input || !output) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize input with some values
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        input[i] = rand();
    }

    applyFilter(input, output);

    free(input);
    free(output);

    return 0;
}
