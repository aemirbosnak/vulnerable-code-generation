//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel_t;

typedef struct {
    size_t width;
    size_t height;
    pixel_t *data;
} image_t;

/* Read an image from a file. */
image_t *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    image_t *image = malloc(sizeof(image_t));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(fp);
        return NULL;
    }

    // Read the header.
    if (fscanf(fp, "P6\n%zu %zu\n255\n", &image->width, &image->height) != 3) {
        fprintf(stderr, "Error reading header from file %s\n", filename);
        free(image);
        fclose(fp);
        return NULL;
    }

    // Allocate memory for the data.
    image->data = malloc(sizeof(pixel_t) * image->width * image->height);
    if (image->data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        free(image);
        fclose(fp);
        return NULL;
    }

    // Read the data.
    if (fread(image->data, sizeof(pixel_t), image->width * image->height, fp) != image->width * image->height) {
        fprintf(stderr, "Error reading data from file %s\n", filename);
        free(image->data);
        free(image);
        fclose(fp);
        return NULL;
    }

    fclose(fp);
    return image;
}

/* Write an image to a file. */
int write_image(const char *filename, image_t *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return -1;
    }

    // Write the header.
    if (fprintf(fp, "P6\n%zu %zu\n255\n", image->width, image->height) < 0) {
        fprintf(stderr, "Error writing header to file %s\n", filename);
        fclose(fp);
        return -1;
    }

    // Write the data.
    if (fwrite(image->data, sizeof(pixel_t), image->width * image->height, fp) != image->width * image->height) {
        fprintf(stderr, "Error writing data to file %s\n", filename);
        fclose(fp);
        return -1;
    }

    fclose(fp);
    return 0;
}

/* Flip an image horizontally. */
void flip_horizontal(image_t *image) {
    for (size_t y = 0; y < image->height; y++) {
        for (size_t x = 0; x < image->width / 2; x++) {
            pixel_t temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - x - 1];
            image->data[y * image->width + image->width - x - 1] = temp;
        }
    }
}

/* Flip an image vertically. */
void flip_vertical(image_t *image) {
    for (size_t y = 0; y < image->height / 2; y++) {
        for (size_t x = 0; x < image->width; x++) {
            pixel_t temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

/* Change the brightness and contrast of an image. */
void adjust_brightness_contrast(image_t *image, double brightness, double contrast) {
    for (size_t i = 0; i < image->width * image->height; i++) {
        pixel_t *p = &image->data[i];
        p->r = (uint8_t)(p->r * contrast + brightness);
        p->g = (uint8_t)(p->g * contrast + brightness);
        p->b = (uint8_t)(p->b * contrast + brightness);
    }
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    image_t *image = read_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    // Flip the image horizontally and vertically.
    flip_horizontal(image);
    flip_vertical(image);

    // Adjust the brightness and contrast.
    adjust_brightness_contrast(image, -50, 1.5);

    // Write the image to a file.
    if (write_image(argv[2], image) != 0) {
        return 1;
    }

    free(image->data);
    free(image);
    return 0;
}