#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void apply_filter(int *image, int width, int height) {
    int kernel[9] = {1, 2, 1, 0, 0, 0, -1, -2, -1};
    int temp_image[width * height];

    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int sum = 0;
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    sum += image[(y + ky) * width + (x + kx)] * kernel[ky * 3 + kx];
                }
            }
            temp_image[y * width + x] = sum;
        }
    }

    for (int i = 0; i < width * height; i++) {
        image[i] = temp_image[i];
    }
}

int main() {
    int width, height;
    printf("Enter image dimensions (width height): ");
    scanf("%d %d", &width, &height);

    int *image = (int *)malloc(width * height * sizeof(int));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
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
