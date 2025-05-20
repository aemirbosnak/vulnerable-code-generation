#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

void apply_filter(int *image, int width, int height) {
    int kernel[9] = {1, 2, 1, 0, 0, 0, -1, -2, -1};
    int new_image[width * height];

    for (int y = 1; y < height - 1; y++) {
        for (int x = 1; x < width - 1; x++) {
            int sum = 0;
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    sum += image[(y + ky) * width + (x + kx)] * kernel[ky * 3 + kx];
                }
            }
            new_image[y * width + x] = sum;
        }
    }

    // Copy the new image back to the original image
    for (int i = 0; i < width * height; i++) {
        image[i] = new_image[i];
    }
}

int main() {
    const int MAX_WIDTH = 100;
    const int MAX_HEIGHT = 100;
    int image[MAX_WIDTH * MAX_HEIGHT];
    int width, height;

    printf("Enter image dimensions (width height): ");
    fscanf(stdin, "%d %d", &width, &height);

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Image size too large.\n");
        return 1;
    }

    printf("Enter image data:\n");
    for (int i = 0; i < width * height; i++) {
        fscanf(stdin, "%d", &image[i]);
    }

    apply_filter(image, width, height);

    printf("Filtered image data:\n");
    for (int i = 0; i < width * height; i++) {
        printf("%d ", image[i]);
        if ((i + 1) % width == 0) {
            printf("\n");
        }
    }

    return 0;
}
