//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char *data;
    int width, height, channels;
} Image;

Image *load_image(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) return NULL;

    Image *image = malloc(sizeof(Image));
    fscanf(f, "P6\n%d %d\n255\n", &image->width, &image->height);
    image->channels = 3;
    image->data = malloc(image->width * image->height * image->channels);
    fread(image->data, image->width * image->height * image->channels, 1, f);
    fclose(f);

    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *f = fopen(filename, "wb");
    if (!f) return;

    fprintf(f, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, image->width * image->height * image->channels, 1, f);
    fclose(f);
}

void flip_image(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                unsigned char temp = image->data[i * image->width * image->channels + j * image->channels + k];
                image->data[i * image->width * image->channels + j * image->channels + k] = image->data[(image->height - i - 1) * image->width * image->channels + j * image->channels + k];
                image->data[(image->height - i - 1) * image->width * image->channels + j * image->channels + k] = temp;
            }
        }
    }
}

void change_brightness(Image *image, int delta) {
    for (int i = 0; i < image->width * image->height * image->channels; i++) {
        image->data[i] = (image->data[i] + delta) > 255 ? 255 : (image->data[i] + delta) < 0 ? 0 : image->data[i] + delta;
    }
}

void change_contrast(Image *image, float factor) {
    for (int i = 0; i < image->width * image->height * image->channels; i++) {
        image->data[i] = (image->data[i] - 128) * factor + 128;
    }
}

int main() {
    Image *image = load_image("input.ppm");
    if (!image) return 1;

    flip_image(image);
    change_brightness(image, 50);
    change_contrast(image, 1.5);

    save_image("output.ppm", image);
    free(image->data);
    free(image);

    return 0;
}