//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_VALUE 255
#define THRESHOLD 128

int main() {
    int i, j;
    int x, y;
    int pixel_value;
    int watermark_value;
    unsigned char *image, *watermark;
    unsigned char pixel;

    image = (unsigned char *)malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    watermark = (unsigned char *)malloc(WIDTH * HEIGHT * sizeof(unsigned char));

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            pixel_value = rand() % MAX_VALUE;
            pixel = (unsigned char)pixel_value;
            image[i * HEIGHT + j] = pixel;
        }
    }

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            pixel_value = rand() % MAX_VALUE;
            pixel = (unsigned char)pixel_value;
            watermark[i * HEIGHT + j] = pixel;
        }
    }

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            x = i * WIDTH + j;
            y = (i * WIDTH + j) % WIDTH;
            pixel_value = image[x];
            watermark_value = watermark[y];

            if (pixel_value > THRESHOLD && watermark_value > THRESHOLD) {
                image[x] = pixel_value + watermark_value;
            } else if (pixel_value > THRESHOLD) {
                image[x] = pixel_value - watermark_value;
            } else if (watermark_value > THRESHOLD) {
                image[x] = pixel_value + watermark_value;
            }
        }
    }

    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            pixel_value = image[i * HEIGHT + j];
            pixel = (unsigned char)pixel_value;
            printf("%c", pixel);
        }
        printf("\n");
    }

    free(image);
    free(watermark);

    return 0;
}