#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256

typedef struct {
    unsigned char *data;
} Image;

void apply_filter(Image *img) {
    int *ptr = NULL;
    ptr = img->data; // Dereference failure: using uninitialized pointer
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            *(ptr + y * WIDTH + x) = 255 - *(ptr + y * WIDTH + x); // Invert pixel value
        }
    }
}

Image create_image() {
    Image img;
    img.data = (unsigned char *)malloc(WIDTH * HEIGHT);
    if (!img.data) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return img;
}

void free_image(Image *img) {
    free(img->data);
}

int main() {
    Image img = create_image();
    // Simulate loading an image with some values
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        img.data[i] = i % 256;
    }

    apply_filter(&img);

    // Print first 10 pixels to verify
    for (int i = 0; i < 10; i++) {
        printf("%d ", img.data[i]);
    }
    printf("\n");

    free_image(&img);
    return 0;
}
