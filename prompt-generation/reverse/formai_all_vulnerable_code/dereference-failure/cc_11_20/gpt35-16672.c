//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

int main(int argc, char **argv)
{
    // Argument error handling
    if (argc != 2) {
        printf("Invalid arguments. Please provide a path to the input image file.\n");
        return 1;
    }

    // Open input image file
    FILE *in_file = fopen(argv[1], "r");
    if (!in_file) {
        printf("Failed to open input file \"%s\"\n", argv[1]);
        return 1;
    }

    // Read image dimensions
    int width, height;
    char format[3];
    fgets(format, sizeof format, in_file);
    fscanf(in_file, "%d %d", &width, &height);
    int max_rgb;
    fscanf(in_file, "%d\n", &max_rgb);
    if (strcmp(format, "P3")) {
        printf("Invalid image format. Only P3 ASCII PPM images are supported.\n");
        return 1;
    }
    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Image too big. Maximum width and height are %d.\n", MAX_WIDTH, MAX_HEIGHT);
        return 1;
    }

    // Allocate memory for image pixels
    unsigned char red[width][height];
    unsigned char green[width][height];
    unsigned char blue[width][height];

    // Fill image pixel values
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int r, g, b;
            fscanf(in_file, "%d %d %d", &r, &g, &b);
            red[x][y] = r;
            green[x][y] = g;
            blue[x][y] = b;
        }
    }

    // Close input file
    fclose(in_file);

    // Convert pixels to ASCII characters
    const char grayscale[] = " .:-=+*#%@";
    char ascii[width][height];
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int p = (red[x][y] + green[x][y] + blue[x][y]) / 3;
            int index = p * (sizeof grayscale - 1) / 255;
            ascii[x][y] = grayscale[index];
        }
    }

    // Output ASCII art
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            putchar(ascii[x][y]);
        }
        putchar('\n');
    }

    return 0;
}