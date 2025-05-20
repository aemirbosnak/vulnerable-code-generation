//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255
#define BIT_DEPTH 8

typedef struct {
    int width;
    int height;
    int max_value;
    int bit_depth;
    unsigned char *data;
} image_t;

void create_image(image_t *image) {
    image->width = WIDTH;
    image->height = HEIGHT;
    image->max_value = MAX_VALUE;
    image->bit_depth = BIT_DEPTH;

    image->data = (unsigned char *)malloc(sizeof(unsigned char) * image->width * image->height);

    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            int value = rand() % image->max_value;
            memcpy(image->data + i * image->width * image->bit_depth + j * image->bit_depth, &value, image->bit_depth);
        }
    }
}

void destroy_image(image_t *image) {
    free(image->data);
}

void embed_watermark(image_t *image, char *watermark, int x, int y) {
    int watermark_size = strlen(watermark);
    int i, j;

    for (i = 0; i < watermark_size; i++) {
        int value = watermark[i] - '0';
        int index = (y + i) * image->width + x;

        for (j = 0; j < BIT_DEPTH; j++) {
            int bit_value = (value >> j) & 1;
            int bit_position = (index * BIT_DEPTH + j) / 8;

            if (bit_value == 1) {
                image->data[index] |= (1 << (7 - bit_position));
            } else {
                image->data[index] &= ~(1 << (7 - bit_position));
            }
        }
    }
}

int main() {
    image_t image;
    create_image(&image);

    char *watermark = "1234567890";
    int x = 100, y = 100;
    embed_watermark(&image, watermark, x, y);

    destroy_image(&image);

    return 0;
}