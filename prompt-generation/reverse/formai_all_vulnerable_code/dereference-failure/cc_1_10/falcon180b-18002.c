//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
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
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = malloc(size);
    fread(img->data, 1, size, fp);
    fclose(fp);

    int width, height;
    if (fscanf(filename, "%dx%d", &width, &height)!= 2 || width <= 0 || height <= 0) {
        printf("Error: Invalid image dimensions.\n");
        exit(1);
    }

    img->width = width;
    img->height = height;
}

void free_image(Image *img) {
    free(img->data);
}

void print_ascii_art(const Image *img, int scale) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int index = (y * img->width + x) * 3;
            int r = img->data[index] * (255 / 31);
            int g = img->data[index + 1] * (255 / 63);
            int b = img->data[index + 2] * (255 / 31);

            int c = 0x00;

            if (r > 127 && g > 127 && b > 127) {
                c = 0x1b; // bold white
            } else if (r > 127 && g > 127) {
                c = 0x1c; // bold yellow
            } else if (r > 127) {
                c = 0x1d; // bold red
            } else if (g > 127 && b > 127) {
                c = 0x1e; // bold cyan
            } else if (g > 127) {
                c = 0x1f; // bold green
            } else if (b > 127) {
                c = 0x20; // bold blue
            } else {
                c = 0x20; // bold black
            }

            printf("%c", c);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <image_file> <scale>\n", argv[0]);
        return 1;
    }

    int scale = atoi(argv[2]);
    if (scale <= 0) {
        printf("Error: Invalid scale factor.\n");
        return 1;
    }

    Image img;
    load_image(&img, argv[1]);

    printf("ASCII art generated from image '%s':\n", argv[1]);
    print_ascii_art(&img, scale);

    free_image(&img);
    return 0;
}