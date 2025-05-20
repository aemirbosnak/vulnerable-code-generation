//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);
    image->data = malloc(image->width * image->height * 3);
    if (image->data == NULL) {
        perror("malloc");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, image->width * image->height * 3, 1, fp);
    fclose(fp);

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void flip_image_horizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            int index1 = (y * image->width + x) * 3;
            int index2 = (y * image->width + (image->width - x - 1)) * 3;
            for (int i = 0; i < 3; i++) {
                unsigned char temp = image->data[index1 + i];
                image->data[index1 + i] = image->data[index2 + i];
                image->data[index2 + i] = temp;
            }
        }
    }
}

void flip_image_vertical(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            int index1 = (y * image->width + x) * 3;
            int index2 = ((image->height - y - 1) * image->width + x) * 3;
            for (int i = 0; i < 3; i++) {
                unsigned char temp = image->data[index1 + i];
                image->data[index1 + i] = image->data[index2 + i];
                image->data[index2 + i] = temp;
            }
        }
    }
}

void change_brightness_contrast(Image *image, int brightness, int contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int index = (y * image->width + x) * 3;
            for (int i = 0; i < 3; i++) {
                int value = image->data[index + i] + brightness;
                value = value * contrast / 100;
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                image->data[index + i] = value;
            }
        }
    }
}

void save_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(image->data, image->width * image->height * 3, 1, fp);
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc < 5) {
        printf("Usage: %s <input image> <output image> <flip> <brightness> <contrast>\n", argv[0]);
        printf("flip: 0 for no flip, 1 for horizontal flip, 2 for vertical flip\n");
        return 1;
    }

    int flip = atoi(argv[3]);
    int brightness = atoi(argv[4]);
    int contrast = atoi(argv[5]);

    Image *image = load_image(argv[1]);
    if (image == NULL) {
        printf("Error loading image %s\n", argv[1]);
        return 1;
    }

    if (flip == 1) {
        flip_image_horizontal(image);
    } else if (flip == 2) {
        flip_image_vertical(image);
    }

    change_brightness_contrast(image, brightness, contrast);

    save_image(image, argv[2]);
    free_image(image);

    return 0;
}