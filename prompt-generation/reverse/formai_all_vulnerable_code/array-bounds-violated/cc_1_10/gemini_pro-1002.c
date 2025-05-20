//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
    int channels;
} Image;

Image *read_image(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[14];
    fread(header, sizeof(unsigned char), 14, file);

    // Check if the file is a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error reading file: not a BMP file\n");
        fclose(file);
        return NULL;
    }

    // Get the image dimensions and channels
    int width = *((int *)&header[18]);
    int height = *((int *)&header[22]);
    int channels = header[28] / 8;

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * channels);

    // Read the image data
    fread(image->data, sizeof(unsigned char), width * height * channels, file);

    // Close the file
    fclose(file);

    // Return the image
    return image;
}

void write_image(const char *filename, Image *image) {
    // Open the file
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[14] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0
    };
    fwrite(header, sizeof(unsigned char), 14, file);

    // Write the dimensions and channels
    int width = image->width;
    int height = image->height;
    int channels = image->channels;
    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);
    fwrite(&channels, sizeof(int), 1, file);

    // Write the image data
    fwrite(image->data, sizeof(unsigned char), width * height * channels, file);

    // Close the file
    fclose(file);
}

void flip_image(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                unsigned char temp = image->data[i * image->width * image->channels + j * image->channels + k];
                image->data[i * image->width * image->channels + j * image->channels + k] = image->data[(image->height - 1 - i) * image->width * image->channels + j * image->channels + k];
                image->data[(image->height - 1 - i) * image->width * image->channels + j * image->channels + k] = temp;
            }
        }
    }
}

void change_brightness(Image *image, double brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                image->data[i * image->width * image->channels + j * image->channels + k] = (unsigned char)fmin(255, fmax(0, image->data[i * image->width * image->channels + j * image->channels + k] + brightness));
            }
        }
    }
}

void change_contrast(Image *image, double contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < image->channels; k++) {
                image->data[i * image->width * image->channels + j * image->channels + k] = (unsigned char)fmin(255, fmax(0, 128 + contrast * (image->data[i * image->width * image->channels + j * image->channels + k] - 128)));
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input filename> <output filename> <brightness>\n", argv[0]);
        return 1;
    }

    // Read the input image
    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Flip the image
    flip_image(image);

    // Change the brightness
    change_brightness(image, atof(argv[3]));

    // Change the contrast
    change_contrast(image, atof(argv[3]));

    // Write the output image
    write_image(argv[2], image);

    // Free the image data
    free(image->data);
    free(image);

    return 0;
}