//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    int width;
    int height;
    char *data;
} Image;

void create_image(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->data = (char *)malloc(width * height);
    memset(img->data, 0, width * height);
}

void set_pixel(Image *img, int x, int y, char value) {
    if (x >= 0 && x < img->width && y >= 0 && y < img->height) {
        img->data[y * img->width + x] = value;
    }
}

void draw_line(Image *img, int x1, int y1, int x2, int y2, char value) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2)? 1 : -1;
    int sy = (y1 < y2)? 1 : -1;
    int err = dx - dy;

    while (1) {
        set_pixel(img, x1, y1, value);
        if (x1 == x2 && y1 == y2) break;
        int e2 = err * 2;
        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void fill_rect(Image *img, int x1, int y1, int x2, int y2, char value) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            set_pixel(img, i, j, value);
        }
    }
}

void save_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp) {
        fwrite(img->data, img->width * img->height, 1, fp);
        fclose(fp);
    }
}

void free_image(Image *img) {
    free(img->data);
}

int main() {
    Image img1, img2;

    create_image(&img1, 100, 100);
    create_image(&img2, 200, 200);

    draw_line(&img1, 0, 0, 99, 99, 255);
    fill_rect(&img2, 0, 0, 199, 199, 128);

    save_image(&img1, "image1.bin");
    save_image(&img2, "image2.bin");

    free_image(&img1);
    free_image(&img2);

    return 0;
}