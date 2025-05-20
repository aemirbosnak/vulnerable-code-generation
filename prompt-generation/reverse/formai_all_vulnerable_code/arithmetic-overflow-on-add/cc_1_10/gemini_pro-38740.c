//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 80  // Desired output width, characters
#define HEIGHT 24 // Desired output height, cells

typedef struct {
    int w;
    int h;
    unsigned char *data;
} Image;

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(file);
        return NULL;
    }

    fread(&image->w, sizeof(int), 1, file);
    fread(&image->h, sizeof(int), 1, file);

    image->data = malloc(image->w * image->h);
    if (!image->data) {
        fclose(file);
        free(image);
        return NULL;
    }

    fread(image->data, sizeof(unsigned char), image->w * image->h, file);
    fclose(file);
    return image;
}

void free_image(Image *image) {
    if (!image) return;
    free(image->data);
    free(image);
}

void draw_image(Image *image) {
    for (int y = 0; y < image->h; ++y) {
        for (int x = 0; x < image->w; ++x) {
            unsigned char pixel = image->data[y * image->w + x];
            printf("%c", pixel);
        }
        printf("\n");
    }
}

void shift_image(Image *image, int sx, int sy) {
    unsigned char *new_data = malloc(image->w * image->h);
    if (!new_data) return;

    for (int y = 0; y < image->h; ++y) {
        for (int x = 0; x < image->w; ++x) {
            int new_x = (x + sx) % image->w;
            int new_y = (y + sy) % image->h;
            new_data[y * image->w + x] = image->data[new_y * image->w + new_x];
        }
    }

    free(image->data);
    image->data = new_data;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        printf("Error loading image.\n");
        return 1;
    }

    const int max_shift = 10;
    for (int sy = -max_shift; sy <= max_shift; ++sy) {
        for (int sx = -max_shift; sx <= max_shift; ++sx) {
            shift_image(image, sx, sy);
            draw_image(image);
            printf("\n");
        }
    }

    free_image(image);
    return 0;
}