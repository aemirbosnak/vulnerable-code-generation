//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

#define MAX_SIZE 1024

typedef struct {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel;

typedef struct {
    int width;
    int height;
    pixel *data;
} image;

image *read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    image *img = malloc(sizeof(image));
    if (img == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return NULL;
    }

    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);
    img->data = malloc(img->width * img->height * sizeof(pixel));
    if (img->data == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        free(img);
        return NULL;
    }

    fread(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);

    return img;
}

void write_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

void embed_watermark(image *img, char *watermark) {
    int len = strlen(watermark);
    for (int i = 0; i < len; i++) {
        int c = watermark[i];
        for (int j = 0; j < 8; j++) {
            int bit = (c >> j) & 1;
            int x = i * 8 + j;
            int y = x / img->width;
            x %= img->width;
            img->data[y * img->width + x].red = (img->data[y * img->width + x].red & ~1) | bit;
        }
    }
}

char *extract_watermark(image *img) {
    int len = img->width * img->height / 8;
    char *watermark = malloc(len + 1);
    if (watermark == NULL) {
        perror("Error allocating memory");
        return NULL;
    }

    for (int i = 0; i < len; i++) {
        int c = 0;
        for (int j = 0; j < 8; j++) {
            int x = i * 8 + j;
            int y = x / img->width;
            x %= img->width;
            c |= (img->data[y * img->width + x].red & 1) << j;
        }
        watermark[i] = c;
    }
    watermark[len] = '\0';

    return watermark;
}

int main() {
    image *img = read_image("image.bmp");
    if (img == NULL) {
        return 1;
    }

    embed_watermark(img, "Watermark");

    write_image(img, "watermarked_image.bmp");

    char *watermark = extract_watermark(img);
    if (watermark == NULL) {
        return 1;
    }

    printf("Watermark: %s\n", watermark);

    free(watermark);
    free(img->data);
    free(img);

    return 0;
}