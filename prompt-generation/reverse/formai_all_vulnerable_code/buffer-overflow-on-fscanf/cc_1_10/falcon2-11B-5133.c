//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

void flipImage(int* image, int width, int height) {
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int temp = image[x*width+y];
            image[x*width+y] = image[(width-1-x)*width+y];
            image[(width-1-x)*width+y] = temp;
        }
    }
}

void changeBrightness(int* image, int width, int height, double brightness) {
    double delta = brightness * 0.02;
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            int value = image[x*width+y];
            int newValue = (int) (value * (1.0 + delta) * 255);
            if(newValue > 255)
                newValue = 255;
            else if(newValue < 0)
                newValue = 0;
            image[x*width+y] = newValue;
        }
    }
}

int main(int argc, char **argv) {
    if(argc!= 2) {
        printf("Usage: %s input_image\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if(!fp) {
        printf("Failed to open input image.\n");
        return 1;
    }

    int width, height, channels;
    fscanf(fp, "%d %d %d", &width, &height, &channels);

    if(width > MAX_WIDTH || height > MAX_HEIGHT || channels > 3) {
        printf("Image too large.\n");
        return 1;
    }

    int* image = malloc(width*height*channels * sizeof(int));
    if(!image) {
        printf("Failed to allocate memory.\n");
        return 1;
    }

    fread(image, sizeof(int), width*height*channels, fp);
    fclose(fp);

    int i, j;
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            image[j*width+i] = (int) (image[j*width+i] * 255 / 255);
        }
    }

    flipImage(image, width, height);
    changeBrightness(image, width, height, 1.2);

    FILE *fp2 = fopen("output.ppm", "w");
    if(!fp2) {
        printf("Failed to open output file.\n");
        return 1;
    }

    fprintf(fp2, "P6\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(int), width*height, fp2);
    fclose(fp2);

    free(image);
    return 0;
}