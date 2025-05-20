//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_VALUE 255

int main() {
    int image[HEIGHT][WIDTH];

    // Read image from file
    FILE *fp = fopen("image.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }
    fclose(fp);

    // Flip image horizontally
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][WIDTH-1-j];
            image[i][WIDTH-1-j] = temp;
        }
    }

    // Change brightness
    int brightness = 50;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] += brightness;
            if (image[i][j] > MAX_VALUE) {
                image[i][j] = MAX_VALUE;
            } else if (image[i][j] < 0) {
                image[i][j] = 0;
            }
        }
    }

    // Change contrast
    double contrast = 1.5;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = round((image[i][j] - 128) * contrast + 128);
        }
    }

    // Write modified image to file
    FILE *fp2 = fopen("modified_image.txt", "w");
    if (fp2 == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fprintf(fp2, "%d ", image[i][j]);
        }
        fprintf(fp2, "\n");
    }
    fclose(fp2);

    return 0;
}