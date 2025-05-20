//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

// Define the image struct
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[18];
    fread(header, sizeof(header), 1, file);

    // Check the header
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: invalid BMP file\n");
        fclose(file);
        return NULL;
    }

    // Read the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the image data
    unsigned char *data = malloc(width * height * 3);
    fread(data, width * height * 3, 1, file);

    // Close the file
    fclose(file);

    // Create the image struct
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

// Save an image to a file
void save_image(const char *filename, Image *image) {
    // Open the file
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[18] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0,
        54, 0, 0, 0, 40, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    };

    *(int *)&header[2] = image->width * image->height * 3 + 54;
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;

    fwrite(header, sizeof(header), 1, file);

    // Write the image data
    fwrite(image->data, image->width * image->height * 3, 1, file);

    // Close the file
    fclose(file);
}

// Flip an image horizontally
void flip_image_horizontally(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            unsigned char temp = image->data[y * image->width * 3 + x * 3];
            image->data[y * image->width * 3 + x * 3] = image->data[y * image->width * 3 + (image->width - x - 1) * 3];
            image->data[y * image->width * 3 + (image->width - x - 1) * 3] = temp;
        }
    }
}

// Flip an image vertically
void flip_image_vertically(Image *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            unsigned char temp = image->data[y * image->width * 3 + x * 3];
            image->data[y * image->width * 3 + x * 3] = image->data[(image->height - y - 1) * image->width * 3 + x * 3];
            image->data[(image->height - y - 1) * image->width * 3 + x * 3] = temp;
        }
    }
}

// Change the brightness of an image
void change_brightness(Image *image, int brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < 3; c++) {
                int value = image->data[y * image->width * 3 + x * 3 + c] + brightness;
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                image->data[y * image->width * 3 + x * 3 + c] = value;
            }
        }
    }
}

// Change the contrast of an image
void change_contrast(Image *image, float contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < 3; c++) {
                float value = (image->data[y * image->width * 3 + x * 3 + c] - 127.5) * contrast + 127.5;
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                image->data[y * image->width * 3 + x * 3 + c] = value;
            }
        }
    }
}

// Main function
int main() {
    // Load an image from a file
    Image *image = load_image("image.bmp");
    if (!image) {
        return 1;
    }

    // Flip the image horizontally
    flip_image_horizontally(image);

    // Flip the image vertically
    flip_image_vertically(image);

    // Change the brightness of the image
    change_brightness(image, 50);

    // Change the contrast of the image
    change_contrast(image, 1.5);

    // Save the image to a file
    save_image("output.bmp", image);

    // Free the image data
    free(image->data);
    free(image);

    return 0;
}