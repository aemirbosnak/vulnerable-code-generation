//FormAI DATASET v1.0 Category: Image Editor ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_PIXEL_VAL 255

typedef struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

typedef struct Image {
    int height;
    int width;
    Pixel *pixels;
} Image;

Image load_image(const char *filename) {
    FILE *infile = fopen(filename, "rb");
    if (!infile) {
        printf("Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    // Read the magic number and dimensions
    char magic_number[3];
    fgets(magic_number, 4, infile);
    int width, height;
    fscanf(infile, "%d %d\n", &width, &height);
    
    // Read the maximum pixel value
    int maxval;
    fscanf(infile, "%d\n", &maxval);
    if (maxval > MAX_PIXEL_VAL) {
        printf("Error: Image is not in PPM format.\n");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the pixels
    Pixel *pixels = (Pixel *)malloc(sizeof(Pixel) * width * height);

    // Read in the pixel data
    for (int i = 0; i < width * height; i++) {
        int r, g, b;
        fscanf(infile, "%d %d %d", &r, &g, &b);
        pixels[i].red = (unsigned char)r;
        pixels[i].green = (unsigned char)g;
        pixels[i].blue = (unsigned char)b;
    }

    fclose(infile);

    Image image = {
        .height = height,
        .width = width,
        .pixels = pixels
    };

    return image;
}

void save_image(const Image *image, const char *filename) {
    FILE *outfile = fopen(filename, "wb");

    // Write the magic number, dimensions, and maximum pixel value
    fprintf(outfile, "P6\n%d %d\n%d\n", image->width, image->height, MAX_PIXEL_VAL);

    // Write the pixel data
    for (int i = 0; i < image->width * image->height; i++) {
        fputc(image->pixels[i].red, outfile);
        fputc(image->pixels[i].green, outfile);
        fputc(image->pixels[i].blue, outfile);
    }

    fclose(outfile);
}

Image grayscale(const Image *image) {
    Image gray_image = {
        .height = image->height,
        .width = image->width,
        .pixels = (Pixel *)malloc(sizeof(Pixel) * image->width * image->height)
    };

    // Convert each pixel to grayscale
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->pixels[i].red + image->pixels[i].green + image->pixels[i].blue) / 3;
        gray_image.pixels[i].red = gray;
        gray_image.pixels[i].green = gray;
        gray_image.pixels[i].blue = gray;
    }

    return gray_image;
}

Image invert(const Image *image) {
    Image inverted_image = {
        .height = image->height,
        .width = image->width,
        .pixels = (Pixel *)malloc(sizeof(Pixel) * image->width * image->height)
    };

    // Invert each pixel
    for (int i = 0; i < image->width * image->height; i++) {
        inverted_image.pixels[i].red = MAX_PIXEL_VAL - image->pixels[i].red;
        inverted_image.pixels[i].green = MAX_PIXEL_VAL - image->pixels[i].green;
        inverted_image.pixels[i].blue = MAX_PIXEL_VAL - image->pixels[i].blue;
    }

    return inverted_image;
}

Image blend(const Image *image1, const Image *image2) {
    Image blended_image = {
        .height = image1->height,
        .width = image1->width,
        .pixels = (Pixel *)malloc(sizeof(Pixel) * image1->width * image1->height)
    };

    // Blend each pixel
    for (int i = 0; i < image1->width * image1->height; i++) {
        blended_image.pixels[i].red = (image1->pixels[i].red + image2->pixels[i].red) / 2;
        blended_image.pixels[i].green = (image1->pixels[i].green + image2->pixels[i].green) / 2;
        blended_image.pixels[i].blue = (image1->pixels[i].blue + image2->pixels[i].blue) / 2;
    }

    return blended_image;
}

int main() {
    char filename1[MAX_FILENAME_LENGTH], filename2[MAX_FILENAME_LENGTH];
    printf("Enter filename of first image: ");
    scanf("%s", filename1);

    Image image1 = load_image(filename1);

    printf("Enter filename of second image: ");
    scanf("%s", filename2);

    Image image2 = load_image(filename2);

    Image gray_image = grayscale(&image1);

    Image inverted_image = invert(&image2);

    Image blended_image = blend(&image1, &image2);

    char gray_filename[MAX_FILENAME_LENGTH];
    strcpy(gray_filename, "gray_");
    strcat(gray_filename, filename1);
    save_image(&gray_image, gray_filename);

    char inverted_filename[MAX_FILENAME_LENGTH];
    strcpy(inverted_filename, "inverted_");
    strcat(inverted_filename, filename2);
    save_image(&inverted_image, inverted_filename);

    char blended_filename[MAX_FILENAME_LENGTH];
    strcpy(blended_filename, "blended_");
    strcat(blended_filename, filename1);
    strcat(blended_filename, "_");
    strcat(blended_filename, filename2);
    save_image(&blended_image, blended_filename);

    free(image1.pixels);
    free(image2.pixels);
    free(gray_image.pixels);
    free(inverted_image.pixels);
    free(blended_image.pixels);

    return 0;
}