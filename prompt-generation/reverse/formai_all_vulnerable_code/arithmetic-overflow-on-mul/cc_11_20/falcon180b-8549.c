//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 50

struct Pixel {
    int x, y;
    int r, g, b;
};

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        fclose(input_file);
        return 1;
    }

    int width, height;
    struct Pixel *pixels = NULL;

    fseek(input_file, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);

    pixels = malloc(width * height * sizeof(struct Pixel));
    if (pixels == NULL) {
        printf("Error allocating memory for pixels.\n");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    fseek(input_file, 54, SEEK_SET);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fread(&pixels[y * width + x].r, sizeof(char), 1, input_file);
            fread(&pixels[y * width + x].g, sizeof(char), 1, input_file);
            fread(&pixels[y * width + x].b, sizeof(char), 1, input_file);
        }
    }

    fclose(input_file);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int intensity = (pixels[y * width + x].r + pixels[y * width + x].g + pixels[y * width + x].b) / 3;

            if (intensity < 0) {
                intensity = 0;
            } else if (intensity > 9) {
                intensity = 9;
            }

            fprintf(output_file, "%c", intensity + '0');
        }
        fprintf(output_file, "\n");
    }

    fclose(output_file);

    free(pixels);

    return 0;
}