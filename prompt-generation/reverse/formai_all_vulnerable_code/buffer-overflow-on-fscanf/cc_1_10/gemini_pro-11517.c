//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40

char *characters = " .,-~:;=!*#$@";

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Color;

int main() {
    FILE *image_file = fopen("image.ppm", "r");
    if (image_file == NULL) {
        fprintf(stderr, "Error: Could not open image file.\n");
        return EXIT_FAILURE;
    }

    // Read the image header
    char header[512];
    fscanf(image_file, "%s\n", header);
    int width, height, max_value;
    fscanf(image_file, "%d %d\n", &width, &height);
    fscanf(image_file, "%d\n", &max_value);

    // Create the output image
    char *output_image = malloc(WIDTH * HEIGHT * sizeof(char));

    // Read the image data
    Color *image_data = malloc(width * height * sizeof(Color));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(image_file, "%hhu %hhu %hhu", &image_data[i * width + j].r, &image_data[i * width + j].g, &image_data[i * width + j].b);
        }
        fscanf(image_file, "\n");
    }

    fclose(image_file);

    // Convert the image to ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = (int) (image_data[i * width + j].r) % (sizeof(characters) - 1);
            output_image[i * WIDTH + j] = characters[index];
        }
    }

    // Print the ASCII art
    for (int i = 0; i < height; i++) {
        printf("%s\n", output_image + i * WIDTH);
    }

    free(output_image);
    free(image_data);

    return EXIT_SUCCESS;
}