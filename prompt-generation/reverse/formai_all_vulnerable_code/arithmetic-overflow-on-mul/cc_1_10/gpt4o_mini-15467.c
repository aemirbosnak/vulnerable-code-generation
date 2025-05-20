//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: random
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *pixels;
} Image;

Image* load_image(const char* filename);
void save_image(const char* filename, Image* image);
void flip_image(Image* image);
void adjust_brightness(Image* image, int amount);
void adjust_contrast(Image* image, float factor);
void free_image(Image* image);

int main() {
    const char *input_file = "input.bmp";
    const char *output_file = "output.bmp";

    Image *image = load_image(input_file);
    if (!image) {
        fprintf(stderr, "Failed to load image.\n");
        return 1;
    }

    // Flip the image
    flip_image(image);
    // Adjust brightness
    adjust_brightness(image, 30);
    // Adjust contrast
    adjust_contrast(image, 1.2f);

    save_image(output_file, image);

    free_image(image);
    printf("Image processing complete!\n");
    return 0;
}

Image* load_image(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s.\n", filename);
        return NULL;
    }
    
    // BMP header read
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    
    // Allocate memory for the pixel data
    Pixel *pixels = malloc(width * height * sizeof(Pixel));
    fseek(file, 54, SEEK_SET);
    fread(pixels, sizeof(Pixel), width * height, file);
    
    fclose(file);
    
    Image* img = (Image*)malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = pixels;

    return img;
}

void save_image(const char* filename, Image* image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing.\n", filename);
        return;
    }

    // Write BMP header
    unsigned char header[54] = {
        'B', 'M',  // Signature
        0, 0, 0, 0,  // File size (we will fix this later)
        0, 0, 0, 0,  // Reserved
        54, 0, 0, 0,  // Offset to pixel array
        40, 0, 0, 0,  // DIB header size
        0, 0, 0, 0,  // Width (we will fix this later)
        0, 0, 0, 0,  // Height (we will fix this later)
        1, 0,        // Planes
        24, 0,       // Bits per pixel
        0, 0, 0, 0,  // Compression (none)
        0, 0, 0, 0,  // Image size (can be zero for uncompressed)
        0x13B0, 0x0, 0x0, 0x0,  // Horiz resolution (2835 Pixels/meter)
        0x13B0, 0x0, 0x0, 0x0,  // Vert resolution (2835 Pixels/meter)
        0, 0, 0, 0,  // Colors in color table
        0, 0, 0, 0   // Important color count
    };

    int file_size = 54 + image->width * image->height * sizeof(Pixel);
    *(int*)&header[2] = file_size;
    *(int*)&header[18] = image->width;
    *(int*)&header[22] = image->height;

    fwrite(header, sizeof(unsigned char), 54, file);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);
    
    fclose(file);
}

void flip_image(Image* image) {
    for (int y = 0; y < image->height / 2; y++) {
        for (int x = 0; x < image->width; x++) {
            int opposite_y = image->height - y - 1;
            Pixel temp = image->pixels[y * image->width + x];
            image->pixels[y * image->width + x] = image->pixels[opposite_y * image->width + x];
            image->pixels[opposite_y * image->width + x] = temp;
        }
    }
}

void adjust_brightness(Image* image, int amount) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].r = (unsigned char)(image->pixels[i].r + amount > 255 ? 255 : image->pixels[i].r + amount);
        image->pixels[i].g = (unsigned char)(image->pixels[i].g + amount > 255 ? 255 : image->pixels[i].g + amount);
        image->pixels[i].b = (unsigned char)(image->pixels[i].b + amount > 255 ? 255 : image->pixels[i].b + amount);
    }
}

void adjust_contrast(Image* image, float factor) {
    for (int i = 0; i < image->width * image->height; i++) {
        float r = (image->pixels[i].r / 255.0 - 0.5) * factor + 0.5;
        float g = (image->pixels[i].g / 255.0 - 0.5) * factor + 0.5;
        float b = (image->pixels[i].b / 255.0 - 0.5) * factor + 0.5;

        image->pixels[i].r = (unsigned char)(r < 0 ? 0 : r > 1 ? 255 : r * 255);
        image->pixels[i].g = (unsigned char)(g < 0 ? 0 : g > 1 ? 255 : g * 255);
        image->pixels[i].b = (unsigned char)(b < 0 ? 0 : b > 1 ? 255 : b * 255);
    }
}

void free_image(Image* image) {
    if (image) {
        free(image->pixels);
        free(image);
    }
}