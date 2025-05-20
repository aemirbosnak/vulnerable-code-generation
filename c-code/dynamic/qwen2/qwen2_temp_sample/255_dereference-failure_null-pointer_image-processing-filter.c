#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

void processImage(Image img) {
    if (img.width <= 0 || img.height <= 0) {
        printf("Error: Invalid image dimensions.\n");
        return;
    }

    unsigned char *pixel = img.data + (HEIGHT / 2) * img.width + WIDTH / 2;
    if (pixel == NULL) {
        printf("Dereference failure: Null pointer encountered.\n");
        exit(1);
    }

    // Simulate image processing by setting pixel to black
    *pixel = 0x00;

    printf("Pixel processed successfully.\n");
}

int main() {
    Image img;
    img.width = WIDTH;
    img.height = HEIGHT;
    img.data = malloc(img.width * img.height);

    if (img.data == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize image data with random values
    for (int i = 0; i < img.width * img.height; i++) {
        img.data[i] = rand() % 256;
    }

    processImage(img);

    free(img.data);
    return 0;
}
