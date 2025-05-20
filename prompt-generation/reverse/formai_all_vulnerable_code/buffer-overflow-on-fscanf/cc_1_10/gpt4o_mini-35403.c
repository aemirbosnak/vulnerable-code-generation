//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <math.h>

#define MAX_HEIGHT 50
#define MAX_WIDTH 100
#define ASCII_CHARS "@%#*+=-:. "
#define ASCII_CHARS_LEN (sizeof(ASCII_CHARS) - 1)

// Struct to hold image data
typedef struct {
    uint8_t *data;      // Pointer to pixel data
    size_t width;       // Image width
    size_t height;      // Image height
} Image;

// Function to read a grayscale PGM image
Image* read_pgm(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);

    if (strcmp(format, "P5") != 0) {
        fprintf(stderr, "Unsupported file format\n");
        fclose(file);
        return NULL;
    }

    size_t width, height, max_val;
    fscanf(file, "%lu %lu\n%lu\n", &width, &height, &max_val);

    uint8_t *data = (uint8_t*)malloc(width * height);
    fread(data, sizeof(uint8_t), width * height, file);
    fclose(file);

    Image *img = (Image*)malloc(sizeof(Image));
    img->data = data;
    img->width = width;
    img->height = height;

    return img;
}

// Function to convert the image to ASCII art
void convert_to_ascii(Image *img) {
    for (size_t y = 0; y < img->height; y += img->height / MAX_HEIGHT) {
        for (size_t x = 0; x < img->width; x += img->width / MAX_WIDTH) {
            size_t pixel_index = y * img->width + x;
            uint8_t pixel_value = img->data[pixel_index];
            int char_index = (pixel_value * ASCII_CHARS_LEN) / 256; // Normalize pixel value
            printf("%c", ASCII_CHARS[char_index]);
        }
        printf("\n");
    }
}

// Clean up image data
void free_image(Image *img) {
    free(img->data);
    free(img);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pgm-image-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = read_pgm(argv[1]);
    if (img == NULL) {
        return EXIT_FAILURE;
    }

    printf("Converting image \"%s\" to ASCII art...\n\n", argv[1]);
    convert_to_ascii(img);
    
    free_image(img);
    
    return EXIT_SUCCESS;
}