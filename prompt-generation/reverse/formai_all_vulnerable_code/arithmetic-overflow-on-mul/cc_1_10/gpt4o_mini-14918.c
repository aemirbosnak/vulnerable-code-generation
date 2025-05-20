//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

Image* load_bmp(const char *filename);
void save_bmp(const char *filename, Image *image);
void flip_image(Image *image);
void adjust_brightness(Image *image, int brightness);
void adjust_contrast(Image *image, float contrast_factor);
void free_image(Image *image);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <image.bmp> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    int brightness = atoi(argv[2]);
    float contrast = atof(argv[3]);

    Image *image = load_bmp(filename);
    if (!image) {
        fprintf(stderr, "Failed to load image: %s\n", filename);
        return 1;
    }

    printf("Loaded image: %dx%d\n", image->width, image->height);

    flip_image(image);
    printf("Image flipped.\n");

    adjust_brightness(image, brightness);
    printf("Brightness adjusted by: %d\n", brightness);

    adjust_contrast(image, contrast);
    printf("Contrast adjusted by factor: %.2f\n", contrast);

    save_bmp("output.bmp", image);
    printf("Processed image saved as output.bmp\n");

    free_image(image);

    return 0;
}

Image* load_bmp(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    // Read BMP Header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int padding = (4 - (width * 3) % 4) % 4;

    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(Pixel));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&image->pixels[(height - 1 - i) * width + j], sizeof(Pixel), 1, file);
        }
        fseek(file, padding, SEEK_CUR);
    }

    fclose(file);
    return image;
}

void save_bmp(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) return;

    unsigned char header[54] = {
        'B', 'M',  // BMP Signature
        0, 0, 0, 0, // Size of the BMP file (will be filled later)
        0, 0,      // Reserved1
        0, 0,      // Reserved2
        54, 0, 0, 0 // Offset to start of pixel data
    };

    int width = image->width;
    int height = image->height;
    int padding = (4 - (width * 3) % 4) % 4;

    // Fill in size of the file
    int file_size = 54 + (3 * width + padding) * height;
    header[2] = (unsigned char)(file_size);
    header[3] = (unsigned char)(file_size >> 8);
    header[4] = (unsigned char)(file_size >> 16);
    header[5] = (unsigned char)(file_size >> 24);

    // Write header
    fwrite(header, sizeof(unsigned char), 54, file);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fwrite(&image->pixels[(height - 1 - i) * width + j], sizeof(Pixel), 1, file);
        }
        for (int k = 0; k < padding; k++) {
            fputc(0, file);
        }
    }

    fclose(file);
}

void flip_image(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            Pixel temp = image->pixels[i * image->width + j];
            image->pixels[i * image->width + j] = image->pixels[(image->height - 1 - i) * image->width + j];
            image->pixels[(image->height - 1 - i) * image->width + j] = temp;
        }
    }
}

void adjust_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->width * image->height; i++) {
        int r = image->pixels[i].r + brightness;
        int g = image->pixels[i].g + brightness;
        int b = image->pixels[i].b + brightness;

        image->pixels[i].r = (r < 0) ? 0 : (r > 255) ? 255 : r;
        image->pixels[i].g = (g < 0) ? 0 : (g > 255) ? 255 : g;
        image->pixels[i].b = (b < 0) ? 0 : (b > 255) ? 255 : b;
    }
}

void adjust_contrast(Image *image, float contrast_factor) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].r = (unsigned char) fmin(255, fmax(0, 128 + (image->pixels[i].r - 128) * contrast_factor));
        image->pixels[i].g = (unsigned char) fmin(255, fmax(0, 128 + (image->pixels[i].g - 128) * contrast_factor));
        image->pixels[i].b = (unsigned char) fmin(255, fmax(0, 128 + (image->pixels[i].b - 128) * contrast_factor));
    }
}

void free_image(Image *image) {
    free(image->pixels);
    free(image);
}