//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 100

int main(int argc, char *argv[]) {
    FILE *fp;
    int i, j, k, l, m, n, c;
    char filename[20];
    unsigned char image[WIDTH][HEIGHT];
    unsigned char temp[WIDTH][HEIGHT];

    // Read input image
    printf("Enter the name of the input image: ");
    scanf("%s", filename);
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    fread(image, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Flip the image
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH/2; j++) {
            temp[i][j] = image[i][WIDTH-1-j];
            temp[i][WIDTH-1-j] = image[i][j];
        }
    }
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            image[i][j] = temp[i][j];
        }
    }

    // Change brightness/contrast
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            c = image[i][j] + 100;
            if (c > 255) {
                c = 255;
            }
            image[i][j] = c;
        }
    }

    // Write output image
    printf("Enter the name of the output image: ");
    scanf("%s", filename);
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }
    fwrite(image, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    printf("Image processing completed.\n");
    return 0;
}