//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLOR_VALUE 255

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    char header[3];
    int width;
    int height;
    Pixel* pixels;
} Image;

Image* load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return NULL;
    }
    Image* img = (Image*)malloc(sizeof(Image));
    fread(img->header, sizeof(char), 3, file);
    fread(&img->width, sizeof(int), 1, file);
    fread(&img->height, sizeof(int), 1, file);
    img->pixels = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void save_image(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return;
    }
    fwrite(img->header, sizeof(char), 3, file);
    fwrite(&img->width, sizeof(int), 1, file);
    fwrite(&img->height, sizeof(int), 1, file);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image* img) {
    Pixel temp;
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            temp = img->pixels[y * img->width + x];
            img->pixels[y * img->width + x] = img->pixels[y * img->width + (img->width - 1 - x)];
            img->pixels[y * img->width + (img->width - 1 - x)] = temp;
        }
    }
}

void change_brightness(Image* img, int delta) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (img->pixels[i].r + delta > MAX_COLOR_VALUE) ? MAX_COLOR_VALUE : 
                           (img->pixels[i].r + delta < 0) ? 0 : img->pixels[i].r + delta;
        img->pixels[i].g = (img->pixels[i].g + delta > MAX_COLOR_VALUE) ? MAX_COLOR_VALUE : 
                           (img->pixels[i].g + delta < 0) ? 0 : img->pixels[i].g + delta;
        img->pixels[i].b = (img->pixels[i].b + delta > MAX_COLOR_VALUE) ? MAX_COLOR_VALUE : 
                           (img->pixels[i].b + delta < 0) ? 0 : img->pixels[i].b + delta;
    }
}

void change_contrast(Image* img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (img->pixels[i].r-128) * factor + 128;
        img->pixels[i].g = (img->pixels[i].g-128) * factor + 128;
        img->pixels[i].b = (img->pixels[i].b-128) * factor + 128;

        img->pixels[i].r = (img->pixels[i].r > MAX_COLOR_VALUE) ? MAX_COLOR_VALUE : 
                           (img->pixels[i].r < 0) ? 0 : img->pixels[i].r;
        
        img->pixels[i].g = (img->pixels[i].g > MAX_COLOR_VALUE) ? MAX_COLOR_VALUE : 
                           (img->pixels[i].g < 0) ? 0 : img->pixels[i].g;
        
        img->pixels[i].b = (img->pixels[i].b > MAX_COLOR_VALUE) ? MAX_COLOR_VALUE : 
                           (img->pixels[i].b < 0) ? 0 : img->pixels[i].b;
    }
}

void free_image(Image* img) {
    free(img->pixels);
    free(img);
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <operation> [params]\n", argv[0]);
        return 1;
    }

    Image* img = load_image(argv[1]);
    if (!img) return 1;

    if (strcmp(argv[3], "flip") == 0) {
        flip_image(img);
    } else if (strcmp(argv[3], "brightness") == 0) {
        if (argc != 5) {
            fprintf(stderr, "Brightness requires a delta value\n");
            free_image(img);
            return 1;
        }
        int delta = atoi(argv[4]);
        change_brightness(img, delta);
    } else if (strcmp(argv[3], "contrast") == 0) {
        if (argc != 5) {
            fprintf(stderr, "Contrast requires a factor value\n");
            free_image(img);
            return 1;
        }
        float factor = atof(argv[4]);
        change_contrast(img, factor);
    } else {
        fprintf(stderr, "Unknown operation %s\n", argv[3]);
        free_image(img);
        return 1;
    }

    save_image(argv[2], img);
    free_image(img);
    return 0;
}