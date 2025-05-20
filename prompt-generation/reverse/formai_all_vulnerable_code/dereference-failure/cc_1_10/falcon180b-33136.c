//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS ".:-=+*#%@"

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

void load_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    img->data = malloc(filesize);
    fread(img->data, filesize, 1, fp);

    fclose(fp);

    int header_size = 54;
    char *header = malloc(header_size);
    memset(header, 0, header_size);
    fseek(fp, 0, SEEK_SET);
    fread(header, header_size, 1, fp);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    img->width = width;
    img->height = height;
}

void free_image(Image *img) {
    free(img->data);
}

void print_ascii_art(Image *img, int scale) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int idx = (y * img->width + x) * 3;
            int r = img->data[idx];
            int g = img->data[idx + 1];
            int b = img->data[idx + 2];

            int brightness = (int)round(0.299 * r + 0.587 * g + 0.114 * b);

            printf("%c", ASCII_CHARS[brightness / (MAX_WIDTH * scale)]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    Image img;
    load_image(&img, argv[1]);

    char *output_filename = argv[2];
    FILE *fp = fopen(output_filename, "w");
    if (fp == NULL) {
        printf("Error: Failed to open file %s\n", output_filename);
        exit(1);
    }

    print_ascii_art(&img, 1);

    fclose(fp);

    free_image(&img);

    return 0;
}