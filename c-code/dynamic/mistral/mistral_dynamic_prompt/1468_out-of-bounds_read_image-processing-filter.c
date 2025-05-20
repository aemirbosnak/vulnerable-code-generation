#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct Image {
    unsigned char *data;
    int width;
    int height;
} Image;

Image load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    fseek(file, 18, SEEK_SET); // Skip file header

    Image img;
    img.width = *(int *)malloc(4);
    fread(&(img.width), sizeof(int), 1, file);
    img.height = *(int *)malloc(4);
    fread(&(img.height), sizeof(int), 1, file);

    img.data = malloc(img.width * img.height);
    fread(img.data, 1, img.width * img.height, file);
    fclose(file);

    return img;
}

void gray_scale(Image *img) {
    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            img->data[y * img->width + x] = (unsigned char)0.3 * img->data[y * img->width + x] +
                                            0.59 * img->data[y * img->width + x] +
                                            0.11 * img->data[y * img->width + x];
        }
    }
}

int main(int argc, char **argv) {
    Image img = load_image(argv[1]);

    gray_scale(&img);

    // Intentionally out-of-bounds read
    printf("%c\n", img.data[(img.width + 1) * img.height]);

    free(img.data);
    free(img.width);
    free(img.height);
    return 0;
}
