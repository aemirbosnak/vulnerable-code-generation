//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512

struct Pixel {
    int x, y;
    int intensity;
};

void add_noise(struct Pixel *pixels, int num_pixels) {
    for (int i = 0; i < num_pixels; i++) {
        pixels[i].intensity += rand() % 10;
    }
}

void add_watermark(struct Pixel *pixels, int num_pixels, char *watermark) {
    int watermark_width = strlen(watermark) / 2;
    int watermark_height = 1;
    int watermark_offset_x = (WIDTH - watermark_width) / 2;
    int watermark_offset_y = (HEIGHT - watermark_height) / 2;

    for (int i = 0; i < watermark_width; i++) {
        for (int j = 0; j < watermark_height; j++) {
            if (watermark[i * 2] == '1') {
                pixels[(i + watermark_offset_x) * WIDTH + (j + watermark_offset_y)]
                   .intensity += 10;
            }
        }
    }
}

void save_image(struct Pixel *pixels, int num_pixels, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fwrite(&num_pixels, sizeof(int), 1, fp);
    for (int i = 0; i < num_pixels; i++) {
        fwrite(&pixels[i].x, sizeof(int), 1, fp);
        fwrite(&pixels[i].y, sizeof(int), 1, fp);
        fwrite(&pixels[i].intensity, sizeof(int), 1, fp);
    }

    fclose(fp);
}

int main() {
    struct Pixel *pixels = malloc(sizeof(struct Pixel) * WIDTH * HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        pixels[i].x = i % WIDTH;
        pixels[i].y = i / WIDTH;
        pixels[i].intensity = rand() % 256;
    }

    char *watermark = "Digital Watermarking Example";
    add_watermark(pixels, WIDTH * HEIGHT, watermark);
    add_noise(pixels, WIDTH * HEIGHT);

    save_image(pixels, WIDTH * HEIGHT, "watermarked.bin");

    free(pixels);

    return 0;
}