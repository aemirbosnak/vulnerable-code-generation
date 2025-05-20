//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Image dimensions
#define WIDTH  640
#define HEIGHT 480

// Image data type
typedef unsigned char pixel_t;

// Image structure
typedef struct {
    pixel_t *data;
    int width;
    int height;
} image_t;

// Read an image from a file
image_t *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    // Read the image header
    int width, height;
    if (fscanf(fp, "%d %d\n", &width, &height) != 2) {
        perror("fscanf");
        fclose(fp);
        return NULL;
    }

    // Allocate memory for the image data
    pixel_t *data = malloc(width * height * sizeof(pixel_t));
    if (data == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    // Read the image data
    if (fread(data, width * height, sizeof(pixel_t), fp) != 1) {
        perror("fread");
        fclose(fp);
        free(data);
        return NULL;
    }

    fclose(fp);

    // Create an image structure
    image_t *image = malloc(sizeof(image_t));
    if (image == NULL) {
        perror("malloc");
        free(data);
        return NULL;
    }

    image->data = data;
    image->width = width;
    image->height = height;

    return image;
}

// Write an image to a file
int write_image(const char *filename, image_t *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return -1;
    }

    // Write the image header
    if (fprintf(fp, "%d %d\n", image->width, image->height) != 2) {
        perror("fprintf");
        fclose(fp);
        return -1;
    }

    // Write the image data
    if (fwrite(image->data, image->width * image->height, sizeof(pixel_t), fp) != 1) {
        perror("fwrite");
        fclose(fp);
        return -1;
    }

    fclose(fp);

    return 0;
}

// Flip an image horizontally
void flip_horizontal(image_t *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            pixel_t temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - j - 1];
            image->data[i * image->width + image->width - j - 1] = temp;
        }
    }
}

// Flip an image vertically
void flip_vertical(image_t *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            pixel_t temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - i - 1) * image->width + j];
            image->data[(image->height - i - 1) * image->width + j] = temp;
        }
    }
}

// Change the brightness of an image
void change_brightness(image_t *image, int brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int new_value = image->data[i * image->width + j] + brightness;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image->data[i * image->width + j] = new_value;
        }
    }
}

// Change the contrast of an image
void change_contrast(image_t *image, float contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            float new_value = (image->data[i * image->width + j] - 127.5) * contrast + 127.5;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image->data[i * image->width + j] = new_value;
        }
    }
}

// Main function
int main(void) {
    // Read an image from a file
    image_t *image = read_image("lena.ppm");
    if (image == NULL) {
        return -1;
    }

    // Flip the image horizontally
    flip_horizontal(image);

    // Flip the image vertically
    flip_vertical(image);

    // Change the brightness of the image
    change_brightness(image, 50);

    // Change the contrast of the image
    change_contrast(image, 1.5);

    // Write the image to a file
    if (write_image("output.ppm", image) != 0) {
        return -1;
    }

    // Free the image data
    free(image->data);

    // Free the image structure
    free(image);

    return 0;
}