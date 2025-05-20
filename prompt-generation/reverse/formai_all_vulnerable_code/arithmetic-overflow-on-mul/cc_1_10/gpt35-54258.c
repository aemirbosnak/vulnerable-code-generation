//FormAI DATASET v1.0 Category: Image Editor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red, green, blue;
} Pixel;

typedef struct {
    int rows, cols;
    Pixel *pixels;
} Image;

Image *new_image(int rows, int cols) {
    Image *img = malloc(sizeof(Image));
    img->rows = rows;
    img->cols = cols;
    img->pixels = calloc(rows * cols, sizeof(Pixel));
    return img;
}

void free_image(Image *img) {
    free(img->pixels);
    free(img);
}

void save_image(Image *img, char *filename) {
    FILE *file;
    file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", img->cols, img->rows);
    fwrite(img->pixels, sizeof(Pixel), img->rows * img->cols, file);
    fclose(file);
}

Image *load_image(char *filename) {
    FILE *file;
    char type[10];
    int rows, cols, maxval;
    file = fopen(filename, "rb");
    fscanf(file, "%s\n%d %d\n%d\n", type, &cols, &rows, &maxval);
    Image *img = new_image(rows, cols);
    fread(img->pixels, sizeof(Pixel), rows * cols, file);
    fclose(file);
    return img;
}

void grayscale(Image *img) {
    for (int i = 0; i < img->rows; i++) {
        for (int j = 0; j < img->cols; j++) {
            Pixel *p = &(img->pixels[i * img->cols + j]);
            int avg = (p->red + p->green + p->blue) / 3;
            p->red = avg;
            p->green = avg;
            p->blue = avg;
        }
    }
}

void invert(Image *img) {
    for (int i = 0; i < img->rows; i++) {
        for (int j = 0; j < img->cols; j++) {
            Pixel *p = &(img->pixels[i * img->cols + j]);
            p->red = 255 - p->red;
            p->green = 255 - p->green;
            p->blue = 255 - p->blue;
        }
    }
}

void sepia(Image *img) {
    for (int i = 0; i < img->rows; i++) {
        for (int j = 0; j < img->cols; j++) {
            Pixel *p = &(img->pixels[i * img->cols + j]);
            int tr = (int)(0.393 * p->red + 0.769 * p->green + 0.189 * p->blue);
            int tg = (int)(0.349 * p->red + 0.686 * p->green + 0.168 * p->blue);
            int tb = (int)(0.272 * p->red + 0.534 * p->green + 0.131 * p->blue);
            if (tr > 255) {
                tr = 255;
            }
            if (tg > 255) {
                tg = 255;
            }
            if (tb > 255) {
                tb = 255;
            }
            p->red = tr;
            p->green = tg;
            p->blue = tb;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }
    char *filename = argv[1];
    Image *img = load_image(filename);
    printf("Loaded image %s (%dx%d)\n", filename, img->cols, img->rows);
    grayscale(img);
    save_image(img, "grayscale.ppm");
    printf("Grayscale image saved as grayscale.ppm\n");
    invert(img);
    save_image(img, "inverted.ppm");
    printf("Inverted image saved as inverted.ppm\n");
    sepia(img);
    save_image(img, "sepia.ppm");
    printf("Sepia image saved as sepia.ppm\n");
    free_image(img);
    return 0;
}