//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <zlib.h>
#include <sys/mman.h>
#include <assert.h>

#define WATERMARK_SCALE 0.5
#define MAX_WATERMARK_SIZE 1024 * 1024

typedef struct {
    uint8_t* data;
    uint32_t size;
} image_t;

typedef struct {
    uint8_t* data;
    uint32_t size;
} watermark_t;

image_t load_image(const char* filename) {
    image_t img;
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening image file\n");
        exit(1);
    }

    img.data = (uint8_t*) malloc(sizeof(uint8_t) * 1024 * 1024);
    img.size = 1024 * 1024;

    fread(img.data, sizeof(uint8_t), img.size, fp);
    fclose(fp);

    return img;
}

void save_image(const char* filename, image_t img) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error opening image file\n");
        exit(1);
    }

    fwrite(img.data, sizeof(uint8_t), img.size, fp);
    fclose(fp);
}

watermark_t create_watermark(const char* filename) {
    watermark_t wm;
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error opening watermark file\n");
        exit(1);
    }

    wm.data = (uint8_t*) malloc(sizeof(uint8_t) * MAX_WATERMARK_SIZE);
    wm.size = MAX_WATERMARK_SIZE;

    fread(wm.data, sizeof(uint8_t), wm.size, fp);
    fclose(fp);

    return wm;
}

void embed_watermark(image_t cover, watermark_t wm) {
    int width = cover.size / 2;
    int height = cover.size / 2;
    int stride = cover.size;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int c = (int) (cover.data[stride * (y + height / 2) + x + width / 2] * WATERMARK_SCALE + (int) wm.data[stride * y + x] * (1 - WATERMARK_SCALE));
            if (c > 255)
                c = 255;
            else if (c < 0)
                c = 0;
            cover.data[stride * (y + height / 2) + x + width / 2] = (uint8_t) c;
        }
    }
}

void save_watermarked_image(const char* filename, image_t cover, watermark_t wm) {
    save_image(filename, cover);
}

int main() {
    image_t cover = load_image("cover.jpg");
    watermark_t wm = create_watermark("watermark.png");
    embed_watermark(cover, wm);
    save_watermarked_image("watermarked_cover.jpg", cover, wm);
    return 0;
}