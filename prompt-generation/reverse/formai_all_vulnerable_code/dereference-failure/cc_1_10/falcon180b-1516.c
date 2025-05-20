//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25
#define CHAR_SET ".:-=+*0123456789ABCDEF"

typedef struct {
    char *data;
    int width;
    int height;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *data = malloc(size);
    if (data == NULL) {
        printf("Error: Could not allocate memory for image data\n");
        exit(1);
    }

    if (fread(data, 1, size, fp)!= size) {
        printf("Error: Could not read image data from file\n");
        exit(1);
    }

    fclose(fp);

    int width, height;
    if (sscanf(filename, "%dx%d.bmp", &width, &height)!= 2) {
        printf("Error: Invalid image file format\n");
        exit(1);
    }

    Image *img = malloc(sizeof(Image));
    if (img == NULL) {
        printf("Error: Could not allocate memory for image struct\n");
        exit(1);
    }

    img->data = data;
    img->width = width;
    img->height = height;

    return img;
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

void print_ascii_art(const Image *img) {
    int x, y;
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            int index = (y * WIDTH + x) * 3;
            int r = img->data[index];
            int g = img->data[index + 1];
            int b = img->data[index + 2];

            int value = (r + g + b) / 3;
            printf("%c", CHAR_SET[value]);
        }
        printf("\n");
    }
}

int main() {
    Image *img = load_image("example.bmp");
    if (img == NULL) {
        return 1;
    }

    print_ascii_art(img);

    free_image(img);

    return 0;
}