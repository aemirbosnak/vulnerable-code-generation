//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int width;
    int height;
    char *data;
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

    int width = 0, height = 0;
    char header[4] = {0};
    fseek(fp, 0, SEEK_SET);
    fread(header, 1, 4, fp);
    if (header[0] == 'B' && header[1] == 'M') {
        fseek(fp, 10, SEEK_SET);
        fread(&width, 4, 1, fp);
        fread(&height, 4, 1, fp);
        fclose(fp);
    } else {
        printf("Error: unsupported image format\n");
        exit(1);
    }

    img->width = width;
    img->height = height;
}

void save_ascii_art(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    int width = img->width;
    int height = img->height;
    int max_value = (int) ceil(log((double) height) / log(2.0));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel = (int) img->data[y * width + x];
            int char_value = (pixel >> (max_value - 1)) & 0x01;

            char c = (char) (char_value + '0');
            fputc(c, fp);
        }
        fputc('\n', fp);
    }

    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    Image img;
    load_image(&img, argv[1]);

    char *output_filename = argv[2];
    strcat(output_filename, ".txt");

    save_ascii_art(&img, output_filename);

    printf("ASCII art saved to '%s'\n", output_filename);

    free(img.data);
    return 0;
}