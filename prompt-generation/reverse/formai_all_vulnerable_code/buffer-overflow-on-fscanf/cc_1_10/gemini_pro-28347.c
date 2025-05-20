//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel *data;
} image;

image *read_image(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    image *img = malloc(sizeof(image));
    if (!img) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d\n", &img->width, &img->height);
    if (img->width <= 0 || img->width > MAX_WIDTH || img->height <= 0 || img->height > MAX_HEIGHT) {
        fprintf(stderr, "Invalid image dimensions\n");
        free(img);
        fclose(file);
        return NULL;
    }

    img->data = malloc(img->width * img->height * sizeof(pixel));
    if (!img->data) {
        fprintf(stderr, "Error allocating memory for image data\n");
        free(img);
        fclose(file);
        return NULL;
    }

    fread(img->data, sizeof(pixel), img->width * img->height, file);
    fclose(file);

    return img;
}

void write_image(image *img, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fprintf(file, "%d %d\n", img->width, img->height);
    fwrite(img->data, sizeof(pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image_horizontal(image *img) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width / 2; j++) {
            pixel temp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[i * img->width + img->width - j - 1];
            img->data[i * img->width + img->width - j - 1] = temp;
        }
    }
}

void flip_image_vertical(image *img) {
    int i, j;
    for (i = 0; i < img->height / 2; i++) {
        for (j = 0; j < img->width; j++) {
            pixel temp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[(img->height - i - 1) * img->width + j];
            img->data[(img->height - i - 1) * img->width + j] = temp;
        }
    }
}

void adjust_brightness(image *img, int brightness) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            img->data[i * img->width + j].r += brightness;
            img->data[i * img->width + j].g += brightness;
            img->data[i * img->width + j].b += brightness;

            if (img->data[i * img->width + j].r > 255) {
                img->data[i * img->width + j].r = 255;
            } else if (img->data[i * img->width + j].r < 0) {
                img->data[i * img->width + j].r = 0;
            }

            if (img->data[i * img->width + j].g > 255) {
                img->data[i * img->width + j].g = 255;
            } else if (img->data[i * img->width + j].g < 0) {
                img->data[i * img->width + j].g = 0;
            }

            if (img->data[i * img->width + j].b > 255) {
                img->data[i * img->width + j].b = 255;
            } else if (img->data[i * img->width + j].b < 0) {
                img->data[i * img->width + j].b = 0;
            }
        }
    }
}

void adjust_contrast(image *img, int contrast) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            img->data[i * img->width + j].r = (img->data[i * img->width + j].r - 128) * contrast / 128 + 128;
            img->data[i * img->width + j].g = (img->data[i * img->width + j].g - 128) * contrast / 128 + 128;
            img->data[i * img->width + j].b = (img->data[i * img->width + j].b - 128) * contrast / 128 + 128;

            if (img->data[i * img->width + j].r > 255) {
                img->data[i * img->width + j].r = 255;
            } else if (img->data[i * img->width + j].r < 0) {
                img->data[i * img->width + j].r = 0;
            }

            if (img->data[i * img->width + j].g > 255) {
                img->data[i * img->width + j].g = 255;
            } else if (img->data[i * img->width + j].g < 0) {
                img->data[i * img->width + j].g = 0;
            }

            if (img->data[i * img->width + j].b > 255) {
                img->data[i * img->width + j].b = 255;
            } else if (img->data[i * img->width + j].b < 0) {
                img->data[i * img->width + j].b = 0;
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    image *img = read_image(argv[1]);
    if (!img) {
        return 1;
    }

    flip_image_horizontal(img);
    flip_image_vertical(img);
    adjust_brightness(img, 50);
    adjust_contrast(img, 150);

    write_image(img, argv[2]);
    free(img->data);
    free(img);

    return 0;
}