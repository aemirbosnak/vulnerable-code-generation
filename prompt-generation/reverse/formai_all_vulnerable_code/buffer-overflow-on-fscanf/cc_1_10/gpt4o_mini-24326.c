//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

// Function Prototypes
Image *load_ppm(const char *filename);
void save_ppm(const char *filename, Image *image);
void free_image(Image *image);
void apply_grayscale(Image *image);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return 1;
    }

    // Load the PPM image
    Image *image = load_ppm(argv[1]);
    if (image == NULL) {
        return 1;
    }

    // Apply the grayscale filter
    apply_grayscale(image);

    // Save the modified image
    save_ppm(argv[2], image);

    // Free allocated memory
    free_image(image);

    printf("Image processed successfully!\n");
    return 0;
}

// Function to load a PPM image
Image *load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format: %s\n", format);
        fclose(file);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    // Read image dimensions and max color value
    fscanf(file, "%d %d", &image->width, &image->height);
    int max_val;
    fscanf(file, "%d", &max_val);
    fgetc(file); // consume the newline

    // Allocate memory for pixel data
    image->data = malloc(image->width * image->height * sizeof(Pixel));
    if (!image->data) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        free(image);
        return NULL;
    }

    // Read pixel data
    fread(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
    return image;
}

// Function to save a PPM image
void save_ppm(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file for writing: %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

// Function to free the Image data
void free_image(Image *image) {
    free(image->data);
    free(image);
}

// Function to apply a grayscale filter to the image
void apply_grayscale(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->data[i].r + image->data[i].g + image->data[i].b) / 3;
        image->data[i].r = gray;
        image->data[i].g = gray;
        image->data[i].b = gray;
    }
}