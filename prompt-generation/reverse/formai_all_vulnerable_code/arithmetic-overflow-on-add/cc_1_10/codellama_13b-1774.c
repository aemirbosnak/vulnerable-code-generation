//Code Llama-13B DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
/*
 * Image to ASCII Art Converter
 *
 * Usage:
 *   image2ascii <image file>
 *
 * This program converts an image file to ASCII art.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for image data
typedef struct {
    int width;
    int height;
    int channels;
    unsigned char *data;
} Image;

// Function to convert an image to ASCII art
void image2ascii(Image *img, char *ascii) {
    // Convert image data to ASCII art
    int i, j, k;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            k = i * img->width + j;
            int gray = img->data[k] * 10 / 255;
            if (gray < 1) {
                ascii[k] = ' ';
            } else if (gray < 2) {
                ascii[k] = '.';
            } else if (gray < 3) {
                ascii[k] = ':';
            } else if (gray < 4) {
                ascii[k] = '-';
            } else if (gray < 5) {
                ascii[k] = '=';
            } else if (gray < 6) {
                ascii[k] = '+';
            } else if (gray < 7) {
                ascii[k] = '*';
            } else if (gray < 8) {
                ascii[k] = '#';
            } else {
                ascii[k] = '@';
            }
        }
        ascii[k] = '\n';
    }
    ascii[k] = '\0';
}

// Function to load an image from a file
Image *loadImage(const char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        return NULL;
    }

    // Read the image data
    Image *img = malloc(sizeof(Image));
    fread(img, sizeof(Image), 1, fp);

    // Close the file
    fclose(fp);

    // Return the image data
    return img;
}

// Function to save the ASCII art to a file
void saveAscii(const char *filename, const char *ascii) {
    // Open the file
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    // Write the ASCII art
    fprintf(fp, "%s", ascii);

    // Close the file
    fclose(fp);
}

int main(int argc, char *argv[]) {
    // Check for valid number of arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    // Load the image
    Image *img = loadImage(argv[1]);
    if (!img) {
        fprintf(stderr, "Error loading image\n");
        return 1;
    }

    // Convert the image to ASCII art
    char ascii[img->height * img->width + 1];
    image2ascii(img, ascii);

    // Save the ASCII art to a file
    saveAscii("output.txt", ascii);

    // Free the image data
    free(img);

    return 0;
}