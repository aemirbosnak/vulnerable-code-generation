//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT 512
#define WIDTH 512

int main() {
    int image[HEIGHT][WIDTH];
    double brightness = 0.5;
    double contrast = 1.5;

    // Load image
    FILE *fp;
    fp = fopen("image.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }
    int i = 0;
    while (fscanf(fp, "%d", &image[i][0])!= EOF) {
        i++;
    }
    fclose(fp);

    // Flip image
    double flipped[HEIGHT][WIDTH];
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            flipped[y][x] = image[HEIGHT - 1 - y][x];
        }
    }

    // Adjust brightness and contrast
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            double value = (flipped[y][x] - 128) * brightness + 128;
            value = (value * contrast) - 128;
            double newValue = (int) value;
            if (newValue < 0) {
                newValue = 0;
            } else if (newValue > 255) {
                newValue = 255;
            }
            flipped[y][x] = (int) newValue;
        }
    }

    // Save flipped image
    FILE *fp2;
    fp2 = fopen("flipped.txt", "w");
    if (fp2 == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            fprintf(fp2, "%d ", flipped[y][x]);
        }
        fprintf(fp2, "\n");
    }
    fclose(fp2);

    return 0;
}