//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600

int main() {
    int image[WIDTH][HEIGHT];
    int flipped[WIDTH][HEIGHT];
    int brightness = 0;
    int contrast = 0;

    // Read input image
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Failed to open input file.\n");
        exit(1);
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fscanf(fp, "%d", &image[j][i]);
        }
    }

    fclose(fp);

    // Flip image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            flipped[i][j] = image[WIDTH - 1 - j][i];
        }
    }

    // Adjust brightness and contrast
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int value = flipped[i][j];

            if (brightness!= 0) {
                value += brightness;
            }

            if (contrast!= 0) {
                int min = 0;
                int max = 255;

                if (brightness > 0) {
                    min = brightness;
                } else if (brightness < 0) {
                    max = brightness;
                }

                value = (value - min) * (max - min) / (max - min + 256) + min;
            }

            flipped[i][j] = value;
        }
    }

    // Save output image
    FILE *out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Error: Failed to open output file.\n");
        exit(1);
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            fprintf(out, "%d ", flipped[i][j]);
        }
        fprintf(out, "\n");
    }

    fclose(out);

    return 0;
}