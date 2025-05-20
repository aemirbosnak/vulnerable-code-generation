//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surprised
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Image data structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return NULL;
    }

    // Read the header
    unsigned char header[18];
    fread(header, sizeof(header), 1, fp);

    // Check if the file is a BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        fclose(fp);
        return NULL;
    }

    // Read the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    unsigned char *data = malloc(width * height);
    if (!data) {
        fclose(fp);
        return NULL;
    }

    // Read the image data
    fread(data, width * height, 1, fp);

    fclose(fp);

    // Create the image structure
    Image *image = malloc(sizeof(Image));
    if (!image) {
        free(data);
        return NULL;
    }

    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

// Save an image to a file
void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return;
    }

    // Write the header
    unsigned char header[18] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0
    };

    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;

    fwrite(header, sizeof(header), 1, fp);

    // Write the image data
    fwrite(image->data, image->width * image->height, 1, fp);

    fclose(fp);
}

// Flip an image vertically
void flip_image_vertical(Image *image) {
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height / 2; j++) {
            unsigned char temp = image->data[i + j * image->width];
            image->data[i + j * image->width] = image->data[i + (image->height - j - 1) * image->width];
            image->data[i + (image->height - j - 1) * image->width] = temp;
        }
    }
}

// Flip an image horizontally
void flip_image_horizontal(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + (image->width - j - 1)];
            image->data[i * image->width + (image->width - j - 1)] = temp;
        }
    }
}

// Change the brightness of an image
void change_image_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->width * image->height; i++) {
        int new_value = image->data[i] + brightness;
        if (new_value < 0) {
            new_value = 0;
        } else if (new_value > 255) {
            new_value = 255;
        }
        image->data[i] = new_value;
    }
}

// Change the contrast of an image
void change_image_contrast(Image *image, int contrast) {
    for (int i = 0; i < image->width * image->height; i++) {
        int new_value = image->data[i] + contrast * (image->data[i] - 128);
        if (new_value < 0) {
            new_value = 0;
        } else if (new_value > 255) {
            new_value = 255;
        }
        image->data[i] = new_value;
    }
}

// Apply a filter to an image
void apply_filter(Image *image, int kernel[3][3]) {
    int new_image[image->width][image->height];

    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            int sum = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (i + k >= 0 && i + k < image->width && j + l >= 0 && j + l < image->height) {
                        sum += image->data[(i + k) + (j + l) * image->width] * kernel[k + 1][l + 1];
                    }
                }
            }
            new_image[i][j] = sum;
        }
    }

    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            if (new_image[i][j] < 0) {
                new_image[i][j] = 0;
            } else if (new_image[i][j] > 255) {
                new_image[i][j] = 255;
            }
            image->data[i + j * image->width] = new_image[i][j];
        }
    }
}

int main() {
    // Load the image
    Image *image = load_image("image.bmp");
    if (!image) {
        return 1;
    }

    // Flip the image vertically
    flip_image_vertical(image);

    // Flip the image horizontally
    flip_image_horizontal(image);

    // Change the brightness of the image
    change_image_brightness(image, 50);

    // Change the contrast of the image
    change_image_contrast(image, 50);

    // Apply a filter to the image
    int kernel[3][3] = {
        { 1, 1, 1 },
        { 1, 1, 1 },
        { 1, 1, 1 }
    };
    apply_filter(image, kernel);

    // Save the image
    save_image("new_image.bmp", image);

    // Free the image
    free(image->data);
    free(image);

    return 0;
}