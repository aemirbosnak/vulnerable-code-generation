//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 120
#define MAX_HEIGHT 50
#define CHAR_SET "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

void print_ascii_art(char ascii_art[MAX_HEIGHT][MAX_WIDTH]) {
    int i, j;
    for (i = 0; i < MAX_HEIGHT; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *input_file, *output_file;
    char input_filename[100], output_filename[100];
    char ascii_art[MAX_HEIGHT][MAX_WIDTH];
    int width, height, i, j, k, gray_level;

    // Get input and output file names
    printf("Enter input image file name: ");
    scanf("%s", input_filename);
    printf("Enter output ASCII art file name: ");
    scanf("%s", output_filename);

    // Open input image file
    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    // Get image dimensions
    fseek(input_file, 18, SEEK_SET); // Skip header
    fread(&width, sizeof(int), 1, input_file);
    fread(&height, sizeof(int), 1, input_file);

    // Allocate memory for ASCII art
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            ascii_art[i][j] = CHAR_SET[gray_level % strlen(CHAR_SET)];
            gray_level++;
        }
    }

    // Save ASCII art to output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        return 1;
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fprintf(output_file, "%c", ascii_art[i][j]);
        }
        fprintf(output_file, "\n");
    }

    fclose(input_file);
    fclose(output_file);

    printf("ASCII art saved to %s.\n", output_filename);

    return 0;
}