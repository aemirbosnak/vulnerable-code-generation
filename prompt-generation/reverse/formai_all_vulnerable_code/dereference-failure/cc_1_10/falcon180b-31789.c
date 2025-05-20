//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void load_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image->data = malloc(size);
    fread(image->data, 1, size, fp);
    fclose(fp);

    image->width = WIDTH;
    image->height = HEIGHT;
}

void image_to_ascii(Image *image, char *ascii) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            int gray = (int)image->data[i * image->width + j] / 32;
            ascii[i * WIDTH + j] = (char)('@' + gray * ('A' - '@'));
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii>\n", argv[0]);
        return 1;
    }

    Image image;
    load_image(&image, argv[1]);

    char *ascii = malloc(WIDTH * HEIGHT);
    image_to_ascii(&image, ascii);

    FILE *fp = fopen(argv[2], "wb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", argv[2]);
        exit(1);
    }

    fwrite(ascii, 1, WIDTH * HEIGHT, fp);
    fclose(fp);

    printf("Conversion done.\n");
    return 0;
}