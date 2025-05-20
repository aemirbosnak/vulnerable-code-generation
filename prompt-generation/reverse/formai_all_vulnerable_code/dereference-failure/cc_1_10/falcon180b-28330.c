//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define CHAR_SET ".,-+=@#%&*?<>0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *data = malloc(size);
    if (data == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for image data\n");
        exit(1);
    }

    if (fread(data, 1, size, fp)!= size) {
        fprintf(stderr, "Error: Could not read image data from file\n");
        exit(1);
    }

    fclose(fp);

    Image *img = malloc(sizeof(Image));
    if (img == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for image structure\n");
        exit(1);
    }

    img->width = 0;
    img->height = 0;
    img->data = data;

    return img;
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

void print_image(Image *img) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            printf("%c", CHAR_SET[img->data[i * img->width + j] / 16]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        exit(1);
    }

    Image *img = load_image(argv[1]);
    if (img == NULL) {
        exit(1);
    }

    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            printf("%c", CHAR_SET[img->data[i * img->width + j] / 16]);
        }
        printf("\n");
    }

    free_image(img);

    return 0;
}