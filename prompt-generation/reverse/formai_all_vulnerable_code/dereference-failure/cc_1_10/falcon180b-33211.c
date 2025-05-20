//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_IMAGE_SIZE 1024

struct pixel {
    int x;
    int y;
    int color;
};

int main() {
    FILE *image_file;
    int image_size, num_pixels;
    char line[MAX_LINE_LENGTH];
    struct pixel *pixels;

    image_file = fopen("image.txt", "r");
    if (image_file == NULL) {
        printf("Error: could not open image file.\n");
        return 1;
    }

    // Read image size from file
    fscanf(image_file, "%d %d\n", &image_size, &num_pixels);

    // Allocate memory for pixels
    pixels = malloc(num_pixels * sizeof(struct pixel));
    if (pixels == NULL) {
        printf("Error: could not allocate memory for pixels.\n");
        return 1;
    }

    // Read pixels from file
    for (int i = 0; i < num_pixels; i++) {
        fscanf(image_file, "%d %d %d\n", &pixels[i].x, &pixels[i].y, &pixels[i].color);
    }

    // Close file
    fclose(image_file);

    // Manipulate pixels as desired
    for (int i = 0; i < num_pixels; i++) {
        // Example: invert colors
        pixels[i].color = 255 - pixels[i].color;
    }

    // Write modified image to file
    image_file = fopen("image.txt", "w");
    if (image_file == NULL) {
        printf("Error: could not open image file for writing.\n");
        return 1;
    }

    fprintf(image_file, "%d %d\n", image_size, num_pixels);
    for (int i = 0; i < num_pixels; i++) {
        fprintf(image_file, "%d %d %d\n", pixels[i].x, pixels[i].y, pixels[i].color);
    }

    // Close file
    fclose(image_file);

    // Free memory
    free(pixels);

    return 0;
}