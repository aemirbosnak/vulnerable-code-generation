//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXEL_VALUE 255

/* Struct for an RGB pixel */
typedef struct {
    int r;
    int g;
    int b;
} PixelRGB;

/* Struct for an Image */
typedef struct {
    int width;
    int height;
    PixelRGB *pixels;
} Image;

/* Function to read an image from file */
Image *readImageFromFile(char *fileName) {
    FILE *file = fopen(fileName, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", fileName);
        return NULL;
    }

    char magicNumber[3];
    int width, height, maxPixelValue;

    /* Read header information */
    fscanf(file, "%2s %d %d %d", magicNumber, &width, &height, &maxPixelValue);

    if (maxPixelValue > MAX_PIXEL_VALUE) {
        fprintf(stderr, "Error: Maximum pixel value is too large for this program\n");
        return NULL;
    }

    /* Skip over any comments in the file */
    char c = fgetc(file);
    while (c == '#') {
        while (c != '\n') {
            c = fgetc(file);
        }
        c = fgetc(file);
    }
    /* Return the file pointer to the previous character, which was not a '#' */
    fseek(file, -1, SEEK_CUR);

    /* Allocate memory for the image */
    Image *image = (Image *) malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: Could not allocate memory for image\n");
        return NULL;
    }
    image->width = width;
    image->height = height;
    image->pixels = (PixelRGB *) malloc(sizeof(PixelRGB) * width * height);
    if (!image->pixels) {
        fprintf(stderr, "Error: Could not allocate memory for image pixels\n");
        free(image);
        return NULL;
    }

    /* Read in the pixel values */
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            PixelRGB *p = &image->pixels[i * width + j];
            fscanf(file, "%d %d %d", &p->r, &p->g, &p->b);
        }
    }

    /* Close the file */
    fclose(file);

    return image;
}

/* Function to write an image to file */
void writeImageToFile(char *fileName, Image *image) {
    FILE *file = fopen(fileName, "wb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", fileName);
        return;
    }

    /* Write the header information */
    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n", image->width, image->height);
    fprintf(file, "%d\n", MAX_PIXEL_VALUE);

    /* Write the pixel values */
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            PixelRGB *p = &image->pixels[i * image->width + j];
            fprintf(file, "%d %d %d\n", p->r, p->g, p->b);
        }
    }

    /* Close the file */
    fclose(file);
}

/* Function to flip an image horizontally */
void flipImageHorizontal(Image *image) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width / 2; j++) {
            PixelRGB *p1 = &image->pixels[i * image->width + j];
            PixelRGB *p2 = &image->pixels[i * image->width + (image->width - j - 1)];
            /* Swap the pixel values */
            PixelRGB temp = *p1;
            *p1 = *p2;
            *p2 = temp;
        }
    }
}

/* Function to adjust the brightness of an image */
void adjustBrightness(Image *image, int amount) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            PixelRGB *p = &image->pixels[i * image->width + j];
            /* Adjust the brightness of each pixel by the specified amount */
            p->r = p->r + amount;
            p->g = p->g + amount;
            p->b = p->b + amount;
            /* Ensure that the pixel values do not fall outside the valid range */
            if (p->r < 0) {
                p->r = 0;
            } else if (p->r > MAX_PIXEL_VALUE) {
                p->r = MAX_PIXEL_VALUE;
            }
            if (p->g < 0) {
                p->g = 0;
            } else if (p->g > MAX_PIXEL_VALUE) {
                p->g = MAX_PIXEL_VALUE;
            }
            if (p->b < 0) {
                p->b = 0;
            } else if (p->b > MAX_PIXEL_VALUE) {
                p->b = MAX_PIXEL_VALUE;
            }
        }
    }
}

/* Function to adjust the contrast of an image */
void adjustContrast(Image *image, double amount) {
    int i, j;
    for (i = 0; i < image->height; i++) {
        for (j = 0; j < image->width; j++) {
            PixelRGB *p = &image->pixels[i * image->width + j];
            /* Adjust the contrast of each pixel by the specified amount */
            p->r = (int) ((p->r - MAX_PIXEL_VALUE / 2) * amount + MAX_PIXEL_VALUE / 2);
            p->g = (int) ((p->g - MAX_PIXEL_VALUE / 2) * amount + MAX_PIXEL_VALUE / 2);
            p->b = (int) ((p->b - MAX_PIXEL_VALUE / 2) * amount + MAX_PIXEL_VALUE / 2);
            /* Ensure that the pixel values do not fall outside the valid range */
            if (p->r < 0) {
                p->r = 0;
            } else if (p->r > MAX_PIXEL_VALUE) {
                p->r = MAX_PIXEL_VALUE;
            }
            if (p->g < 0) {
                p->g = 0;
            } else if (p->g > MAX_PIXEL_VALUE) {
                p->g = MAX_PIXEL_VALUE;
            }
            if (p->b < 0) {
                p->b = 0;
            } else if (p->b > MAX_PIXEL_VALUE) {
                p->b = MAX_PIXEL_VALUE;
            }
        }
    }
}

int main(void) {
    /* Read in the image from file */
    Image *image = readImageFromFile("example_image.ppm");
    if (!image) {
        return 1;
    }

    /* Flip the image horizontally */
    flipImageHorizontal(image);

    /* Adjust the brightness of the image */
    adjustBrightness(image, 20);

    /* Adjust the contrast of the image */
    adjustContrast(image, 1.5);

    /* Write the image to file */
    writeImageToFile("processed_image.ppm", image);

    /* Free the memory allocated for the image pixels and the image struct itself */
    free(image->pixels);
    free(image);

    return 0;
}