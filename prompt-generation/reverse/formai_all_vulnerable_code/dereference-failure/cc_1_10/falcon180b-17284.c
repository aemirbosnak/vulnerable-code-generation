//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    int width;
    int height;
    char *data;
} Image;

typedef struct {
    int x;
    int y;
    char c;
} Cell;

void load_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    img->data = malloc(size);
    fread(img->data, 1, size, fp);
    fclose(fp);

    img->width = atoi(strtok(filename, "."));
    img->height = atoi(strtok(NULL, "."));
}

void free_image(Image *img) {
    free(img->data);
}

void print_cell(Cell c) {
    printf("%c", c.c);
}

void print_image(Image img, int scale) {
    int x, y;
    for (y = 0; y < img.height; y++) {
        for (x = 0; x < img.width; x++) {
            Cell c = (Cell) {
               .x = x * scale,
               .y = y * scale,
               .c = (int) (img.data[y * img.width + x] * (scale / 2) + 33) % 94 + 33
            };
            print_cell(c);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <image> <scale>\n", argv[0]);
        return 1;
    }

    Image img;
    load_image(&img, argv[1]);

    int scale = atoi(argv[2]);

    print_image(img, scale);

    free_image(&img);

    return 0;
}