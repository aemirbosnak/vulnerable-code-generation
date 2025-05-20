//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100

int main() {
    int image[WIDTH][HEIGHT];

    // Load image from file
    FILE *fp = fopen("image.txt", "r");
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            fscanf(fp, "%d", &image[x][y]);
        }
    }
    fclose(fp);

    // Flip image horizontally
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH / 2; x++) {
            int temp = image[x][y];
            image[x][y] = image[WIDTH - x - 1][y];
            image[WIDTH - x - 1][y] = temp;
        }
    }

    // Change brightness and contrast
    int brightness = 50;
    int contrast = 100;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int value = image[x][y];
            int newValue = (int) ((double) value * (double) (brightness + 100) / 255.0 + (double) contrast / 2.0);
            newValue = (newValue > 255)? 255 : newValue;
            newValue = (newValue < 0)? 0 : newValue;
            image[x][y] = newValue;
        }
    }

    // Save modified image to file
    FILE *fp2 = fopen("modified_image.txt", "w");
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            fprintf(fp2, "%d ", image[x][y]);
        }
        fprintf(fp2, "\n");
    }
    fclose(fp2);

    return 0;
}