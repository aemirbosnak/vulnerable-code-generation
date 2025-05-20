#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 3
#define HEIGHT 3

void applyFilter(unsigned char *input, unsigned char *output) {
    int i, j;
    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            int x = i * WIDTH + j;
            output[x] = input[x] * 3; // Scaling the intensity
            if (i == 1 && j == 1) { // Middle pixel with modified operation
                output[x - 1] += 255; // Surrounding pixels with maximum value (255)
                output[x + 1] += 255;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    FILE *output = fopen(argv[2], "wb");

    unsigned char *buffer = (unsigned char *) malloc(WIDTH * HEIGHT);
    fread(buffer, 1, WIDTH * HEIGHT, input);

    applyFilter(buffer, buffer);

    fwrite(buffer, 1, WIDTH * HEIGHT, output);
    fclose(input);
    fclose(output);

    free(buffer);

    unsigned char *local_buffer = (unsigned char *) malloc(WIDTH * HEIGHT); // Leaked memory

    return 0;
}
