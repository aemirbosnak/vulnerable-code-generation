//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define IMAGE_SIZE WIDTH * HEIGHT

#define MAX_VALUE 255
#define THRESHOLD 127

typedef struct {
    int x, y;
} Point;

typedef struct {
    int *data;
    int width;
    int height;
} Image;

void create_image(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->data[i * image->width + j] = rand() % MAX_VALUE;
        }
    }
}

void print_image(const Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            printf("%d ", image->data[i * image->width + j]);
        }
        printf("\n");
    }
}

void add_watermark(Image *image, const char *watermark) {
    int i, j, k;
    int watermark_width = strlen(watermark) * 8;
    int watermark_height = 8;

    if (watermark_width > image->width || watermark_height > image->height) {
        printf("Watermark is too large.\n");
        return;
    }

    for (i = 0; i < watermark_height; i++) {
        for (j = 0; j < watermark_width; j++) {
            int x = (i * image->width + j) / watermark_width;
            int y = (i * image->width + j) % watermark_width;

            if (watermark[k] == '1') {
                image->data[i * image->width + j] = MAX_VALUE;
            }

            k++;
        }
    }
}

void detect_watermark(const Image *image, const char *watermark) {
    int i, j, k;
    int watermark_width = strlen(watermark) * 8;
    int watermark_height = 8;

    if (watermark_width > image->width || watermark_height > image->height) {
        printf("Watermark is too large.\n");
        return;
    }

    int count = 0;
    for (i = 0; i < watermark_height; i++) {
        for (j = 0; j < watermark_width; j++) {
            int x = (i * image->width + j) / watermark_width;
            int y = (i * image->width + j) % watermark_width;

            if (image->data[i * image->width + j] > THRESHOLD) {
                count++;
            }
        }
    }

    if (count > 0) {
        printf("Watermark detected.\n");
    } else {
        printf("Watermark not detected.\n");
    }
}

int main() {
    Image image;
    create_image(&image);

    char watermark[] = "Hello, world!";
    add_watermark(&image, watermark);

    print_image(&image);

    detect_watermark(&image, watermark);

    return 0;
}