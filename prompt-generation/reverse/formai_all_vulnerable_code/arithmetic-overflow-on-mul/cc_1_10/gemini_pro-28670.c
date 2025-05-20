//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
    int channels;
} Image;

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: failed to open file '%s'.\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[54];
    fread(header, 1, 54, file);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: '%s' is not a valid BMP file.\n", filename);
        fclose(file);
        return NULL;
    }

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int channels = 3;

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * channels);
    image->width = width;
    image->height = height;
    image->channels = channels;

    // Read the image data
    fread(image->data, 1, width * height * channels, file);

    // Close the file
    fclose(file);

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void flip_image(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int c = 0; c < image->channels; c++) {
                int index1 = (i * image->width + j) * image->channels + c;
                int index2 = ((image->height - i - 1) * image->width + j) * image->channels + c;
                unsigned char temp = image->data[index1];
                image->data[index1] = image->data[index2];
                image->data[index2] = temp;
            }
        }
    }
}

void adjust_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int c = 0; c < image->channels; c++) {
                int index = (i * image->width + j) * image->channels + c;
                int value = image->data[index] + brightness;
                image->data[index] = (value < 0) ? 0 : (value > 255) ? 255 : value;
            }
        }
    }
}

void adjust_contrast(Image *image, double contrast) {
    double factor = (contrast - 1) / 127;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int c = 0; c < image->channels; c++) {
                int index = (i * image->width + j) * image->channels + c;
                double value = (image->data[index] - 127) * factor + 127;
                image->data[index] = (value < 0) ? 0 : (value > 255) ? 255 : value;
            }
        }
    }
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: failed to open file '%s'.\n", filename);
        return;
    }

    // Write the header
    unsigned char header[54];
    memset(header, 0, 54);
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[2] = 54 + image->width * image->height * 3;
    *(int *)&header[10] = 54;
    *(int *)&header[14] = 40;
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    *(short *)&header[26] = 1;
    *(short *)&header[28] = 24;
    *(int *)&header[34] = image->width * image->height * 3;
    fwrite(header, 1, 54, file);

    // Write the image data
    fwrite(image->data, 1, image->width * image->height * image->channels, file);

    // Close the file
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Flip the image
    flip_image(image);

    // Adjust the brightness
    adjust_brightness(image, 30);

    // Adjust the contrast
    adjust_contrast(image, 1.5);

    // Save the output image
    save_image(image, argv[2]);

    // Free the image data
    free_image(image);

    return 0;
}