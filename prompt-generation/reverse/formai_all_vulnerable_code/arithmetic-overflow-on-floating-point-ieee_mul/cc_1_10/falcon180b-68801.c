//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 640
#define HEIGHT 480
#define MAX_COLOR 256

typedef struct {
    int x, y;
    int r, g, b;
} Pixel;

int main() {
    Pixel *pixels = malloc(WIDTH * HEIGHT * sizeof(Pixel));
    if (!pixels) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    int max_x = WIDTH / 2;
    int max_y = HEIGHT / 2;

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int distance = sqrt(pow(x - max_x, 2) + pow(y - max_y, 2));
            int color = (int) (distance * MAX_COLOR / max_x);

            pixels[y * WIDTH + x].r = color;
            pixels[y * WIDTH + x].g = color;
            pixels[y * WIDTH + x].b = color;
        }
    }

    FILE *fp = fopen("image.ppm", "wb");
    if (!fp) {
        printf("Failed to open file.\n");
        free(pixels);
        return 1;
    }

    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, MAX_COLOR);

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            fprintf(fp, "%d %d %d ", pixels[y * WIDTH + x].r, pixels[y * WIDTH + x].g, pixels[y * WIDTH + x].b);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    free(pixels);

    return 0;
}