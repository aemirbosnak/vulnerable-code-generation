//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

// function to flip image horizontally
void flipHorizontally(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    int temp;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width/2; j++) {
            temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// function to adjust brightness of image
void adjustBrightness(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height, int brightness) {
    int pixel;

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            pixel = image[i][j] + brightness;
            image[i][j] = pixel <= 255 ? (pixel >= 0 ? pixel : 0) : 255;
        }
    }
}

// function to adjust contrast of image
void adjustContrast(int image[MAX_HEIGHT][MAX_WIDTH], int width, int height, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            image[i][j] = factor * (image[i][j] - 128) + 128;
        }
    }
}

int main() {
    int image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;
    char filename[100];

    printf("Enter filename of image: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // read width and height of image
    fscanf(fp, "%d %d", &width, &height);

    // read pixel values of image
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }

    fclose(fp);

    // flip image horizontally
    flipHorizontally(image, width, height);

    // adjust brightness of image
    int brightness;
    printf("Enter brightness adjustment value (-255 to 255): ");
    scanf("%d", &brightness);
    adjustBrightness(image, width, height, brightness);

    // adjust contrast of image
    float contrast;
    printf("Enter contrast adjustment value (0.1 to 10.0): ");
    scanf("%f", &contrast);
    adjustContrast(image, width, height, contrast);

    // save modified image to new file
    char newFilename[100];
    strcpy(newFilename, "modified_");
    strcat(newFilename, filename);

    FILE *newFp = fopen(newFilename, "w");

    if(newFp == NULL) {
        printf("Error: Could not create new file.\n");
        return 1;
    }

    fprintf(newFp, "%d %d\n", width, height);

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            fprintf(newFp, "%d ", image[i][j]);
        }
        fprintf(newFp, "\n");
    }

    fclose(newFp);

    printf("Modified image saved to %s.\n", newFilename);

    return 0;
}