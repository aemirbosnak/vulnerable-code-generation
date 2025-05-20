//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: immersive
#include<stdio.h>
#include<stdlib.h>

struct Image {
    int width;
    int height;
    int** pixels;
};

typedef struct Image Image;

Image readImage(char* filename);
void writeImage(char* filename, Image img);
void flipImage(Image* img);
void changeBrightness(Image* img, int value);
void changeContrast(Image* img, int value);

int main() {
    char* filename = "sample.ppm"; // Change to your image filename
    Image img = readImage(filename); // Read the image file
    
    // Perform image processing tasks
    flipImage(&img);
    changeBrightness(&img, 50);
    changeContrast(&img, 100);
    
    // Write the processed image to a new file
    writeImage("processed.ppm", img);
    
    // Free dynamic memory used by the image
    for(int i=0; i<img.height; i++) {
        free(img.pixels[i]);
    }
    free(img.pixels);
    
    return 0;
}

Image readImage(char* filename) {
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Error: Cannot open file \"%s\".\n", filename);
        exit(1);
    }
    
    char magic[3]; // Magic number of the image format
    fscanf(fp, "%s", magic);
    if(magic[0] != 'P' || magic[1] != '3') {
        printf("Error: %s is not a valid PPM image file.\n", filename);
        exit(1);
    }
    
    int width, height, maxVal; // Image information
    fscanf(fp, "%d %d %d", &width, &height, &maxVal);
    if(maxVal > 255) { // Only support 8-bit color depth
        printf("Error: %d-bit color depth is not supported.\n", maxVal);
        exit(1);
    }
    
    Image img = {width, height, NULL}; // Initialize the image structure
    img.pixels = (int**)malloc(height * sizeof(int*));
    for(int i=0; i<height; i++) {
        img.pixels[i] = (int*)malloc(width * sizeof(int));
    }
    
    for(int i=0; i<height; i++) { // Read pixel values
        for(int j=0; j<width; j++) {
            fscanf(fp, "%d", &img.pixels[i][j]);
        }
    }
    
    fclose(fp);
    return img;
}

void writeImage(char* filename, Image img) {
    FILE* fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error: Cannot open file \"%s\".\n", filename);
        exit(1);
    }
    
    fprintf(fp, "P3\n%d %d\n255\n", img.width, img.height); // Write header
    
    for(int i=0; i<img.height; i++) { // Write pixel values
        for(int j=0; j<img.width; j++) {
            fprintf(fp, "%d ", img.pixels[i][j]);
            fprintf(fp, "%d ", img.pixels[i][j]);
            fprintf(fp, "%d ", img.pixels[i][j]);
        }
        fprintf(fp, "\n");
    }
    
    fclose(fp);
}

void flipImage(Image* img) {
    int temp;
    for(int i=0; i<img->height; i++) {
        for(int j=0; j<img->width/2; j++) { // Swap pixels horizontally
            temp = img->pixels[i][j];
            img->pixels[i][j] = img->pixels[i][img->width-j-1];
            img->pixels[i][img->width-j-1] = temp;
        }
    }
}

void changeBrightness(Image* img, int value) {
    int maxVal = 255;
    for(int i=0; i<img->height; i++) {
        for(int j=0; j<img->width; j++) {
            img->pixels[i][j] += value; // Change pixel values by the brightness value
            img->pixels[i][j] = img->pixels[i][j] < 0 ? 0 : img->pixels[i][j]; // Clamp pixel values to [0, maxVal]
            img->pixels[i][j] = img->pixels[i][j] > maxVal ? maxVal : img->pixels[i][j];
        }
    }
}

void changeContrast(Image* img, int value) {
    double factor = (259.0 * (value + 255.0)) / (255.0 * (259.0 - value)); // Compute the contrast factor
    int maxVal = 255;
    for(int i=0; i<img->height; i++) {
        for(int j=0; j<img->width; j++) {
            img->pixels[i][j] = (int)(factor * (img->pixels[i][j] - 128) + 128); // Change pixel values by the contrast factor
            img->pixels[i][j] = img->pixels[i][j] < 0 ? 0 : img->pixels[i][j]; // Clamp pixel values to [0, maxVal]
            img->pixels[i][j] = img->pixels[i][j] > maxVal ? maxVal : img->pixels[i][j];
        }
    }
}