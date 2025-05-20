//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define ASCII_CHARS "@%#*+=-:. " // Characters from darkest to lightest

// Function prototypes
void load_image(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int *width, int *height);
void convert_to_ascii(unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int width, int height);
void print_ascii_image(int gray[MAX_HEIGHT][MAX_WIDTH], int width, int height);
int rgb_to_gray(unsigned char r, unsigned char g, unsigned char b);

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    unsigned char image[MAX_HEIGHT][MAX_WIDTH][3];
    int width = 0, height = 0;

    load_image(argv[1], image, &width, &height);
    convert_to_ascii(image, width, height);

    return 0;
}

void load_image(const char *filename, unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int *width, int *height) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file");
        exit(EXIT_FAILURE);
    }

    // Read the PPM header
    char format[3];
    fscanf(file, "%s", format);
    fscanf(file, "%d %d", width, height);
    int max_val;
    fscanf(file, "%d", &max_val);

    if (strcmp(format, "P6") != 0 || max_val != 255) {
        fprintf(stderr, "Unsupported image format or max value\n");
        fclose(file);
        exit(EXIT_FAILURE);
    }

    // Read the pixel data
    fread(image, sizeof(unsigned char), (*width) * (*height) * 3, file);
    fclose(file);
}

int rgb_to_gray(unsigned char r, unsigned char g, unsigned char b) {
    // Using luminosity method for converting RGB to Gray
    return (int)(0.299 * r + 0.587 * g + 0.114 * b);
}

void convert_to_ascii(unsigned char image[MAX_HEIGHT][MAX_WIDTH][3], int width, int height) {
    int gray[MAX_HEIGHT][MAX_WIDTH];

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            unsigned char r = image[y][x][0];
            unsigned char g = image[y][x][1];
            unsigned char b = image[y][x][2];
            gray[y][x] = rgb_to_gray(r, g, b);
        }
    }

    print_ascii_image(gray, width, height);
}

void print_ascii_image(int gray[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    // Normalize the gray values and map them to ASCII characters
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = gray[y][x] * (strlen(ASCII_CHARS) - 1) / 255;
            printf("%c", ASCII_CHARS[index]);
        }
        printf("\n");
    }
}