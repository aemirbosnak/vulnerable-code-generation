//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 100000
#define PIXEL_SIZE 4

typedef struct {
    int width;
    int height;
    unsigned char* pixels;
} Image;

void create_image(Image* img, int width, int height) {
    img->width = width;
    img->height = height;
    img->pixels = (unsigned char*)malloc(MAX_PIXELS * PIXEL_SIZE);
    memset(img->pixels, 0, MAX_PIXELS * PIXEL_SIZE);
}

void destroy_image(Image* img) {
    free(img->pixels);
}

void set_pixel(Image* img, int x, int y, unsigned char* color) {
    int offset = (y * img->width + x) * PIXEL_SIZE;
    memcpy(img->pixels + offset, color, PIXEL_SIZE);
}

unsigned char* get_pixel(Image* img, int x, int y) {
    int offset = (y * img->width + x) * PIXEL_SIZE;
    return img->pixels + offset;
}

void save_image(Image* img, char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error: could not save image.\n");
        return;
    }
    fwrite(img->pixels, 1, MAX_PIXELS * PIXEL_SIZE, file);
    fclose(file);
}

int main() {
    Image img;
    create_image(&img, 100, 100);
    set_pixel(&img, 50, 50, (unsigned char*)"\xff\x00\x00\x00");
    unsigned char* pixel = get_pixel(&img, 50, 50);
    printf("Pixel value: %d %d %d %d\n", pixel[0], pixel[1], pixel[2], pixel[3]);
    save_image(&img, "example.bmp");
    destroy_image(&img);
    return 0;
}