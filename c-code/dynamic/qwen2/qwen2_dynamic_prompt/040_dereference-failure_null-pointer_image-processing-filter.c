#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
    int data[HEIGHT][WIDTH];
} Image;

void apply_filter(Image *img, int (*filter)(int)) {
    if (img == NULL) {
        printf("Error: Image is null\n");
        return;
    }

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            img->data[y][x] = filter(img->data[y][x]);
        }
    }
}

int grayscale(int pixel) {
    return pixel;
}

int main() {
    Image img;
    Image *img_ptr = &img;

    // Simulate an error by setting img_ptr to NULL
    img_ptr = NULL;

    apply_filter(img_ptr, grayscale);

    return 0;
}
