//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255
#define MAX_PIXELS 1000000

// Function to convert pixel values to ASCII characters
char pixel_to_char(int pixel_val) {
    char ascii_char;

    switch (pixel_val / 25) {
        case 0:
            ascii_char = ' ';
            break;
        case 1:
            ascii_char = '.';
            break;
        case 2:
            ascii_char = ':';
            break;
        case 3:
            ascii_char = '-';
            break;
        case 4:
            ascii_char = '=';
            break;
        case 5:
            ascii_char = '+';
            break;
        case 6:
            ascii_char = '*';
            break;
        case 7:
            ascii_char = '#';
            break;
        case 8:
            ascii_char = '%';
            break;
        case 9:
            ascii_char = '@';
            break;
        default:
            ascii_char = ' ';
    }

    return ascii_char;
}

int main() {
    char filename[50];
    int pixels[MAX_PIXELS];
    int image_width, image_height;

    // Ask user for input file name
    printf("Enter input file name (max 50 characters): ");
    scanf("%s", filename);

    // Open input file
    FILE *input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Cannot open input file.\n");
        return 1;
    }

    // Read image height and width from input file
    fscanf(input_file, "%d %d", &image_height, &image_width);

    // Read pixel values from input file
    int num_pixels = image_height * image_width;
    for (int i = 0; i < num_pixels; i++) {
        fscanf(input_file, "%d", &pixels[i]);
    }

    // Close input file
    fclose(input_file);

    // Create output file name
    char output_filename[50];
    strcpy(output_filename, filename);
    char *dot = strrchr(output_filename, '.');
    if (dot != NULL) {
        *dot = '\0';
    }
    strcat(output_filename, "_ascii.txt");

    // Open output file
    FILE *output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Cannot open output file.\n");
        return 1;
    }

    // Write ASCII art to output file
    for (int i = 0; i < num_pixels; i++) {
        char ascii_char = pixel_to_char(pixels[i] * 255 / MAX_PIXEL_VALUE);
        fprintf(output_file, "%c", ascii_char);
        if ((i + 1) % image_width == 0) {
            fprintf(output_file, "\n");
        }
    }

    // Close output file
    fclose(output_file);

    printf("Conversion complete! Output file: %s\n", output_filename);

    return 0;
}