//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 80 // Width of the ASCII art
#define HEIGHT 24 // Height of the ASCII art
#define CHAR_SET "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()_+-=[]{}|;:,.<>/?`~" // Set of characters to use for ASCII art

// Function to print the ASCII art
void print_ascii_art(char* ascii_art) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", ascii_art[i * WIDTH + j]);
        }
        printf("\n");
    }
}

// Function to convert image to ASCII art
void image_to_ascii_art(char* image_data, int image_width, int image_height, char* ascii_art) {
    int i, j, gray_value;
    for (i = 0; i < image_height; i++) {
        for (j = 0; j < image_width; j++) {
            gray_value = (int) image_data[i * image_width + j] / 3; // Convert RGB to grayscale
            ascii_art[i * WIDTH + j] = CHAR_SET[gray_value % strlen(CHAR_SET)]; // Map grayscale value to character in CHAR_SET
        }
    }
}

// Function to save ASCII art to file
void save_ascii_art_to_file(char* ascii_art, char* filename) {
    FILE* file;
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }
    fprintf(file, "%s", ascii_art);
    fclose(file);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    // Read input image data
    FILE* input_file = fopen(argv[1], "rb");
    if (input_file == NULL) {
        printf("Error: Could not open input file '%s'\n", argv[1]);
        return 1;
    }
    fseek(input_file, 0, SEEK_END);
    long input_file_size = ftell(input_file);
    rewind(input_file);
    char* input_data = (char*) malloc(input_file_size);
    fread(input_data, input_file_size, 1, input_file);
    fclose(input_file);

    // Convert image to ASCII art
    char* ascii_art = (char*) malloc(WIDTH * HEIGHT);
    image_to_ascii_art(input_data, WIDTH, HEIGHT, ascii_art);

    // Save ASCII art to output file
    char* output_filename = argv[2];
    save_ascii_art_to_file(ascii_art, output_filename);

    printf("ASCII art saved to file '%s'\n", output_filename);

    return 0;
}