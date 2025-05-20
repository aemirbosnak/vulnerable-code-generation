//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void load_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = malloc(filesize);
    fread(img->data, filesize, 1, fp);
    fclose(fp);

    int header_size = *(int *)img->data;
    if (header_size!= filesize - 4) {
        printf("Error: invalid image file\n");
        exit(1);
    }

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
            int value = *(int *)(img->data + y * img->width + x) >> 16;
            int ascii_value = value % 94 + 33;

            if (ascii_value == 127) {
                ascii_value = 126;
            }

            printf("%c", ascii_value);
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
    if (!fp) {
        printf("Error: could not open file '%s' for writing\n", output_filename);
        exit(1);
    }

    print_ascii_art(&img);

    fclose(fp);
    free_image(&img);

    return 0;
}