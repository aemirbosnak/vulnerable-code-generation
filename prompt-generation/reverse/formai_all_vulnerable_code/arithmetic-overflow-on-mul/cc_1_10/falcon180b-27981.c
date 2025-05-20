//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24
#define ASCII_CHARS ".:-=+*#%@"

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void print_image(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            printf("%c", ASCII_CHARS[(int)image->data[i * image->width + j] / 32]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    unsigned char header[54];
    int width, height, channels, size;
    Image image;

    fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    fread(header, 1, 54, fp);

    width = *(int *)&header[18];
    height = *(int *)&header[22];
    channels = *(int *)&header[28];
    size = width * height * channels;

    image.data = malloc(size);
    image.width = width;
    image.height = height;

    fseek(fp, 54, SEEK_SET);
    fread(image.data, 1, size, fp);

    fclose(fp);

    print_image(&image);

    free(image.data);
    return 0;
}