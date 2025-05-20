//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define NUM_WATERMARKS 10

typedef struct {
    int x, y;
} Point;

void watermark_image(unsigned char *image, Point *watermarks) {
    int i;
    for (i = 0; i < NUM_WATERMARKS; i++) {
        int x = watermarks[i].x;
        int y = watermarks[i].y;
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        int alpha = rand() % 256;
        int offset = (y * WIDTH + x) * 3;
        image[offset] += r;
        image[offset + 1] += g;
        image[offset + 2] += b;
        image[offset + 3] += alpha;
    }
}

int main() {
    unsigned char *image = malloc(WIDTH * HEIGHT * 4);
    if (image == NULL) {
        printf("Error: could not allocate memory\n");
        return 1;
    }
    Point watermarks[NUM_WATERMARKS] = {
        {0, 0},
        {WIDTH - 1, 0},
        {0, HEIGHT - 1},
        {WIDTH - 1, HEIGHT - 1},
        {rand() % WIDTH, rand() % HEIGHT},
        {rand() % WIDTH, rand() % HEIGHT},
        {rand() % WIDTH, rand() % HEIGHT},
        {rand() % WIDTH, rand() % HEIGHT},
        {rand() % WIDTH, rand() % HEIGHT},
        {rand() % WIDTH, rand() % HEIGHT}
    };
    watermark_image(image, watermarks);
    printf("Watermarking complete!\n");
    return 0;
}