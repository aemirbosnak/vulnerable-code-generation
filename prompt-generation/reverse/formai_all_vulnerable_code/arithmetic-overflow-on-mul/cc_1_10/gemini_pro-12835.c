//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the image structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fclose(file);
        return NULL;
    }

    // Read the image header
    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);

    // Allocate memory for the image data
    image->data = malloc(image->width * image->height * sizeof(unsigned char));
    if (image->data == NULL) {
        fclose(file);
        free(image);
        return NULL;
    }

    // Read the image data
    fread(image->data, sizeof(unsigned char), image->width * image->height, file);

    fclose(file);

    return image;
}

// Save an image to a file
void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }

    // Write the image header
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    // Write the image data
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, file);

    fclose(file);
}

// Flip an image horizontally
void flip_image_horizontally(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - j - 1];
            image->data[i * image->width + image->width - j - 1] = temp;
        }
    }
}

// Flip an image vertically
void flip_image_vertically(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - i - 1) * image->width + j];
            image->data[(image->height - i - 1) * image->width + j] = temp;
        }
    }
}

// Change the brightness of an image
void change_brightness(Image *image, double brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->data[i * image->width + j] = (unsigned char) (image->data[i * image->width + j] * brightness);
        }
    }
}

// Change the contrast of an image
void change_contrast(Image *image, double contrast) {
    double factor = (259 * (contrast + 1)) / 255;
    double midpoint = 128;

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->data[i * image->width + j] = (unsigned char) ((factor * (image->data[i * image->width + j] - midpoint)) + midpoint);
        }
    }
}

// Main function
int main() {
    // Load an image from a file
    Image *image = load_image("image.bmp");
    if (image == NULL) {
        printf("Error loading image.\n");
        return 1;
    }

    // Flip the image horizontally
    flip_image_horizontally(image);

    // Flip the image vertically
    flip_image_vertically(image);

    // Change the brightness of the image
    change_brightness(image, 1.2);

    // Change the contrast of the image
    change_contrast(image, 1.5);

    // Save the image to a file
    save_image(image, "output.bmp");

    // Free the image data
    free(image->data);
    free(image);

    return 0;
}