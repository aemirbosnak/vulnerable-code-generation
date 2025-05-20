//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void load_image(Image *img, const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);

    img->data = malloc(size);
    fread(img->data, 1, size, f);
    fclose(f);

    int header_size = *(int *)img->data;
    img->width = *(int *)(img->data + 4);
    img->height = *(int *)(img->data + 8);
}

void free_image(Image *img) {
    free(img->data);
}

void print_ascii_art(const Image *img) {
    int x, y;
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            int value = *(unsigned char *)(img->data + y * img->width + x);
            if (value < 128) {
                printf(" ");
            } else {
                printf("%c", value);
            }
        }
        printf("\n");
    }
}

int main() {
    Image img;
    load_image(&img, "example.bmp");
    print_ascii_art(&img);
    free_image(&img);
    return 0;
}