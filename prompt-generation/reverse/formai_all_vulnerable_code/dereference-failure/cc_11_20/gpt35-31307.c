//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./bright-contrast <input_file> <output_file> <brightness_level> <contrast_level>\n");
        return 1;
    }

    char *in_filename = argv[1];
    char *out_filename = argv[2];
    float brightness_level = atof(argv[3]);
    float contrast_level = atof(argv[4]);

    FILE *in_file = fopen(in_filename, "rb");
    FILE *out_file = fopen(out_filename, "wb");

    if (!in_file || !out_file) {
        printf("Could not open input or output file.\n");
        return 1;
    }

    int width, height;
    fscanf(in_file, "%d %d\n", &width, &height);

    Pixel **image = malloc(sizeof(Pixel*) * height);
    for (int y = 0; y < height; y++) {
        image[y] = malloc(sizeof(Pixel) * width);

        for (int x = 0; x < width; x++) {
            fread(&image[y][x], sizeof(Pixel), 1, in_file);
        }
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Apply brightness adjustment
            image[y][x].r = (unsigned char) (image[y][x].r * brightness_level);
            image[y][x].g = (unsigned char) (image[y][x].g * brightness_level);
            image[y][x].b = (unsigned char) (image[y][x].b * brightness_level);

            // Apply contrast adjustment
            float pixel_intensity = (float) (image[y][x].r + image[y][x].g + image[y][x].b) / 3;
            image[y][x].r = (unsigned char) (pixel_intensity + contrast_level * (image[y][x].r - pixel_intensity));
            image[y][x].g = (unsigned char) (pixel_intensity + contrast_level * (image[y][x].g - pixel_intensity));
            image[y][x].b = (unsigned char) (pixel_intensity + contrast_level * (image[y][x].b - pixel_intensity));
        }
    }

    fprintf(out_file, "%d %d\n", width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fwrite(&image[y][x], sizeof(Pixel), 1, out_file);
        }
    }

    fclose(in_file);
    fclose(out_file);

    for (int y = 0; y < height; y++) {
        free(image[y]);
    }

    free(image);

    return 0;
}