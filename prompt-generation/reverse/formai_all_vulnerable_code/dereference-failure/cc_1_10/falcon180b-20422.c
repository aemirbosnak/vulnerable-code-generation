//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024
#define MAX_CHANNELS 4

typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

Image *create_image(int width, int height, int channels) {
    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->channels = channels;
    img->data = (unsigned char *)malloc(width * height * channels);
    return img;
}

void destroy_image(Image *img) {
    free(img->data);
    free(img);
}

void set_pixel(Image *img, int x, int y, int channel, unsigned char value) {
    int offset = (y * img->width + x) * img->channels + channel;
    img->data[offset] = value;
}

unsigned char get_pixel(Image *img, int x, int y, int channel) {
    int offset = (y * img->width + x) * img->channels + channel;
    return img->data[offset];
}

void save_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
    fprintf(fp, "P6\n%d %d\n%d\n", img->width, img->height, 255);
    fwrite(img->data, 1, img->width * img->height * img->channels, fp);
    fclose(fp);
}

int main() {
    Image *img = create_image(512, 512, 3);
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int r = (int)(255 * sin(x / 50.0) * cos(y / 50.0));
            int g = (int)(255 * cos(x / 50.0) * cos(y / 50.0));
            int b = (int)(255 * sin(y / 50.0));
            set_pixel(img, x, y, 0, r);
            set_pixel(img, x, y, 1, g);
            set_pixel(img, x, y, 2, b);
        }
    }
    save_image(img, " Mandelbrot set.png");
    destroy_image(img);
    return 0;
}