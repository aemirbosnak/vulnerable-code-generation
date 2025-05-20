//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

Image* load_image(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return NULL;
    }

    char format[3];
    fscanf(f, "%s\n", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported file format. Only P6 (PPM) format is supported.\n");
        fclose(f);
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(f, "%d %d\n255\n", &img->width, &img->height);
    img->pixels = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));

    fread(img->pixels, sizeof(Pixel), img->width * img->height, f);
    fclose(f);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *f = fopen(filename, "wb");
    if (!f) {
        fprintf(stderr, "Unable to open file %s\n", filename);
        return;
    }

    fprintf(f, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, f);
    fclose(f);
}

void flip_image(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int opposite_x = img->width - 1 - x;
            Pixel temp = img->pixels[y * img->width + x];
            img->pixels[y * img->width + x] = img->pixels[y * img->width + opposite_x];
            img->pixels[y * img->width + opposite_x] = temp;
        }
    }
}

void adjust_brightness_contrast(Image *img, int brightness, float contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (unsigned char)clamp(img->pixels[i].r + brightness, 0, 255);
        img->pixels[i].g = (unsigned char)clamp(img->pixels[i].g + brightness, 0, 255);
        img->pixels[i].b = (unsigned char)clamp(img->pixels[i].b + brightness, 0, 255);

        float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
        img->pixels[i].r = (unsigned char)clamp(factor * (img->pixels[i].r - 128) + 128, 0, 255);
        img->pixels[i].g = (unsigned char)clamp(factor * (img->pixels[i].g - 128) + 128, 0, 255);
        img->pixels[i].b = (unsigned char)clamp(factor * (img->pixels[i].b - 128) + 128, 0, 255);
    }
}

int clamp(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

void free_image(Image *img) {
    if (img) {
        free(img->pixels);
        free(img);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    Image *img = load_image(argv[1]);
    if (!img) return 1;

    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    flip_image(img);
    adjust_brightness_contrast(img, brightness, contrast);

    save_image(argv[2], img);
    free_image(img);

    printf("Image processing done!\n");
    return 0;
}