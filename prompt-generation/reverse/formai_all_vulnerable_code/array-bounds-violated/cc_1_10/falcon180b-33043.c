//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS ".:-=+*#%@"

typedef struct {
    int width;
    int height;
    unsigned char *data;
} image_t;

image_t *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    rewind(fp);

    unsigned char *buffer = (unsigned char *) malloc(filesize);
    if (buffer == NULL) {
        printf("Error: Cannot allocate memory for image data\n");
        exit(1);
    }

    fread(buffer, filesize, 1, fp);
    fclose(fp);

    image_t *image = (image_t *) malloc(sizeof(image_t));
    image->width = filesize / 3;
    image->height = 1;
    image->data = buffer;

    return image;
}

void free_image(image_t *image) {
    free(image->data);
    free(image);
}

void print_ascii_art(const image_t *image) {
    int max_value = image->height * image->width;
    int ascii_index = 0;

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int value = image->data[y * image->width + x] * max_value / 255;
            printf("%c", ASCII_CHARS[ascii_index + value / 10]);
        }
        printf("\n");
    }
}

int main() {
    image_t *image = load_image("example.bmp");
    print_ascii_art(image);
    free_image(image);

    return 0;
}