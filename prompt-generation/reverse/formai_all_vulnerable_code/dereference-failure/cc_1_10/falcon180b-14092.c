//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    int x, y;
} Point;

typedef struct {
    char *data;
    int width, height;
} Image;

void load_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    img->width = ftell(fp) / 3;
    img->height = 1;
    img->data = malloc(img->width * img->height * 2 + 1);

    rewind(fp);
    fread(img->data, 1, img->width * img->height * 2, fp);
    fclose(fp);
}

void save_ascii_art(Image *img, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int c = img->data[y * img->width * 2 + x * 2];
            fprintf(fp, "%c", c < 32? '.' : c > 126? '?' : c);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

void print_ascii_art(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int c = img->data[y * img->width * 2 + x * 2];
            printf("%c", c < 32? '.' : c > 126? '?' : c);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    Image img;
    load_image(&img, argv[1]);

    char *output_filename = argv[2];
    save_ascii_art(&img, output_filename);

    printf("ASCII art saved to file '%s'\n", output_filename);

    return 0;
}