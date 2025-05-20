//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file \"%s\"\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(file);
        return NULL;
    }

    // Read the header
    if (fscanf(file, "P5\n%d %d\n255\n", &image->width, &image->height) != 3) {
        fprintf(stderr, "Error: could not read header from file \"%s\"\n", filename);
        fclose(file);
        free(image);
        return NULL;
    }

    // Allocate memory for the image data
    image->data = malloc(image->width * image->height);
    if (!image->data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(file);
        free(image);
        return NULL;
    }

    // Read the image data
    if (fread(image->data, 1, image->width * image->height, file) != image->width * image->height) {
        fprintf(stderr, "Error: could not read image data from file \"%s\"\n", filename);
        fclose(file);
        free(image->data);
        free(image);
        return NULL;
    }

    fclose(file);
    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file \"%s\"\n", filename);
        return;
    }

    // Write the header
    fprintf(file, "P5\n%d %d\n255\n", image->width, image->height);

    // Write the image data
    fwrite(image->data, 1, image->width * image->height, file);

    fclose(file);
}

void flip_image(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - 1 - y) * image->width + x];
            image->data[(image->height - 1 - y) * image->width + x] = temp;
        }
    }
}

void adjust_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->width * image->height; i++) {
        int value = (int)image->data[i] + brightness;
        if (value < 0) {
            value = 0;
        } else if (value > 255) {
            value = 255;
        }
        image->data[i] = (unsigned char)value;
    }
}

void adjust_contrast(Image *image, double contrast) {
    for (int i = 0; i < image->width * image->height; i++) {
        int value = (int)(128 + contrast * (image->data[i] - 128));
        if (value < 0) {
            value = 0;
        } else if (value > 255) {
            value = 255;
        }
        image->data[i] = (unsigned char)value;
    }
}

int main() {
    Image *image = read_image("input.pgm");
    if (!image) {
        return EXIT_FAILURE;
    }

    // Flip the image
    flip_image(image);

    // Adjust the brightness
    adjust_brightness(image, 50);

    // Adjust the contrast
    adjust_contrast(image, 1.5);

    // Write the image to a file
    write_image(image, "output.pgm");

    free(image->data);
    free(image);
    return EXIT_SUCCESS;
}