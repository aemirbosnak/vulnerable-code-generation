#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void applyFilter(int* img, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Out-of-bounds read example
            int pixel = img[(y + 1) * width + (x - 1)];
            printf("%d ", pixel);
        }
        printf("\n");
    }
}

int main() {
    int img[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int width = 3;
    int height = 3;

    applyFilter(img, width, height);

    return 0;
}
