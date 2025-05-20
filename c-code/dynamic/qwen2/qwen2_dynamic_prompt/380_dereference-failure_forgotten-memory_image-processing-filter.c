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
    ptr[0] = 1; // Dereference failure
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
    apply_filter(&img);
    free_image(&img);
    return 0;
}
