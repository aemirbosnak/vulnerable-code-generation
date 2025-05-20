//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT 100
#define WIDTH 100

int main() {
    int i, j;
    float image[HEIGHT][WIDTH]; // create an array to store the image
    float flipped[HEIGHT][WIDTH]; // create an array to store the flipped image
    float brightness_contrast[HEIGHT][WIDTH]; // create an array to store the modified image

    // read in the image from a file
    FILE *fp = fopen("image.data", "r");
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fscanf(fp, "%f", &image[i][j]);
        }
    }
    fclose(fp);

    // flip the image
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            flipped[i][j] = image[HEIGHT-i-1][WIDTH-j-1];
        }
    }

    // adjust the brightness and contrast of the image
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            brightness_contrast[i][j] = (image[i][j] * 1.5) + 50; // increase brightness by 50 and multiply by 1.5 for contrast
        }
    }

    // write the modified image to a file
    FILE *fp2 = fopen("modified_image.data", "w");
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fprintf(fp2, "%f\n", brightness_contrast[i][j]);
        }
    }
    fclose(fp2);

    // print the original and modified images to the console
    printf("Original image:\n");
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%f ", image[i][j]);
        }
        printf("\n");
    }

    printf("\nFlipped image:\n");
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%f ", flipped[i][j]);
        }
        printf("\n");
    }

    printf("\nModified image:\n");
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%f ", brightness_contrast[i][j]);
        }
        printf("\n");
    }

    return 0;
}