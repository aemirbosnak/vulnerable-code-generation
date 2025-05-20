//Code Llama-13B DATASET v1.0 Category: Image to ASCII art converter ; Style: Claude Shannon
/*
 * Convert an image to ASCII art using Claude Shannon's algorithm
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ASCII_CHARS "@%#*+=-:. "
#define ASCII_CHARS_LEN 11

typedef struct {
    int width;
    int height;
    int **data;
} Image;

void read_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "r");
    fscanf(fp, "%d %d", &img->width, &img->height);
    img->data = malloc(img->width * sizeof(int *));
    for (int i = 0; i < img->width; i++) {
        img->data[i] = malloc(img->height * sizeof(int));
        for (int j = 0; j < img->height; j++) {
            fscanf(fp, "%d", &img->data[i][j]);
        }
    }
    fclose(fp);
}

void write_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height; j++) {
            int value = img->data[i][j];
            int index = round(value / 255.0 * (ASCII_CHARS_LEN - 1));
            fprintf(fp, "%c", ASCII_CHARS[index]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    Image img;
    read_image(&img, argv[1]);
    write_image(&img, argv[2]);
    return 0;
}