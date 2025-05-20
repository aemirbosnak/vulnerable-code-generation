//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

image *read_image(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("fopen");
        return NULL;
    }

    int width, height;
    fscanf(f, "%d %d\n", &width, &height);

    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(sizeof(pixel) * width * height);

    fread(img->data, sizeof(pixel), width * height, f);

    fclose(f);

    return img;
}

void write_image(const char *filename, image *img) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        perror("fopen");
        return;
    }

    fprintf(f, "%d %d\n", img->width, img->height);
    fwrite(img->data, sizeof(pixel), img->width * img->height, f);

    fclose(f);
}

void flip_image(image *img) {
    for (int y = 0; y < img->height / 2; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel tmp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[(img->height - y - 1) * img->width + x];
            img->data[(img->height - y - 1) * img->width + x] = tmp;
        }
    }
}

void change_brightness(image *img, double factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char)(img->data[i].r * factor);
        img->data[i].g = (unsigned char)(img->data[i].g * factor);
        img->data[i].b = (unsigned char)(img->data[i].b * factor);
    }
}

void change_contrast(image *img, double factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char)((img->data[i].r - 128) * factor + 128);
        img->data[i].g = (unsigned char)((img->data[i].g - 128) * factor + 128);
        img->data[i].b = (unsigned char)((img->data[i].b - 128) * factor + 128);
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <operation> <value>\n", argv[0]);
        return 1;
    }

    image *img = read_image(argv[1]);
    if (!img) {
        return 1;
    }

    if (!strcmp(argv[3], "flip")) {
        flip_image(img);
    } else if (!strcmp(argv[3], "brightness")) {
        change_brightness(img, atof(argv[4]));
    } else if (!strcmp(argv[3], "contrast")) {
        change_contrast(img, atof(argv[4]));
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[3]);
        return 1;
    }

    write_image(argv[2], img);

    free(img->data);
    free(img);

    return 0;
}