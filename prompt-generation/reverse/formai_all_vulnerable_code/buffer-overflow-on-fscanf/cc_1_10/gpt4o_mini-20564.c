//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: post-apocalyptic
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

// Function to load a PPM image
Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "The world has gone dark. Can't open image file %s...\n", filename);
        return NULL;
    }

    // Read the PPM header
    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unfamiliar horrors haunt the format of the file. Expecting P6.\n");
        fclose(file);
        return NULL;
    }
    
    Image *image = malloc(sizeof(Image));
    fscanf(file, "%d %d", &image->width, &image->height);
    fscanf(file, "%*d"); // ignore max color value

    image->pixels = malloc(image->width * image->height * sizeof(Pixel));
    fread(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
    
    return image;
}

// Function to save a PPM image
void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Struggling to find light in this dark world. Can't save image file %s...\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

// Function to flip the image horizontally
void flip_image(Image *image) {
    printf("The reflection of what once was... Flipping the image...\n");
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            Pixel temp = image->pixels[y * image->width + x];
            image->pixels[y * image->width + x] = image->pixels[y * image->width + (image->width - 1 - x)];
            image->pixels[y * image->width + (image->width - 1 - x)] = temp;
        }
    }
}

// Function to increase brightness
void increase_brightness(Image *image, int value) {
    printf("The sun has set, but let's make this image a bit brighter...\n");
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].r = (image->pixels[i].r + value > 255) ? 255 : image->pixels[i].r + value;
        image->pixels[i].g = (image->pixels[i].g + value > 255) ? 255 : image->pixels[i].g + value;
        image->pixels[i].b = (image->pixels[i].b + value > 255) ? 255 : image->pixels[i].b + value;
    }
}

// Function to adjust contrast
void adjust_contrast(Image *image, float factor) {
    printf("In this desolate world, let’s seek contrast in the shadows...\n");
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].r = (unsigned char) ((image->pixels[i].r - 128) * factor + 128);
        image->pixels[i].g = (unsigned char) ((image->pixels[i].g - 128) * factor + 128);
        image->pixels[i].b = (unsigned char) ((image->pixels[i].b - 128) * factor + 128);
    }
}

// Free the image memory
void free_image(Image *image) {
    free(image->pixels);
    free(image);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Help! I wander lost in a post-apocalyptic wasteland! Provide an image filename to process.\n");
        return EXIT_FAILURE;
    }
    
    Image *image = load_image(argv[1]);
    if (!image) {
        return EXIT_FAILURE;
    }
    
    flip_image(image);
    increase_brightness(image, 50); // Increase brightness by 50
    adjust_contrast(image, 1.2f); // Increase contrast by 20%
    
    char output_filename[256];
    snprintf(output_filename, sizeof(output_filename), "modified_%s", argv[1]);
    save_image(output_filename, image);
    
    printf("A faint glimmer of hope as we saved the modified image as %s\n", output_filename);
    
    free_image(image);
    return EXIT_SUCCESS;
}