//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define NUM_PIXELS WIDTH * HEIGHT
#define MAX_COLOR 255

typedef struct {
    int r;
    int g;
    int b;
} Color;

void init_pixels(int* pixels) {
    for (int i = 0; i < NUM_PIXELS; i++) {
        pixels[i] = rand() % MAX_COLOR;
    }
}

void print_pixels(int* pixels) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int index = y * WIDTH + x;
            printf("%d ", pixels[index]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int* pixels = malloc(NUM_PIXELS * sizeof(int));
    init_pixels(pixels);

    while (1) {
        system("clear");
        print_pixels(pixels);
        printf("\nPress any key to regenerate...\n");
        getchar();

        free(pixels);
        pixels = malloc(NUM_PIXELS * sizeof(int));
        init_pixels(pixels);
    }

    return 0;
}