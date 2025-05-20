//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

image *load_image(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    char header[2];
    fread(header, 1, 2, f);
    if (header[0] != 'P' || header[1] != '6') {
        printf("Error: Invalid file format\n");
        fclose(f);
        return NULL;
    }

    int width, height;
    fscanf(f, "%d %d\n", &width, &height);

    int max_value;
    fscanf(f, "%d\n", &max_value);

    if (max_value != 255) {
        printf("Error: Invalid max value\n");
        fclose(f);
        return NULL;
    }

    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(pixel));
    fread(img->data, sizeof(pixel), width * height, f);
    fclose(f);

    return img;
}

void free_image(image *img) {
    free(img->data);
    free(img);
}

char *to_ascii(pixel p) {
    static char *ascii_chars = " .,-~:;!@#$%^&*()_+=-`";
    int index = (p.r + p.g + p.b) / 3 / 32;
    return &ascii_chars[index];
}

void print_ascii_image(image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            printf("%s", to_ascii(img->data[y * img->width + x]));
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    image *img = load_image(argv[1]);
    if (!img) {
        printf("Error: Could not load image\n");
        return 1;
    }

    print_ascii_image(img);
    free_image(img);

    return 0;
}