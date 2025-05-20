//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WATERMARK_WIDTH 256
#define WATERMARK_HEIGHT 256
#define WATERMARK_SIZE (WATERMARK_WIDTH * WATERMARK_HEIGHT)
#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define IMAGE_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT)
#define NUM_WATERMARKS 10
#define MAX_VALUE 255

typedef struct {
    int x, y;
    int value;
} watermark_t;

watermark_t watermarks[NUM_WATERMARKS];

void generate_watermarks() {
    for (int i = 0; i < NUM_WATERMARKS; i++) {
        watermark_t watermark;
        watermark.x = rand() % WATERMARK_WIDTH;
        watermark.y = rand() % WATERMARK_HEIGHT;
        watermark.value = rand() % MAX_VALUE;
        watermarks[i] = watermark;
    }
}

void apply_watermarks(int *image) {
    for (int i = 0; i < NUM_WATERMARKS; i++) {
        watermark_t watermark = watermarks[i];
        int x = watermark.x % IMAGE_WIDTH;
        int y = watermark.y % IMAGE_HEIGHT;
        int value = watermark.value;
        image[y * IMAGE_WIDTH + x] += value;
    }
}

int main() {
    srand(time(NULL));
    generate_watermarks();

    int *image = (int *) malloc(IMAGE_SIZE * sizeof(int));
    for (int i = 0; i < IMAGE_SIZE; i++) {
        image[i] = rand() % MAX_VALUE;
    }

    apply_watermarks(image);

    FILE *output = fopen("watermarked_image.bin", "wb");
    fwrite(image, sizeof(int), IMAGE_SIZE, output);
    fclose(output);

    return 0;
}