//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

// Function to load a PPM image
Image* load_image(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported image format: %s\n", format);
        fclose(file);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    fscanf(file, "%d %d", &image->width, &image->height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // consume the newline character

    image->data = malloc(image->width * image->height * sizeof(Pixel));
    fread(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
    
    return image;
}

// Function to save a PPM image
void save_image(const char* filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Unable to open file %s for writing\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

// Function to invert colors of the image
void invert_colors(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i].r = 255 - image->data[i].r;
        image->data[i].g = 255 - image->data[i].g;
        image->data[i].b = 255 - image->data[i].b;
    }
}

// Function to free the image memory
void free_image(Image *image) {
    free(image->data);
    free(image);
}

// Main function - Image Editor
int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        return EXIT_FAILURE;
    }

    printf("Loaded image with width %d and height %d\n", image->width, image->height);
    
    invert_colors(image);
    printf("Inverted colors of the image.\n");

    save_image(argv[2], image);
    printf("Saved inverted image as %s\n", argv[2]);

    free_image(image);
    printf("Freed image memory.\n");

    return EXIT_SUCCESS;
}