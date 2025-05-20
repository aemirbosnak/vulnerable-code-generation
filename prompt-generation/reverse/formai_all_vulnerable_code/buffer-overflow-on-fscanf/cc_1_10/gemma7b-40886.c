//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXELS 1024

typedef struct Pixel {
    int r, g, b, a;
} Pixel;

Pixel pixels[MAX_PIXELS];

void loadPixels(FILE *fp) {
    int i = 0;
    fscanf(fp, "%d ", &pixels[i].r);
    fscanf(fp, "%d ", &pixels[i].g);
    fscanf(fp, "%d ", &pixels[i].b);
    fscanf(fp, "%d ", &pixels[i].a);
    i++;
    while (!feof(fp)) {
        fscanf(fp, "%d ", &pixels[i].r);
        fscanf(fp, "%d ", &pixels[i].g);
        fscanf(fp, "%d ", &pixels[i].b);
        fscanf(fp, "%d ", &pixels[i].a);
        i++;
    }
}

void savePixels(FILE *fp) {
    int i = 0;
    fprintf(fp, "%d ", pixels[i].r);
    fprintf(fp, "%d ", pixels[i].g);
    fprintf(fp, "%d ", pixels[i].b);
    fprintf(fp, "%d ", pixels[i].a);
    i++;
    while (!feof(fp)) {
        fprintf(fp, "%d ", pixels[i].r);
        fprintf(fp, "%d ", pixels[i].g);
        fprintf(fp, "%d ", pixels[i].b);
        fprintf(fp, "%d ", pixels[i].a);
        i++;
    }
}

int main() {
    FILE *fp = fopen("image.txt", "r");
    loadPixels(fp);
    fclose(fp);

    // Edit pixels here

    fp = fopen("image.txt", "w");
    savePixels(fp);
    fclose(fp);

    return 0;
}