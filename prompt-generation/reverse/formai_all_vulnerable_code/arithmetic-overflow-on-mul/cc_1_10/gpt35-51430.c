//FormAI DATASET v1.0 Category: Image Editor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for Pixel with RGB values
typedef struct Pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

// Define struct for Image with size and array of pixels
typedef struct Image {
    int width;
    int height;
    Pixel* pixels;
} Image;

// Function to load an image from a file
Image* loadImage(char* filename) {
    FILE* fptr = fopen(filename, "rb");
    if (fptr == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return NULL;
    }

    // Read the header of the BMP file
    int headerSize = 54; // BMP header size
    unsigned char header[headerSize];
    fread(header, sizeof(unsigned char), headerSize, fptr);

    // Read the width and height of the image
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // Allocate memory for image and pixel array
    Image* image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(sizeof(Pixel) * width * height);

    // Read the pixel data and store it in the pixel array
    int padding = (4 - (width * sizeof(Pixel)) % 4) % 4;
    for (int i = height - 1; i >= 0; i--) {
        for (int j = 0; j < width; j++) {
            Pixel* pixel = &image->pixels[i * width + j];
            fread(&pixel->b, sizeof(unsigned char), 1, fptr);
            fread(&pixel->g, sizeof(unsigned char), 1, fptr);
            fread(&pixel->r, sizeof(unsigned char), 1, fptr);
        }
        fseek(fptr, padding, SEEK_CUR);
    }

    fclose(fptr);
    return image;
}

// Function to save an image to a file
void saveImage(Image* image, char* filename) {
    FILE* fptr = fopen(filename, "wb");
    if (fptr == NULL) {
        fprintf(stderr, "Error: Unable to create file %s\n", filename);
        return;
    }

    // Write the header of the BMP file
    int headerSize = 54;
    unsigned char header[headerSize];
    memset(header, 0, headerSize);
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = headerSize + image->width * image->height * sizeof(Pixel);
    *(int*)&header[10] = headerSize;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = image->width;
    *(int*)&header[22] = image->height;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;

    fwrite(header, sizeof(unsigned char), headerSize, fptr);

    // Write the pixel data to the file
    int padding = (4 - (image->width * sizeof(Pixel)) % 4) % 4;
    for (int i = image->height - 1; i >= 0; i--) {
        for (int j = 0; j < image->width; j++) {
            Pixel* pixel = &image->pixels[i * image->width + j];
            fwrite(&pixel->b, sizeof(unsigned char), 1, fptr);
            fwrite(&pixel->g, sizeof(unsigned char), 1, fptr);
            fwrite(&pixel->r, sizeof(unsigned char), 1, fptr);
        }
        for (int j = 0; j < padding; j++) {
            fputc(0, fptr);
        }
    }

    fclose(fptr);
    printf("Image saved to file %s\n", filename);
}

// Function to convert a color image to grayscale
void grayscale(Image* image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel* pixel = &image->pixels[i * image->width + j];
            unsigned char gray = 0.2126 * pixel->r + 0.7152 * pixel->g + 0.0722 * pixel->b;
            pixel->r = gray;
            pixel->g = gray;
            pixel->b = gray;
        }
    }
}

// Function to apply a sepia tone to an image
void sepia(Image* image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel* pixel = &image->pixels[i * image->width + j];
            unsigned char r = 0.393 * pixel->r + 0.769 * pixel->g + 0.189 * pixel->b;
            unsigned char g = 0.349 * pixel->r + 0.686 * pixel->g + 0.168 * pixel->b;
            unsigned char b = 0.272 * pixel->r + 0.534 * pixel->g + 0.131 * pixel->b;
            pixel->r = r > 255 ? 255 : r;
            pixel->g = g > 255 ? 255 : g;
            pixel->b = b > 255 ? 255 : b;
        }
    }
}

// Function to apply a negative filter to an image
void negative(Image* image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel* pixel = &image->pixels[i * image->width + j];
            pixel->r = 255 - pixel->r;
            pixel->g = 255 - pixel->g;
            pixel->b = 255 - pixel->b;
        }
    }
}

// Main function to test image editor functions
int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input.bmp output.bmp mode\n", argv[0]);
        fprintf(stderr, "  mode: 1 - grayscale, 2 - sepia, 3 - negative\n");
        return 1;
    }

    int mode = atoi(argv[3]);

    Image* image = loadImage(argv[1]);
    if (image == NULL) {
        fprintf(stderr, "Failed to load image %s\n", argv[1]);
        return 1;
    }

    switch (mode) {
    case 1:
        grayscale(image);
        break;
    case 2:
        sepia(image);
        break;
    case 3:
        negative(image);
        break;
    default:
        fprintf(stderr, "Invalid mode %d\n", mode);
        return 1;
    }

    saveImage(image, argv[2]);

    free(image->pixels);
    free(image);

    return 0;
}