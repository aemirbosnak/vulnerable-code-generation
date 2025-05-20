//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

// Function to create an empty image
Image *createImage(int width, int height) {
    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(sizeof(Pixel) * width * height);
    return img;
}

// Function to free image memory
void freeImage(Image *img) {
    free(img->pixels);
    free(img);
}

// Function to read a PPM image
Image *readPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(1);
    }

    char header[3];
    fscanf(file, "%s\n", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Error: Unsupported PPM format\n");
        fclose(file);
        exit(1);
    }

    Image *img = createImage(0, 0);
    fscanf(file, "%d %d\n255\n", &img->width, &img->height);
    img->pixels = malloc(sizeof(Pixel) * img->width * img->height);
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

// Function to write a PPM image
void writePPM(const char *filename, const Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        exit(1);
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

// Function to invert color
void invertColors(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = 255 - img->pixels[i].r;
        img->pixels[i].g = 255 - img->pixels[i].g;
        img->pixels[i].b = 255 - img->pixels[i].b;
    }
}

// Function to convert image to grayscale
void convertToGrayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (img->pixels[i].r + img->pixels[i].g + img->pixels[i].b) / 3;
        img->pixels[i].r = gray;
        img->pixels[i].g = gray;
        img->pixels[i].b = gray;
    }
}

// Function to adjust brightness
void adjustBrightness(Image *img, int amount) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (img->pixels[i].r + amount > 255) ? 255 : (img->pixels[i].r + amount < 0) ? 0 : img->pixels[i].r + amount;
        img->pixels[i].g = (img->pixels[i].g + amount > 255) ? 255 : (img->pixels[i].g + amount < 0) ? 0 : img->pixels[i].g + amount;
        img->pixels[i].b = (img->pixels[i].b + amount > 255) ? 255 : (img->pixels[i].b + amount < 0) ? 0 : img->pixels[i].b + amount;
    }
}

// Main function - image editing menu
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return 1;
    }

    Image *img = readPPM(argv[1]);
    int choice, brightness;

    printf("Choose an operation:\n");
    printf("1. Invert Colors\n");
    printf("2. Convert to Grayscale\n");
    printf("3. Adjust Brightness\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            invertColors(img);
            printf("Inverted colors.\n");
            break;
        case 2:
            convertToGrayscale(img);
            printf("Converted to grayscale.\n");
            break;
        case 3:
            printf("Enter brightness adjustment value (-255 to 255): ");
            scanf("%d", &brightness);
            adjustBrightness(img, brightness);
            printf("Adjusted brightness by %d.\n", brightness);
            break;
        default:
            printf("Invalid choice.\n");
            freeImage(img);
            return 1;
    }

    writePPM(argv[2], img);
    printf("Image saved as %s\n", argv[2]);
    freeImage(img);
    return 0;
}