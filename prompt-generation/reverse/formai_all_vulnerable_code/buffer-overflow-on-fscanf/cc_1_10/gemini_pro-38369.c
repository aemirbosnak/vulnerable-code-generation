//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000
#define MAX_DEPTH 8

typedef struct {
    unsigned char **data;
    int width, height;
} Image;

typedef struct {
    int bit;
    int pos;
} Position;

Image *load_image(char *filename) {
    FILE *fp;
    Image *image;
    int i, j;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    image = malloc(sizeof(Image));
    if (image == NULL) {
        perror("malloc");
        exit(1);
    }

    fscanf(fp, "%d %d", &image->width, &image->height);

    image->data = malloc(image->height * sizeof(unsigned char *));
    if (image->data == NULL) {
        perror("malloc");
        exit(1);
    }

    for (i = 0; i < image->height; i++) {
        image->data[i] = malloc(image->width * sizeof(unsigned char));
        if (image->data[i] == NULL) {
            perror("malloc");
            exit(1);
        }

        for (j = 0; j < image->width; j++) {
            fscanf(fp, "%hhu", &image->data[i][j]);
        }
    }

    fclose(fp);

    return image;
}

void save_image(Image *image, char *filename) {
    FILE *fp;
    int i, j;

    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    fprintf(fp, "%d %d\n", image->width, image->height);

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            fprintf(fp, "%hhu ", image->data[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void embed_watermark(Image *image, char *watermark, int depth) {
    int i, j, k;
    Position pos;

    pos.bit = 0;
    pos.pos = 0;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            for (k = 0; k < depth; k++) {
                if (watermark[pos.pos] == '\0') {
                    return;
                }

                if ((image->data[i][j] & (1 << k)) == 0) {
                    image->data[i][j] |= (watermark[pos.pos] & (1 << pos.bit)) >> pos.bit;
                } else {
                    image->data[i][j] &= ~(1 << k);
                    image->data[i][j] |= ((~watermark[pos.pos]) & (1 << pos.bit)) >> pos.bit;
                }

                pos.bit++;
                if (pos.bit == 8) {
                    pos.bit = 0;
                    pos.pos++;
                }
            }
        }
    }
}

char *extract_watermark(Image *image, int depth) {
    int i, j, k;
    Position pos;
    char *watermark;

    watermark = malloc(MAX_SIZE * sizeof(char));
    if (watermark == NULL) {
        perror("malloc");
        exit(1);
    }

    pos.bit = 0;
    pos.pos = 0;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            for (k = 0; k < depth; k++) {
                watermark[pos.pos] |= ((image->data[i][j] >> k) & 1) << pos.bit;
                pos.bit++;
                if (pos.bit == 8) {
                    pos.bit = 0;
                    pos.pos++;
                }
            }
        }
    }

    return watermark;
}

int main(int argc, char **argv) {
    Image *image;
    char *watermark;
    int depth;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <watermark> <depth> <output image>\n", argv[0]);
        exit(1);
    }

    image = load_image(argv[1]);
    watermark = argv[2];
    depth = atoi(argv[3]);

    if (depth > MAX_DEPTH) {
        fprintf(stderr, "Error: depth must be between 1 and %d\n", MAX_DEPTH);
        exit(1);
    }

    embed_watermark(image, watermark, depth);
    save_image(image, argv[4]);

    watermark = extract_watermark(image, depth);
    printf("Extracted watermark: %s\n", watermark);

    free(image->data);
    free(image);
    free(watermark);

    return 0;
}