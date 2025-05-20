//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    int width, height, channels;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    fscanf(fp, "P%d\n%d %d\n255\n", &image->channels, &image->width, &image->height);

    image->data = malloc(image->width * image->height * image->channels);
    if (!image->data) {
        perror("malloc");
        fclose(fp);
        free(image);
        return NULL;
    }

    fread(image->data, image->width * image->height * image->channels, 1, fp);
    fclose(fp);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    fprintf(fp, "P%d\n%d %d\n255\n", image->channels, image->width, image->height);
    fwrite(image->data, image->width * image->height * image->channels, 1, fp);
    fclose(fp);
}

void flip_image(Image *image) {
    int i, j, k;
    for (i = 0; i < image->height / 2; i++) {
        for (j = 0; j < image->width; j++) {
            for (k = 0; k < image->channels; k++) {
                unsigned char temp = image->data[i * image->width * image->channels + j * image->channels + k];
                image->data[i * image->width * image->channels + j * image->channels + k] = image->data[(image->height - i - 1) * image->width * image->channels + j * image->channels + k];
                image->data[(image->height - i - 1) * image->width * image->channels + j * image->channels + k] = temp;
            }
        }
    }
}

void change_brightness_contrast(Image *image, int brightness, float contrast) {
    int i, j, k;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            for (k = 0; k < image->channels; k++) {
                int value = image->data[i * image->width * image->channels + j * image->channels + k] + brightness;
                value = (value - 128) * contrast + 128;
                if (value < 0) value = 0;
                if (value > 255) value = 255;
                image->data[i * image->width * image->channels + j * image->channels + k] = value;
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <flip> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    if (strcmp(argv[3], "true") == 0) {
        flip_image(image);
    }

    change_brightness_contrast(image, atoi(argv[4]), atof(argv[5]));

    write_image(image, argv[2]);

    free(image->data);
    free(image);

    return 0;
}