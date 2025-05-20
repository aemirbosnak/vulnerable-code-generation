//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

typedef struct {
    char *data;
    int width;
    int height;
} image_t;

void load_image(image_t *img, char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = malloc(size);
    fread(img->data, size, 1, fp);
    fclose(fp);

    img->width = WIDTH;
    img->height = HEIGHT;
}

void save_ascii_art(image_t *img, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error: Could not open file %s.\n", filename);
        exit(1);
    }

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            char c = img->data[y * img->width + x];
            fprintf(fp, "%c", c);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    image_t img;
    load_image(&img, argv[1]);
    save_ascii_art(&img, argv[2]);

    return 0;
}