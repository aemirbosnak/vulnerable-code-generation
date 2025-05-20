//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

void freeImage(Image *img) {
    free(img->data);
    img->data = NULL;
}

int loadPPM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading.\n", filename);
        return -1;
    }

    char format[3];
    fscanf(file, "%2s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported format: %s\n", format);
        fclose(file);
        return -1;
    }

    fscanf(file, "%d %d", &img->width, &img->height);
    int maxVal;
    fscanf(file, "%d", &maxVal);
    fgetc(file);  // Consume the newline after maxVal

    img->data = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return 0;
}

int savePPM(const char *filename, const Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing.\n", filename);
        return -1;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return 0;
}

void flipImage(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + (img->width - x - 1)];
            img->data[y * img->width + (img->width - x - 1)] = temp;
        }
    }
}

void changeBrightnessContrast(Image *img, int brightness, float contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char)fmax(0, fmin(255, (contrast * (img->data[i].r - 128)) + 128 + brightness));
        img->data[i].g = (unsigned char)fmax(0, fmin(255, (contrast * (img->data[i].g - 128)) + 128 + brightness));
        img->data[i].b = (unsigned char)fmax(0, fmin(255, (contrast * (img->data[i].b - 128)) + 128 + brightness));
    }
}

void printUsage(const char *programName) {
    printf("Usage: %s <input_file> <output_file> <brightness> <contrast>\n", programName);
    printf("  brightness: integer value (-255 to 255)\n");
    printf("  contrast: float value (0.0 to 3.0)\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printUsage(argv[0]);
        return 1;
    }

    Image img;
    if (loadPPM(argv[1], &img) != 0) {
        return 1;
    }

    flipImage(&img);

    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);
    changeBrightnessContrast(&img, brightness, contrast);

    if (savePPM(argv[2], &img) != 0) {
        freeImage(&img);
        return 1;
    }

    freeImage(&img);
    printf("Processing completed successfully.\n");
    return 0;
}