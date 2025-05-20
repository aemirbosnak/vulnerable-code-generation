//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    pixel *data;
    int width, height;
} image;

image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[18];
    if (fread(header, sizeof(header), 1, fp) != 1) {
        fprintf(stderr, "Error: could not read header from file '%s'\n", filename);
        fclose(fp);
        return NULL;
    }

    // Check if the file is a valid BMP file
    if (memcmp(header, "BM", 2) != 0) {
        fprintf(stderr, "Error: '%s' is not a valid BMP file\n", filename);
        fclose(fp);
        return NULL;
    }

    // Get the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Allocate memory for the image data
    image *img = malloc(sizeof(image));
    if (img == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(fp);
        return NULL;
    }

    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(pixel));
    if (img->data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        free(img);
        fclose(fp);
        return NULL;
    }

    // Read the image data
    if (fread(img->data, sizeof(pixel), width * height, fp) != width * height) {
        fprintf(stderr, "Error: could not read image data from file '%s'\n", filename);
        free(img->data);
        free(img);
        fclose(fp);
        return NULL;
    }

    fclose(fp);
    return img;
}

void free_image(image *img) {
    free(img->data);
    free(img);
}

void convert_to_ascii(image *img, char *ascii_art) {
    int i, j, k;
    const char *chars = " .,:;irsXA253hg9WM#*&@";
    int len = strlen(chars);

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            int index = (i * img->width + j) * 3;
            int gray = (img->data[index].r + img->data[index].g + img->data[index].b) / 3;
            int char_index = (int)((float)gray / 255.0 * (len - 1));
            ascii_art[i * WIDTH + j] = chars[char_index];
        }
        ascii_art[i * WIDTH + j] = '\n';
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    image *img = load_image(argv[1]);
    if (img == NULL) {
        return 1;
    }

    char *ascii_art = malloc(WIDTH * HEIGHT + 1);
    if (ascii_art == NULL) {
        fprintf(stderr, "Error: could not allocate memory for ASCII art\n");
        free_image(img);
        return 1;
    }

    convert_to_ascii(img, ascii_art);

    printf("%s", ascii_art);

    free(ascii_art);
    free_image(img);

    return 0;
}