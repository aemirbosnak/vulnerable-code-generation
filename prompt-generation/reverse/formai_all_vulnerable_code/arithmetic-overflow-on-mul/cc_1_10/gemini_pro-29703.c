//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: futuristic
//  ██████  ██████ ███████ ██   ██ ███████ ███    ██ ██████  
// ██    ██ ██    ██ ██    ██ ██  ██ ██     ██ ██  ██ ██    ██ 
// ██████ ███████ ███████ █████ ██ █████  ██████ ██ ██████ ██ 
// ██    ██ ██    ██      ██ ██ ██ ██    ██ ██  ██ ██    ██ ██ 
// ██    ██ ██      ███████ ██  ████ ███████ ██  ██ ███████  
//                                               

#include <stdio.h>
#include <stdlib.h>

// Define the maximum image size
#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// Define the pixel structure
typedef struct pixel {
    unsigned char r, g, b;
} pixel;

// Define the image structure
typedef struct image {
    int width, height;
    pixel *pixels;
} image;

// Load an image from a file
image *load_image(char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the header
    int width, height;
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Create the image
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(width * height * sizeof(pixel));

    // Read the pixels
    fread(img->pixels, sizeof(pixel), width * height, fp);

    // Close the file
    fclose(fp);

    return img;
}

// Save an image to a file
void save_image(image *img, char *filename) {
    // Open the file
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header
    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);

    // Write the pixels
    fwrite(img->pixels, sizeof(pixel), img->width * img->height, fp);

    // Close the file
    fclose(fp);
}

// Flip an image horizontally
void flip_horizontal(image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            pixel temp = img->pixels[y * img->width + x];
            img->pixels[y * img->width + x] = img->pixels[y * img->width + img->width - x - 1];
            img->pixels[y * img->width + img->width - x - 1] = temp;
        }
    }
}

// Flip an image vertically
void flip_vertical(image *img) {
    for (int y = 0; y < img->height / 2; y++) {
        for (int x = 0; x < img->width; x++) {
            pixel temp = img->pixels[y * img->width + x];
            img->pixels[y * img->width + x] = img->pixels[(img->height - y - 1) * img->width + x];
            img->pixels[(img->height - y - 1) * img->width + x] = temp;
        }
    }
}

// Change the brightness of an image
void change_brightness(image *img, int brightness) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            img->pixels[y * img->width + x].r += brightness;
            img->pixels[y * img->width + x].g += brightness;
            img->pixels[y * img->width + x].b += brightness;
        }
    }
}

// Change the contrast of an image
void change_contrast(image *img, float contrast) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            img->pixels[y * img->width + x].r = img->pixels[y * img->width + x].r * contrast;
            img->pixels[y * img->width + x].g = img->pixels[y * img->width + x].g * contrast;
            img->pixels[y * img->width + x].b = img->pixels[y * img->width + x].b * contrast;
        }
    }
}

// Main function
int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    // Load the input image
    image *img = load_image(argv[1]);
    if (img == NULL) {
        return 1;
    }

    // Flip the image horizontally
    flip_horizontal(img);

    // Flip the image vertically
    flip_vertical(img);

    // Change the brightness of the image
    change_brightness(img, 100);

    // Change the contrast of the image
    change_contrast(img, 1.5);

    // Save the output image
    save_image(img, argv[2]);

    // Free the image
    free(img->pixels);
    free(img);

    return 0;
}