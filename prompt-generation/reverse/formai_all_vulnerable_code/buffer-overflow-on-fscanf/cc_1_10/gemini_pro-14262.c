//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
// A tranquil C sojourn into image processing

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our canvas, where pixels dance like fireflies
typedef struct {
    unsigned char *data; // Array of pixel intensities (0-255)
    int width, height;   // Dimensions of our canvas
} Image;

// Unveiling our image's hidden beauty
Image* loadImage(char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Woe is me! Could not open file: %s\n", filename);
        return NULL;
    } else {
        printf("Behold, the image emerges from its slumber!\n");
    }
    
    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(file);
        printf("Alas, memory eludes us!\n");
        return NULL;
    }

    // Reading image dimensions
    fscanf(file, "%d %d", &image->width, &image->height);
    printf("Our canvas measures %d pixels wide and %d pixels tall.\n", image->width, image->height);

    // Allocating memory for our pixel array
    image->data = malloc(image->width * image->height * sizeof(unsigned char));
    if (!image->data) {
        fclose(file);
        free(image);
        printf("Alas, our coffers are empty!\n");
        return NULL;
    }

    // Transferring pixel data from file to memory
    fread(image->data, sizeof(unsigned char), image->width * image->height, file);
    fclose(file);

    return image;
}

// Mirror, mirror on the wall, let's reverse this image's call
void flipImage(Image *image) {
    printf("May the pixels dance in reverse!\n");
    int halfWidth = image->width / 2;

    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < halfWidth; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[i * image->width + image->width - 1 - j];
            image->data[i * image->width + image->width - 1 - j] = temp;
        }
    }
}

// Adjust the brightness and contrast of our image
void adjustBrightnessContrast(Image *image, int brightness, int contrast) {
    printf("Let's add some sparkle and depth!\n");
    int min, max;

    // Calculate min and max values for the current contrast
    min = 255;
    max = 0;
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            if (image->data[i * image->width + j] < min)
                min = image->data[i * image->width + j];
            if (image->data[i * image->width + j] > max)
                max = image->data[i * image->width + j];
        }
    }

    // Applying brightness and contrast adjustments
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int newPixelValue = ((image->data[i * image->width + j] - min) * 255) / (max - min);
            newPixelValue += brightness;
            newPixelValue = (newPixelValue * contrast) / 100;

            // Keep pixel values within range (0-255)
            if (newPixelValue < 0)
                newPixelValue = 0;
            else if (newPixelValue > 255)
                newPixelValue = 255;

            image->data[i * image->width + j] = newPixelValue;
        }
    }
}

// Saving our masterpiece to an image file
void saveImage(Image *image, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Alas, we cannot preserve our creation: %s\n", filename);
        return;
    } else {
        printf("May our image live on forever in %s!\n", filename);
    }

    // Writing image dimensions
    fprintf(file, "%d %d\n", image->width, image->height);

    // Writing pixel data
    fwrite(image->data, sizeof(unsigned char), image->width * image->height, file);
    fclose(file);
}

// Freeing the memory allocated for our image
void freeImage(Image *image) {
    if (image->data) {
        free(image->data);
    }
    free(image);
}

// Our canvas is ready, let's invite an image to grace it
int main() {
    char *originalImage = "image.ppm";
    Image *image = loadImage(originalImage);
    if (!image) {
        return 1;
    }

    // Flip the image to see the world from a different angle
    flipImage(image);

    // Adjust brightness and contrast for a more radiant glow
    adjustBrightnessContrast(image, 50, 150);

    // Save our transformed image as a new masterpiece
    char *processedImage = "processed_image.ppm";
    saveImage(image, processedImage);

    printf("Our journey into image processing has come to an end.\n");
    freeImage(image);
    return 0;
}