//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXELS 1024

typedef struct Pixel {
    int r, g, b, a;
} Pixel;

Pixel pixels[MAX_PIXELS];

void draw_pixel(int x, int y, int r, int g, int b) {
    pixels[x + MAX_PIXELS * y].r = r;
    pixels[x + MAX_PIXELS * y].g = g;
    pixels[x + MAX_PIXELS * y].b = b;
}

int main() {
    int i, j, x, y;
    Pixel pixel;

    // Draw a red line from (0, 0) to (100, 100)
    for (x = 0; x <= 100; x++) {
        for (y = 0; y <= 100; y++) {
            if (x >= 0 && x <= 100 && y == 100) {
                draw_pixel(x, y, 255, 0, 0);
            }
        }
    }

    // Draw a green circle at (50, 50)
    pixel.r = 0;
    pixel.g = 255;
    pixel.b = 0;
    pixel.a = 255;
    draw_pixel(50, 50, pixel.r, pixel.g, pixel.b);

    // Draw a blue square at (25, 25)
    pixel.r = 0;
    pixel.g = 0;
    pixel.b = 255;
    pixel.a = 255;
    draw_pixel(25, 25, pixel.r, pixel.g, pixel.b);

    // Save the image to a file
    FILE *fp = fopen("image.bmp", "wb");
    fwrite(pixels, MAX_PIXELS * sizeof(Pixel), 1, fp);
    fclose(fp);

    return 0;
}