//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100

int main() {
    // read in image data
    int image[WIDTH][HEIGHT];
    FILE *fp = fopen("image.txt", "r");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fscanf(fp, "%d", &image[y][x]);
        }
    }
    fclose(fp);

    // flip image
    int flipped[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            flipped[y][x] = image[HEIGHT - y - 1][x];
        }
    }

    // change brightness/contrast
    int brightness = 50;
    int contrast = 100;
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int value = (flipped[y][x] * contrast) / 255 + brightness;
            if (value > 255) {
                value = 255;
            } else if (value < 0) {
                value = 0;
            }
            flipped[y][x] = value;
        }
    }

    // write out modified image
    FILE *fp2 = fopen("modified_image.txt", "w");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fprintf(fp2, "%d ", flipped[y][x]);
        }
        fprintf(fp2, "\n");
    }
    fclose(fp2);

    return 0;
}