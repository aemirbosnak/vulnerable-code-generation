//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    unsigned char r, g, b;
} Color;

typedef struct {
    int width, height;
    Color *data;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "P3\n%d %d\n255\n", &image->width, &image->height);
    image->data = malloc(image->width * image->height * sizeof(Color));
    if (!image->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(fp);
        free(image);
        return NULL;
    }

    for (int i = 0; i < image->width * image->height; i++) {
        fscanf(fp, "%hhu %hhu %hhu\n", &image->data[i].r, &image->data[i].g, &image->data[i].b);
    }

    fclose(fp);
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

char *convert_image_to_ascii(Image *image) {
    char *ascii = malloc(image->width * image->height + 1);
    if (!ascii) {
        fprintf(stderr, "Error: could not allocate memory for ASCII art\n");
        return NULL;
    }

    for (int i = 0; i < image->width * image->height; i++) {
        double brightness = (image->data[i].r + image->data[i].g + image->data[i].b) / 3.0;
        char c;
        if (brightness < 32) {
            c = ' ';
        } else if (brightness < 64) {
            c = '.';
        } else if (brightness < 96) {
            c = ',';
        } else if (brightness < 128) {
            c = ':';
        } else if (brightness < 160) {
            c = ';';
        } else if (brightness < 192) {
            c = '=';
        } else if (brightness < 224) {
            c = '+';
        } else {
            c = '#';
        }
        ascii[i] = c;
    }

    ascii[image->width * image->height] = '\0';
    return ascii;
}

void print_ascii_art(char *ascii) {
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        if (i % WIDTH == 0) {
            putchar('\n');
        }
        putchar(ascii[i]);
    }
    putchar('\n');
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    char *ascii = convert_image_to_ascii(image);
    if (!ascii) {
        free_image(image);
        return 1;
    }

    print_ascii_art(ascii);

    free(ascii);
    free_image(image);
    return 0;
}