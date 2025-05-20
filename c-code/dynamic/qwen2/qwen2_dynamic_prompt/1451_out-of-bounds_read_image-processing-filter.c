#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void process_image(int *image) {
    int new_image[WIDTH][HEIGHT];
    for (int y = 0; y <= HEIGHT; y++) { // Out-of-bounds read
        for (int x = 0; x <= WIDTH; x++) { // Out-of-bounds read
            new_image[y][x] = image[y * WIDTH + x] * 2;
        }
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%d ", new_image[y][x]);
        }
        printf("\n");
    }
}

int main() {
    int image[WIDTH * HEIGHT];
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = rand() % 256;
    }
    process_image(image);
    return 0;
}
