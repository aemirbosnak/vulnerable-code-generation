//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS "@%#*+=-:. " // Characters used in ASCII art, from dark to light

typedef struct {
    int width;
    int height;
    unsigned char *data; // Stores the image in grayscale
} Image;

// Function declarations
Image* load_image(const char *filename);
void free_image(Image *image);
void convert_to_ascii(const Image *image, const char *output_file);
void print_ascii(const Image *image);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = load_image(argv[1]);
    if (!img) {
        fprintf(stderr, "Error loading image: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    convert_to_ascii(img, argv[2]);

    free_image(img);
    return EXIT_SUCCESS;
}

// Load an image from a PGM file (P2 format)
Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("File opening failed");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(file);
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P2") != 0) {
        free(image);
        fclose(file);
        fprintf(stderr, "Unsupported image format: %s\n", format);
        return NULL;
    }

    fscanf(file, "%d %d", &image->width, &image->height);
    int maxval;
    fscanf(file, "%d", &maxval);

    image->data = malloc(image->width * image->height);
    if (!image->data) {
        free(image);
        fclose(file);
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < image->width * image->height; i++) {
        int pixel;
        fscanf(file, "%d", &pixel);
        image->data[i] = (unsigned char)((pixel * 255) / maxval); // Scale to 0-255
    }

    fclose(file);
    return image;
}

// Free the image memory
void free_image(Image *image) {
    if (image) {
        free(image->data);
        free(image);
    }
}

// Convert the image to ASCII art and save it to a file
void convert_to_ascii(const Image *image, const char *output_file) {
    FILE *file = fopen(output_file, "w");
    if (!file) {
        perror("File opening failed");
        return;
    }

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int idx = (y * image->width) + x;
            unsigned char gray_value = image->data[idx];
            int char_index = (gray_value * (strlen(ASCII_CHARS) - 1)) / 255;
            fputc(ASCII_CHARS[char_index], file);
        }
        fputc('\n', file);
    }

    fclose(file);
}

// Print the ASCII art to the console
void print_ascii(const Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            int idx = (y * image->width) + x;
            unsigned char gray_value = image->data[idx];
            int char_index = (gray_value * (strlen(ASCII_CHARS) - 1)) / 255;
            putchar(ASCII_CHARS[char_index]);
        }
        putchar('\n');
    }
}