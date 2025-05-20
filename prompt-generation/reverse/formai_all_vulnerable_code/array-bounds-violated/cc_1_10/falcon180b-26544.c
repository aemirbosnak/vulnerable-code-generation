//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define CHAR_SET "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

typedef struct {
    int width, height;
    unsigned char *data;
} image_t;

void load_image(const char *filename, image_t *img) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open file '%s'.\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = malloc(size);
    fread(img->data, 1, size, fp);
    fclose(fp);

    int header_size = *(int *)img->data;
    img->width = *(int *)(img->data + 4);
    img->height = *(int *)(img->data + 8);
}

void save_ascii_art(const char *filename, const image_t *img) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: Cannot open file '%s'.\n", filename);
        exit(1);
    }

    int x, y;
    for (y = 0; y < img->height; ++y) {
        for (x = 0; x < img->width; ++x) {
            int index = (y * img->width + x) * 3;
            int r = img->data[index];
            int g = img->data[index + 1];
            int b = img->data[index + 2];

            int brightness = (r + g + b) / 3;
            if (brightness < 128) {
                fprintf(fp, " ");
            } else {
                fprintf(fp, "%c", CHAR_SET[brightness % 63]);
            }
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input.png output.txt\n", argv[0]);
        return 1;
    }

    image_t img;
    load_image(argv[1], &img);
    save_ascii_art(argv[2], &img);

    return 0;
}