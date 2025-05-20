//Code Llama-13B DATASET v1.0 Category: Image to ASCII art converter ; Style: portable
// Image to ASCII art converter
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a pixel
struct pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

// Structure to represent an image
struct image {
    int width;
    int height;
    struct pixel *pixels;
};

// Function to convert an image to ASCII art
void convert_to_ascii_art(struct image *img) {
    int i, j;
    char *ascii_art = malloc(sizeof(char) * (img->width * img->height));
    for (i = 0; i < img->width; i++) {
        for (j = 0; j < img->height; j++) {
            struct pixel *pixel = &img->pixels[i * img->width + j];
            int value = (pixel->r + pixel->g + pixel->b) / 3;
            ascii_art[i * img->width + j] = (value < 64) ? '@' : (value < 128) ? '#' : (value < 192) ? '$' : (value < 256) ? '%' : '*';
        }
    }
    printf("%s\n", ascii_art);
    free(ascii_art);
}

// Function to load an image from a file
struct image *load_image(char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    struct image *img = malloc(sizeof(struct image));
    fread(&img->width, sizeof(int), 1, file);
    fread(&img->height, sizeof(int), 1, file);
    img->pixels = malloc(sizeof(struct pixel) * img->width * img->height);
    fread(img->pixels, sizeof(struct pixel), img->width * img->height, file);

    fclose(file);
    return img;
}

// Function to save an image to a file
void save_image(struct image *img, char *filename) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    fwrite(&img->width, sizeof(int), 1, file);
    fwrite(&img->height, sizeof(int), 1, file);
    fwrite(img->pixels, sizeof(struct pixel), img->width * img->height, file);

    fclose(file);
}

int main() {
    struct image *img = load_image("image.jpg");
    convert_to_ascii_art(img);
    save_image(img, "ascii_art.txt");
    free(img);
    return 0;
}