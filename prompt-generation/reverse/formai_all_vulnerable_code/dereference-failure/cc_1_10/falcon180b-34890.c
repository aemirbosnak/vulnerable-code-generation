//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PIXELS 1000000

typedef struct {
    int x;
    int y;
    int color;
} Pixel;

Pixel *generatePixels(int width, int height) {
    Pixel *pixels = (Pixel *)malloc(MAX_PIXELS * sizeof(Pixel));
    if (pixels == NULL) {
        printf("Error: Failed to allocate memory for pixels.\n");
        exit(1);
    }

    int numPixels = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            pixels[numPixels++] = (Pixel) { x, y, (r << 16) | (g << 8) | b };
        }
    }

    return pixels;
}

void savePixelsToFile(Pixel *pixels, int numPixels, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Failed to open file %s for writing.\n", filename);
        exit(1);
    }

    fwrite(pixels, sizeof(Pixel), numPixels, file);
    fclose(file);
}

int main() {
    int width, height;
    printf("Enter the desired width and height of the image: ");
    scanf("%d %d", &width, &height);

    Pixel *pixels = generatePixels(width, height);
    savePixelsToFile(pixels, width * height, "image.raw");

    printf("Image generated successfully and saved to file image.raw.\n");
    return 0;
}