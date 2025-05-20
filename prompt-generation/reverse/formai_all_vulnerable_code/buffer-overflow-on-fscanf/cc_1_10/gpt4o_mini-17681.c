//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

// Function to load a PPM image
Image* loadPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }
    
    char format[3];
    fscanf(file, "%s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format\n");
        fclose(file);
        return NULL;
    }

    Image *img = (Image*)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int maxColor;
    fscanf(file, "%d", &maxColor);
    fgetc(file); // read the newline character after maxColor

    img->data = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

// Function to save a PPM image
void savePPM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    fprintf(file, "P6\n");
    fprintf(file, "%d %d\n", img->width, img->height);
    fprintf(file, "255\n");
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

// Function to flip the image horizontally
void flipImage(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + (img->width - 1 - x)];
            img->data[y * img->width + (img->width - 1 - x)] = temp;
        }
    }
}

// Function to adjust the brightness of the image
void changeBrightness(Image *img, int adjustment) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r + adjustment > 255) ? 255 : (img->data[i].r + adjustment < 0) ? 0 : img->data[i].r + adjustment;
        img->data[i].g = (img->data[i].g + adjustment > 255) ? 255 : (img->data[i].g + adjustment < 0) ? 0 : img->data[i].g + adjustment;
        img->data[i].b = (img->data[i].b + adjustment > 255) ? 255 : (img->data[i].b + adjustment < 0) ? 0 : img->data[i].b + adjustment;
    }
}

// Main function to demonstrate image processing
int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness_adjustment>\n", argv[0]);
        fprintf(stderr, "Example: %s input.ppm output.ppm 30\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = loadPPM(argv[1]);
    if (!img) {
        return EXIT_FAILURE;
    }

    // Change brightness according to the user input
    int brightnessAdjustment = atoi(argv[3]);
    changeBrightness(img, brightnessAdjustment); // Change brightness

    // Flip the image horizontally
    flipImage(img); // Flip the image

    // Save the resultant image
    savePPM(argv[2], img);

    // Clean up
    free(img->data);
    free(img);
    
    printf("Image processing complete!\n");
    return EXIT_SUCCESS;
}