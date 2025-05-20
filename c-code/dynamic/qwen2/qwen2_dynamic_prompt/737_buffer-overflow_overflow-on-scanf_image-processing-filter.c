#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void apply_filter(int *image, int width, int height) {
    int kernel[3][3] = {{1, 1, 1}, {1, -8, 1}, {1, 1, 1}};
    int new_image[height][width];

    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int sum = 0;
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    sum += image[(y + ky) * width + (x + kx)] * kernel[ky + 1][kx + 1];
                }
            }
            new_image[y][x] = sum;
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            image[y * width + x] = new_image[y][x];
        }
    }
}

int main() {
    int width, height;
    printf("Enter image dimensions (width height): ");
    scanf("%d %d", &width, &height);

    int *image = (int *)malloc(width * height * sizeof(int));
    if (!image) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter image data:\n");
    for (int i = 0; i < width * height; i++) {
        scanf("%d", &image[i]);
    }

    apply_filter(image, width, height);

    printf("Filtered image data:\n");
    for (int i = 0; i < width * height; i++) {
        printf("%d ", image[i]);
        if ((i + 1) % width == 0) {
            printf("\n");
        }
    }

    free(image);
    return 0;
}
