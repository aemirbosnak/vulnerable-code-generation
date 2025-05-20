//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT 512
#define WIDTH 512

int main() {
    int image[HEIGHT][WIDTH];
    int newimage[HEIGHT][WIDTH];
    int i, j, k;

    // Read image from file
    FILE *fp = fopen("image.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }

    fclose(fp);

    // Flip image horizontally
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            newimage[i][WIDTH - j - 1] = image[i][j];
        }
    }

    // Change brightness and contrast
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            k = (int) (image[i][j] * 1.5 + 128);
            newimage[i][j] = k > 255? 255 : k < 0? 0 : k;
        }
    }

    // Write new image to file
    fp = fopen("newimage.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fprintf(fp, "%d ", newimage[i][j]);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return 0;
}