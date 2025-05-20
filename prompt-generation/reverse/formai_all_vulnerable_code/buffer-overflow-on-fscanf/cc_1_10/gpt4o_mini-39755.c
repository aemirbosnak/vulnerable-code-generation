//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Image;

Image *readPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format); 
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported format: %s\n", format);
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // Consume the newline after maxval

    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    
    return img;
}

void writePPM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Cannot open file");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flipImageHorizontally(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int oppositeX = img->width - 1 - x;
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + oppositeX];
            img->data[y * img->width + oppositeX] = temp;
        }
    }
}

void changeBrightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char) fmin(fmax(img->data[i].r + value, 0), 255);
        img->data[i].g = (unsigned char) fmin(fmax(img->data[i].g + value, 0), 255);
        img->data[i].b = (unsigned char) fmin(fmax(img->data[i].b + value, 0), 255);
    }
}

void changeContrast(Image *img, float contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char) fmin(fmax((1.0 + contrast) * img->data[i].r - 128.0 * contrast, 0), 255);
        img->data[i].g = (unsigned char) fmin(fmax((1.0 + contrast) * img->data[i].g - 128.0 * contrast, 0), 255);
        img->data[i].b = (unsigned char) fmin(fmax((1.0 + contrast) * img->data[i].b - 128.0 * contrast, 0), 255);
    }
}

void freeImage(Image *img) {
    free(img->data);
    free(img);
}

int main() {
    const char *inputFile = "input.ppm";
    const char *flippedFile = "flipped.ppm";
    const char *brightenedFile = "brightened.ppm";
    const char *contrastedFile = "contrasted.ppm";

    Image *img = readPPM(inputFile);
    if (!img) {
        return EXIT_FAILURE;
    }

    // Flip the image horizontally
    flipImageHorizontally(img);
    writePPM(flippedFile, img);
    
    // Change brightness
    changeBrightness(img, 50); // Increase brightness
    writePPM(brightenedFile, img);
    
    // Change contrast
    changeContrast(img, 0.5); // Increase contrast
    writePPM(contrastedFile, img);

    freeImage(img);
    printf("Image processing completed successfully!\n");
    return EXIT_SUCCESS;
}