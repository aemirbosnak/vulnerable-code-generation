//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Define the maximum width and height of the image
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Define the characters used to represent the different shades of gray
char *shades = " .,-~:;=*#%@";

// Read the image data from a file
unsigned char *read_image(char *filename, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the header information
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    // Get the width and height of the image
    *width = *(int *)&header[18];
    *height = *(int *)&header[22];

    // Allocate memory for the image data
    unsigned char *data = malloc((*width) * (*height));
    if (data == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read the image data
    fread(data, sizeof(unsigned char), (*width) * (*height), fp);

    // Close the file
    fclose(fp);

    return data;
}

// Convert the image data to ASCII art
char *convert_to_ascii(unsigned char *data, int width, int height) {
    // Allocate memory for the ASCII art
    char *ascii = malloc(width * height * sizeof(char));
    if (ascii == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Convert each pixel to an ASCII character
    for (int i = 0; i < width * height; i++) {
        int shade = data[i] / 25.5;
        ascii[i] = shades[shade];
    }

    return ascii;
}

// Write the ASCII art to a file
void write_ascii(char *ascii, int width, int height, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Write the ASCII art to the file
    fwrite(ascii, sizeof(char), width * height, fp);

    // Close the file
    fclose(fp);
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 4) {
        printf("Usage: %s <input image> <output ASCII> <width>\n", argv[0]);
        exit(1);
    }

    // Read the image data
    int width, height;
    unsigned char *data = read_image(argv[1], &width, &height);
    int resize_width = atoi(argv[3]);

    printf("Image dimensions: %d x %d\n", width, height);
    
    // Convert the image data to ASCII art
    char *ascii = convert_to_ascii(data, width, height);

    // Resize the ASCII art
    int new_height = resize_width * height / width;
    char *resized_ascii = malloc(resize_width * new_height * sizeof(char));
    for (int i = 0; i < new_height; i++) {
        for (int j = 0; j < resize_width; j++) {
            resized_ascii[i * resize_width + j] = ascii[i * width / new_height + j * width / resize_width];
        }
    }

    // Write the ASCII art to a file
    write_ascii(resized_ascii, resize_width, new_height, argv[2]);

    // Free the memory
    free(data);
    free(ascii);

    return 0;
}