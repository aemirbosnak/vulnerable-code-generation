//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 10000
#define MAX_COLORS 256

struct pixel {
    int x, y;
    int r, g, b;
};

struct color {
    char name[20];
    int r, g, b;
};

int read_pixels(struct pixel pixels[], int max_pixels, FILE *fp) {
    int count = 0;
    while (count < max_pixels && fscanf(fp, "%d %d %d %d %d %d",
        &pixels[count].x, &pixels[count].y,
        &pixels[count].r, &pixels[count].g,
        &pixels[count].b) == 6) {
        count++;
    }
    return count;
}

int read_colors(struct color colors[], int max_colors, FILE *fp) {
    int count = 0;
    while (count < max_colors && fscanf(fp, "%s %d %d %d",
        &colors[count].name,
        &colors[count].r, &colors[count].g, &colors[count].b) == 4) {
        count++;
    }
    return count;
}

void write_pixels(struct pixel pixels[], int num_pixels, FILE *fp) {
    for (int i = 0; i < num_pixels; i++) {
        fprintf(fp, "%d %d %d %d %d %d\n",
            pixels[i].x, pixels[i].y,
            pixels[i].r, pixels[i].g,
            pixels[i].b);
    }
}

void write_colors(struct color colors[], int num_colors, FILE *fp) {
    for (int i = 0; i < num_colors; i++) {
        fprintf(fp, "%s %d %d %d\n",
            colors[i].name, colors[i].r, colors[i].g, colors[i].b);
    }
}

int main() {
    struct pixel pixels[MAX_PIXELS];
    int num_pixels = read_pixels(pixels, MAX_PIXELS, stdin);

    struct color colors[MAX_COLORS];
    int num_colors = read_colors(colors, MAX_COLORS, stdin);

    // do some image editing here...

    write_pixels(pixels, num_pixels, stdout);
    write_colors(colors, num_colors, stdout);

    return 0;
}