//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    char format[3];
    int width, height, maxColorValue;
    Pixel *pixels;
} Image;

// Function to load a PPM image
Image* loadPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        exit(1);
    }
    
    Image *img = malloc(sizeof(Image));
    fscanf(file, "%s", img->format);
    fscanf(file, "%d %d", &img->width, &img->height);
    fscanf(file, "%d", &img->maxColorValue);
    
    img->pixels = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    
    return img;
}

// Function to save a PPM image
void savePPM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "%s\n%d %d\n%d\n", img->format, img->width, img->height, img->maxColorValue);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

// Function to flip the image vertically
void flipVertically(Image *img) {
    for (int y = 0; y < img->height / 2; y++) {
        for (int x = 0; x < img->width; x++) {
            // Swap pixel values top to bottom
            Pixel temp = img->pixels[y * img->width + x];
            img->pixels[y * img->width + x] = img->pixels[(img->height - y - 1) * img->width + x];
            img->pixels[(img->height - y - 1) * img->width + x] = temp;
        }
    }
}

// Function to adjust brightness
void adjustBrightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (img->pixels[i].r + value > 255) ? 255 : (img->pixels[i].r + value < 0) ? 0 : img->pixels[i].r + value;
        img->pixels[i].g = (img->pixels[i].g + value > 255) ? 255 : (img->pixels[i].g + value < 0) ? 0 : img->pixels[i].g + value;
        img->pixels[i].b = (img->pixels[i].b + value > 255) ? 255 : (img->pixels[i].b + value < 0) ? 0 : img->pixels[i].b + value;
    }
}

// Function to adjust contrast
void adjustContrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->pixels[i].r = (img->pixels[i].r - 128) * factor + 128;
        img->pixels[i].g = (img->pixels[i].g - 128) * factor + 128;
        img->pixels[i].b = (img->pixels[i].b - 128) * factor + 128;

        // Clamp the values to the [0, 255] range
        if(img->pixels[i].r > 255) img->pixels[i].r = 255; 
        if(img->pixels[i].g > 255) img->pixels[i].g = 255; 
        if(img->pixels[i].b > 255) img->pixels[i].b = 255; 
        if(img->pixels[i].r < 0) img->pixels[i].r = 0; 
        if(img->pixels[i].g < 0) img->pixels[i].g = 0; 
        if(img->pixels[i].b < 0) img->pixels[i].b = 0; 
    }
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <input.ppm> <output.ppm> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    Image *img = loadPPM(argv[1]);
    
    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    flipVertically(img);
    adjustBrightness(img, brightness);
    adjustContrast(img, contrast);

    savePPM(argv[2], img);
    
    free(img->pixels);
    free(img);
    
    return 0;
}