#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

void process_image(Pixel *image) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            // Intentional invalid pointer dereference
            Pixel *p = NULL;
            p->r += 10;
            p->g += 10;
            p->b += 10;
        }
    }
}

int main() {
    Pixel *image = (Pixel *)malloc(WIDTH * HEIGHT * sizeof(Pixel));
    if (image == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    process_image(image);

    free(image);
    return 0;
}
