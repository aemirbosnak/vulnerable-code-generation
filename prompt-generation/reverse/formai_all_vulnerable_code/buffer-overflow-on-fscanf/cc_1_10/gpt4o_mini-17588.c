//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

// Define the ASCII characters to use for the different pixel intensities
const char *ASCII_CHARS = "@#S%?*+;:. ";
const int ASCII_CHARS_NUM = 10;

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    Pixel **data;
    int width;
    int height;
} Image;

// Function to create a new image
Image *create_image(int width, int height) {
    Image *img = (Image *)malloc(sizeof(Image));
    img->width = width;
    img->height = height;

    img->data = (Pixel **)malloc(height * sizeof(Pixel *));
    for (int i = 0; i < height; i++) {
        img->data[i] = (Pixel *)malloc(width * sizeof(Pixel));
    }

    return img;
}

// Function to free the image memory
void free_image(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->data[i]);
    }
    free(img->data);
    free(img);
}

// Function to calculate the grayscale value of a pixel
int get_grayscale(Pixel pixel) {
    return (int)(0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b);
}

// Function to convert an image to ASCII art
void image_to_ascii(Image *img) {
    int new_width = 80; // Desired width for ASCII art
    int new_height = (img->height * new_width) / img->width; // Maintain aspect ratio

    printf("ASCII Art Representation:\n");
    
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            int original_x = (x * img->width) / new_width;
            int original_y = (y * img->height) / new_height;

            Pixel pixel = img->data[original_y][original_x];
            int grayscale_value = get_grayscale(pixel);
            int ascii_index = (grayscale_value * (ASCII_CHARS_NUM - 1)) / 255;

            putchar(ASCII_CHARS[ascii_index]);
        }
        putchar('\n');
    }
}

// Function to read an image from a PPM file
Image *read_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format. Use P6.\n");
        fclose(file);
        return NULL;
    }

    int width, height, max_color_value;
    fscanf(file, "%d %d %d", &width, &height, &max_color_value);
    fgetc(file); // Consume the newline after max color value

    Image *img = create_image(width, height);
    fread(img->data[0], sizeof(Pixel), width * height, file);
    fclose(file);

    return img;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = read_ppm(argv[1]);
    if (img == NULL) {
        return EXIT_FAILURE;
    }

    image_to_ascii(img);
    free_image(img);

    return EXIT_SUCCESS;
}