//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Image struct
typedef struct {
    int width;
    int height;
    unsigned char *pixels;
} Image;

// Function to create a new image
Image *new_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(unsigned char));
    return image;
}

// Function to free an image
void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

// Function to load an image from a file
Image *load_image(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }
    // Read the header
    unsigned char header[14];
    fread(header, 1, 14, file);
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: invalid BMP file\n");
        fclose(file);
        return NULL;
    }
    // Read the dimensions
    int width = *((int *)&header[18]);
    int height = *((int *)&header[22]);
    // Read the pixel data
    Image *image = new_image(width, height);
    fread(image->pixels, 1, width * height * sizeof(unsigned char), file);
    fclose(file);
    return image;
}

// Function to save an image to a file
void save_image(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }
    // Write the header
    unsigned char header[14] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0
    };
    *((int *)&header[18]) = image->width;
    *((int *)&header[22]) = image->height;
    fwrite(header, 1, 14, file);
    // Write the pixel data
    fwrite(image->pixels, 1, image->width * image->height * sizeof(unsigned char), file);
    fclose(file);
}

// Function to apply a filter to an image
void filter_image(Image *image, int filter) {
    int width = image->width;
    int height = image->height;
    unsigned char *pixels = image->pixels;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = i * width + j;
            int pixel = pixels[index];
            switch (filter) {
                case 1: // Invert
                    pixels[index] = 255 - pixel;
                    break;
                case 2: // Grayscale
                    pixels[index] = (pixel + pixels[index + 1] + pixels[index + 2]) / 3;
                    break;
                case 3: // Sepia
                    pixels[index] = (pixel * .393) + (pixels[index + 1] * .769) + (pixels[index + 2] * .189);
                    break;
                case 4: // Emboss
                    if (j < width - 1 && i < height - 1) {
                        int dx = pixels[index + 1] - pixels[index];
                        int dy = pixels[index + width] - pixels[index];
                        int magnitude = sqrt(dx * dx + dy * dy);
                        pixels[index] = 128 + magnitude / 2;
                    }
                    break;
                case 5: // Sharpen
                    if (j > 0 && i > 0 && j < width - 1 && i < height - 1) {
                        int dx = pixels[index - 1] - pixels[index + 1];
                        int dy = pixels[index - width] - pixels[index + width];
                        pixels[index] += dx + dy;
                    }
                    break;
            }
        }
    }
}

// Function to print the usage message
void usage() {
    printf("Usage: image_editor <input_file> <output_file> <filter>\n");
    printf("Filters:\n");
    printf("  1: Invert\n");
    printf("  2: Grayscale\n");
    printf("  3: Sepia\n");
    printf("  4: Emboss\n");
    printf("  5: Sharpen\n");
}

// Main function
int main(int argc, char **argv) {
    if (argc != 4) {
        usage();
        return 1;
    }
    char *input_file = argv[1];
    char *output_file = argv[2];
    int filter = atoi(argv[3]);
    Image *image = load_image(input_file);
    if (!image) {
        return 1;
    }
    filter_image(image, filter);
    save_image(image, output_file);
    free_image(image);
    return 0;
}