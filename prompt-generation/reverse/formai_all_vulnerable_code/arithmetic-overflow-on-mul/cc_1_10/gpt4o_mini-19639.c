//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
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

Image* load_image(const char *filename);
void save_image(const char *filename, Image *image);
Image* flip_image(Image *image);
void change_brightness(Image *image, int offset);
void change_contrast(Image *image, float factor);
void free_image(Image *image);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }
    
    Image *image = load_image(argv[1]);
    if (!image) {
        fprintf(stderr, "Failed to load image.\n");
        return 1;
    }
    
    printf("Loaded image with dimensions: %dx%d\n", image->width, image->height);
    
    Image *flipped_image = flip_image(image);
    printf("Flipped image.\n");

    change_brightness(flipped_image, 50);
    printf("Increased brightness.\n");

    change_contrast(flipped_image, 1.5);
    printf("Increased contrast.\n");

    save_image("flipped_bright_contrast_image.ppm", flipped_image);
    printf("Saved processed image as 'flipped_bright_contrast_image.ppm'.\n");

    free_image(image);
    free_image(flipped_image);

    return 0;
}

Image* load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return NULL;
    }
    
    char header[3]; 
    fscanf(fp, "%2s", header);
    if (header[0] != 'P' || header[1] != '6') {
        fclose(fp);
        return NULL;
    }

    int width, height;
    fscanf(fp, "%d %d", &width, &height);
    int max_color_value;
    fscanf(fp, "%d", &max_color_value);
    
    fgetc(fp); // Consume the newline character

    Image *image = (Image *)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = (Pixel *)malloc(width * height * sizeof(Pixel));
    
    fread(image->pixels, sizeof(Pixel), width * height, fp);
    fclose(fp);
    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Failed to save image.\n");
        return;
    }

    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, fp);
    fclose(fp);
}

Image* flip_image(Image *image) {
    Image *flipped = (Image *)malloc(sizeof(Image));
    flipped->width = image->width;
    flipped->height = image->height;
    flipped->pixels = (Pixel *)malloc(image->width * image->height * sizeof(Pixel));

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            flipped->pixels[y * image->width + (image->width - x - 1)] = image->pixels[y * image->width + x];
        }
    }
    return flipped;
}

void change_brightness(Image *image, int offset) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].r = (image->pixels[i].r + offset > 255) ? 255 : (image->pixels[i].r + offset < 0) ? 0 : image->pixels[i].r + offset;
        image->pixels[i].g = (image->pixels[i].g + offset > 255) ? 255 : (image->pixels[i].g + offset < 0) ? 0 : image->pixels[i].g + offset;
        image->pixels[i].b = (image->pixels[i].b + offset > 255) ? 255 : (image->pixels[i].b + offset < 0) ? 0 : image->pixels[i].b + offset;
    }
}

void change_contrast(Image *image, float factor) {
    float midpoint = 128.0;
    for (int i = 0; i < image->width * image->height; i++) {
        int r = (int)((image->pixels[i].r - midpoint) * factor + midpoint);
        int g = (int)((image->pixels[i].g - midpoint) * factor + midpoint);
        int b = (int)((image->pixels[i].b - midpoint) * factor + midpoint);
        
        image->pixels[i].r = (r > 255) ? 255 : (r < 0) ? 0 : r;
        image->pixels[i].g = (g > 255) ? 255 : (g < 0) ? 0 : g;
        image->pixels[i].b = (b > 255) ? 255 : (b < 0) ? 0 : b;
    }
}

void free_image(Image *image) {
    if (image) {
        free(image->pixels);
        free(image);
    }
}