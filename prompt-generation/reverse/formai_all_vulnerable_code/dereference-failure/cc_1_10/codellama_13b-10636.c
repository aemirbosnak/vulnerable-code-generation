//Code Llama-13B DATASET v1.0 Category: Image Editor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 800
#define MAX_HEIGHT 600

struct image {
    int width;
    int height;
    int **data;
};

void init_image(struct image *img) {
    img->width = 0;
    img->height = 0;
    img->data = (int **)malloc(MAX_WIDTH * sizeof(int *));
    for (int i = 0; i < MAX_WIDTH; i++) {
        img->data[i] = (int *)malloc(MAX_HEIGHT * sizeof(int));
    }
}

void free_image(struct image *img) {
    for (int i = 0; i < MAX_WIDTH; i++) {
        free(img->data[i]);
    }
    free(img->data);
}

void set_pixel(struct image *img, int x, int y, int color) {
    img->data[x][y] = color;
}

int get_pixel(struct image *img, int x, int y) {
    return img->data[x][y];
}

void draw_line(struct image *img, int x1, int y1, int x2, int y2, int color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x = x1;
    int y = y1;

    while (x <= x2 && y <= y2) {
        set_pixel(img, x, y, color);
        x++;
        y++;
    }
}

void draw_circle(struct image *img, int x, int y, int radius, int color) {
    int x1 = x - radius;
    int y1 = y - radius;
    int x2 = x + radius;
    int y2 = y + radius;

    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            int distance = sqrt((i - x) * (i - x) + (j - y) * (j - y));
            if (distance <= radius) {
                set_pixel(img, i, j, color);
            }
        }
    }
}

int main() {
    struct image img;
    init_image(&img);

    set_pixel(&img, 0, 0, 1);
    set_pixel(&img, 1, 1, 1);
    set_pixel(&img, 2, 2, 1);
    set_pixel(&img, 3, 3, 1);

    draw_line(&img, 0, 0, 4, 4, 1);
    draw_circle(&img, 2, 2, 2, 1);

    free_image(&img);

    return 0;
}