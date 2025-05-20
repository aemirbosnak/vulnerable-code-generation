//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define BLOCK_SIZE 8
#define MAX_VALUE 255
#define THRESHOLD 0.1

typedef struct {
    int x, y;
    int value;
} Pixel;

void read_image(char *filename, Pixel *image) {
    FILE *fp = fopen(filename, "rb");
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    image = malloc(sizeof(Pixel) * size);

    fread(image, sizeof(Pixel), size, fp);
    fclose(fp);
}

void write_image(char *filename, Pixel *image) {
    FILE *fp = fopen(filename, "wb");
    fwrite(image, sizeof(Pixel), WIDTH * HEIGHT, fp);
    fclose(fp);
}

void add_watermark(Pixel *image, int watermark) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int x = i % WIDTH;
        int y = i / WIDTH;

        if (image[i].value < THRESHOLD) {
            image[i].value += watermark;
        }
    }
}

void detect_watermark(Pixel *image, int watermark) {
    int sum = 0;
    int count = 0;

    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        int x = i % WIDTH;
        int y = i / WIDTH;

        if (image[i].value >= THRESHOLD && image[i].value <= MAX_VALUE - watermark) {
            sum += image[i].value;
            count++;
        }
    }

    if (count > 0) {
        double avg = (double) sum / count;

        if (avg > watermark) {
            printf("Watermark detected!\n");
        } else {
            printf("Watermark not detected.\n");
        }
    } else {
        printf("No watermark found.\n");
    }
}

int main() {
    Pixel image[WIDTH * HEIGHT];

    read_image("image.bmp", image);

    int watermark = 50;
    add_watermark(image, watermark);

    write_image("watermarked_image.bmp", image);

    detect_watermark(image, watermark);

    return 0;
}