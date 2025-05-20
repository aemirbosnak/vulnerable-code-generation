//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <limits.h>

#define RGB(r,g,b) ((r << 16) | (g << 8) | b)
#define MAX_SIZE 1000

typedef struct {
    int x, y, size;
    uint32_t color;
} pixel;

void draw_pixel(int x, int y, uint32_t color) {
    printf("Pixel (%d,%d) - Color: #%06X\n", x, y, color);
}

void generate_pixels(int num_pixels, int max_size) {
    srand(time(NULL));
    pixel pixels[MAX_SIZE];
    int count = 0;

    while (count < num_pixels) {
        int x = rand() % max_size;
        int y = rand() % max_size;
        int size = rand() % (max_size / 4) + 1;
        uint32_t color = RGB(rand() % 256, rand() % 256, rand() % 256);

        for (int i = -size; i <= size; i++) {
            for (int j = -size; j <= size; j++) {
                if ((x + i) >= 0 && (x + i) < max_size &&
                    (y + j) >= 0 && (y + j) < max_size) {
                    draw_pixel(x + i, y + j, color);
                }
            }
        }

        pixels[count] = (pixel) {x, y, size, color};
        count++;
    }

    for (int i = 0; i < count; i++) {
        draw_pixel(pixels[i].x, pixels[i].y, pixels[i].color);
    }
}

int main() {
    int num_pixels;
    printf("Enter the number of pixels to generate: ");
    scanf("%d", &num_pixels);

    int max_size;
    printf("Enter the maximum size of the image (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &max_size);

    generate_pixels(num_pixels, max_size);

    return 0;
}