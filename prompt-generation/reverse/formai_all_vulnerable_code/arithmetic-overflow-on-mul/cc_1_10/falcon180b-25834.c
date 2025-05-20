//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert image to ASCII art in a recursive manner
void image_to_ascii(char *image, int width, int height, char *ascii, int ascii_width, int ascii_height, int x, int y) {
    // Base case: If the width or height of the image is less than or equal to 1, print a space
    if (width <= 1 || height <= 1) {
        strcat(ascii, " ");
        return;
    }

    // Recursive case: Divide the image into four sub-images and convert each sub-image to ASCII art
    int sub_width = width / 2;
    int sub_height = height / 2;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            int sub_x = x + i * sub_width;
            int sub_y = y + j * sub_height;
            char sub_ascii[ascii_width * ascii_height];
            image_to_ascii(image + sub_x * 3 + sub_y * width * 3, sub_width, sub_height, sub_ascii, ascii_width, ascii_height, sub_x, sub_y);
            strcat(ascii, sub_ascii);
        }
    }
}

int main() {
    // Read the image from a file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    // Read the image header
    int header_size = 54;
    char header[header_size];
    fread(header, 1, header_size, fp);

    // Read the image dimensions
    int width, height;
    fseek(fp, 18, SEEK_SET);
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);

    // Read the image data
    char *image = malloc(width * height * 3);
    fseek(fp, 54, SEEK_SET);
    fread(image, 1, width * height * 3, fp);

    // Convert the image to ASCII art
    char ascii[width * height];
    image_to_ascii(image, width, height, ascii, width, height, 0, 0);

    // Print the ASCII art
    printf("%s\n", ascii);

    // Free the memory used by the image data
    free(image);

    // Close the image file
    fclose(fp);

    return 0;
}