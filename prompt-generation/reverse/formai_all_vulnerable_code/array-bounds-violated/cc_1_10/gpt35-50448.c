//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60

// This function maps the pixel intensity to an ASCII character
char map_intensity_to_char(int intensity) {
    char characters[] = " .:-=+*#%@";
    int num_characters = strlen(characters);
    int step_size = 256 / num_characters;
    return characters[intensity / step_size];
}

// This function reads the image data from a binary file
void read_image_data(char *image_path, char *image_data) {
    FILE *fp = fopen(image_path, "rb");
    fread(image_data, WIDTH * HEIGHT, 1, fp);
    fclose(fp);
}

// This function converts the image data to ASCII art and prints to console
void convert_to_ascii_art(char *image_data) {
    char ascii_art[WIDTH * HEIGHT];

    // Map each pixel intensity to an ASCII character
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        ascii_art[i] = map_intensity_to_char((int)image_data[i]);
    }

    // Print the ASCII art to console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", ascii_art[i * WIDTH + j]);
        }
        printf("\n");
    }
}

int main() {
    char *image_path = "image.data";
    char image_data[WIDTH * HEIGHT];

    // Read image data from file
    read_image_data(image_path, image_data);

    // Convert to ASCII art and print
    convert_to_ascii_art(image_data);

    return 0;
}