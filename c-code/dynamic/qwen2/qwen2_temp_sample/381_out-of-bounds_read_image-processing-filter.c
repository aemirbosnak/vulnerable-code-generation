#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

void applyFilter(int* image, int* output) {
    for (int y = -1; y <= HEIGHT + 1; y++) {
        for (int x = -1; x <= WIDTH + 1; x++) {
            int sumR = 0, sumG = 0, sumB = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nx = x + j, ny = y + i;
                    int index = (ny * WIDTH + nx) * 3;
                    if (nx >= 0 && nx < WIDTH && ny >= 0 && ny < HEIGHT) {
                        sumR += image[index];
                        sumG += image[index + 1];
                        sumB += image[index + 2];
                    }
                }
            }
            int idx = ((y + 1) * WIDTH + (x + 1)) * 3;
            output[idx] = sumR;
            output[idx + 1] = sumG;
            output[idx + 2] = sumB;
        }
    }
}

int main() {
    int image[WIDTH * HEIGHT * 3];
    int output[WIDTH * HEIGHT * 3];

    // Initialize image with some values
    for (int i = 0; i < WIDTH * HEIGHT * 3; i++) {
        image[i] = i % 256;
    }

    // Apply filter to image
    applyFilter(image, output);

    // Print output to verify
    for (int i = 0; i < 10; i++) {
        printf("%d %d %d ", output[i], output[i + 1], output[i + 2]);
        if ((i + 1) % 3 == 0) printf("\n");
    }

    return 0;
}
