//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(unsigned char));
    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: invalid BMP file '%s'\n", filename);
        fclose(file);
        return NULL;
    }

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Create the image
    Image *image = new_image(width, height);

    // Read the image data
    fread(image->data, sizeof(unsigned char), width * height, file);

    fclose(file);

    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return;
    }

    // Write the header
    unsigned char header[54];
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[2] = sizeof(header) + image->width * image->height;
    *(int *)&header[10] = sizeof(header);
    *(int *)&header[14] = 40;
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    header[26] = 1;
    header[28] = 24;
    header[34] = image->width * image->height * 3;
    fwrite(header, sizeof(unsigned char), 54, file);

    // Write the image data
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, file);

    fclose(file);
}

void flip_image(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char tmp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = tmp;
        }
    }
}

void change_brightness(Image *image, int brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->data[y * image->width + x] += brightness;
        }
    }
}

void change_contrast(Image *image, double contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->data[y * image->width + x] = image->data[y * image->width + x] * contrast;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_image.bmp> [output_image.bmp]\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    flip_image(image);
    change_brightness(image, 50);
    change_contrast(image, 1.5);

    if (argc >= 3) {
        save_image(argv[2], image);
    } else {
        save_image("output.bmp", image);
    }

    free_image(image);

    return 0;
}