//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024
#define MAX_VALUE 255

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel data[MAX_WIDTH][MAX_HEIGHT];
} Image;

Image *read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "P6\n%d %d\n%d\n", &image->width, &image->height, &image->data[0][0].r);
    if (image->width > MAX_WIDTH || image->height > MAX_HEIGHT) {
        fprintf(stderr, "Error: image is too large\n");
        fclose(fp);
        free(image);
        return NULL;
    }

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fread(&image->data[j][i], sizeof(Pixel), 1, fp);
        }
    }

    fclose(fp);

    return image;
}

void write_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    fprintf(fp, "P6\n%d %d\n%d\n", image->width, image->height, image->data[0][0].r);

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            fwrite(&image->data[j][i], sizeof(Pixel), 1, fp);
        }
    }

    fclose(fp);
}

void convert_to_ascii(Image *image, char *output) {
    double max_value = 0;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            double value = 0.3 * image->data[j][i].r + 0.59 * image->data[j][i].g + 0.11 * image->data[j][i].b;
            if (value > max_value) {
                max_value = value;
            }
        }
    }

    double scale = 100.0 / max_value;

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            double value = 0.3 * image->data[j][i].r + 0.59 * image->data[j][i].g + 0.11 * image->data[j][i].b;
            int index = (int)(value * scale);
            output[i * image->width + j] = " .,-~:;=!*#$@"[index];
        }
    }

    output[image->height * image->width] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input image> <output ascii>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    char output[image->height * image->width + 1];
    convert_to_ascii(image, output);

    FILE *fp = fopen(argv[2], "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", argv[2]);
        free(image);
        return 1;
    }

    fprintf(fp, "%s\n", output);
    fclose(fp);

    free(image);

    return 0;
}