//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 500
#define HEIGHT 500

// Function to create a random image
void createRandomImage(int *img, int width, int height) {
    srand(time(NULL));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            img[i * height + j] = rand() % 256;
        }
    }
}

// Function to flip an image horizontally
void flipHorizontal(int *img, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height / 2; j++) {
            int temp = img[i * height + j];
            img[i * height + j] = img[i * height + height - j - 1];
            img[i * height + height - j - 1] = temp;
        }
    }
}

// Function to change brightness and contrast of an image
void changeBrightnessContrast(int *img, int width, int height, int brightness, int contrast) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            int value = img[i * height + j];
            int newValue = ((value * contrast) / 100) + brightness;
            if (newValue > 255) {
                newValue = 255;
            } else if (newValue < 0) {
                newValue = 0;
            }
            img[i * height + j] = newValue;
        }
    }
}

// Function to display an image
void displayImage(int *img, int width, int height) {
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            printf("%d ", img[i * height + j]);
        }
        printf("\n");
    }
}

int main() {
    int *img;
    img = (int *) malloc(WIDTH * HEIGHT * sizeof(int));
    createRandomImage(img, WIDTH, HEIGHT);
    displayImage(img, WIDTH, HEIGHT);

    flipHorizontal(img, WIDTH, HEIGHT);
    printf("\nAfter flipping horizontally:\n");
    displayImage(img, WIDTH, HEIGHT);

    changeBrightnessContrast(img, WIDTH, HEIGHT, 50, 150);
    printf("\nAfter changing brightness and contrast:\n");
    displayImage(img, WIDTH, HEIGHT);

    free(img);
    return 0;
}