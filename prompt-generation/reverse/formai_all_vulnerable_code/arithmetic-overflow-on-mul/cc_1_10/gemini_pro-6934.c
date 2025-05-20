//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int width, height;
    unsigned char *data;
} Image;

Image* load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file\n");
        return NULL;
    }
    Image *img = malloc(sizeof(Image));
    fscanf(fp, "P5 %d %d 255\n", &img->width, &img->height);
    img->data = malloc(img->width * img->height);
    fread(img->data, img->width * img->height, 1, fp);
    fclose(fp);
    return img;
}

void save_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file\n");
        return;
    }
    fprintf(fp, "P5 %d %d 255\n", img->width, img->height);
    fwrite(img->data, img->width * img->height, 1, fp);
    fclose(fp);
}

void blur(Image *img, int radius) {
    int x, y, i, j;
    double sum, count;
    unsigned char *new_data = malloc(img->width * img->height);
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            sum = 0;
            count = 0;
            for (i = y - radius; i <= y + radius; i++) {
                if (i < 0 || i >= img->height) {
                    continue;
                }
                for (j = x - radius; j <= x + radius; j++) {
                    if (j < 0 || j >= img->width) {
                        continue;
                    }
                    sum += img->data[i * img->width + j];
                    count++;
                }
            }
            new_data[y * img->width + x] = round(sum / count);
        }
    }
    free(img->data);
    img->data = new_data;
}

void edge_detect(Image *img) {
    int x, y, i, j;
    int gx, gy;
    unsigned char *new_data = malloc(img->width * img->height);
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            gx = 0;
            gy = 0;
            for (i = y - 1; i <= y + 1; i++) {
                if (i < 0 || i >= img->height) {
                    continue;
                }
                for (j = x - 1; j <= x + 1; j++) {
                    if (j < 0 || j >= img->width) {
                        continue;
                    }
                    if (i == y && j == x) {
                        continue;
                    }
                    gx += img->data[i * img->width + j] - img->data[y * img->width + x];
                    gy += img->data[i * img->width + j] - img->data[y * img->width + x];
                }
            }
            new_data[y * img->width + x] = sqrt(gx * gx + gy * gy);
        }
    }
    free(img->data);
    img->data = new_data;
}

void invert(Image *img) {
    int x, y;
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            img->data[y * img->width + x] = 255 - img->data[y * img->width + x];
        }
    }
}

void main() {
    Image *img = load_image("image.pgm");
    blur(img, 5);
    edge_detect(img);
    invert(img);
    save_image(img, "output.pgm");
    free(img->data);
    free(img);
}