//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* loadPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    char header[3];
    if (fscanf(file, "%s", header) != 1 || header[0] != 'P' || header[1] != '6') {
        perror("Not a valid PPM file");
        fclose(file);
        return NULL;
    }

    Image *img = (Image*)malloc(sizeof(Image));
    if (!img) {
        perror("Unable to allocate memory for image");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d", &img->width, &img->height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // Consume the newline after maxval

    img->data = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    if (!img->data) {
        perror("Unable to allocate memory for pixel data");
        free(img);
        fclose(file);
        return NULL;
    }

    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void savePPM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for saving");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flipVertical(Image *img) {
    for (int y = 0; y < img->height / 2; y++) {
        for (int x = 0; x < img->width; x++) {
            int topIndex = y * img->width + x;
            int bottomIndex = (img->height - 1 - y) * img->width + x;
            Pixel temp = img->data[topIndex];
            img->data[topIndex] = img->data[bottomIndex];
            img->data[bottomIndex] = temp;
        }
    }
}

void adjustBrightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char) fmin(fmax(img->data[i].r + value, 0), 255);
        img->data[i].g = (unsigned char) fmin(fmax(img->data[i].g + value, 0), 255);
        img->data[i].b = (unsigned char) fmin(fmax(img->data[i].b + value, 0), 255);
    }
}

void adjustContrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (unsigned char) fmin(fmax(((img->data[i].r - 128) * factor) + 128, 0), 255);
        img->data[i].g = (unsigned char) fmin(fmax(((img->data[i].g - 128) * factor) + 128, 0), 255);
        img->data[i].b = (unsigned char) fmin(fmax(((img->data[i].b - 128) * factor) + 128, 0), 255);
    }
}

void freeImage(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness> <contrast>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = loadPPM(argv[1]);
    if (!img) return EXIT_FAILURE;

    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    flipVertical(img);
    adjustBrightness(img, brightness);
    adjustContrast(img, contrast);

    savePPM(argv[2], img);
    freeImage(img);

    printf("Image processing completed successfully!\n");
    return EXIT_SUCCESS;
}