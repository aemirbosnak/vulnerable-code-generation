//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void flip_image(int* image, int width, int height) {
    int temp;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp = image[j * height + i];
            image[j * height + i] = image[(width - 1 - j) * height + (height - 1 - i)];
            image[(width - 1 - j) * height + (height - 1 - i)] = temp;
        }
    }
}

void change_brightness_contrast(int* image, int width, int height, double brightness, double contrast) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int pixel = image[j * height + i];
            int new_pixel = (int)(pixel * (brightness + contrast));
            image[j * height + i] = new_pixel;
        }
    }
}

int main() {
    int width, height, image[2048];
    int temp;

    printf("Enter width and height of image: ");
    scanf("%d%d", &width, &height);

    printf("Enter pixels of image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &image[j * height + i]);
        }
    }

    flip_image(image, width, height);
    change_brightness_contrast(image, width, height, 1.2, 0.8);

    printf("Flipped and modified image:\n");
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", image[j * height + i]);
        }
        printf("\n");
    }

    return 0;
}