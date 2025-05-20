//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    Pixel *data;
    int width, height;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *image);
void invert_colors(Image *image);
void grayscale_image(Image *image);
void free_image(Image *image);
void print_usage(const char *prog_name);

int main(int argc, char **argv) {
    if (argc < 4) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    const char *operation = argv[3];

    Image *image = load_image(input_filename);
    if (!image) {
        fprintf(stderr, "Failed to load image: %s\n", input_filename);
        return EXIT_FAILURE;
    }

    if (strcmp(operation, "invert") == 0) {
        invert_colors(image);
    } else if (strcmp(operation, "grayscale") == 0) {
        grayscale_image(image);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", operation);
        free_image(image);
        return EXIT_FAILURE;
    }

    save_image(output_filename, image);
    free_image(image);

    printf("Image processing completed. Saved to: %s\n", output_filename);
    return EXIT_SUCCESS;
}

Image* load_image(const char *filename) {
    // A simple PPM (P3) format image loader for demonstration
    FILE *file = fopen(filename, "r");
    if (!file) {
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P3") != 0) {
        fclose(file);
        return NULL;
    }

    Image *image = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &image->width, &image->height);
    int max_color_value;
    fscanf(file, "%d", &max_color_value);

    image->data = (Pixel *)malloc(sizeof(Pixel) * image->width * image->height);
    for (int i = 0; i < image->width * image->height; i++) {
        fscanf(file, "%hhu %hhu %hhu", &image->data[i].r, &image->data[i].g, &image->data[i].b);
    }
    fclose(file);
    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "P3\n%d %d\n255\n", image->width, image->height);
    for (int i = 0; i < image->width * image->height; i++) {
        fprintf(file, "%hhu %hhu %hhu\n", image->data[i].r, image->data[i].g, image->data[i].b);
    }
    fclose(file);
}

void invert_colors(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i].r = 255 - image->data[i].r;
        image->data[i].g = 255 - image->data[i].g;
        image->data[i].b = 255 - image->data[i].b;
    }
}

void grayscale_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        uint8_t gray = (uint8_t)(0.3 * image->data[i].r + 0.59 * image->data[i].g + 0.11 * image->data[i].b);
        image->data[i].r = gray;
        image->data[i].g = gray;
        image->data[i].b = gray;
    }
}

void free_image(Image *image) {
    if (image) {
        free(image->data);
        free(image);
    }
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <input.ppm> <output.ppm> <operation>\n", prog_name);
    printf("Operation: invert | grayscale\n");
}