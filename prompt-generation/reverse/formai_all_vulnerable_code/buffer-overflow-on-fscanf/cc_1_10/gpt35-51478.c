//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

void convert_to_ascii(int pixel_value, char ascii_char[], int grayscale_levels);

int main(int argc, char *argv[]) {
    // Load image from file
    FILE *infile;
    char *filename;
    if (argc > 1) {
        filename = argv[1];
    } else {
        printf("Enter filename: ");
        scanf("%s", filename);
    }

    infile = fopen(filename, "r");
    if (infile == NULL) {
        printf("Error: unable to open file\n");
        exit(EXIT_FAILURE);
    }

    // Read image dimensions
    int width, height;
    fscanf(infile, "%d %d\n", &width, &height);

    // Read pixel data
    int pixel_data[MAX_HEIGHT][MAX_WIDTH];
    int max_value;
    fscanf(infile, "%d", &max_value);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(infile, "%d", &pixel_data[i][j]);
        }
    }

    fclose(infile);

    // Convert pixel data to ASCII art
    char ascii_art[MAX_HEIGHT][MAX_WIDTH];
    int grayscale_levels = 10;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel_value = pixel_data[i][j];
            char ascii_char[2];
            convert_to_ascii(pixel_value, ascii_char, grayscale_levels);
            ascii_art[i][j] = ascii_char[0];
        }
    }

    // Print ASCII art to console
    for (int i = 0; i < height; i++) {
        printf("%s\n", ascii_art[i]);
    }

    return 0;
}

void convert_to_ascii(int pixel_value, char ascii_char[], int grayscale_levels) {
    int level = (int) ((float) pixel_value / 255 * (grayscale_levels - 1));
    switch (level) {
        case 0:
            strcpy(ascii_char, " ");
            break;
        case 1:
            strcpy(ascii_char, ".");
            break;
        case 2:
            strcpy(ascii_char, ":");
            break;
        case 3:
            strcpy(ascii_char, "-");
            break;
        case 4:
            strcpy(ascii_char, "=");
            break;
        case 5:
            strcpy(ascii_char, "+");
            break;
        case 6:
            strcpy(ascii_char, "*");
            break;
        case 7:
            strcpy(ascii_char, "#");
            break;
        case 8:
            strcpy(ascii_char, "%");
            break;
        case 9:
            strcpy(ascii_char, "@");
            break;
        default:
            strcpy(ascii_char, "@");
    }
}