#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

void apply_filter(unsigned char *image, int width, int height) {
    unsigned char *filtered_image = (unsigned char *)malloc(width * height);
    if (!filtered_image) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            filtered_image[y * width + x] = image[y * width + x];
        }
    }

    free(filtered_image);
}

int main() {
    unsigned char image[MAX_IMAGE_SIZE];
    int width, height;

    printf("Enter image dimensions (width height): ");
    scanf("%d %d", &width, &height);

    if (width * height > MAX_IMAGE_SIZE) {
        printf("Image size exceeds maximum allowed\n");
        return 1;
    }

    printf("Enter image data:\n");
    for (int i = 0; i < width * height; i++) {
        scanf("%hhu", &image[i]);
    }

    apply_filter(image, width, height);

    printf("Filtered image data:\n");
    for (int i = 0; i < width * height; i++) {
        printf("%hhu ", image[i]);
    }
    printf("\n");

    return 0;
}
