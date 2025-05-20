//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Image structure
typedef struct {
    unsigned char *data;
    int width;
    int height;
    int channels;
} Image;

// Load an image from a file
Image *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[54];
    fread(header, sizeof(header), 1, fp);

    // Check if the file is a BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file is not a BMP image\n");
        fclose(fp);
        return NULL;
    }

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Get the number of channels
    int channels = header[28] / 8;

    // Allocate memory for the image data
    unsigned char *data = malloc(width * height * channels);
    if (data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(fp);
        return NULL;
    }

    // Read the image data
    fread(data, width * height * channels, 1, fp);

    // Close the file
    fclose(fp);

    // Create the image structure
    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image structure\n");
        free(data);
        return NULL;
    }

    image->data = data;
    image->width = width;
    image->height = height;
    image->channels = channels;

    return image;
}

// Flip an image vertically
void flip_image_vertical(Image *image) {
    int width = image->width;
    int height = image->height;
    int channels = image->channels;

    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < channels; k++) {
                unsigned char temp = image->data[i * width * channels + j * channels + k];
                image->data[i * width * channels + j * channels + k] = image->data[(height - i - 1) * width * channels + j * channels + k];
                image->data[(height - i - 1) * width * channels + j * channels + k] = temp;
            }
        }
    }
}

// Flip an image horizontally
void flip_image_horizontal(Image *image) {
    int width = image->width;
    int height = image->height;
    int channels = image->channels;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            for (int k = 0; k < channels; k++) {
                unsigned char temp = image->data[i * width * channels + j * channels + k];
                image->data[i * width * channels + j * channels + k] = image->data[i * width * channels + (width - j - 1) * channels + k];
                image->data[i * width * channels + (width - j - 1) * channels + k] = temp;
            }
        }
    }
}

// Change the brightness of an image
void change_brightness(Image *image, int brightness) {
    int width = image->width;
    int height = image->height;
    int channels = image->channels;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < channels; k++) {
                int new_value = image->data[i * width * channels + j * channels + k] + brightness;
                if (new_value < 0) {
                    new_value = 0;
                } else if (new_value > 255) {
                    new_value = 255;
                }
                image->data[i * width * channels + j * channels + k] = new_value;
            }
        }
    }
}

// Change the contrast of an image
void change_contrast(Image *image, float contrast) {
    int width = image->width;
    int height = image->height;
    int channels = image->channels;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            for (int k = 0; k < channels; k++) {
                float new_value = (image->data[i * width * channels + j * channels + k] - 127) * contrast + 127;
                if (new_value < 0) {
                    new_value = 0;
                } else if (new_value > 255) {
                    new_value = 255;
                }
                image->data[i * width * channels + j * channels + k] = new_value;
            }
        }
    }
}

// Save an image to a file
void save_image(char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[54];
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[2] = 54 + image->width * image->height * image->channels;
    *(int *)&header[10] = 54;
    *(int *)&header[14] = 40;
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    header[26] = 1;
    header[28] = image->channels * 8;
    fwrite(header, sizeof(header), 1, fp);

    // Write the image data
    fwrite(image->data, image->width * image->height * image->channels, 1, fp);

    // Close the file
    fclose(fp);
}

// Free the memory allocated for an image
void free_image(Image *image) {
    free(image->data);
    free(image);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    // Load the input image
    Image *image = load_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    // Flip the image vertically
    flip_image_vertical(image);

    // Change the brightness of the image
    change_brightness(image, 50);

    // Change the contrast of the image
    change_contrast(image, 1.5);

    // Save the output image
    save_image(argv[2], image);

    // Free the memory allocated for the image
    free_image(image);

    return 0;
}