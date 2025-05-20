//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct pixel {
    int x;
    int y;
    int r;
    int g;
    int b;
};

void draw_pixel(struct pixel *p, int size, int *image) {
    if (p->x >= 0 && p->x < size && p->y >= 0 && p->y < size) {
        int index = p->y * size + p->x;
        image[index] = p->r << 16 | p->g << 8 | p->b;
    }
}

void fill_rectangle(struct pixel start, struct pixel end, int size, int *image) {
    struct pixel current = start;
    while (current.y < end.y) {
        draw_pixel(&current, size, image);
        current.y++;
    }
    while (current.x < end.x) {
        draw_pixel(&current, size, image);
        current.x++;
    }
}

void flood_fill(int x, int y, int r, int g, int b, int *image, int size) {
    struct pixel current = {x, y, r, g, b};
    struct pixel start = {x - 1, y - 1, 0, 0, 0};
    struct pixel end = {x + 1, y + 1, 0, 0, 0};
    if (start.x >= 0 && start.x < size && start.y >= 0 && start.y < size &&
        image[start.y * size + start.x] == 0) {
        fill_rectangle(start, end, size, image);
    }
}

int main() {
    int size = 500;
    int *image = (int *)malloc(size * size * sizeof(int));
    memset(image, 0, size * size * sizeof(int));

    struct pixel start = {0, 0, 255, 0, 0};
    struct pixel end = {size - 1, size - 1, 0, 0, 0};
    flood_fill(start.x, start.y, 255, 0, 0, image, size);

    FILE *fp = fopen("image.bmp", "wb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fwrite(&size, sizeof(int), 1, fp);
    fwrite(&size, sizeof(int), 1, fp);
    fwrite(image, sizeof(int), size * size, fp);

    fclose(fp);

    return 0;
}