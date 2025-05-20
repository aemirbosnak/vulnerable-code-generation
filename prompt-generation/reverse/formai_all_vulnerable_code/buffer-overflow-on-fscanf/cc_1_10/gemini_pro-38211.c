//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    unsigned char *data;
    int width, height;
} Image;

void flip_image(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - x - 1];
            image->data[y * image->width + image->width - x - 1] = temp;
        }
    }
}

void change_brightness(Image *image, double factor) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = (unsigned char)round(image->data[i] * factor);
    }
}

void change_contrast(Image *image, double factor) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = (unsigned char)round((image->data[i] - 128) * factor + 128);
    }
}

void save_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fprintf(fp, "P5\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, image->width * image->height, 1, fp);
    fclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <operation>\n", argv[0]);
        return 1;
    }

    Image image;
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("Error opening input image");
        exit(1);
    }

    fscanf(fp, "P5\n%d %d\n255\n", &image.width, &image.height);
    image.data = malloc(image.width * image.height);
    fread(image.data, image.width * image.height, 1, fp);
    fclose(fp);

    if (strcmp(argv[3], "flip") == 0) {
        flip_image(&image);
    } else if (strcmp(argv[3], "brightness") == 0) {
        double factor = atof(argv[2]);
        change_brightness(&image, factor);
    } else if (strcmp(argv[3], "contrast") == 0) {
        double factor = atof(argv[2]);
        change_contrast(&image, factor);
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[3]);
        return 1;
    }

    save_image(&image, argv[2]);
    free(image.data);
    return 0;
}