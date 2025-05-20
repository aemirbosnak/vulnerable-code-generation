//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    unsigned char *pixels;
    int width;
    int height;
} Image;

Image *create_image(int width, int height) {
    Image *image = (Image *) malloc(sizeof(Image));
    image->pixels = (unsigned char *) malloc(width * height);
    image->width = width;
    image->height = height;
    return image;
}

void destroy_image(Image *image) {
    free(image->pixels);
    free(image);
}

void read_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read the header
    unsigned char header[14];
    fread(header, 1, 14, fp);

    // Check if the file is a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a BMP file\n", filename);
        exit(1);
    }

    // Read the image dimensions
    int width = *(int *) &header[18];
    int height = *(int *) &header[22];

    // Read the image data
    fread(image->pixels, 1, width * height, fp);

    fclose(fp);
}

void write_image(Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    // Write the header
    unsigned char header[14] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 24, 0, 0, 0
    };
    *(int *) &header[2] = image->width * image->height * 3 + 14;
    *(int *) &header[18] = image->width;
    *(int *) &header[22] = image->height;
    fwrite(header, 1, 14, fp);

    // Write the image data
    fwrite(image->pixels, 1, image->width * image->height * 3, fp);

    fclose(fp);
}

void flip_image(Image *image) {
    int i, j;
    for (i = 0; i < image->height / 2; i++) {
        for (j = 0; j < image->width; j++) {
            unsigned char temp = image->pixels[i * image->width + j];
            image->pixels[i * image->width + j] = image->pixels[(image->height - 1 - i) * image->width + j];
            image->pixels[(image->height - 1 - i) * image->width + j] = temp;
        }
    }
}

void change_brightness_contrast(Image *image, float brightness, float contrast) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            image->pixels[i * image->width + j] = (unsigned char) (brightness * image->pixels[i * image->width + j] + contrast);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <brightness> <contrast>\n", argv[0]);
        exit(1);
    }

    Image *image = create_image(0, 0);
    read_image(image, argv[1]);

    flip_image(image);
    change_brightness_contrast(image, atof(argv[3]), atof(argv[4]));

    write_image(image, argv[2]);

    destroy_image(image);

    return 0;
}