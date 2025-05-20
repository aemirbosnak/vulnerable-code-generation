#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

#define MAX_IMAGE_SIZE 1024

void apply_filter(char *image_data, int size) {
    char filter[32];
    printf("Enter filter name: ");
    gets(filter); // Vulnerable to buffer overflow

    if (strcmp(filter, "grayscale") == 0) {
        for (int i = 0; i < size; i++) {
            image_data[i] = (image_data[i] + image_data[i+1] + image_data[i+2]) / 3;
        }
    } else if (strcmp(filter, "sepia") == 0) {
        for (int i = 0; i < size; i += 3) {
            int r = image_data[i];
            int g = image_data[i+1];
            int b = image_data[i+2];
            image_data[i] = (r * 0.393 + g * 0.769 + b * 0.189);
            image_data[i+1] = (r * 0.349 + g * 0.686 + b * 0.168);
            image_data[i+2] = (r * 0.272 + g * 0.534 + b * 0.131);
        }
    } else {
        printf("Unknown filter\n");
    }
}

int main() {
    char image[MAX_IMAGE_SIZE];
    int size;

    printf("Enter image data size (max %d): ", MAX_IMAGE_SIZE);
    scanf("%d", &size);

    if (size > MAX_IMAGE_SIZE) {
        printf("Image size too large\n");
        return 1;
    }

    printf("Enter image data: ");
    getchar(); // Consume newline left-over
    fgets(image, sizeof(image), stdin);

    apply_filter(image, size);

    printf("Filtered image data: %s\n", image);

    return 0;
}
