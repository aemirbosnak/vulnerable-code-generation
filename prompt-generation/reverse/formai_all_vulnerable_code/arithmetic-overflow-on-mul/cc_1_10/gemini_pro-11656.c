//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: post-apocalyptic
// Enter the bunker, wanderer. We've got pixelated horrors to process.

#include <stdio.h>
#include <stdlib.h>

// Pixel precision, because radiation makes things messy.
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel_t;

// Scrounge for a tattered image.
pixel_t* load_image(const char* filename, int* width, int* height) {
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Could not open %s. Are we lost in the wasteland?\n", filename);
        return NULL;
    }

    // Begin decoding the hieroglyphs on the file.
    fread(width, sizeof(int), 1, fp);
    fread(height, sizeof(int), 1, fp);
    pixel_t* pixels = malloc(*width * *height * sizeof(pixel_t));
    fread(pixels, sizeof(pixel_t), *width * *height, fp);
    fclose(fp);
    return pixels;
}

// Flip the image upside-down, like the world we live in.
void flip_image(pixel_t* pixels, int width, int height) {
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            pixel_t temp = pixels[i * width + j];
            pixels[i * width + j] = pixels[(height - i - 1) * width + j];
            pixels[(height - i - 1) * width + j] = temp;
        }
    }
}

// Adjust brightness and contrast, for our weary eyes.
void adjust_brightness_contrast(pixel_t* pixels, int width, int height, int brightness, int contrast) {
    for (int i = 0; i < width * height; i++) {
        pixels[i].r = (pixels[i].r + brightness) * contrast / 255;
        pixels[i].g = (pixels[i].g + brightness) * contrast / 255;
        pixels[i].b = (pixels[i].b + brightness) * contrast / 255;
    }
}

// Save the mutated image, a relic of our time.
void save_image(const char* filename, pixel_t* pixels, int width, int height) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("Could not save %s. The wasteland has claimed our pixels.\n", filename);
        return;
    }

    // Etch the altered image into the wasteland.
    fwrite(width, sizeof(int), 1, fp);
    fwrite(height, sizeof(int), 1, fp);
    fwrite(pixels, sizeof(pixel_t), width * height, fp);
    fclose(fp);
}

int main(int argc, char** argv) {
    if (argc != 5) {
        printf("Usage: %s <input_image> <output_image> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    int width, height;
    pixel_t* pixels = load_image(argv[1], &width, &height);
    if (!pixels) {
        return 1;
    }

    int brightness = atoi(argv[3]);
    int contrast = atoi(argv[4]);
    adjust_brightness_contrast(pixels, width, height, brightness, contrast);
    flip_image(pixels, width, height);
    save_image(argv[2], pixels, width, height);
    free(pixels);
    return 0;
}