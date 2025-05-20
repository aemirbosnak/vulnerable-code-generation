//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    Pixel *pixels;
    int width, height;
} Image;

Image* load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return NULL;
    }

    // Skip the BMP file header
    fseek(fp, 18, SEEK_SET);

    Image *img = (Image *)malloc(sizeof(Image));
    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);

    fseek(fp, 54, SEEK_SET); // Move to the beginning of pixel data
    img->pixels = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->pixels, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);

    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: Unable to write file %s\n", filename);
        return;
    }

    // Write BMP header
    fwrite("BM", 2, 1, fp);
    int file_size = 54 + img->width * img->height * sizeof(Pixel);
    fwrite(&file_size, 4, 1, fp);
    fwrite("\0\0\0\0", 4, 1, fp);
    int offset = 54;
    fwrite(&offset, 4, 1, fp);
    
    // Write DIB header
    int dib_header_size = 40;
    fwrite(&dib_header_size, 4, 1, fp);
    fwrite(&img->width, 4, 1, fp);
    fwrite(&img->height, 4, 1, fp);
    short planes = 1, bits_per_pixel = 24;
    fwrite(&planes, 2, 1, fp);
    fwrite(&bits_per_pixel, 2, 1, fp);
    fwrite("\0\0\0\0\0\0\0\0", 8, 1, fp);
    
    // Write pixel data
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
}

void flip_image(Image *img) {
    int width = img->width;
    int height = img->height;
    Pixel *flipped = (Pixel *)malloc(width * height * sizeof(Pixel));
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            flipped[y * width + x] = img->pixels[y * width + (width - 1 - x)];
        }
    }
    free(img->pixels);
    img->pixels = flipped;
}

void adjust_brightness_contrast(Image *img, int brightness, float contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        int r = img->pixels[i].r + brightness;
        int g = img->pixels[i].g + brightness;
        int b = img->pixels[i].b + brightness;

        // Contrast adjustment
        r = (int)((((float)(r - 128) * contrast) + 128));
        g = (int)((((float)(g - 128) * contrast) + 128));
        b = (int)((((float)(b - 128) * contrast) + 128));

        img->pixels[i].r = (uint8_t)(r < 0 ? 0 : (r > 255 ? 255 : r));
        img->pixels[i].g = (uint8_t)(g < 0 ? 0 : (g > 255 ? 255 : g));
        img->pixels[i].b = (uint8_t)(b < 0 ? 0 : (b > 255 ? 255 : b));
    }
}

void free_image(Image *img) {
    free(img->pixels);
    free(img);
}

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <brightness> <contrast>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    Image *img = load_image(input_filename);
    if (!img) {
        return EXIT_FAILURE;
    }

    flip_image(img);
    adjust_brightness_contrast(img, brightness, contrast);
    save_image(output_filename, img);

    free_image(img);
    return EXIT_SUCCESS;
}