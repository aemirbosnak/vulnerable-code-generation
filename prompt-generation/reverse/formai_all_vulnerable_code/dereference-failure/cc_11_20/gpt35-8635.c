//FormAI DATASET v1.0 Category: Image Editor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Invalid syntax. Usage: ./image_editor <input_file> <output_file> <filter>\n");
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *filter = argv[3];

    FILE *infile = fopen(input_file, "r");
    if (infile == NULL) {
        printf("Unable to open input file.\n");
        return 1;
    }

    FILE *outfile = fopen(output_file, "w");
    if (outfile == NULL) {
        printf("Unable to open output file.\n");
        return 1;
    }

    int width, height;
    char magic_number[3];

    fscanf(infile, "%s", magic_number);
    if (strcmp(magic_number, "P3") != 0) {
        printf("Invalid file format.\n");
        return 1;
    }

    fscanf(infile, "%d %d", &width, &height);

    int max_color_value;
    fscanf(infile, "%d", &max_color_value);

    int **pixels;
    pixels = malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        pixels[i] = malloc(width * sizeof(int));
        for (int j = 0; j < width; j++) {
            int r, g, b;
            fscanf(infile, "%d %d %d", &r, &g, &b);
            int average = (r + g + b) / 3;
            pixels[i][j] = average;
            if (strcmp(filter, "invert") == 0) {
                pixels[i][j] = max_color_value - average;
            } else if (strcmp(filter, "grayscale") == 0) {
                pixels[i][j] = average;
            } else if (strcmp(filter, "sepia") == 0) {
                pixels[i][j] = (0.393 * r) + (0.769 * g) + (0.189 * b);
            }
        }
    }

    fprintf(outfile, "%s\n", magic_number);
    fprintf(outfile, "%d %d\n", width, height);
    fprintf(outfile, "%d\n", max_color_value);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(outfile, "%d ", pixels[i][j]);
        }
        fprintf(outfile, "\n");
    }

    fclose(infile);
    fclose(outfile);

    for (int i = 0; i < height; i++) {
        free(pixels[i]);
    }
    free(pixels);

    printf("Image processing complete!\n");

    return 0;
}