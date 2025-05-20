//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *load_image(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(f);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, f);
    fread(&image->height, sizeof(int), 1, f);
    image->data = malloc(image->width * image->height);
    if (!image->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(f);
        free(image);
        return NULL;
    }

    fread(image->data, image->width * image->height, 1, f);
    fclose(f);

    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(int), 1, f);
    fwrite(&image->height, sizeof(int), 1, f);
    fwrite(image->data, image->width * image->height, 1, f);
    fclose(f);
}

void flip_image(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - i - 1) * image->width + j];
            image->data[(image->height - i - 1) * image->width + j] = temp;
        }
    }
}

void change_brightness(Image *image, double brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->data[i * image->width + j] = (unsigned char) (image->data[i * image->width + j] * brightness);
        }
    }
}

void change_contrast(Image *image, double contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->data[i * image->width + j] = (unsigned char) ((image->data[i * image->width + j] - 127.5) * contrast + 127.5);
        }
    }
}

int main() {
    Image *image = load_image("image.bmp");
    if (!image) {
        return 1;
    }

    flip_image(image);
    change_brightness(image, 1.2);
    change_contrast(image, 1.5);

    save_image("output.bmp", image);

    free(image->data);
    free(image);

    return 0;
}