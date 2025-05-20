//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    int width;
    int height;
    char *data;
} Image;

void load_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    img->data = malloc(filesize);
    if (img->data == NULL) {
        printf("Error: Could not allocate memory for image data\n");
        exit(1);
    }

    fread(img->data, filesize, 1, fp);
    fclose(fp);

    img->width = *(int *)img->data;
    img->height = *(int *)(img->data + 4);
}

void free_image(Image *img) {
    free(img->data);
}

void print_ascii_art(const Image *img) {
    const int stride = img->width * 3;
    const int height = img->height;
    const unsigned char *data = img->data + 8;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            const int index = y * stride + x * 3;
            const unsigned char r = data[index];
            const unsigned char g = data[index + 1];
            const unsigned char b = data[index + 2];

            int brightness = (r + g + b) / 3;
            if (brightness < 0) brightness = 0;
            if (brightness > MAX_WIDTH) brightness = MAX_WIDTH;

            printf("%*c", brightness, " ");
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    Image img;
    load_image(&img, argv[1]);

    FILE *fp = fopen(argv[2], "w");
    if (fp == NULL) {
        printf("Error: Could not open file '%s' for writing\n", argv[2]);
        exit(1);
    }

    print_ascii_art(&img);
    fclose(fp);

    free_image(&img);

    return 0;
}