//Code Llama-13B DATASET v1.0 Category: Image to ASCII art converter ; Style: dynamic
/*
 * Image to ASCII art converter in C
 *
 * This program takes an image file as input and converts it to an ASCII art representation.
 * The output is printed to the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_HEIGHT 100
#define MAX_WIDTH 100

/*
 * Structure to represent an image
 */
struct image {
    unsigned char pixels[MAX_HEIGHT][MAX_WIDTH];
    int height;
    int width;
};

/*
 * Function to load an image from a file
 */
struct image load_image(const char *filename) {
    struct image img;
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: unable to open file %s\n", filename);
        exit(1);
    }
    fread(&img.height, sizeof(int), 1, file);
    fread(&img.width, sizeof(int), 1, file);
    fread(img.pixels, sizeof(unsigned char), img.height * img.width, file);
    fclose(file);
    return img;
}

/*
 * Function to convert an image to ASCII art
 */
void convert_to_ascii(struct image *img) {
    int i, j;
    char *ascii_chars = " .,:;i1tfLCG08@";
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            unsigned char pixel = img->pixels[i][j];
            int index = pixel * (strlen(ascii_chars) - 1) / 255;
            printf("%c", ascii_chars[index]);
        }
        printf("\n");
    }
}

/*
 * Main function
 */
int main(int argc, char **argv) {
    struct image img;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        exit(1);
    }
    img = load_image(argv[1]);
    convert_to_ascii(&img);
    return 0;
}