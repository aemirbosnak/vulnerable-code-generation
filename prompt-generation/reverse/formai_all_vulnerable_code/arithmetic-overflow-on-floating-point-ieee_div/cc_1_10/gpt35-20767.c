//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

// Flip Image Function
void flip_image(int img[MAX_HEIGHT][MAX_WIDTH], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            int temp = img[i][j];
            img[i][j] = img[i][width - j - 1];
            img[i][width - j - 1] = temp;
        }
    }
}

// Change Brightness Function
void change_brightness(int img[MAX_HEIGHT][MAX_WIDTH], int width, int height, int value) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = img[i][j];
            pixel += value;
            if (pixel < 0) {
                pixel = 0;
            } else if (pixel > 255) {
                pixel = 255;
            }
            img[i][j] = pixel;
        }
    }
}

// Change Contrast Function
void change_contrast(int img[MAX_HEIGHT][MAX_WIDTH], int width, int height, float value) {
    float factor = (259 * (value + 255)) / (255 * (259 - value));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = img[i][j];
            pixel = (int)(factor * (pixel - 128) + 128);
            if (pixel < 0) {
                pixel = 0;
            } else if (pixel > 255) {
                pixel = 255;
            }
            img[i][j] = pixel;
        }
    }
}

int main() {

    // Read Input Image
    int width, height, img[MAX_HEIGHT][MAX_WIDTH];
    scanf("%d %d", &width, &height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &img[i][j]);
        }
    }

    // Flip Image
    int flip;
    scanf("%d", &flip);
    if (flip == 1) {
        flip_image(img, width, height);
    }

    // Change Brightness
    int brightness;
    scanf("%d", &brightness);
    if (brightness != 0) {
        change_brightness(img, width, height, brightness);
    }

    // Change Contrast
    float contrast;
    scanf("%f", &contrast);
    if (contrast != 0.0) {
        change_contrast(img, width, height, contrast);
    }

    // Print Output Image
    printf("%d %d\n", width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}