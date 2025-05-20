//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    // Read image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    Image *img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(width * height * sizeof(Pixel));

    // Read pixel data
    fread(img->pixels, sizeof(Pixel), width * height, file);
    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to save file");
        return;
    }

    fwrite(&img->width, sizeof(int), 1, file);
    fwrite(&img->height, sizeof(int), 1, file);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image *img) {
    int width = img->width;
    int height = img->height;
    Pixel *flipped = malloc(width * height * sizeof(Pixel));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            flipped[y * width + x] = img->pixels[y * width + (width - 1 - x)];
        }
    }

    free(img->pixels);
    img->pixels = flipped;
}

void change_brightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (img->pixels[i].r + value > 255) ? 255 : (img->pixels[i].r + value < 0) ? 0 : img->pixels[i].r + value;
        img->pixels[i].g = (img->pixels[i].g + value > 255) ? 255 : (img->pixels[i].g + value < 0) ? 0 : img->pixels[i].g + value;
        img->pixels[i].b = (img->pixels[i].b + value > 255) ? 255 : (img->pixels[i].b + value < 0) ? 0 : img->pixels[i].b + value;
    }
}

void change_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (uint8_t)(fmin(fmax((factor * (img->pixels[i].r - 128) + 128), 0), 255));
        img->pixels[i].g = (uint8_t)(fmin(fmax((factor * (img->pixels[i].g - 128) + 128), 0), 255));
        img->pixels[i].b = (uint8_t)(fmin(fmax((factor * (img->pixels[i].b - 128) + 128), 0), 255));
    }
}

void free_image(Image *img) {
    free(img->pixels);
    free(img);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <input_file> <output_file> <brightness_change> <contrast_factor>\n", argv[0]);
        return 1;
    }

    int brightness_change = atoi(argv[3]);
    float contrast_factor = atof(argv[4]);

    Image *img = load_image(argv[1]);
    if (!img) {
        return 1;
    }

    printf("Loaded image of size %dx%d\n", img->width, img->height);
    
    // Flip the image
    flip_image(img);
    
    // Change brightness
    change_brightness(img, brightness_change);
    
    // Change contrast
    change_contrast(img, contrast_factor);
    
    // Save the modified image
    save_image(argv[2], img);
    
    free_image(img);
    printf("Image processing completed and saved to %s\n", argv[2]);

    return 0;
}