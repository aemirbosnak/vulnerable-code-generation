//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
// C Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast

#include <stdio.h>
#include <stdlib.h>

// Image struct containing information about the image such as width, height, and pixels
typedef struct Image {
    int width;
    int height;
    unsigned char* pixels;
} Image;

// Function to load image from a ppm file
Image* loadImage(char* filename) {
    Image* image = (Image*)malloc(sizeof(Image));
    FILE* fp = fopen(filename, "rb");
    char magicnumber[10];
    int maxval;
    fscanf(fp, "%s %d %d %d\n", magicnumber, &image->width, &image->height, &maxval);
    int numPixels = image->width * image->height;
    image->pixels = (unsigned char*)malloc(sizeof(unsigned char) * numPixels * 3);
    fread(image->pixels, 1, numPixels * 3, fp);
    fclose(fp);
    return image;
}

// Function to save image to a ppm file
void saveImage(Image* image, char* filename) {
    FILE* fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", image->width, image->height);
    int numPixels = image->width * image->height;
    fwrite(image->pixels, 1, numPixels * 3, fp);
    fclose(fp);
}

// Function to flip image horizontally
void flip(Image* image) {
    int numPixels = image->width * image->height;
    unsigned char* temp = (unsigned char*)malloc(sizeof(unsigned char) * 3);
    int rowLength = image->width * 3;
    for (int i = 0; i < numPixels / 2; i++) {
        int j = (numPixels - i - 1) * 3;
        int k = i * 3;
        for (int l = 0; l < 3; l++) {
            temp[l] = image->pixels[k + l];
            image->pixels[k + l] = image->pixels[j + l];
            image->pixels[j + l] = temp[l];
        }
    }
    free(temp);
}

// Function to adjust image brightness and contrast
void adjustBrightnessContrast(Image* image, int brightness, float contrast) {
    int numPixels = image->width * image->height;
    float contrastFactor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for (int i = 0; i < numPixels * 3; i++) {
        int temp = image->pixels[i] * contrastFactor - (128 * contrastFactor) + brightness;
        if (temp < 0) {
            temp = 0;
        } else if (temp > 255) {
            temp = 255;
        }
        image->pixels[i] = (unsigned char)temp;
    }
}

int main() {
    // Load image
    Image* image = loadImage("image.ppm");

    // Flip image horizontally
    flip(image);

    // Adjust brightness and contrast
    adjustBrightnessContrast(image, 50, 1.5);

    // Save image
    saveImage(image, "output.ppm");

    // Free image memory
    free(image->pixels);
    free(image);

    return 0;
}