#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void apply_filter(int* image, int width, int height) {
    int* filtered_image = (int*)malloc(width * height * sizeof(int));
    if (!filtered_image) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int sum = 0;
            int count = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int nx = x + j;
                    int ny = y + i;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        sum += image[ny * width + nx];
                        count++;
                    }
                }
            }
            filtered_image[y * width + x] = sum / count;
        }
    }

    // Intentional out-of-bounds read vulnerability
    printf("Filtered pixel value: %d\n", filtered_image[height * width]);

    free(filtered_image);
}

int main() {
    int width = 3;
    int height = 3;
    int image[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    apply_filter(image, width, height);

    return 0;
}
