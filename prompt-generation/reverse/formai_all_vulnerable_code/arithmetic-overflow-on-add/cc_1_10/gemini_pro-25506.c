//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    int width, height;
    pixel data[MAX_WIDTH][MAX_HEIGHT];
} image;

image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    image *img = malloc(sizeof(image));
    if (!img) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(file);
        return NULL;
    }

    // Read header
    fread(&img->width, sizeof(int), 1, file);
    fread(&img->height, sizeof(int), 1, file);

    // Read data
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fread(&img->data[j][i].r, sizeof(unsigned char), 1, file);
            fread(&img->data[j][i].g, sizeof(unsigned char), 1, file);
            fread(&img->data[j][i].b, sizeof(unsigned char), 1, file);
        }
    }

    fclose(file);

    return img;
}

void free_image(image *img) {
    free(img);
}

void to_ascii_art(image *img, char *output) {
    // Calculate the average brightness of each pixel
    double avg_brightness[MAX_WIDTH][MAX_HEIGHT];
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            avg_brightness[j][i] = (img->data[j][i].r + img->data[j][i].g + img->data[j][i].b) / 3.0;
        }
    }

    // Convert the brightness values to ASCII characters
    char ascii_chars[] = " .,-~:;=!*#$@";
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            int index = (int)floor(avg_brightness[j][i] / 255.0 * (strlen(ascii_chars) - 1));
            output[i * img->width + j] = ascii_chars[index];
        }
    }

    output[img->height * img->width] = '\0';
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input image> <output file>\n", argv[0]);
        return 1;
    }

    image *img = load_image(argv[1]);
    if (!img) {
        return 1;
    }

    char *output = malloc(img->height * img->width + 1);
    if (!output) {
        fprintf(stderr, "Error: could not allocate memory for output\n");
        free_image(img);
        return 1;
    }

    to_ascii_art(img, output);

    FILE *file = fopen(argv[2], "w");
    if (!file) {
        fprintf(stderr, "Error: could not open file '%s'\n", argv[2]);
        free_image(img);
        free(output);
        return 1;
    }

    fprintf(file, "%s", output);

    fclose(file);

    free_image(img);
    free(output);

    return 0;
}