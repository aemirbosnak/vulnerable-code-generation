#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void applyFilter(unsigned char* image, int width, int height) {
    unsigned char* temp = (unsigned char*)malloc(width * height);
    if (!temp) {
        printf("Memory allocation failed\n");
        return;
    }

    // Simulate an invalid pointer usage
    unsigned char* invalidPtr = NULL;
    *invalidPtr = 255; // Dereferencing invalid pointer

    free(temp);
}

int main() {
    unsigned char image[WIDTH * HEIGHT];
    applyFilter(image, WIDTH, HEIGHT);
    return 0;
}
