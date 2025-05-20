//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLORS 256

typedef struct {
    int r;
    int g;
    int b;
} Color;

Color* generate_palette(int num_colors) {
    Color* palette = malloc(num_colors * sizeof(Color));

    for (int i = 0; i < num_colors; i++) {
        palette[i].r = rand() % 256;
        palette[i].g = rand() % 256;
        palette[i].b = rand() % 256;
    }

    return palette;
}

void apply_palette(Color* palette, int width, int height, unsigned char* pixels) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;

            pixels[index] = palette[0].r;
            pixels[index + 1] = palette[0].g;
            pixels[index + 2] = palette[0].b;
        }
    }
}

int main() {
    srand(time(NULL));

    Color* palette = generate_palette(MAX_COLORS);
    unsigned char* pixels = malloc(WIDTH * HEIGHT * 3);

    apply_palette(palette, WIDTH, HEIGHT, pixels);

    FILE* fp = fopen("pixel_art.ppm", "wb");

    fprintf(fp, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);

    for (int y = 0; y < HEIGHT; y++) {
        fwrite(pixels + y * WIDTH * 3, 1, WIDTH * 3, fp);
    }

    fclose(fp);

    free(palette);
    free(pixels);

    return 0;
}