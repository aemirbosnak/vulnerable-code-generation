//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 256
#define HEIGHT 256
#define MAX_VALUE 255

int main() {
    int image[WIDTH][HEIGHT];
    int flipped[WIDTH][HEIGHT];
    int resized[WIDTH/2][HEIGHT/2];
    int new_image[WIDTH][HEIGHT];
    int i, j, k;

    // Read image from file
    FILE *fp = fopen("image.txt", "r");
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }
    fclose(fp);

    // Flip the image
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            flipped[WIDTH-i-1][HEIGHT-j-1] = image[i][j];
        }
    }

    // Resize the image
    for (i = 0; i < WIDTH/2; i++) {
        for (j = 0; j < HEIGHT/2; j++) {
            k = 0;
            for (int m = 0; m < 2; m++) {
                for (int n = 0; n < 2; n++) {
                    k += flipped[i*2+m][j*2+n];
                }
            }
            resized[i][j] = k/4;
        }
    }

    // Change brightness/contrast
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            new_image[i][j] = (int)round(resized[i][j] * 1.5 + 100);
        }
    }

    // Save new image to file
    FILE *fp2 = fopen("new_image.txt", "w");
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            fprintf(fp2, "%d\n", new_image[i][j]);
        }
    }
    fclose(fp2);

    return 0;
}