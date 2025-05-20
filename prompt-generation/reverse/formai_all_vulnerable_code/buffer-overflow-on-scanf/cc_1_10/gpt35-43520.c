//FormAI DATASET v1.0 Category: Image compression ; Style: bold
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BLOCK_SIZE 8
#define MAX_IMAGE_SIZE 1024

uint8_t image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];

void print_image(uint8_t (*img)[MAX_IMAGE_SIZE], int height, int width) {
    printf("Compressed Image:\n");
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            printf("%d ", img[r][c]);
        }
        printf("\n");
    }
}

void compress_image(int height, int width) {
    uint8_t compressed[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
    for (int r = 0; r < height; r += BLOCK_SIZE) {
        for (int c = 0; c < width; c += BLOCK_SIZE) {
            uint8_t sum = 0;
            for (int i = r; i < r + BLOCK_SIZE; i++) {
                for (int j = c; j < c + BLOCK_SIZE; j++) {
                    sum += image[i][j];
                }
            }
            compressed[r / BLOCK_SIZE][c / BLOCK_SIZE] = sum / (BLOCK_SIZE * BLOCK_SIZE);
        }
    }
    print_image(compressed, height / BLOCK_SIZE, width / BLOCK_SIZE);
}

int main() {
    int height, width;
    printf("Enter the height and width of the image: ");
    scanf("%d %d", &height, &width);

    printf("Enter the pixel values of the image:\n");
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            scanf("%hhu", &image[r][c]);
        }
    }

    compress_image(height, width);

    return 0;
}