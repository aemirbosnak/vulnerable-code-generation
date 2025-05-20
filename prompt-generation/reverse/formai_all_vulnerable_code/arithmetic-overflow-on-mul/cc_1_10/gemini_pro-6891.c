//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Image data structure
typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

// Load image from file
Image *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return NULL;
    }

    // Read header
    char header[2];
    fread(header, sizeof(char), 2, fp);
    if (header[0] != 'P' || header[1] != '5') {
        fclose(fp);
        return NULL;
    }

    // Read width and height
    int width, height;
    fscanf(fp, "%d %d", &width, &height);

    // Read channels
    int channels;
    fscanf(fp, "%d", &channels);

    // Read data
    unsigned char *data = (unsigned char *)malloc(width * height * sizeof(unsigned char));
    fread(data, sizeof(unsigned char), width * height, fp);

    fclose(fp);

    // Create image object
    Image *image = (Image *)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->channels = channels;
    image->data = data;

    return image;
}

// Save image to file
void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return;
    }

    // Write header
    fprintf(fp, "P5\n");

    // Write width and height
    fprintf(fp, "%d %d\n", image->width, image->height);

    // Write channels
    fprintf(fp, "%d\n", image->channels);

    // Write data
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, fp);

    fclose(fp);
}

// Flip image vertically
void flip_vertical(Image *image) {
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height / 2; j++) {
            unsigned char temp = image->data[i + j * image->width];
            image->data[i + j * image->width] = image->data[i + (image->height - j - 1) * image->width];
            image->data[i + (image->height - j - 1) * image->width] = temp;
        }
    }
}

// Flip image horizontally
void flip_horizontal(Image *image) {
    for (int i = 0; i < image->width / 2; i++) {
        for (int j = 0; j < image->height; j++) {
            unsigned char temp = image->data[i + j * image->width];
            image->data[i + j * image->width] = image->data[(image->width - i - 1) + j * image->width];
            image->data[(image->width - i - 1) + j * image->width] = temp;
        }
    }
}

// Change brightness and contrast
void adjust_brightness_contrast(Image *image, int brightness, int contrast) {
    for (int i = 0; i < image->width * image->height; i++) {
        int value = image->data[i] + brightness;
        value = value * contrast / 100;
        value = value < 0 ? 0 : value;
        value = value > 255 ? 255 : value;
        image->data[i] = value;
    }
}

int main() {
    // Load image
    Image *image = load_image("image.pgm");
    if (!image) {
        printf("Error loading image\n");
        return 1;
    }

    // Flip image vertically
    flip_vertical(image);

    // Flip image horizontally
    flip_horizontal(image);

    // Adjust brightness and contrast
    adjust_brightness_contrast(image, 50, 150);

    // Save image
    save_image(image, "output.pgm");

    // Free image data
    free(image->data);
    free(image);

    return 0;
}