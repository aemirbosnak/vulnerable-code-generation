//FormAI DATASET v1.0 Category: Image compression ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// A simple 2D array of pixel values
int pixels[10][10] = {
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 0, 0, 0, 0, 255, 255, 255},
    {255, 255, 0, 0, 0, 0, 0, 0, 255, 255},
    {255, 0, 0, 0, 0, 0, 0, 0, 0, 255},
    {255, 0, 0, 0, 0, 0, 0, 0, 0, 255},
    {255, 0, 0, 0, 0, 0, 0, 0, 0, 255},
    {255, 255, 0, 0, 0, 0, 0, 0, 255, 255},
    {255, 255, 255, 0, 0, 0, 0, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255},
    {255, 255, 255, 255, 255, 255, 255, 255, 255, 255}
};

// A function to compress an image
void compress_image(int pixels[][10], int size) {
    int i, j, count = 1;
    int current_pixel = pixels[0][0];
    printf("Compressed image:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            if (current_pixel == pixels[i][j]) {
                count++;
            } else {
                printf("%d%c", current_pixel, count == 1 ? ',' : ':');
                current_pixel = pixels[i][j];
                count = 1;
            }
        }
    }
    printf("%d%c", current_pixel, count == 1 ? ',' : ':');
}

// A function to decompress a compressed image
void decompress_image(char *compressed_image) {
    int i, j, k, count = 0, pixel_count = 0, size = 10;
    int decompressed_pixels[10][10];
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            char current_char = compressed_image[pixel_count++];
            if (current_char >= '0' && current_char <= '9') {
                count = count * 10 + (current_char - '0');
            } else if (current_char == ',' || current_char == ':') {
                if (count == 0) {
                    decompressed_pixels[i][j] = current_char - '0';
                } else {
                    for (k = 0; k < count; k++) {
                        decompressed_pixels[i][j + k] = current_char - '0';
                    }
                }
                count = 0;
            }
        }
    }
    printf("Decompressed image:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", decompressed_pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int i, j;
    int size = 10;
    printf("Original image:\n");
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }
    char compressed_image[100];
    compress_image(pixels, size);
    printf("\n");
    decompress_image("255,7:0,4:255,3:0,2:255,2:0,3:255,2:0,4:255,2:0,2:255,3:255,1:0,3:255,1:0,4:255,7\n");
    return 0;
}