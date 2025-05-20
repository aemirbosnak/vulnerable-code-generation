//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define CHAR_SET ".,:;=!@#$%^&*()_+-="

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void load_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = malloc(size);
    if (img->data == NULL) {
        printf("Error: could not allocate memory for image data\n");
        exit(1);
    }

    fread(img->data, 1, size, fp);
    fclose(fp);

    int width, height;
    if (sscanf(filename, "%dx%d.bmp", &width, &height)!= 2) {
        printf("Error: invalid filename format\n");
        exit(1);
    }

    img->width = width;
    img->height = height;
}

void save_ascii_art(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for writing\n", filename);
        exit(1);
    }

    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            int index = (y * img->width + x) * 3;
            int r = img->data[index];
            int g = img->data[index + 1];
            int b = img->data[index + 2];

            int brightness = (r + g + b) / 3;
            int ascii_char = CHAR_SET[brightness % strlen(CHAR_SET)];

            fputc(ascii_char, fp);
        }
        fputc('\n', fp);
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s input_image.bmp output_ascii_art.txt\n", argv[0]);
        return 1;
    }

    Image img;
    load_image(&img, argv[1]);
    save_ascii_art(&img, argv[2]);

    free(img.data);
    return 0;
}