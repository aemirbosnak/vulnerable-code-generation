#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

void apply_filter(int *image, int size) {
    int kernel[3][3] = {{-1, -1, -1}, {-1, 9, -1}, {-1, -1, -1}};
    int result[MAX_IMAGE_SIZE];

    for (int i = 1; i < size - 1; i++) {
        for (int j = 1; j < size - 1; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    sum += image[(i + k) * size + (j + l)] * kernel[k + 1][l + 1];
                }
            }
            result[i * size + j] = sum;
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", result[i * size + j]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter image size: ");
    scanf("%d", &size);

    if (size > MAX_IMAGE_SIZE) {
        printf("Image size too large\n");
        return 1;
    }

    int *image = malloc(size * size * sizeof(int));
    if (!image) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter image pixels (row by row): \n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &image[i * size + j]);
        }
    }

    apply_filter(image, size);

    free(image);
    return 0;
}
