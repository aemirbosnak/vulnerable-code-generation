#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 1024
#define HEIGHT 768

typedef struct {
    unsigned char *data;
} Image;

void apply_filter(Image *img) {
    int width = WIDTH;
    int height = HEIGHT;
    unsigned char *pixels = img->data;

    // Simulate an image processing filter
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            pixels[index] = pixels[index] * 2; // Example operation
        }
    }
}

Image* load_image(const char *filename) {
    Image *img = malloc(sizeof(Image));
    if (!img) return NULL;

    img->data = malloc(WIDTH * HEIGHT);
    if (!img->data) {
        free(img);
        return NULL;
    }

    // Simulate loading image data
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        img->data[i] = rand() % 256;
    }

    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) return;

    fwrite(img->data, sizeof(unsigned char), WIDTH * HEIGHT, file);
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input output\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];

    Image *img = load_image(input_filename);
    if (!img) {
        printf("Failed to load image.\n");
        return 1;
    }

    apply_filter(img);

    save_image(output_filename, img);

    free(img->data);
    free(img);

    return 0;
}
