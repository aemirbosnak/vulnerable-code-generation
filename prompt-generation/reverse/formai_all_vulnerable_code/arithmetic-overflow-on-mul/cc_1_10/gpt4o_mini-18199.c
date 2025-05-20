//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

// Function to load a PPM image
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return NULL;
    }

    char header[3];
    fscanf(file, "%2s", header);

    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported format: %s\n", header);
        fclose(file);
        return NULL;
    }

    Image *image = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &image->width, &image->height);
    fgetc(file); // Consume the whitespace after dimensions

    size_t image_size = image->width * image->height;
    image->data = (Pixel *)malloc(image_size * sizeof(Pixel));
    fread(image->data, sizeof(Pixel), image_size, file);

    fclose(file);
    return image;
}

// Function to save a PPM image
void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

// Function to invert image colors
void invert_image(Image *image) {
    for (int i = 0; i < image->width * image->height; ++i) {
        image->data[i].r = 255 - image->data[i].r;
        image->data[i].g = 255 - image->data[i].g;
        image->data[i].b = 255 - image->data[i].b;
    }
}

// Function to free image memory
void free_image(Image *image) {
    if (image) {
        free(image->data);
        free(image);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        return EXIT_FAILURE;
    }

    invert_image(image);
    save_image(argv[2], image);

    printf("Image inverted and saved to %s\n", argv[2]);
    free_image(image);
    return EXIT_SUCCESS;
}