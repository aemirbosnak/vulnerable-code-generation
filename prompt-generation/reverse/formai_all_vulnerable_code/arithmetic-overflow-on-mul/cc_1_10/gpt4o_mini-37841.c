//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image* load_image(const char* filename);
void save_image(const char* filename, Image* img);
void free_image(Image* img);
void flip_image(Image* img);
void adjust_brightness(Image* img, int factor);
void adjust_contrast(Image* img, float factor);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    Image* img = load_image(argv[1]);
    if (!img) {
        printf("Could not load image: %s\n", argv[1]);
        return 1;
    }

    flip_image(img);
    adjust_brightness(img, 50);
    adjust_contrast(img, 1.5);

    save_image(argv[2], img);
    free_image(img);
    
    printf("Image processing complete: %s saved.\n", argv[2]);
    
    return 0;
}

Image* load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    fseek(file, 18, SEEK_SET);
    Image* img = (Image*)malloc(sizeof(Image));
    fread(&img->width, sizeof(int), 1, file);
    fread(&img->height, sizeof(int), 1, file);

    img->pixels = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    fseek(file, 54, SEEK_SET);
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);

    fclose(file);
    return img;
}

void save_image(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        return;
    }

    unsigned short header[27] = {
        0x4D42, // Signature
        0, 0, 0, 0, 54, 0, 0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0, 0, 0, 0, 0, 0
    };

    int size = img->width * img->height * sizeof(Pixel);
    header[2] = sizeof(header) + size;   // File size
    header[3] = 0;                        // Reserved 1
    header[4] = 0;                        // Reserved 2
    header[5] = sizeof(header) + size;   // Data offset
    header[6] = img->width;               // Width
    header[7] = img->height;              // Height

    fwrite(header, sizeof(unsigned short), 27, file);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);

    fclose(file);
}

void free_image(Image* img) {
    if (img) {
        free(img->pixels);
        free(img);
    }
}

void flip_image(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int opposite_x = img->width - 1 - x;
            Pixel temp = img->pixels[y * img->width + x];
            img->pixels[y * img->width + x] = img->pixels[y * img->width + opposite_x];
            img->pixels[y * img->width + opposite_x] = temp;
        }
    }
}

void adjust_brightness(Image* img, int factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (unsigned char)fmin(fmax(img->pixels[i].r + factor, 0), 255);
        img->pixels[i].g = (unsigned char)fmin(fmax(img->pixels[i].g + factor, 0), 255);
        img->pixels[i].b = (unsigned char)fmin(fmax(img->pixels[i].b + factor, 0), 255);
    }
}

void adjust_contrast(Image* img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (unsigned char)fmin(fmax((int)((img->pixels[i].r - 128) * factor + 128), 0), 255);
        img->pixels[i].g = (unsigned char)fmin(fmax((int)((img->pixels[i].g - 128) * factor + 128), 0), 255);
        img->pixels[i].b = (unsigned char)fmin(fmax((int)((img->pixels[i].b - 128) * factor + 128), 0), 255);
    }
}