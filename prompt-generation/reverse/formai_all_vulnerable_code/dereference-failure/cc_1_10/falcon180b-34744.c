//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void load_image(Image *img, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
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

void free_image(Image *img) {
    free(img->data);
}

void print_ascii_art(Image *img) {
    int x, y;
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            int value = *(unsigned char *)(img->data + y * img->width + x) / 16;
            printf("%c", value < 10? '0' + value : 'A' + value - 10);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_image output_ascii_art\n", argv[0]);
        return 1;
    }

    Image img;
    load_image(&img, argv[1]);

    char *output_filename = argv[2];
    FILE *fp = fopen(output_filename, "w");
    if (fp == NULL) {
        printf("Error: could not open file '%s' for writing\n", output_filename);
        free_image(&img);
        return 1;
    }

    print_ascii_art(&img);

    fclose(fp);
    free_image(&img);

    printf("ASCII art saved to '%s'\n", output_filename);
    return 0;
}