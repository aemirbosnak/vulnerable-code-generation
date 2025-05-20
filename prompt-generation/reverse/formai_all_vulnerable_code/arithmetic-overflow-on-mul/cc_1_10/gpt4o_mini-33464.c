//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image* loadPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    char buf[16];
    fgets(buf, sizeof(buf), file);
    if (buf[0] != 'P' || buf[1] != '6') {
        fprintf(stderr, "Not a valid PPM file\n");
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    if (!img) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d\n255\n", &img->width, &img->height);
    img->pixels = malloc(img->width * img->height * sizeof(Pixel));
    if (!img->pixels) {
        perror("Error allocating memory for pixels");
        free(img);
        fclose(file);
        return NULL;
    }

    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void savePPM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flipImageVertically(Image *img) {
    Pixel temp;
    for (int y = 0; y < img->height / 2; y++) {
        for (int x = 0; x < img->width; x++) {
            temp = img->pixels[y * img->width + x];
            img->pixels[y * img->width + x] = img->pixels[(img->height - 1 - y) * img->width + x];
            img->pixels[(img->height - 1 - y) * img->width + x] = temp;
        }
    }
}

void changeBrightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (unsigned char) fmin(fmax(img->pixels[i].r + value, 0), 255);
        img->pixels[i].g = (unsigned char) fmin(fmax(img->pixels[i].g + value, 0), 255);
        img->pixels[i].b = (unsigned char) fmin(fmax(img->pixels[i].b + value, 0), 255);
    }
}

void adjustContrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (unsigned char) fmin(fmax((img->pixels[i].r - 128) * factor + 128, 0), 255);
        img->pixels[i].g = (unsigned char) fmin(fmax((img->pixels[i].g - 128) * factor + 128, 0), 255);
        img->pixels[i].b = (unsigned char) fmin(fmax((img->pixels[i].b - 128) * factor + 128, 0), 255);
    }
}

void freeImage(Image *img) {
    free(img->pixels);
    free(img);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness_change> <contrast_factor>\n", argv[0]);
        return 1;
    }

    Image *img = loadPPM(argv[1]);
    if (!img) {
        return 1;
    }

    int brightnessChange = atoi(argv[3]);
    float contrastFactor = atof(argv[4]);

    flipImageVertically(img);
    changeBrightness(img, brightnessChange);
    adjustContrast(img, contrastFactor);

    savePPM(argv[2], img);
    freeImage(img);
    return 0;
}