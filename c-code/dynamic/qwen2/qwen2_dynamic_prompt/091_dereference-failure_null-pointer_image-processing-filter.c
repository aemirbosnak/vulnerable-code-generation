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
} Image;

void apply_filter(Image *img) {
    int *ptr = NULL;
    ptr[0] = 255; // Dereference null pointer
}

Image create_image() {
    Image img;
    img.data = malloc(WIDTH * HEIGHT * sizeof(unsigned char));
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
    apply_filter(&img);
    free_image(&img);
    return 0;
}
