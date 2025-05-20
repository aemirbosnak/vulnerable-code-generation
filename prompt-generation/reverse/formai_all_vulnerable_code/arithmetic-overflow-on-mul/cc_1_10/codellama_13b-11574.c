//Code Llama-13B DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
/*
 * Convert an image to ASCII art.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

/*
 * Structure to store pixel data.
 */
typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

/*
 * Structure to store image data.
 */
typedef struct {
    int width;
    int height;
    Pixel pixels[MAX_WIDTH][MAX_HEIGHT];
} Image;

/*
 * Load an image from a file.
 */
Image load_image(char *filename) {
    Image image;
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", filename);
        exit(1);
    }

    // Read the width and height of the image.
    fread(&image.width, sizeof(int), 1, fp);
    fread(&image.height, sizeof(int), 1, fp);

    // Read the pixel data.
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            fread(&image.pixels[x][y].red, sizeof(int), 1, fp);
            fread(&image.pixels[x][y].green, sizeof(int), 1, fp);
            fread(&image.pixels[x][y].blue, sizeof(int), 1, fp);
        }
    }

    fclose(fp);
    return image;
}

/*
 * Convert an image to ASCII art.
 */
void convert_image(Image image, char *ascii_art) {
    // Calculate the maximum intensity of the image.
    int max_intensity = 0;
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            int intensity = image.pixels[x][y].red + image.pixels[x][y].green + image.pixels[x][y].blue;
            if (intensity > max_intensity) {
                max_intensity = intensity;
            }
        }
    }

    // Convert the image to ASCII art.
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            int intensity = image.pixels[x][y].red + image.pixels[x][y].green + image.pixels[x][y].blue;
            int ascii_char = (intensity * 95) / max_intensity;
            ascii_art[y * image.width + x] = ascii_char + 33;
        }
    }
    ascii_art[image.width * image.height] = '\0';
}

/*
 * Save the ASCII art to a file.
 */
void save_ascii_art(char *ascii_art, char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", filename);
        exit(1);
    }

    fprintf(fp, "%s", ascii_art);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <image_file> <ascii_art_file>\n", argv[0]);
        return 1;
    }

    Image image = load_image(argv[1]);
    char ascii_art[MAX_WIDTH * MAX_HEIGHT + 1];
    convert_image(image, ascii_art);
    save_ascii_art(ascii_art, argv[2]);

    return 0;
}