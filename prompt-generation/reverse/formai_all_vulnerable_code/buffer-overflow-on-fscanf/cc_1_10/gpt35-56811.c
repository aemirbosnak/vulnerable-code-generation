//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

int main(int argc, char *argv[]) {

    // Check if the user has provided file name in the arguments
    if (argc < 2) {
        fprintf(stderr, "Please provide an input file.\n");
        return 1;
    }

    // Open the input file in read mode
    FILE *fp = fopen(argv[1], "r");

    // Check if the file exists or not
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s.\n", argv[1]);
        return 1;
    }

    // Read the magic number from the file
    char magic_number[3];
    fscanf(fp, "%2s", magic_number);

    // Skip the next 2 lines (width and height)
    int width, height, max_val;
    fscanf(fp, "%d %d", &width, &height);
    fscanf(fp, "%d", &max_val);

    // Read the pixel values and store them in an array
    int pixel_values[MAX_HEIGHT][MAX_WIDTH];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(fp, "%d", &pixel_values[i][j]);
        }
    }

    // Close the input file
    fclose(fp);

    // Define a lookup table to map pixel values to characters
    char *lookup_table = " .:-=+*#%@";
    int lookup_table_size = strlen(lookup_table);

    // Initialize the output string
    char output[MAX_HEIGHT * (MAX_WIDTH + 1)] = {0};

    // Convert each pixel to a character and add it to the output string
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = (pixel_values[i][j] * (lookup_table_size - 1)) / max_val;
            output[i * (width + 1) + j] = lookup_table[index];
        }
        output[(i + 1) * (width + 1) - 1] = '\n';
    }

    // Print the output string
    printf("%s", output);

    return 0;
}