//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 100
#define HEIGHT 100
#define MAX_VALUE 255

int main() {
    int width, height, x, y, i, j, k, l;
    unsigned char *image, *tmp;
    double brightness, contrast;

    // Read image from file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error reading file.\n");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    image = malloc(size);
    if (image == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }
    fread(image, 1, size, fp);
    fclose(fp);

    // Get user input for brightness and contrast
    printf("Enter brightness (0-100): ");
    scanf("%d", &brightness);
    printf("Enter contrast (0-100): ");
    scanf("%d", &contrast);

    // Flip image horizontally
    for (i = 0; i < height; i++) {
        for (j = 0; j < width/2; j++) {
            k = width-j-1;
            l = i*width+j;
            tmp = image + l;
            image[l] = image[k];
            image[k] = *tmp;
        }
    }

    // Adjust brightness and contrast
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            k = i*width+j;
            image[k] = (unsigned char)((double)image[k]*brightness/100.0 + (1-brightness/100.0)*MAX_VALUE);
            image[k] = (unsigned char)((double)image[k]*contrast/100.0*MAX_VALUE);
        }
    }

    // Write modified image to file
    fp = fopen("modified_image.bmp", "wb");
    if (fp == NULL) {
        printf("Error writing file.\n");
        exit(1);
    }
    fwrite(image, 1, size, fp);
    fclose(fp);

    printf("Image processing completed.\n");
    return 0;
}