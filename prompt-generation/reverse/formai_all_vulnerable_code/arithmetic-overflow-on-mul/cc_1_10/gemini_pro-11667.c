//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    image *img = malloc(sizeof(image));
    if (!img) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(fp);
        return NULL;
    }

    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);

    img->data = malloc(img->width * img->height * sizeof(pixel));
    if (!img->data) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(fp);
        free(img);
        return NULL;
    }

    fread(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);

    return img;
}

void save_image(const char *filename, image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

void invert_image(image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    image *img = load_image(argv[1]);
    if (!img) {
        return 1;
    }

    invert_image(img);
    save_image(argv[2], img);

    free(img->data);
    free(img);

    return 0;
}