//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 256
#define HEIGHT 256
#define MAX_RGB 255

typedef struct {
    int r;
    int g;
    int b;
} RGB;

typedef struct {
    float value;
} Frequency;

RGB rgb_parse(char *str) {
    RGB rgb;
    sscanf(str, "(%d, %d, %d)", &rgb.r, &rgb.g, &rgb.b);
    return rgb;
}

Frequency rgb_to_grayscale(RGB rgb) {
    Frequency fs;
    float luminance = 0.299 * rgb.r + 0.587 * rgb.g + 0.114 * rgb.b;
    fs.value = luminance;
    return fs;
}

void save_image(char *filename, Frequency **freq_matrix, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fputc(freq_matrix[i][j].value, fp);
        }
    }
    fclose(fp);
}

int main() {
    int num_pixels = WIDTH * HEIGHT;
    RGB rgb_pixels[num_pixels];
    Frequency *freq_matrix = malloc(num_pixels * sizeof(Frequency));

    // Read RGB pixels from standard input
    for (int i = 0; i < num_pixels; i++) {
        char str[100];
        fgets(str, sizeof(str), stdin);
        rgb_pixels[i] = rgb_parse(str);
    }

    // Convert RGB pixels to grayscale
    for (int i = 0; i < num_pixels; i++) {
        freq_matrix[i] = rgb_to_grayscale(rgb_pixels[i]);
    }

    // Save grayscale image to file
    save_image("output.raw", freq_matrix, WIDTH, HEIGHT);

    free(freq_matrix);
    return 0;
}