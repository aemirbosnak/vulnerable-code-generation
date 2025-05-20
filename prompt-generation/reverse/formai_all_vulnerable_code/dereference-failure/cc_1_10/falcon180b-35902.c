//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_PIXELS (WIDTH * HEIGHT)
#define MAX_COLOR 255

// Struct for pixel data
typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

// Function to initialize random seed
void init_seed() {
    srand(time(NULL));
}

// Function to generate a random color
int rand_color() {
    return rand() % MAX_COLOR;
}

// Function to draw a pixel
void draw_pixel(int x, int y, int r, int g, int b) {
    Pixel* pixel = (Pixel*)malloc(sizeof(Pixel));
    pixel->x = x;
    pixel->y = y;
    pixel->r = r;
    pixel->g = g;
    pixel->b = b;
}

// Function to fill the image with random pixels
void fill_image(Pixel** pixels) {
    for (int i = 0; i < MAX_PIXELS; i++) {
        int x = rand() % WIDTH;
        int y = rand() % HEIGHT;
        int r = rand_color();
        int g = rand_color();
        int b = rand_color();
        draw_pixel(x, y, r, g, b);
    }
}

// Function to save the image to a file
void save_image(char* filename, Pixel** pixels) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    fwrite(pixels, sizeof(Pixel), MAX_PIXELS, file);
    fclose(file);
}

// Function to main
int main() {
    init_seed();
    Pixel** pixels = (Pixel**)malloc(sizeof(Pixel*) * MAX_PIXELS);
    fill_image(pixels);
    save_image("random.bmp", pixels);
    return 0;
}