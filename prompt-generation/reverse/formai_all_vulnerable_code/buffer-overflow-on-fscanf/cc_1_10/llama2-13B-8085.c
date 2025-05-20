//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

typedef struct {
    int x;
    int y;
    int r;
    int g;
    int b;
} Pixel;

typedef struct {
    Pixel pixels[WIDTH * HEIGHT];
} Image;

void load_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "r");
    int i = 0;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fscanf(file, "%d %d %d", &image->pixels[i].x, &image->pixels[i].y, &image->pixels[i].r);
            i++;
        }
    }
    fclose(file);
}

void apply_statistical_transformations(Image *image) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        Pixel pixel = image->pixels[i];
        pixel.r += (rand() % 20) - 10;
        pixel.g += (rand() % 20) - 10;
        pixel.b += (rand() % 20) - 10;
        image->pixels[i] = pixel;
    }
}

void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        Pixel pixel = image->pixels[i];
        fprintf(file, "%d %d %d\n", pixel.x, pixel.y, pixel.r);
    }
    fclose(file);
}

int main() {
    Image image;
    load_image(&image, "example.bmp");
    apply_statistical_transformations(&image);
    save_image(&image, "output.bmp");
    return 0;
}