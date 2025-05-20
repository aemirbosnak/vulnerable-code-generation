//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

// Function to load a PPM image
Image* loadImage(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s\n", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported image format\n");
        fclose(file);
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d\n255\n", &img->width, &img->height);
    
    img->data = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

// Function to save a PPM image
void saveImage(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

// Function to apply grayscale filter on the image
void applyGrayscale(Image *img) {
    for (int i = 0; i < img->width * img->height; ++i) {
        unsigned char gray = (img->data[i].r + img->data[i].g + img->data[i].b) / 3;
        img->data[i].r = gray;
        img->data[i].g = gray;
        img->data[i].b = gray;
    }
}

// Function to free the image memory
void freeImage(Image *img) {
    free(img->data);
    free(img);
}

int main() {
    const char *inputFile = "input.ppm";
    const char *outputFile = "output.ppm";

    Image *img = loadImage(inputFile);
    if (!img) {
        return EXIT_FAILURE;
    }

    printf("Loaded image: %s (%dx%d)\n", inputFile, img->width, img->height);
    applyGrayscale(img);
    printf("Applied grayscale filter.\n");

    saveImage(outputFile, img);
    printf("Saved edited image as: %s\n", outputFile);

    freeImage(img);
    return EXIT_SUCCESS;
}