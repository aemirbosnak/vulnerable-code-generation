//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

// Structure to hold the PGM image properties
typedef struct {
    int width;
    int height;
    int maxval;
    unsigned char **pixels;
} PGMImage;

// Function to read a PGM image
PGMImage* readPGM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Could not open file %s for reading.\n", filename);
        return NULL;
    }

    PGMImage *img = (PGMImage *)malloc(sizeof(PGMImage));
    if (img == NULL) {
        printf("Memory allocation failed for PGMImage.\n");
        fclose(file);
        return NULL;
    }

    // Read header
    char format[3];
    fscanf(file, "%s", format);
    fscanf(file, "%d %d", &img->width, &img->height);
    fscanf(file, "%d", &img->maxval);

    // Allocate memory for pixel data
    img->pixels = (unsigned char **)malloc(img->height * sizeof(unsigned char *));
    for (int i = 0; i < img->height; i++) {
        img->pixels[i] = (unsigned char *)malloc(img->width * sizeof(unsigned char));
    }

    // Read pixel data
    for (int i = 0; i < img->height; i++) {
        fread(img->pixels[i], sizeof(unsigned char), img->width, file);
    }

    fclose(file);
    return img;
}

// Function to write a PGM image
void writePGM(const char *filename, PGMImage *img) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Could not open file %s for writing.\n", filename);
        return;
    }

    fprintf(file, "P5\n%d %d\n%d\n", img->width, img->height, img->maxval);
    for (int i = 0; i < img->height; i++) {
        fwrite(img->pixels[i], sizeof(unsigned char), img->width, file);
    }

    fclose(file);
}

// Function to embed a watermark into the image
void embedWatermark(PGMImage *img, const char *watermark) {
    int w_len = strlen(watermark);
    int w_index = 0;
    for (int y = 0; y < img->height && w_index < w_len; y++) {
        for (int x = 0; x < img->width && w_index < w_len; x++) {
            // Embed the watermark character into the least significant bit
            img->pixels[y][x] = (img->pixels[y][x] & ~1) | ((watermark[w_index] >> (7 - (x % 8))) & 1);
            if (x % 8 == 7) {
                w_index++;  // Move to the next character after 8 bits
            }
        }
    }
}

// Function to free the PGM image memory
void freePGMImage(PGMImage *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

// Main function
int main(int argc, char *argv[]) {
    printf("Welcome to the Digital Watermarking Program!\n");
    if (argc < 3) {
        printf("Usage: %s <input.pgm> <output.pgm> <watermark>\n", argv[0]);
        return 1;
    }

    PGMImage *image = readPGM(argv[1]);
    if (image == NULL) {
        return 1;
    }

    embedWatermark(image, argv[3]);
    writePGM(argv[2], image);
    freePGMImage(image);

    printf("Watermark embedded successfully into %s.\n", argv[2]);
    return 0;
}