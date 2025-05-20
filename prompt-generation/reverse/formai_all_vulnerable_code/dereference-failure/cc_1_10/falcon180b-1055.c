//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_SIZE 100
#define NUM_POINTS 1000
#define NUM_COLORS 256

typedef struct point {
    int x, y;
    int r, g, b;
} point_t;

typedef struct image {
    point_t *points;
    int size;
} image_t;

void init_image(image_t *image) {
    image->points = (point_t *)malloc(MAX_SIZE * sizeof(point_t));
    image->size = 0;
}

void free_image(image_t *image) {
    free(image->points);
}

void add_point(image_t *image, int x, int y, int r, int g, int b) {
    if (image->size >= MAX_SIZE) {
        printf("Error: Max size reached.\n");
        return;
    }

    image->points[image->size].x = x;
    image->points[image->size].y = y;
    image->points[image->size].r = r;
    image->points[image->size].g = g;
    image->points[image->size].b = b;

    image->size++;
}

void draw_point(image_t *image, int index, int x, int y) {
    point_t *point = &image->points[index];

    printf("drawing point: (%d, %d) -> (%d, %d)\n", point->x, point->y, x, y);
    printf("color: (%d, %d, %d)\n", point->r, point->g, point->b);
}

void draw_image(image_t *image) {
    for (int i = 0; i < image->size; i++) {
        draw_point(image, i, image->points[i].x, image->points[i].y);
    }
}

void main() {
    srand(time(NULL));

    image_t image;
    init_image(&image);

    for (int i = 0; i < NUM_POINTS; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        int r = rand() % NUM_COLORS;
        int g = rand() % NUM_COLORS;
        int b = rand() % NUM_COLORS;

        add_point(&image, x, y, r, g, b);
    }

    draw_image(&image);

    free_image(&image);
}