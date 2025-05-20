//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 60
#define MAX_COLOR 255

// Function to convert RGB values to grayscale
int rgb_to_gray(int r, int g, int b) {
    return (r + g + b) / 3;
}

// Function to map a grayscale value to a character in the ASCII character set
char gray_to_char(int gray_val) {
    char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int n_chars = sizeof(ascii_chars) / sizeof(char);
    int step = MAX_COLOR / n_chars;

    for (int i = 1; i <= n_chars; i++) {
        if (gray_val < i * step) {
            return ascii_chars[i-1];
        }
    }

    return ascii_chars[n_chars-1];
}

int main() {
    // Open image file
    FILE* fp = fopen("image.ppm", "rb");
    if (!fp) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read image header
    char format[3];
    fscanf(fp, "%s", format);
    if (format[0] != 'P' || format[1] != '3') {
        printf("Error: Unsupported file format.\n");
        return 1;
    }
    int width, height, max_color;
    fscanf(fp, "%d %d %d", &width, &height, &max_color);
    if (width > WIDTH || height > HEIGHT) {
        printf("Error: Image size too large.\n");
        return 1;
    }

    // Allocate memory for RGB values
    int* r_vals = (int*) malloc(width * height * sizeof(int));
    int* g_vals = (int*) malloc(width * height * sizeof(int));
    int* b_vals = (int*) malloc(width * height * sizeof(int));
    if (!r_vals || !g_vals || !b_vals) {
        printf("Error: Memory allocation failed.\n");
        return 1;
    }

    // Load RGB values from file
    for (int i = 0; i < width * height; i++) {
        fscanf(fp, "%d %d %d", &(r_vals[i]), &(g_vals[i]), &(b_vals[i]));
    }

    // Convert RGB values to grayscale and map to ASCII characters
    char ascii_art[HEIGHT][WIDTH];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int gray_val = rgb_to_gray(r_vals[i*width+j], g_vals[i*width+j], b_vals[i*width+j]);
            ascii_art[i][j] = gray_to_char(gray_val);
        }
    }

    // Print ASCII art to terminal
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    free(r_vals);
    free(g_vals);
    free(b_vals);

    return 0;
}