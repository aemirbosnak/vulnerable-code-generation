//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 256
#define MAX_HEIGHT 256

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    image *img = malloc(sizeof(image));
    if (img == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(fp);
        return NULL;
    }

    // Read the header
    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);

    // Allocate memory for the data
    img->data = malloc(img->width * img->height * sizeof(pixel));
    if (img->data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(fp);
        free(img);
        return NULL;
    }

    // Read the data
    fread(img->data, sizeof(pixel), img->width * img->height, fp);

    fclose(fp);

    return img;
}

void free_image(image *img) {
    free(img->data);
    free(img);
}

void convert_to_ascii(image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel p = img->data[y * img->width + x];
            double avg = (p.r + p.g + p.b) / 3.0;
            char c;
            if (avg < 32) {
                c = '#';
            } else if (avg < 64) {
                c = '&';
            } else if (avg < 128) {
                c = '@';
            } else if (avg < 192) {
                c = '%';
            } else {
                c = ' ';
            }
            printf("%c", c);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    image *img = load_image(argv[1]);
    if (img == NULL) {
        return 1;
    }

    convert_to_ascii(img);

    free_image(img);

    return 0;
}