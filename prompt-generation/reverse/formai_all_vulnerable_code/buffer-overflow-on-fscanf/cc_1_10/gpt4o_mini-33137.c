//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel* data;
} Image;

Image* load_image(const char* filename);
void save_image(const char* filename, Image* img);
void flip_image(Image* img);
void adjust_brightness(Image* img, int value);
void adjust_contrast(Image* img, float factor);
void free_image(Image* img);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    Image* img = load_image(argv[1]);
    if (!img) {
        fprintf(stderr, "Error loading image\n");
        return 1;
    }

    printf("Loaded image: %dx%d\n", img->width, img->height);

    // Flip the image
    flip_image(img);

    // Adjust brightness (+50)
    adjust_brightness(img, 50);

    // Adjust contrast (1.2x)
    adjust_contrast(img, 1.2f);

    // Save modified image
    save_image(argv[2], img);
    
    free_image(img);
    
    printf("Image processed and saved to %s\n", argv[2]);
    return 0;
}

Image* load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) return NULL;

    // Simple PPM loader for 24-bit RGB images
    char buffer[16];
    int width, height, maxval;

    fgets(buffer, sizeof(buffer), file);
    if (buffer[0] != 'P' || buffer[1] != '6') {
        fclose(file);
        return NULL; // Not a P6 PPM image
    }

    fscanf(file, "%d %d %d", &width, &height, &maxval);
    fgetc(file); // Read the newline after maxval

    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(Pixel));

    fread(img->data, sizeof(Pixel), width * height, file);
    fclose(file);
    
    return img;
}

void save_image(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) return;

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int flip_x = img->width - x - 1; // Flipped x-coordinate
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + flip_x];
            img->data[y * img->width + flip_x] = temp;
        }
    }
}

void adjust_brightness(Image* img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (uint8_t) fmin(fmax(img->data[i].r + value, 0), 255);
        img->data[i].g = (uint8_t) fmin(fmax(img->data[i].g + value, 0), 255);
        img->data[i].b = (uint8_t) fmin(fmax(img->data[i].b + value, 0), 255);
    }
}

void adjust_contrast(Image* img, float factor) {
    float contrast = (259 * (factor + 255)) / (255 * (259 - factor));

    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (uint8_t) fmin(fmax(contrast * (img->data[i].r - 128) + 128, 0), 255);
        img->data[i].g = (uint8_t) fmin(fmax(contrast * (img->data[i].g - 128) + 128, 0), 255);
        img->data[i].b = (uint8_t) fmin(fmax(contrast * (img->data[i].b - 128) + 128, 0), 255);
    }
}

void free_image(Image* img) {
    if (img) {
        free(img->data);
        free(img);
    }
}