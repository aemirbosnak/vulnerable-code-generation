//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 200
#define MAX_HEIGHT 200
#define MAX_COLOR 255

typedef struct Image {
    int width;
    int height;
    int pixels[MAX_HEIGHT][MAX_WIDTH];
} Image;

Image loadImage(char fileName[]) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Could not open %s\n", fileName);
        exit(1);
    }
    
    int width, height;
    fscanf(fp, "%d%d", &width, &height);
    Image img = {width, height};
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(fp, "%d", &img.pixels[i][j]);
        }
    }
    
    fclose(fp);
    return img;
}

void saveImage(Image img, char fileName[]) {
    FILE* fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Could not open %s\n", fileName);
        exit(1);
    }
    
    fprintf(fp, "%d %d\n", img.width, img.height);
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            fprintf(fp, "%d ", img.pixels[i][j]);
        }
        fprintf(fp, "\n");
    }
    
    fclose(fp);
}

Image flipImage(Image img) {
    Image flipped = {img.width, img.height};
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            flipped.pixels[i][img.width-j-1] = img.pixels[i][j];
        }
    }
    return flipped;
}

Image adjustBrightness(Image img, int amount) {
    Image adjusted = {img.width, img.height};
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            int newPixel = img.pixels[i][j] + amount;
            adjusted.pixels[i][j] = (newPixel > MAX_COLOR) ? MAX_COLOR : ((newPixel < 0) ? 0 : newPixel);
        }
    }
    return adjusted;
}

Image adjustContrast(Image img, float amount) {
    Image adjusted = {img.width, img.height};
    float factor = (259.0 * (amount + 255.0)) / (255.0 * (259.0 - amount));
    for (int i = 0; i < img.height; i++) {
        for (int j = 0; j < img.width; j++) {
            int newPixel = (int)(factor * (img.pixels[i][j] - 128) + 128);
            adjusted.pixels[i][j] = (newPixel > MAX_COLOR) ? MAX_COLOR : ((newPixel < 0) ? 0 : newPixel);
        }
    }
    return adjusted;
}

int main() {
    Image img = loadImage("input.txt");
    
    // Flip image
    Image flipped = flipImage(img);
    saveImage(flipped, "flipped.txt");
    
    // Increase brightness by 50
    Image brightened = adjustBrightness(img, 50);
    saveImage(brightened, "brightened.txt");
    
    // Decrease contrast by 50%
    Image contrasted = adjustContrast(img, 0.5);
    saveImage(contrasted, "contrasted.txt");
    
    return 0;
}