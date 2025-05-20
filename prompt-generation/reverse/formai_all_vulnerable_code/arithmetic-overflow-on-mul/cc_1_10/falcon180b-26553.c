//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 500
#define HEIGHT 500
#define MAX_VALUE 255

int main(int argc, char **argv) {

    // Read image from file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error: could not open file!\n");
        return 1;
    }

    // Read image data
    unsigned char header[54];
    fread(header, 1, 54, fp);
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int bpp = *(int*)&header[28];
    int size = width * height * bpp / 8;
    unsigned char *data = (unsigned char*)malloc(size);
    fread(data, 1, size, fp);
    fclose(fp);

    // Flip image
    int row, col;
    for (row = 0; row < height; row++) {
        for (col = 0; col < width / 2; col++) {
            int index1 = row * width + col;
            int index2 = row * width + width - 1 - col;
            unsigned char temp = data[index1];
            data[index1] = data[index2];
            data[index2] = temp;
        }
    }

    // Change brightness
    int delta = 50;
    int factor = (MAX_VALUE - delta) / MAX_VALUE;
    for (int i = 0; i < size; i++) {
        data[i] = (data[i] * factor) + delta;
    }

    // Change contrast
    for (int i = 0; i < size; i++) {
        data[i] = (data[i] - 127) * 2;
    }

    // Save modified image
    fp = fopen("modified.bmp", "wb");
    if (fp == NULL) {
        printf("Error: could not create file!\n");
        return 1;
    }

    fwrite(header, 1, 54, fp);
    fwrite(data, 1, size, fp);
    fclose(fp);

    printf("Image modified successfully!\n");

    return 0;
}