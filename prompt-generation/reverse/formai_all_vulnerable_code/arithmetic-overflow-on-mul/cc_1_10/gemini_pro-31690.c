//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Image data structure
typedef struct {
    unsigned char *data;
    int width;
    int height;
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
    fread(header, 1, 54, fp);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a valid BMP file\n", filename);
        fclose(fp);
        return NULL;
    }

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * 3);
    image->width = width;
    image->height = height;

    // Read the image data
    fread(image->data, 1, width * height * 3, fp);

    fclose(fp);

    return image;
}

// Save an image to a file
void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[54];
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[2] = 54 + image->width * image->height * 3;
    *(int *)&header[10] = 54;
    *(int *)&header[14] = 40;
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    *(short *)&header[26] = 1;
    *(short *)&header[28] = 24;
    *(int *)&header[30] = 0;
    *(int *)&header[34] = image->width * image->height * 3;
    *(int *)&header[38] = 0;
    *(int *)&header[42] = 0;
    *(int *)&header[46] = 0;
    *(int *)&header[50] = 0;
    fwrite(header, 1, 54, fp);

    // Write the image data
    fwrite(image->data, 1, image->width * image->height * 3, fp);

    fclose(fp);
}

// Flip an image horizontally
void flip_image_horizontal(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            // Swap the pixels at (j, i) and (width - j - 1, i)
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - j - 1];
            image->data[i * image->width + image->width - j - 1] = temp;
        }
    }
}

// Flip an image vertically
void flip_image_vertical(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            // Swap the pixels at (j, i) and (j, height - i - 1)
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
            // Adjust the RGB values by the given brightness
            image->data[i * image->width + j * 3 + 0] += brightness;
            image->data[i * image->width + j * 3 + 1] += brightness;
            image->data[i * image->width + j * 3 + 2] += brightness;
        }
    }
}

// Change the contrast of an image
void change_contrast(Image *image, double contrast) {
    // Calculate the factor to adjust the contrast
    double factor = (259 * (contrast + 128)) / 255;

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            // Adjust the RGB values by the given contrast
            image->data[i * image->width + j * 3 + 0] = (image->data[i * image->width + j * 3 + 0] - 128) * factor + 128;
            image->data[i * image->width + j * 3 + 1] = (image->data[i * image->width + j * 3 + 1] - 128) * factor + 128;
            image->data[i * image->width + j * 3 + 2] = (image->data[i * image->width + j * 3 + 2] - 128) * factor + 128;
        }
    }
}

int main() {
    // Load the input image
    Image *image = load_image("input.bmp");
    if (image == NULL) {
        return 1;
    }

    // Flip the image horizontally
    flip_image_horizontal(image);

    // Change the brightness of the image
    change_brightness(image, 50);

    // Change the contrast of the image
    change_contrast(image, 1.5);

    // Save the output image
    save_image(image, "output.bmp");

    // Free the memory allocated for the image
    free(image->data);
    free(image);

    return 0;
}