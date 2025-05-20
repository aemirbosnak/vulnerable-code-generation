//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80 // Maximum width of ASCII art image
#define MAX_HEIGHT 80 // Maximum height of ASCII art image

char ascii_chars[] = {' ', '.', ':', '+', '*', '?', '%', 'S', '#', '@'}; // ASCII characters that will be used for conversion

int get_gray_scale(int r, int g, int b) {
    return (0.299 * r) + (0.587 * g) + (0.114 * b);
}

char get_ascii_char(int gray_scale) {
    int range_size = 255 / (sizeof(ascii_chars) / sizeof(char));
    int index = gray_scale / range_size; // The ASCII character to use is based on the gray scale value

    return ascii_chars[index];
}

int main() {
    char image_path[100];
    printf("Enter the path to the image: ");
    scanf("%s", image_path);

    FILE *image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        printf("Error in opening image file!");
        return 1;
    }

    // Read the header of the input image
    char header[54];
    fread(header, sizeof(char), 54, image_file);

    // Extract image height, width and bits per pixel information from the header
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bits_per_pixel = *(int*)&header[28];

    // Check if input image meets requirements for the converter
    if (width > MAX_WIDTH || height > MAX_HEIGHT || bits_per_pixel != 24) {
        printf("Input image does not meet requirements! (max width = %d, max height = %d, bits per pixel = 24)\n", MAX_WIDTH, MAX_HEIGHT);
        return 1;
    }

    // Allocate memory for the input image and read it from the file
    int size = width * height * 3; // 3 represents the 3 colors (RGB)
    unsigned char *image_data = (unsigned char*)malloc(size * sizeof(unsigned char));
    fread(image_data, sizeof(unsigned char), size, image_file);

    // Close the input image file
    fclose(image_file);

    // Allocate memory for the ASCII art output image
    char ascii_image[MAX_HEIGHT][MAX_WIDTH];

    // Convert the RGB values of each pixel to a gray scale value and then to an ASCII character
    int index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r = (int)image_data[index];
            int g = (int)image_data[index + 1];
            int b = (int)image_data[index + 2];

            int gray_scale = get_gray_scale(r, g, b);
            char ascii_char = get_ascii_char(gray_scale);

            ascii_image[i][j] = ascii_char;
            index += 3;
        }
    }

    // Print the ASCII art image to the console
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c", ascii_image[i][j]);
        }
        printf("\n");
    }

    // Free memory allocated for the input and output images
    free(image_data);

    return 0;
}