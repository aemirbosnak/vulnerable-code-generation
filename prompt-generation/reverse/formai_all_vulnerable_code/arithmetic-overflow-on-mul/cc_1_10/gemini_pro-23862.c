//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Image dimensions
#define WIDTH 512
#define HEIGHT 512

// Image data type
typedef unsigned char pixel_t;

// Image structure
typedef struct {
    pixel_t *data;
    int width;
    int height;
} image_t;

// Load an image from a file
image_t *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen()");
        return NULL;
    }

    // Read the image header
    int width, height;
    if (fscanf(fp, "P5 %d %d\n", &width, &height) != 2) {
        perror("fscanf()");
        fclose(fp);
        return NULL;
    }

    // Check the image dimensions
    if (width <= 0 || height <= 0) {
        fprintf(stderr, "Invalid image dimensions: %d x %d\n", width, height);
        fclose(fp);
        return NULL;
    }

    // Allocate memory for the image data
    pixel_t *data = malloc(width * height * sizeof(pixel_t));
    if (!data) {
        perror("malloc()");
        fclose(fp);
        return NULL;
    }

    // Read the image data
    if (fread(data, sizeof(pixel_t), width * height, fp) != width * height) {
        perror("fread()");
        free(data);
        fclose(fp);
        return NULL;
    }

    // Close the file
    fclose(fp);

    // Return the image
    image_t *image = malloc(sizeof(image_t));
    if (!image) {
        perror("malloc()");
        free(data);
        return NULL;
    }

    image->data = data;
    image->width = width;
    image->height = height;

    return image;
}

// Save an image to a file
int save_image(const char *filename, const image_t *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen()");
        return -1;
    }

    // Write the image header
    if (fprintf(fp, "P5 %d %d\n", image->width, image->height) < 0) {
        perror("fprintf()");
        fclose(fp);
        return -1;
    }

    // Write the image data
    if (fwrite(image->data, sizeof(pixel_t), image->width * image->height, fp) != image->width * image->height) {
        perror("fwrite()");
        fclose(fp);
        return -1;
    }

    // Close the file
    fclose(fp);

    return 0;
}

// Flip an image horizontally
void flip_image_horizontal(image_t *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            pixel_t temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + image->width - x - 1];
            image->data[y * image->width + image->width - x - 1] = temp;
        }
    }
}

// Flip an image vertically
void flip_image_vertical(image_t *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            pixel_t temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - y - 1) * image->width + x];
            image->data[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

// Change the brightness of an image
void change_brightness(image_t *image, int brightness) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int new_brightness = image->data[y * image->width + x] + brightness;
            if (new_brightness < 0) {
                new_brightness = 0;
            } else if (new_brightness > 255) {
                new_brightness = 255;
            }
            image->data[y * image->width + x] = new_brightness;
        }
    }
}

// Change the contrast of an image
void change_contrast(image_t *image, float contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int new_contrast = image->data[y * image->width + x] * contrast;
            if (new_contrast < 0) {
                new_contrast = 0;
            } else if (new_contrast > 255) {
                new_contrast = 255;
            }
            image->data[y * image->width + x] = new_contrast;
        }
    }
}

// Free the memory allocated for an image
void free_image(image_t *image) {
    free(image->data);
    free(image);
}

// Main function
int main(int argc, char **argv) {
    // Check the command line arguments
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input image> <output image> <operation> <value>\n", argv[0]);
        return -1;
    }

    // Load the input image
    image_t *image = load_image(argv[1]);
    if (!image) {
        return -1;
    }

    // Perform the specified operation on the image
    if (strcmp(argv[3], "flip_horizontal") == 0) {
        flip_image_horizontal(image);
    } else if (strcmp(argv[3], "flip_vertical") == 0) {
        flip_image_vertical(image);
    } else if (strcmp(argv[3], "change_brightness") == 0) {
        change_brightness(image, atoi(argv[4]));
    } else if (strcmp(argv[3], "change_contrast") == 0) {
        change_contrast(image, atof(argv[4]));
    } else {
        fprintf(stderr, "Invalid operation: %s\n", argv[3]);
        free_image(image);
        return -1;
    }

    // Save the output image
    if (save_image(argv[2], image) != 0) {
        free_image(image);
        return -1;
    }

    // Free the memory allocated for the image
    free_image(image);

    return 0;
}