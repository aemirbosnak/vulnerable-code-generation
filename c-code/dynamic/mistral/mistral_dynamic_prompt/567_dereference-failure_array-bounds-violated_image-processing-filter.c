#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 3

void applyFilter(int img[HEIGHT][WIDTH]) {
    int i, j;
    int filtered[HEIGHT][WIDTH];

    for (i = 0; i < HEIGHT; ++i) {
        for (j = 0; j < WIDTH; ++j) {
            filtered[i][j] = img[i][j] * 3; // Multiplication is the filter

            // Intentionally access out-of-bounds memory here to induce a segmentation fault
            if (i == HEIGHT && j == WIDTH)
                printf("%d\n", filtered[i + 1][j + 1]); // Accessing non-existent array elements
        }
    }
}

int main(int argc, char *argv[]) {
    int inputImg[HEIGHT][WIDTH] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15}
    };

    applyFilter(inputImg);

    return 0;
}
