//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the image structure
typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[54];
    fread(header, sizeof(header), 1, file);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a valid BMP file\n", filename);
        fclose(file);
        return NULL;
    }

    // Read the image dimensions and channels
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];
    int channels = 1;

    // Read the image data
    unsigned char *data = (unsigned char *)malloc(width * height * channels);
    fread(data, width * height * channels, 1, file);

    fclose(file);

    // Create the image object
    Image *image = (Image *)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->channels = channels;
    image->data = data;

    return image;
}

// Save an image to a file
void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[54];
    memset(header, 0, sizeof(header));
    header[0] = 'B';
    header[1] = 'M';
    header[2] = sizeof(header) + image->width * image->height * image->channels;
    header[28] = sizeof(header);
    header[29] = 24;
    header[30] = 0;
    header[31] = 0;
    header[32] = 0;
    header[33] = 0;
    header[34] = 0;
    header[35] = 0;
    header[36] = 1;
    header[37] = 0;
    header[38] = image->width;
    header[39] = 0;
    header[40] = image->height;
    header[41] = 0;
    header[42] = 1;
    header[43] = 0;
    header[44] = 24;
    header[45] = 0;
    header[46] = 0;
    header[47] = 0;
    header[48] = 0;
    header[49] = 0;
    header[50] = 0;
    header[51] = 0;
    header[52] = 0;
    header[53] = 0;

    fwrite(header, sizeof(header), 1, file);

    // Write the image data
    fwrite(image->data, image->width * image->height * image->channels, 1, file);

    fclose(file);
}

// Flip an image horizontally
void flip_horizontal(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - j - 1];
            image->data[i * image->width + image->width - j - 1] = temp;
        }
    }
}

// Flip an image vertically
void flip_vertical(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - i - 1) * image->width + j];
            image->data[(image->height - i - 1) * image->width + j] = temp;
        }
    }
}

// Change the brightness of an image
void change_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int value = image->data[i * image->width + j] + brightness;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image->data[i * image->width + j] = value;
        }
    }
}

// Change the contrast of an image
void change_contrast(Image *image, float contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int value = (image->data[i * image->width + j] - 127.5) * contrast + 127.5;
            if (value < 0) {
                value = 0;
            } else if (value > 255) {
                value = 255;
            }
            image->data[i * image->width + j] = value;
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Check if the user specified an input image file
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input image file>\n", argv[0]);
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Flip the image horizontally
    flip_horizontal(image);

    // Flip the image vertically
    flip_vertical(image);

    // Change the brightness of the image
    change_brightness(image, 50);

    // Change the contrast of the image
    change_contrast(image, 1.5);

    // Save the output image
    save_image("output.bmp", image);

    // Free the image data
    free(image->data);
    free(image);

    return 0;
}