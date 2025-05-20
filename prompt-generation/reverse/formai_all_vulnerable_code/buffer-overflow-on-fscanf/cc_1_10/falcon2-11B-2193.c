//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int x;
    int y;
    char r, g, b;
} Pixel;

Pixel* read_pixel(FILE* f) {
    Pixel* pixels = malloc(sizeof(Pixel) * 100);
    int n = 0;
    char c;

    while (fscanf(f, "%c", &c) == 1 && c!= '\n') {
        pixels[n].x = 0;
        pixels[n].y = 0;
        fscanf(f, "%d %d %c %c %c", &pixels[n].x, &pixels[n].y, &pixels[n].r, &pixels[n].g, &pixels[n].b);
        n++;
    }

    return pixels;
}

void flip_horizontal(Pixel* pixels, int n) {
    for (int i = 0; i < n; i++) {
        pixels[i].x = n - 1 - pixels[i].x;
    }
}

void change_brightness(Pixel* pixels, int n, float factor) {
    for (int i = 0; i < n; i++) {
        pixels[i].r = pixels[i].r * factor;
        pixels[i].g = pixels[i].g * factor;
        pixels[i].b = pixels[i].b * factor;
    }
}

void write_pixel(FILE* f, Pixel* pixels, int n) {
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %d %c %c %c\n", pixels[i].x, pixels[i].y, pixels[i].r, pixels[i].g, pixels[i].b);
    }
}

int main() {
    char filename[80];
    FILE* f;
    Pixel* pixels;
    int n;

    printf("Enter image filename: ");
    scanf("%s", filename);

    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    pixels = read_pixel(f);
    n = (int)strlen(filename);
    strcat(filename, "flip.ppm");
    fclose(f);

    f = fopen(filename, "w");
    if (f == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    flip_horizontal(pixels, n);
    change_brightness(pixels, n, 1.2);
    write_pixel(f, pixels, n);

    fclose(f);

    printf("Done.\n");

    return 0;
}