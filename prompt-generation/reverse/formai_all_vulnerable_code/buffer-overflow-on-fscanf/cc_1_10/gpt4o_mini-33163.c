//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} RGB;

typedef struct {
    int width, height;
    RGB *data;
} Image;

// Function declarations
Image* loadPPM(const char *filename);
void savePPM(const char *filename, const Image *image);
void applyGrayscale(Image *image);
void freeImage(Image *image);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = loadPPM(argv[1]);
    if (!image) {
        fprintf(stderr, "Error loading image.\n");
        return EXIT_FAILURE;
    }

    applyGrayscale(image);

    savePPM(argv[2], image);
    freeImage(image);

    printf("Image processed and saved to %s\n", argv[2]);
    return EXIT_SUCCESS;
}

Image* loadPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s\n", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format. Only P6 is supported.\n");
        fclose(file);
        return NULL;
    }

    Image *image = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d\n", &image->width, &image->height);
    
    int maxVal;
    fscanf(file, "%d\n", &maxVal);
    if (maxVal != 255) {
        fprintf(stderr, "Unsupported max value. Only 255 is supported.\n");
        fclose(file);
        free(image);
        return NULL;
    }

    image->data = (RGB *)malloc(image->width * image->height * sizeof(RGB));
    fread(image->data, sizeof(RGB), image->width * image->height, file);
    
    fclose(file);
    return image;
}

void savePPM(const char *filename, const Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Cannot open file");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(RGB), image->width * image->height, file);
    
    fclose(file);
}

void applyGrayscale(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (unsigned char)(0.3 * image->data[i].r + 0.59 * image->data[i].g + 0.11 * image->data[i].b);
        image->data[i].r = gray;
        image->data[i].g = gray;
        image->data[i].b = gray;
    }
}

void freeImage(Image *image) {
    if (image) {
        free(image->data);
        free(image);
    }
}