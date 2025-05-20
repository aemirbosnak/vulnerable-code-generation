//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS " .:-=+*%@#"

void paranoia_warning() {
    printf("WARNING: Processing high-risk image data! Ensure the source is trusted!\n");
    printf("Do NOT proceed without validating the image integrity!\n");
}

void print_ascii_art(char ascii_image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            putchar(ascii_image[y][x]);
        }
        putchar('\n');
    }
}

int get_ascii_char(double intensity) {
    int len = strlen(ASCII_CHARS);
    return (int)((intensity / 255.0) * (len - 1));
}

void convert_image_to_ascii(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        perror("Failed to open image file");
        exit(EXIT_FAILURE);
    }

    unsigned char image[MAX_HEIGHT][MAX_WIDTH][3];
    int width, height;

    // Assume we read a simple PPM image format for simplicity, sanity check is mandatory
    char header[3];
    fscanf(f, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported image format! Only P6 (PPM) is allowed.\n");
        fclose(f);
        exit(EXIT_FAILURE);
    }

    fscanf(f, "%d %d", &width, &height);
    int max_color_value;
    fscanf(f, "%d", &max_color_value);
    
    if (max_color_value != 255) {
        fprintf(stderr, "Warning: Unsupported max color value! Proceeding at your own risk.\n");
    }

    fread(image, sizeof(unsigned char), width * height * 3, f);
    fclose(f);

    char ascii_image[MAX_HEIGHT][MAX_WIDTH] = {0};
    int ascii_width = width < MAX_WIDTH ? width : MAX_WIDTH;
    int ascii_height = height < MAX_HEIGHT ? height : MAX_HEIGHT;

    for (int y = 0; y < ascii_height; y++) {
        for (int x = 0; x < ascii_width; x++) {
            unsigned char r = image[y][x][0];
            unsigned char g = image[y][x][1];
            unsigned char b = image[y][x][2];
            double intensity = (0.299 * r + 0.587 * g + 0.114 * b);
            int ascii_index = get_ascii_char(intensity);
            ascii_image[y][x] = ASCII_CHARS[ascii_index];
        }
    }

    print_ascii_art(ascii_image, ascii_width, ascii_height);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    paranoia_warning();
    convert_image_to_ascii(argv[1]);
    return 0;
}