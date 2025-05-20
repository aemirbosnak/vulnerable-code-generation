#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

typedef struct {
    int width;
    int height;
    unsigned char pixels[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
} Image;

void apply_filter(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            // Simulate a simple filter: invert each pixel value
            img->pixels[y][x] = 255 - img->pixels[y][x];
        }
    }
}

int main() {
    Image img;
    FILE *file = fopen("input.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    // Vulnerability: No bounds checking on fscanf
    fscanf(file, "%d %d", &img.width, &img.height);
    if (img.width <= 0 || img.height <= 0 || img.width > MAX_IMAGE_SIZE || img.height > MAX_IMAGE_SIZE) {
        printf("Invalid image dimensions\n");
        fclose(file);
        return 1;
    }

    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            fscanf(file, "%hhu", &img.pixels[y][x]);
        }
    }

    fclose(file);

    apply_filter(&img);

    // Output the filtered image to a new file
    FILE *output_file = fopen("output.txt", "w");
    if (!output_file) {
        printf("Error opening output file\n");
        return 1;
    }

    fprintf(output_file, "%d %d\n", img.width, img.height);
    for (int y = 0; y < img.height; y++) {
        for (int x = 0; x < img.width; x++) {
            fprintf(output_file, "%hhu ", img.pixels[y][x]);
        }
        fprintf(output_file, "\n");
    }

    fclose(output_file);

    return 0;
}
