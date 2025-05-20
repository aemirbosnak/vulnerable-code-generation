//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_DEPTH 10

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

typedef struct {
    int width;
    int height;
    pixel *data;
} image;

image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return NULL;
    }

    image *img = malloc(sizeof(image));
    if (!img) {
        fclose(fp);
        return NULL;
    }

    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);

    img->data = malloc(img->width * img->height * sizeof(pixel));
    if (!img->data) {
        free(img);
        fclose(fp);
        return NULL;
    }

    fread(img->data, sizeof(pixel), img->width * img->height, fp);

    fclose(fp);

    return img;
}

void save_image(const char *filename, image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return;
    }

    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);

    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);

    fclose(fp);
}

void free_image(image *img) {
    free(img->data);
    free(img);
}

void embed_watermark(image *img, const char *watermark, int depth) {
    if (depth == MAX_DEPTH) {
        return;
    }

    int x = rand() % img->width;
    int y = rand() % img->height;

    pixel *p = &img->data[y * img->width + x];

    int bit = watermark[depth] - '0';
    p->red = (p->red & ~1) | bit;

    embed_watermark(img, watermark, depth + 1);
}

char extract_watermark(image *img, int depth) {
    if (depth == MAX_DEPTH) {
        return '\0';
    }

    int x = rand() % img->width;
    int y = rand() % img->height;

    pixel *p = &img->data[y * img->width + x];

    int bit = p->red & 1;

    char c = bit + '0';
    c = extract_watermark(img, depth + 1);

    return c;
}

int main() {
    image *img = load_image("lena.bmp");
    if (!img) {
        printf("Error loading image\n");
        return 1;
    }

    char *watermark = "Hello, world!";

    embed_watermark(img, watermark, 0);

    save_image("watermarked_lena.bmp", img);

    free_image(img);

    img = load_image("watermarked_lena.bmp");
    if (!img) {
        printf("Error loading image\n");
        return 1;
    }

    char *extracted_watermark = extract_watermark(img, 0);

    printf("Extracted watermark: %s\n", extracted_watermark);

    free_image(img);

    return 0;
}