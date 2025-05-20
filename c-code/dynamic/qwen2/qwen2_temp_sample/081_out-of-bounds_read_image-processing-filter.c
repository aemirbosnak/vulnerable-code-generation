#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void applyFilter(int* image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Out-of-bounds read
            int pixel = image[(y + 1) * width + (x - 1)];
            // Process the pixel (example: invert color)
            image[y * width + x] = ~pixel;
        }
    }
}

int main() {
    int width = 3;
    int height = 3;
    int image[9] = {255, 0, 0, 0, 255, 0, 0, 0, 255};

    printf("Original Image:\n");
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) printf("\n");
        printf("%d ", image[i]);
    }

    applyFilter(image, width, height);

    printf("\nFiltered Image:\n");
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) printf("\n");
        printf("%d ", image[i]);
    }

    return 0;
}
