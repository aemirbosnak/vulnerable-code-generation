//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel data[MAX_WIDTH * MAX_HEIGHT];
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    fread(image->data, sizeof(Pixel), image->width * image->height, fp);

    fclose(fp);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);

    fwrite(image->data, sizeof(Pixel), image->width * image->height, fp);

    fclose(fp);
}

void invert_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i].r = 255 - image->data[i].r;
        image->data[i].g = 255 - image->data[i].g;
        image->data[i].b = 255 - image->data[i].b;
    }
}

void grayscale_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->data[i].r + image->data[i].g + image->data[i].b) / 3;
        image->data[i].r = gray;
        image->data[i].g = gray;
        image->data[i].b = gray;
    }
}

void blur_image(Image *image, int radius) {
    Pixel *temp = malloc(sizeof(Pixel) * image->width * image->height);
    if (!temp) {
        perror("malloc");
        return;
    }

    for (int i = 0; i < image->width * image->height; i++) {
        int r = 0, g = 0, b = 0;
        int count = 0;
        for (int j = -radius; j <= radius; j++) {
            for (int k = -radius; k <= radius; k++) {
                int x = i % image->width + j;
                int y = i / image->width + k;
                if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
                    r += image->data[y * image->width + x].r;
                    g += image->data[y * image->width + x].g;
                    b += image->data[y * image->width + x].b;
                    count++;
                }
            }
        }
        temp[i].r = r / count;
        temp[i].g = g / count;
        temp[i].b = b / count;
    }

    memcpy(image->data, temp, sizeof(Pixel) * image->width * image->height);
    free(temp);
}

void sharpen_image(Image *image, int radius) {
    Pixel *temp = malloc(sizeof(Pixel) * image->width * image->height);
    if (!temp) {
        perror("malloc");
        return;
    }

    for (int i = 0; i < image->width * image->height; i++) {
        int r = 0, g = 0, b = 0;
        int count = 0;
        for (int j = -radius; j <= radius; j++) {
            for (int k = -radius; k <= radius; k++) {
                int x = i % image->width + j;
                int y = i / image->width + k;
                if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
                    r += image->data[y * image->width + x].r;
                    g += image->data[y * image->width + x].g;
                    b += image->data[y * image->width + x].b;
                    count++;
                }
            }
        }
        temp[i].r = r / count - image->data[i].r;
        temp[i].g = g / count - image->data[i].g;
        temp[i].b = b / count - image->data[i].b;
    }

    memcpy(image->data, temp, sizeof(Pixel) * image->width * image->height);
    free(temp);
}

void edge_detection_image(Image *image, int radius) {
    Pixel *temp = malloc(sizeof(Pixel) * image->width * image->height);
    if (!temp) {
        perror("malloc");
        return;
    }

    for (int i = 0; i < image->width * image->height; i++) {
        int r = 0, g = 0, b = 0;
        int count = 0;
        for (int j = -radius; j <= radius; j++) {
            for (int k = -radius; k <= radius; k++) {
                int x = i % image->width + j;
                int y = i / image->width + k;
                if (x >= 0 && x < image->width && y >= 0 && y < image->height) {
                    r += image->data[y * image->width + x].r;
                    g += image->data[y * image->width + x].g;
                    b += image->data[y * image->width + x].b;
                    count++;
                }
            }
        }
        temp[i].r = abs(r / count - image->data[i].r);
        temp[i].g = abs(g / count - image->data[i].g);
        temp[i].b = abs(b / count - image->data[i].b);
    }

    memcpy(image->data, temp, sizeof(Pixel) * image->width * image->height);
    free(temp);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    invert_image(image);
    grayscale_image(image);
    blur_image(image, 2);
    sharpen_image(image, 1);
    edge_detection_image(image, 1);

    write_image(image, argv[2]);

    free(image);

    return 0;
}