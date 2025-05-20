//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ASCII_CHARS " .:-=+*%@#"

typedef struct {
    uint8_t *data;
    int width;
    int height;
} Image;

Image *load_image(const char *filename);
void free_image(Image *img);
void print_ascii_art(const Image *img, const char *ascii_chars);
int get_character_index(uint8_t value, int max_value, const char *ascii_chars);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = load_image(argv[1]);
    if (!img) {
        fprintf(stderr, "Could not load image: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    print_ascii_art(img, ASCII_CHARS);
    free_image(img);
    
    return EXIT_SUCCESS;
}

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    // Simple PGM loader for grayscale images
    char buffer[16];
    if (!fgets(buffer, sizeof(buffer), file)) {
        perror("Error reading PGM header");
        fclose(file);
        return NULL;
    }

    if (buffer[0] != 'P' || buffer[1] != '5') {
        fprintf(stderr, "Not a valid PGM file\n");
        fclose(file);
        return NULL;
    }

    int width, height, max_value;
    fscanf(file, "%d %d %d", &width, &height, &max_value);
    fgetc(file);  // read the newline after max_value

    Image *img = malloc(sizeof(Image));
    if (!img) {
        perror("Could not allocate memory for image");
        fclose(file);
        return NULL;
    }

    img->width = width;
    img->height = height;
    img->data = malloc(width * height);
    if (!img->data) {
        perror("Could not allocate memory for image data");
        free(img);
        fclose(file);
        return NULL;
    }

    fread(img->data, 1, width * height, file);
    fclose(file);

    return img;
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

void print_ascii_art(const Image *img, const char *ascii_chars) {
    int max_value = 255;  // Maximum possible grayscale value
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            uint8_t pixel_value = img->data[y * img->width + x];
            int index = get_character_index(pixel_value, max_value, ascii_chars);
            putchar(ascii_chars[index]);
        }
        putchar('\n');
    }
}

int get_character_index(uint8_t value, int max_value, const char *ascii_chars) {
    int num_chars = strlen(ascii_chars);
    // Map the pixel value to the range of ASCII characters
    return (value * (num_chars - 1)) / max_value;
}