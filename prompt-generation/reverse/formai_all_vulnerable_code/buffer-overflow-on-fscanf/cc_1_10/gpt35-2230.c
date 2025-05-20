//FormAI DATASET v1.0 Category: Image compression ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// Definition of the Image struct
typedef struct {
    int width;
    int height;
    int pixels[MAX_WIDTH][MAX_HEIGHT];
} Image;

// Compresses the given image
void compressImage(Image *img) {
    int compressed[MAX_WIDTH * MAX_HEIGHT]; // Store the compressed image
    int index = 0; // Index to insert the compressed value
    
    // Loop through each pixel and compress the image
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            if (j == 0) {
                compressed[index++] = img->pixels[j][i];
            } else {
                if (img->pixels[j][i] == img->pixels[j-1][i]) {
                    compressed[index-1]++;
                } else {
                    compressed[index++] = img->pixels[j][i];
                }
            }
        }
    }
    
    // Set the compressed array as the pixels of the image
    img->width = index;
    for (int i = 0; i < index; i++) {
        img->pixels[i][0] = compressed[i];
    }
}

// Reads the image from the given file
void readImage(Image *img, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    
    fscanf(file, "%d %d", &img->width, &img->height);
    
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fscanf(file, "%d", &img->pixels[j][i]);
        }
    }
    
    fclose(file);
}

// Writes the compressed image to the given file
void writeCompressedImage(Image *img, char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    
    fprintf(file, "%d\n", img->width);
    
    for (int i = 0; i < img->width; i++) {
        fprintf(file, "%d ", img->pixels[i][0]);
    }
    
    fclose(file);
}

int main() {
    Image img;
    
    // Read the image from the file
    readImage(&img, "input.txt");
    
    // Compress the image
    compressImage(&img);
    
    // Write the compressed image to the file
    writeCompressedImage(&img, "compressed.txt");
    
    return 0;
}