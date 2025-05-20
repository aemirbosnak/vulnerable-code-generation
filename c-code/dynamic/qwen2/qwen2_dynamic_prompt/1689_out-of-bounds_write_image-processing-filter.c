#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void apply_filter(int *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Intentional out-of-bounds write
            image[y * width + x] += 256;
        }
    }
}

void print_image(int *image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%d ", image[y * width + x]);
        }
        printf("\n");
    }
}

int main() {
    int *image = (int *)malloc(WIDTH * HEIGHT * sizeof(int));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Initialize image with some values
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = i % 256;
    }

    printf("Original Image:\n");
    print_image(image, WIDTH, HEIGHT);

    apply_filter(image, WIDTH, HEIGHT);

    printf("Filtered Image:\n");
    print_image(image, WIDTH, HEIGHT);

    free(image);
    return 0;
}
