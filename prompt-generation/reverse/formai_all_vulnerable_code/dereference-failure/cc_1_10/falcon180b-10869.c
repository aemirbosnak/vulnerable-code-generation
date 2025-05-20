//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_DEPTH 8
#define MAX_COLOR_COMPONENTS 4

typedef struct {
    int width;
    int height;
    int depth;
    int color_components;
    char *data;
} Image;

void init_image(Image *img, int width, int height, int depth, int color_components) {
    img->width = width;
    img->height = height;
    img->depth = depth;
    img->color_components = color_components;
    img->data = malloc(img->width * img->height * img->color_components * sizeof(char));
}

void free_image(Image *img) {
    free(img->data);
}

void set_pixel(Image *img, int x, int y, int c) {
    int offset = (y * img->width + x) * img->color_components;
    img->data[offset] = c;
    img->data[offset + 1] = c;
    img->data[offset + 2] = c;
    img->data[offset + 3] = 255;
}

void save_image(Image *img, char *filename) {
    FILE *f;
    f = fopen(filename, "wb");
    if (f == NULL) {
        printf("Error: could not save image to file.\n");
        return;
    }
    fprintf(f, "P6\n%d %d\n%d\n", img->width, img->height, 255);
    fwrite(img->data, img->width * img->height * img->color_components, sizeof(char), f);
    fclose(f);
}

int main() {
    Image img;
    init_image(&img, 500, 500, 8, 3);
    set_pixel(&img, 0, 0, 255);
    set_pixel(&img, 499, 499, 0);
    set_pixel(&img, 499, 0, 0);
    set_pixel(&img, 0, 499, 0);
    save_image(&img, "image.png");
    free_image(&img);
    return 0;
}