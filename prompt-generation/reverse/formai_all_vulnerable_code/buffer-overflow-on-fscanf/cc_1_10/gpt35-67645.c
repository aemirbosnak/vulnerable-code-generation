//FormAI DATASET v1.0 Category: Image Editor ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 512
#define MAX_HEIGHT 512

int image[MAX_HEIGHT][MAX_WIDTH], temp[MAX_HEIGHT][MAX_WIDTH];

// Function to perform the recursive flood fill algorithm
void flood_fill(int x, int y, int old_color, int new_color, int width, int height) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        return;
    }

    if (image[y][x] != old_color) {
        return;
    }

    image[y][x] = new_color;

    flood_fill(x + 1, y, old_color, new_color, width, height);
    flood_fill(x - 1, y, old_color, new_color, width, height);
    flood_fill(x, y + 1, old_color, new_color, width, height);
    flood_fill(x, y - 1, old_color, new_color, width, height);
}

// Function to read an image from a file
void read_image(char *filename, int *width, int *height) {
    FILE *infile;
    int x, y;

    infile = fopen(filename, "r");
    if (infile == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    fscanf(infile, "%d %d", width, height);

    for (y = 0; y < *height; y++) {
        for (x = 0; x < *width; x++) {
            fscanf(infile, "%d", &image[y][x]);
        }
    }

    fclose(infile);
}

// Function to write an image to a file
void write_image(char *filename, int width, int height) {
    FILE *outfile;
    int x, y;

    outfile = fopen(filename, "w");
    if (outfile == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        exit(1);
    }

    fprintf(outfile, "%d %d\n", width, height);

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            fprintf(outfile, "%d ", image[y][x]);
        }
        fprintf(outfile, "\n");
    }

    fclose(outfile);
}

// Main function that takes command line arguments
int main(int argc, char *argv[]) {
    int width, height, old_color, new_color;
    int x, y;
    char input[100];

    if (argc != 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        exit(1);
    }

    read_image(argv[1], &width, &height);

    printf("Enter the old color value: ");
    fgets(input, 100, stdin);
    old_color = atoi(input);

    printf("Enter the new color value: ");
    fgets(input, 100, stdin);
    new_color = atoi(input);

    printf("Enter the starting x coordinate: ");
    fgets(input, 100, stdin);
    x = atoi(input);

    printf("Enter the starting y coordinate: ");
    fgets(input, 100, stdin);
    y = atoi(input);

    if (x < 0 || x >= width || y < 0 || y >= height) {
        fprintf(stderr, "Error: starting coordinates are outside the image bounds\n");
        exit(1);
    }

    flood_fill(x, y, old_color, new_color, width, height);

    write_image("output.pgm", width, height);

    printf("Image written to output.pgm\n");

    return 0;
}