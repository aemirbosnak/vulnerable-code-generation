//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXELS 1000

int flipImage(unsigned char image[], int imageWidth, int imageHeight);
int changeBrightness(unsigned char image[], int imageWidth, int imageHeight, int brightness);
int changeContrast(unsigned char image[], int imageWidth, int imageHeight, float contrast);

int main(void) {
    int imageWidth, imageHeight, brightness;
    float contrast;
    unsigned char image[MAX_PIXELS];

    // read image file
    FILE* fp = fopen("image.pgm", "rb");
    if (fp == NULL) {
        printf("Error: could not open image file.\n");
        exit(1);
    }
    fscanf(fp, "P5\n%d %d\n255\n", &imageWidth, &imageHeight);
    fread(image, sizeof(unsigned char), imageWidth * imageHeight, fp);
    fclose(fp);

    // flip image
    int flipped = flipImage(image, imageWidth, imageHeight);
    if (flipped) {
        // write flipped image file
        FILE* fp_write = fopen("flipped_image.pgm", "wb");
        fprintf(fp_write, "P5\n%d %d\n255\n", imageWidth, imageHeight);
        fwrite(image, sizeof(unsigned char), imageWidth * imageHeight, fp_write);
        fclose(fp_write);

        printf("Image successfully flipped.\n");
    } else {
        printf("Error: could not flip image.\n");
    }

    // change brightness
    printf("Enter brightness value (-255 to 255): ");
    scanf("%d", &brightness);
    int brightnessChanged = changeBrightness(image, imageWidth, imageHeight, brightness);
    if (brightnessChanged) {
        // write brightness changed image file
        FILE* fp_write = fopen("brightness_changed_image.pgm", "wb");
        fprintf(fp_write, "P5\n%d %d\n255\n", imageWidth, imageHeight);
        fwrite(image, sizeof(unsigned char), imageWidth * imageHeight, fp_write);
        fclose(fp_write);

        printf("Image brightness successfully changed.\n");
    } else {
        printf("Error: could not change image brightness.\n");
    }

    // change contrast
    printf("Enter contrast value (0.1 to 10): ");
    scanf("%f", &contrast);
    int contrastChanged = changeContrast(image, imageWidth, imageHeight, contrast);
    if (contrastChanged) {
        // write contrast changed image file
        FILE* fp_write = fopen("contrast_changed_image.pgm", "wb");
        fprintf(fp_write, "P5\n%d %d\n255\n", imageWidth, imageHeight);
        fwrite(image, sizeof(unsigned char), imageWidth * imageHeight, fp_write);
        fclose(fp_write);

        printf("Image contrast successfully changed.\n");
    } else {
        printf("Error: could not change image contrast.\n");
    }

    return 0;
}

// flip image function
int flipImage(unsigned char image[], int imageWidth, int imageHeight) {
    unsigned char tempRow[imageWidth];
    for (int i = 0; i < imageHeight / 2; i++) {
        unsigned char* topRow = &image[i * imageWidth];
        unsigned char* bottomRow = &image[(imageHeight - i - 1) * imageWidth];
        // swap top row with bottom row
        memcpy(tempRow, topRow, imageWidth);
        memcpy(topRow, bottomRow, imageWidth);
        memcpy(bottomRow, tempRow, imageWidth);
    }
    return 1;
}

// change brightness function
int changeBrightness(unsigned char image[], int imageWidth, int imageHeight, int brightness) {
    for (int i = 0; i < imageWidth * imageHeight; i++) {
        int pixel = image[i] + brightness;
        // limit pixel value to 0-255
        if (pixel < 0)
            image[i] = 0;
        else if (pixel > 255)
            image[i] = 255;
        else
            image[i] = pixel;
    }
    return 1;
}

// change contrast function
int changeContrast(unsigned char image[], int imageWidth, int imageHeight, float contrast) {
    for (int i = 0; i < imageWidth * imageHeight; i++) {
        int pixel = contrast * (image[i] - 128) + 128;
        // limit pixel value to 0-255
        if (pixel < 0)
            image[i] = 0;
        else if (pixel > 255)
            image[i] = 255;
        else
            image[i] = pixel;
    }
    return 1;
}