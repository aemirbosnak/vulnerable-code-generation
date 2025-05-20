//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define MAX_CHARS (MAX_WIDTH * MAX_HEIGHT)

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

void read_image(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    img->data = malloc(size);
    if (!img->data) {
        fprintf(stderr, "Error: Could not allocate memory for image data\n");
        exit(1);
    }

    if (fread(img->data, 1, size, fp)!= size) {
        fprintf(stderr, "Error: Could not read image data from file '%s'\n", filename);
        exit(1);
    }

    fclose(fp);

    img->width = *(int *)img->data;
    img->height = *(int *)(img->data + 4);
}

void write_ascii_art(const Image *img, FILE *fp) {
    int x, y;
    for (y = 0; y < img->height; ++y) {
        for (x = 0; x < img->width; ++x) {
            int value = *(int *)(img->data + y * img->width + x) & 0xFF;
            char c = (value < 16)? '.' : (value < 32)? '.' : (value < 64)? ':' : '-';
            fprintf(fp, "%c", c);
        }
        fprintf(fp, "\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    Image img;
    read_image(argv[1], &img);

    FILE *fp = fopen(argv[2], "w");
    if (!fp) {
        fprintf(stderr, "Error: Could not open file '%s' for writing\n", argv[2]);
        return 1;
    }

    write_ascii_art(&img, fp);
    fclose(fp);

    return 0;
}