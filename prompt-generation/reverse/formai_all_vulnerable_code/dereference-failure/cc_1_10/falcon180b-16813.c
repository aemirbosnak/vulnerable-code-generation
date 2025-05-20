//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define NUM_PIXELS (WIDTH * HEIGHT)
#define NUM_COLORS 256
#define NUM_FRAMES 60

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

typedef struct {
    int num_pixels;
    Pixel *pixels;
} Frame;

void init_frame(Frame *frame, int num_pixels) {
    frame->num_pixels = num_pixels;
    frame->pixels = malloc(num_pixels * sizeof(Pixel));
}

void free_frame(Frame *frame) {
    free(frame->pixels);
}

void set_pixel(Pixel *pixel, int x, int y, int r, int g, int b) {
    pixel->x = x;
    pixel->y = y;
    pixel->r = r;
    pixel->g = g;
    pixel->b = b;
}

void draw_pixel(Frame *frame, int x, int y, int r, int g, int b) {
    Pixel *pixel = &frame->pixels[x + y * WIDTH];
    set_pixel(pixel, x, y, r, g, b);
}

void generate_pixels(Frame *frame) {
    srand(time(NULL));
    for (int i = 0; i < NUM_PIXELS; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        draw_pixel(frame, x, y, r, g, b);
    }
}

void save_frame(Frame *frame, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }
    fwrite(frame->pixels, sizeof(Pixel), frame->num_pixels, fp);
    fclose(fp);
}

int main() {
    Frame frame;
    init_frame(&frame, NUM_PIXELS);
    generate_pixels(&frame);
    save_frame(&frame, "output.bin");
    return 0;
}