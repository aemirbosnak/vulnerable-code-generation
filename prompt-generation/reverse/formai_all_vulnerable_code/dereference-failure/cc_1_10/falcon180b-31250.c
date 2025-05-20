//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define NUM_COLORS 256
#define NUM_PIXELS (WIDTH * HEIGHT)

typedef struct {
    int r;
    int g;
    int b;
} Color;

typedef struct {
    int x;
    int y;
    Color color;
} Pixel;

Pixel *generate_pixels(int seed) {
    srand(seed);
    Pixel *pixels = (Pixel *)malloc(NUM_PIXELS * sizeof(Pixel));

    for (int i = 0; i < NUM_PIXELS; i++) {
        pixels[i].x = i % WIDTH;
        pixels[i].y = i / WIDTH;

        Color color;
        color.r = rand() % 256;
        color.g = rand() % 256;
        color.b = rand() % 256;

        pixels[i].color = color;
    }

    return pixels;
}

void save_pixels_to_file(Pixel *pixels, char *filename) {
    FILE *file = fopen(filename, "wb");

    if (file == NULL) {
        printf("Error: could not open output file.\n");
        exit(1);
    }

    fwrite(pixels, sizeof(Pixel), NUM_PIXELS, file);

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <output_file> <seed>\n", argv[0]);
        return 1;
    }

    char *output_file = argv[1];
    int seed = atoi(argv[2]);

    Pixel *pixels = generate_pixels(seed);
    save_pixels_to_file(pixels, output_file);

    free(pixels);

    return 0;
}