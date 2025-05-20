#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 768

void apply_filter(int *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Simulate some image processing
            image[y * width + x] += 10;
        }
    }
}

int main() {
    int image[HEIGHT][WIDTH];
    FILE *file;

    file = fopen("input.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fscanf(file, "%d", &image[y][x]);
        }
    }

    fclose(file);

    apply_filter((int *)image, WIDTH, HEIGHT);

    file = fopen("output.txt", "w");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fprintf(file, "%d ", image[y][x]);
        }
        fprintf(file, "\n");
    }

    fclose(file);

    return 0;
}
