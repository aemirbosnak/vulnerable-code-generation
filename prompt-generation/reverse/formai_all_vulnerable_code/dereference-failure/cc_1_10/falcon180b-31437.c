//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_DOTS 5000

typedef struct {
    int x;
    int y;
    int r;
    int g;
    int b;
} pixel;

pixel *dots = NULL;
int num_dots = 0;

void init() {
    srand(time(NULL));
    dots = (pixel *)malloc(MAX_DOTS * sizeof(pixel));
    num_dots = 0;
}

void add_dot(int x, int y, int r, int g, int b) {
    if (num_dots >= MAX_DOTS) {
        return;
    }
    dots[num_dots].x = x;
    dots[num_dots].y = y;
    dots[num_dots].r = r;
    dots[num_dots].g = g;
    dots[num_dots].b = b;
    num_dots++;
}

void generate_image(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Failed to open %s for writing\n", filename);
        exit(1);
    }

    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = (y * WIDTH + x) / num_dots;
            pixel p = dots[index];
            int r = p.r;
            int g = p.g;
            int b = p.b;

            fprintf(fp, "%d %d %d\n", r, g, b);
        }
    }

    fclose(fp);
}

int main() {
    init();

    for (int i = 0; i < 10; i++) {
        add_dot(rand() % WIDTH, rand() % HEIGHT, rand() % 256, rand() % 256, rand() % 256);
    }

    generate_image("pixel_art.png");

    return 0;
}