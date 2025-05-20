#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

void apply_filter(int *image, int size) {
    for (int i = 0; i < size; i++) {
        image[i] *= 2;
    }
}

int main() {
    int image[MAX_IMAGE_SIZE];
    int size;

    printf("Enter the size of the image: ");
    scanf("%d", &size);

    if (size > MAX_IMAGE_SIZE) {
        printf("Image size too large!\n");
        return 1;
    }

    printf("Enter the pixel values:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &image[i]);
    }

    apply_filter(image, size);

    printf("Filtered image:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", image[i]);
    }
    printf("\n");

    return 0;
}
