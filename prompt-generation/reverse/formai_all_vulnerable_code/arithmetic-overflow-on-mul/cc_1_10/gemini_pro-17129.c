//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Claude Shannon
/*
 * A Simple Image Processing Program in Claude Shannon's Style.
 *
 * This program performs simple image processing tasks such as flipping an image,
 * changing brightness/contrast, and adding noise.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel_t;

typedef struct {
    int width;
    int height;
    pixel_t *pixels;
} image_t;

/*
 * Load an image from a file.
 */
image_t *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return NULL;
    }

    image_t *image = malloc(sizeof(image_t));
    if (!image) {
        fprintf(stderr, "Error: Could not allocate memory for image\n");
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);
    image->pixels = malloc(image->width * image->height * sizeof(pixel_t));
    if (!image->pixels) {
        fprintf(stderr, "Error: Could not allocate memory for image pixels\n");
        fclose(file);
        free(image);
        return NULL;
    }

    fread(image->pixels, sizeof(pixel_t), image->width * image->height, file);
    fclose(file);

    return image;
}

/*
 * Save an image to a file.
 */
void save_image(const char *filename, image_t *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(image->pixels, sizeof(pixel_t), image->width * image->height, file);
    fclose(file);
}

/*
 * Flip an image horizontally.
 */
void flip_image_horizontal(image_t *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            pixel_t temp = image->pixels[y * image->width + x];
            image->pixels[y * image->width + x] = image->pixels[y * image->width + image->width - x - 1];
            image->pixels[y * image->width + image->width - x - 1] = temp;
        }
    }
}

/*
 * Flip an image vertically.
 */
void flip_image_vertical(image_t *image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            pixel_t temp = image->pixels[y * image->width + x];
            image->pixels[y * image->width + x] = image->pixels[(image->height - y - 1) * image->width + x];
            image->pixels[(image->height - y - 1) * image->width + x] = temp;
        }
    }
}

/*
 * Change the brightness and contrast of an image.
 */
void adjust_brightness_contrast(image_t *image, double brightness, double contrast) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            pixel_t *pixel = &image->pixels[y * image->width + x];

            // Adjust the brightness.
            pixel->red = (unsigned char)round(pixel->red * brightness);
            pixel->green = (unsigned char)round(pixel->green * brightness);
            pixel->blue = (unsigned char)round(pixel->blue * brightness);

            // Adjust the contrast.
            pixel->red = (unsigned char)round((pixel->red - 128) * contrast + 128);
            pixel->green = (unsigned char)round((pixel->green - 128) * contrast + 128);
            pixel->blue = (unsigned char)round((pixel->blue - 128) * contrast + 128);
        }
    }
}

/*
 * Add noise to an image.
 */
void add_noise(image_t *image, double noise) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            pixel_t *pixel = &image->pixels[y * image->width + x];

            // Add noise to the red channel.
            pixel->red = (unsigned char)round(pixel->red + (double)rand() / (double)RAND_MAX * noise * 255);

            // Add noise to the green channel.
            pixel->green = (unsigned char)round(pixel->green + (double)rand() / (double)RAND_MAX * noise * 255);

            // Add noise to the blue channel.
            pixel->blue = (unsigned char)round(pixel->blue + (double)rand() / (double)RAND_MAX * noise * 255);
        }
    }
}

/*
 * Main function.
 */
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_file> [options]\n", argv[0]);
        fprintf(stderr, "Options:\n");
        fprintf(stderr, "  -h: Flip the image horizontally\n");
        fprintf(stderr, "  -v: Flip the image vertically\n");
        fprintf(stderr, "  -b: Adjust the brightness (default: 1.0)\n");
        fprintf(stderr, "  -c: Adjust the contrast (default: 1.0)\n");
        fprintf(stderr, "  -n: Add noise (default: 0.0)\n");
        return 1;
    }

    // Load the image.
    image_t *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Parse the options.
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            flip_image_horizontal(image);
        } else if (strcmp(argv[i], "-v") == 0) {
            flip_image_vertical(image);
        } else if (strcmp(argv[i], "-b") == 0) {
            double brightness = 1.0;
            if (i + 1 < argc) {
                brightness = atof(argv[i + 1]);
                i++;
            }
            adjust_brightness_contrast(image, brightness, 1.0);
        } else if (strcmp(argv[i], "-c") == 0) {
            double contrast = 1.0;
            if (i + 1 < argc) {
                contrast = atof(argv[i + 1]);
                i++;
            }
            adjust_brightness_contrast(image, 1.0, contrast);
        } else if (strcmp(argv[i], "-n") == 0) {
            double noise = 0.0;
            if (i + 1 < argc) {
                noise = atof(argv[i + 1]);
                i++;
            }
            add_noise(image, noise);
        }
    }

    // Save the image.
    save_image("output.bmp", image);

    // Free the image.
    free(image->pixels);
    free(image);

    return 0;
}