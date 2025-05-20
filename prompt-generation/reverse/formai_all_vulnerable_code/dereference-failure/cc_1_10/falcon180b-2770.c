//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void load_image(Image *img, FILE *fp) {
    fseek(fp, 0L, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    img->data = malloc(size);
    fread(img->data, size, 1, fp);

    int header_size = 0;
    while (header_size < size && img->data[header_size]!= '\0') {
        header_size++;
    }

    img->width = *(int *)&img->data[header_size + 18];
    img->height = *(int *)&img->data[header_size + 22];
}

void free_image(Image *img) {
    free(img->data);
}

void print_ascii_art(Image *img) {
    int x, y;
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            int pixel = *(int *)&img->data[y * img->width * 3 + x * 3];
            int r = (pixel >> 16) & 0xFF;
            int g = (pixel >> 8) & 0xFF;
            int b = pixel & 0xFF;

            int brightness = (r + g + b) / 3;

            if (brightness < 128) {
                printf("  ");
            } else if (brightness < 192) {
                printf("*");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}

int main() {
    Image img;

    FILE *fp = fopen("example.bmp", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    load_image(&img, fp);
    fclose(fp);

    print_ascii_art(&img);

    free_image(&img);

    return 0;
}