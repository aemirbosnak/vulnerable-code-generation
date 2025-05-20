//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* loadPPM(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }
    
    Image* img = (Image*)malloc(sizeof(Image));
    char header[3];
    fscanf(file, "%s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format\n");
        fclose(file);
        free(img);
        return NULL;
    }
    
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_val;
    fscanf(file, "%d", &max_val);
    fgetc(file); // skip the newline after max value

    img->data = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void savePPM(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flipHorizontally(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + (img->width - x - 1)];
            img->data[y * img->width + (img->width - x - 1)] = temp;
        }
    }
}

void flipVertically(Image* img) {
    for (int y = 0; y < img->height / 2; y++) {
        for (int x = 0; x < img->width; x++) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[(img->height - y - 1) * img->width + x];
            img->data[(img->height - y - 1) * img->width + x] = temp;
        }
    }
}

void changeBrightnessContrast(Image* img, int brightness, float contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = fmin(fmax((int)(img->data[i].r * contrast + brightness), 0), 255);
        img->data[i].g = fmin(fmax((int)(img->data[i].g * contrast + brightness), 0), 255);
        img->data[i].b = fmin(fmax((int)(img->data[i].b * contrast + brightness), 0), 255);
    }
}

void freeImage(Image* img) {
    free(img->data);
    free(img);
}

int main(int argc, char* argv[]) {
    if (argc < 6) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <flip (h/v)> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    const char* inputFilename = argv[1];
    const char* outputFilename = argv[2];
    char flipDirection = argv[3][0];
    int brightness = atoi(argv[4]);
    float contrast = atof(argv[5]);

    Image* img = loadPPM(inputFilename);
    if (!img) {
        return 1;
    }

    if (flipDirection == 'h') {
        flipHorizontally(img);
    } else if (flipDirection == 'v') {
        flipVertically(img);
    } else {
        fprintf(stderr, "Invalid flip direction. Use 'h' for horizontal or 'v' for vertical.\n");
        freeImage(img);
        return 1;
    }

    changeBrightnessContrast(img, brightness, contrast);

    savePPM(outputFilename, img);
    freeImage(img);

    printf("Process completed successfully. Output saved to %s\n", outputFilename);
    return 0;
}