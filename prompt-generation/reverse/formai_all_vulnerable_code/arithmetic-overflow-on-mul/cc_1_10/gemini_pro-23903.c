//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define the image structure
typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[14];
    fread(header, sizeof(header), 1, file);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: invalid BMP file\n");
        fclose(file);
        return NULL;
    }

    // Read the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * 3);
    image->width = width;
    image->height = height;

    // Read the image data
    fread(image->data, width * height * 3, 1, file);

    // Close the file
    fclose(file);

    return image;
}

// Save an image to a file
void save_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[14];
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[2] = sizeof(header) + image->width * image->height * 3;
    *(int *)&header[10] = sizeof(header);
    *(int *)&header[14] = 40;
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    *(short *)&header[26] = 1;
    *(short *)&header[28] = 24;
    *(int *)&header[30] = 0;
    *(int *)&header[34] = image->width * image->height * 3;
    fwrite(header, sizeof(header), 1, file);

    // Write the image data
    fwrite(image->data, image->width * image->height * 3, 1, file);

    // Close the file
    fclose(file);
}

// Flip an image horizontally
void flip_horizontal(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            // Swap the pixels at (x, y) and (width - 1 - x, y)
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - 1 - x];
            image->data[y * image->width + image->width - 1 - x] = temp;
        }
    }
}

// Flip an image vertically
void flip_vertical(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            // Swap the pixels at (x, y) and (x, height - 1 - y)
            unsigned char temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - 1 - y) * image->width + x];
            image->data[(image->height - 1 - y) * image->width + x] = temp;
        }
    }
}

// Change the brightness of an image
void change_brightness(Image *image, int brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            // Add the brightness value to each pixel
            image->data[y * image->width + x] += brightness;
        }
    }
}

// Change the contrast of an image
void change_contrast(Image *image, float contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            // Multiply each pixel by the contrast value
            image->data[y * image->width + x] *= contrast;
        }
    }
}

// main function 
int main() {
    // Load the image
    Image *image = load_image("image.bmp");
    if (image == NULL) {
        return 1;
    }

    // Flip the image horizontally
    flip_horizontal(image);

    // Flip the image vertically
    flip_vertical(image);

    // Change the brightness of the image
    change_brightness(image, 10);

    // Change the contrast of the image
    change_contrast(image, 1.5);

    // Save the image
    save_image(image, "output.bmp");

    // Free the image data
    free(image->data);
    free(image);

    return 0;
}