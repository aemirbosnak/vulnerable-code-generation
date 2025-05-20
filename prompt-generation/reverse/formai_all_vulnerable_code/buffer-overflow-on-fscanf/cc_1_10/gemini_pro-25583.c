//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel data[MAX_HEIGHT][MAX_WIDTH];
} image;

image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    image img;
    fscanf(fp, "%d %d\n", &img.width, &img.height);
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            fscanf(fp, "%hhu %hhu %hhu ", &img.data[i][j].r, &img.data[i][j].g, &img.data[i][j].b);
        }
    }

    fclose(fp);
    return img;
}

void save_image(const char *filename, image img) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    fprintf(fp, "%d %d\n", img.width, img.height);
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            fprintf(fp, "%hhu %hhu %hhu ", img.data[i][j].r, img.data[i][j].g, img.data[i][j].b);
        }
    }

    fclose(fp);
}

char *convert_image_to_ascii(image img) {
    char *ascii_art = malloc(img.width * img.height * 2 + 1);
    if (ascii_art == NULL) {
        fprintf(stderr, "Error: could not allocate memory for ASCII art\n");
        exit(1);
    }

    int index = 0;
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            pixel p = img.data[i][j];
            char c = ' ';
            if (p.r > 128) {
                c = '#';
            } else if (p.r > 64) {
                c = '%';
            } else if (p.r > 32) {
                c = '@';
            }

            ascii_art[index++] = c;
            ascii_art[index++] = ' ';
        }
        ascii_art[index++] = '\n';
    }
    ascii_art[index] = '\0';

    return ascii_art;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input image> <output ASCII art>\n", argv[0]);
        exit(1);
    }

    image img = load_image(argv[1]);
    char *ascii_art = convert_image_to_ascii(img);

    FILE *fp = fopen(argv[2], "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", argv[2]);
        exit(1);
    }

    fprintf(fp, "%s", ascii_art);
    fclose(fp);

    free(ascii_art);

    return 0;
}