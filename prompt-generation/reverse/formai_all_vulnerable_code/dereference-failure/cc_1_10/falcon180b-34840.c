//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define CHAR_SET_SIZE 95

// Character set to use for ASCII art
char char_set[CHAR_SET_SIZE] = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

void load_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image->data = malloc(filesize);
    fread(image->data, 1, filesize, fp);
    fclose(fp);

    image->width = *(int *)image->data;
    image->height = *(int *)(image->data + 4);
}

void free_image(Image *image) {
    free(image->data);
}

void print_ascii_art(const Image *image, int x, int y, int scale) {
    unsigned char *data = image->data + 8; // Skip header

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int value = *(data++);
            int intensity = value * scale / 255;

            printf("%c", char_set[intensity]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <image_file> <scale>\n", argv[0]);
        return 1;
    }

    Image image;
    load_image(&image, argv[1]);

    int scale = atoi(argv[2]);
    if (scale <= 0 || scale > 255) {
        printf("Error: invalid scale value\n");
        return 1;
    }

    print_ascii_art(&image, 0, 0, scale);

    free_image(&image);
    return 0;
}