//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256

int main() {

    // Initialize image
    int image[HEIGHT][WIDTH] = {0};

    // Read image from file
    FILE *f = fopen("image.txt", "r");
    if (f == NULL) {
        printf("Error: Could not open image file.\n");
        return 1;
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fscanf(f, "%d", &image[i][j]);
        }
    }

    fclose(f);

    // Flip image horizontally
    int flipped_image[HEIGHT][WIDTH] = {0};

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            flipped_image[i][WIDTH - j - 1] = image[i][j];
        }
    }

    // Change brightness and contrast
    int brightness = 50;
    int contrast = 50;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int gray = (image[i][j] * brightness) / 100;
            int contrast_gray = (gray * contrast) / 100;
            flipped_image[i][WIDTH - j - 1] = contrast_gray;
        }
    }

    // Save flipped image to file
    FILE *f2 = fopen("flipped_image.txt", "w");
    if (f2 == NULL) {
        printf("Error: Could not create flipped image file.\n");
        return 1;
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fprintf(f2, "%d ", flipped_image[i][j]);
        }
        fprintf(f2, "\n");
    }

    fclose(f2);

    return 0;
}