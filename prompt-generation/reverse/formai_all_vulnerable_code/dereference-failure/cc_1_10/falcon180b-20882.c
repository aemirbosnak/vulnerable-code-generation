//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255
#define NUM_WATERMARKS 5
#define WATERMARK_SIZE 32
#define WATERMARK_MAX_VALUE 127
#define WATERMARK_STEP (MAX_VALUE / WATERMARK_MAX_VALUE)
#define WATERMARK_MASK (WATERMARK_MAX_VALUE - 1)

typedef struct {
    int x, y;
    int value;
} Pixel;

void print_image(Pixel *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%3d ", image[i * width + j].value);
        }
        printf("\n");
    }
}

void add_watermark(Pixel *image, int width, int height, int watermark) {
    int x, y;
    for (int i = 0; i < WATERMARK_SIZE; i++) {
        for (int j = 0; j < WATERMARK_SIZE; j++) {
            x = rand() % width;
            y = rand() % height;
            image[y * width + x].value += watermark * (i == 0 || j == 0 || i == WATERMARK_SIZE - 1 || j == WATERMARK_SIZE - 1);
        }
    }
}

int main() {
    Pixel *image = calloc(WIDTH * HEIGHT, sizeof(Pixel));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i].value = rand() % MAX_VALUE;
    }

    for (int i = 0; i < NUM_WATERMARKS; i++) {
        int watermark = rand() % MAX_VALUE;
        add_watermark(image, WIDTH, HEIGHT, watermark);
    }

    print_image(image, WIDTH, HEIGHT);

    free(image);
    return 0;
}