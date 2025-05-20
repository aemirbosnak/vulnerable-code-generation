//Falcon2-11B DATASET v1.0 Category: Image to ASCII art converter ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    int width;
    int height;
    int num_colors;
    Point* points;
    unsigned char* colors;
} Image;

Image* load_image(const char* filename) {
    Image* image = malloc(sizeof(Image));
    image->width = 0;
    image->height = 0;
    image->num_colors = 0;
    image->points = NULL;
    image->colors = NULL;

    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file '%s'\n", filename);
        exit(1);
    }

    int color;
    int x, y;
    int r, g, b;
    fread(&color, sizeof(int), 1, file);
    fread(&x, sizeof(int), 1, file);
    fread(&y, sizeof(int), 1, file);
    fread(&r, sizeof(int), 1, file);
    fread(&g, sizeof(int), 1, file);
    fread(&b, sizeof(int), 1, file);

    image->width = x;
    image->height = y;
    image->num_colors = 1;
    image->points = malloc(image->width * image->height * sizeof(Point));
    image->colors = malloc(image->width * image->height * sizeof(unsigned char));

    for (int i = 0; i < image->width * image->height; i++) {
        image->points[i].x = (int)((double)i / (double)image->width * (double)image->width);
        image->points[i].y = (int)((double)i / (double)image->height * (double)image->height);
        image->colors[i] = (unsigned char)color;
    }

    fclose(file);

    return image;
}

void save_image(const char* filename, Image* image) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file '%s'\n", filename);
        exit(1);
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(&image->num_colors, sizeof(int), 1, file);
    fwrite(&image->num_colors, sizeof(int), 1, file);
    fwrite(&image->num_colors, sizeof(int), 1, file);
    fwrite(&image->num_colors, sizeof(int), 1, file);

    for (int i = 0; i < image->width * image->height; i++) {
        fwrite(&image->points[i].x, sizeof(int), 1, file);
        fwrite(&image->points[i].y, sizeof(int), 1, file);
        fwrite(&image->colors[i], sizeof(unsigned char), 1, file);
    }

    fclose(file);
}

void draw_image(Image* image, int x, int y) {
    for (int i = 0; i < image->width * image->height; i++) {
        if (image->points[i].x == x && image->points[i].y == y) {
            printf("%c", image->colors[i]);
        }
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <image-file>\n", argv[0]);
        exit(1);
    }

    Image* image = load_image(argv[1]);
    if (image == NULL) {
        fprintf(stderr, "Error: Failed to load image '%s'\n", argv[1]);
        exit(1);
    }

    draw_image(image, 0, 0);
    save_image(argv[1], image);

    free(image->points);
    free(image->colors);
    free(image);

    return 0;
}