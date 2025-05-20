//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000
#define MAX_COLORS 256

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

typedef struct {
    unsigned int width;
    unsigned int height;
    Color pixels[MAX_WIDTH][MAX_HEIGHT];
} Image;

Image *read_image(char *filename) {
    FILE *fp;
    Image *image;
    int i, j;

    fp = fopen(filename, "rb");
    if (!fp) {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }

    image = malloc(sizeof(Image));
    if (!image) {
        printf("Error: could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "%u %u\n", &image->width, &image->height);
    if (image->width > MAX_WIDTH || image->height > MAX_HEIGHT) {
        printf("Error: image is too large\n");
        fclose(fp);
        free(image);
        return NULL;
    }

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            fscanf(fp, "%hhu %hhu %hhu ", &image->pixels[j][i].red, &image->pixels[j][i].green, &image->pixels[j][i].blue);
        }
    }

    fclose(fp);

    return image;
}

void write_image(Image *image, char *filename) {
    FILE *fp;
    int i, j;

    fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: could not open file %s\n", filename);
        return;
    }

    fprintf(fp, "%u %u\n", image->width, image->height);

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            fprintf(fp, "%hhu %hhu %hhu ", image->pixels[j][i].red, image->pixels[j][i].green, image->pixels[j][i].blue);
        }
    }

    fclose(fp);
}

Image *convert_image_to_ascii(Image *image) {
    Image *ascii_image;
    int i, j;

    ascii_image = malloc(sizeof(Image));
    if (!ascii_image) {
        printf("Error: could not allocate memory for ascii image\n");
        return NULL;
    }

    ascii_image->width = image->width;
    ascii_image->height = image->height;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            ascii_image->pixels[j][i].red = (image->pixels[j][i].red + image->pixels[j][i].green + image->pixels[j][i].blue) / 3;
            ascii_image->pixels[j][i].green = ascii_image->pixels[j][i].red;
            ascii_image->pixels[j][i].blue = ascii_image->pixels[j][i].red;
        }
    }

    return ascii_image;
}

void print_image(Image *image) {
    int i, j;

    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            printf("%c", "#$@%;:-`'.,         "[image->pixels[j][i].red / 32]);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    Image *image, *ascii_image;

    if (argc != 3) {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    ascii_image = convert_image_to_ascii(image);
    if (!ascii_image) {
        free(image);
        return 1;
    }

    print_image(ascii_image);

    write_image(ascii_image, argv[2]);

    free(image);
    free(ascii_image);

    return 0;
}