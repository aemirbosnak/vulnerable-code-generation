//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 40
#define ASCII_CHARS "@%#*+=-:. "

// Function to map a pixel value to an ASCII character
char pixel_to_ascii(int pixel_value) {
    int index = (pixel_value * (strlen(ASCII_CHARS) - 1)) / 255;
    return ASCII_CHARS[index];
}

// Function to create ASCII art from PGM image
void create_ascii_art(const char *input_file, const char *output_file) {
    FILE *pgm = fopen(input_file, "r");
    if (!pgm) {
        fprintf(stderr, "Error: Cannot open input file %s\n", input_file);
        exit(EXIT_FAILURE);
    }

    // Read PGM header
    char format[3];
    int width, height, max_gray;
    fscanf(pgm, "%s", format);
    fscanf(pgm, "%d %d", &width, &height);
    fscanf(pgm, "%d", &max_gray);
    
    if (strcmp(format, "P2") != 0 && strcmp(format, "P5") != 0) {
        fprintf(stderr, "Error: Unsupported PGM format! Please use P2 or P5.\n");
        fclose(pgm);
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the image
    unsigned char *image = (unsigned char *)malloc(width * height);
    if (!image) {
        fprintf(stderr, "Error: Memory allocation failed!\n");
        fclose(pgm);
        exit(EXIT_FAILURE);
    }

    // Read pixel values
    for (int i = 0; i < width * height; i++) {
        fscanf(pgm, "%hhu", &image[i]);
    }
    
    fclose(pgm);

    // Create output file to store ASCII art
    FILE *ascii_art = fopen(output_file, "w");
    if (!ascii_art) {
        fprintf(stderr, "Error: Cannot open output file %s\n", output_file);
        free(image);
        exit(EXIT_FAILURE);
    }

    // Scale down the image to fit the specified WIDTH and HEIGHT
    int step_x = width / WIDTH;
    int step_y = height / HEIGHT;

    // Convert pixels to ASCII
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int pixel_index = (y * step_y * width) + (x * step_x);
            char ascii_char = pixel_to_ascii(image[pixel_index]);
            fputc(ascii_char, ascii_art);
        }
        fputc('\n', ascii_art);
    }

    free(image);
    fclose(ascii_art);
}

// Main function to execute the program
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.pgm> <output.txt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    create_ascii_art(argv[1], argv[2]);

    printf("ASCII art successfully created in %s!\n", argv[2]);
    return EXIT_SUCCESS;
}