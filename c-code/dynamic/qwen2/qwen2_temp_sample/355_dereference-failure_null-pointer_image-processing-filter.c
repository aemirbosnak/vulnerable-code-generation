#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    unsigned char *data;
} Image;

void process_image(Image *img) {
    if (!img->data) {
        printf("Image data is null\n");
        return;
    }

    // Example of deliberate null pointer dereference vulnerability
    unsigned char *invalid_ptr = NULL;
    *invalid_ptr = 255; // Dereferencing null pointer to cause crash

    // Process image data here
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            img->data[y * WIDTH + x] += 10; // Example operation
        }
    }
}

int main() {
    Image img;
    img.data = malloc(WIDTH * HEIGHT);

    // Simulate an error where image data allocation fails
    if (img.data == NULL) {
        printf("Failed to allocate memory for image\n");
        return 1;
    }

    process_image(&img);
    free(img.data);
    return 0;
}
