//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 40
#define MAX_CHARS (MAX_WIDTH * MAX_HEIGHT)

typedef struct {
    int width;
    int height;
    char *data;
} Image;

void load_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    img->data = malloc(filesize);
    fread(img->data, filesize, 1, fp);
    fclose(fp);

    img->width = atoi((char*)img->data);
    img->height = atoi((char*)(img->data + 4));
}

void free_image(Image *img) {
    free(img->data);
}

void print_ascii_art(const char *art, int x, int y) {
    int i;
    for (i = 0; i < strlen(art); i++) {
        printf("%c", art[i]);
        if (++x >= MAX_WIDTH) {
            printf("\n");
            x = 0;
        }
    }
}

int main() {
    Image img;
    load_image(&img, "image.bin");

    int x = 0, y = 0;
    int c = 0;
    int width = img.width;
    int height = img.height;
    char *data = img.data;

    while (y < height) {
        while (x < width) {
            char ascii = data[c++];
            if (ascii == 0) {
                printf("\n");
                x = 0;
                y++;
            } else {
                printf("%c", ascii);
                x++;
            }
        }
        printf("\n");
        x = 0;
        y++;
    }

    free_image(&img);

    return 0;
}