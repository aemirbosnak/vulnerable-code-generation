//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define PIXEL_TYPE unsigned char

typedef struct {
    int width;
    int height;
    PIXEL_TYPE *data;
} Image;

Image *read_image(char *filename) {
    Image *image = malloc(sizeof(Image));
    FILE *file = fopen(filename, "rb");
    assert(file != NULL);

    // Read the header
    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);

    // Allocate memory for the data
    image->data = malloc(image->width * image->height * sizeof(PIXEL_TYPE));

    // Read the data
    fread(image->data, sizeof(PIXEL_TYPE), image->width * image->height, file);

    fclose(file);

    return image;
}

void write_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    assert(file != NULL);

    // Write the header
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    // Write the data
    fwrite(image->data, sizeof(PIXEL_TYPE), image->width * image->height, file);

    fclose(file);
}

void flip_image_horizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            PIXEL_TYPE temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - 1 - x];
            image->data[y * image->width + image->width - 1 - x] = temp;
        }
    }
}

void flip_image_vertical(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            PIXEL_TYPE temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - 1 - y) * image->width + x];
            image->data[(image->height - 1 - y) * image->width + x] = temp;
        }
    }
}

void change_brightness_contrast(Image *image, double brightness, double contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->data[y * image->width + x] = (PIXEL_TYPE) ((image->data[y * image->width + x] - 128) * contrast + 128 + brightness);
        }
    }
}

int main() {
    Image *image = read_image("image.bmp");

    flip_image_horizontal(image);
    flip_image_vertical(image);
    change_brightness_contrast(image, 50, 1.5);

    write_image(image, "new_image.bmp");

    free(image->data);
    free(image);

    return 0;
}