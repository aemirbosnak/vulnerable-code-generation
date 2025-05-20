//Code Llama-13B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 1000

// Structures
typedef struct {
    int width;
    int height;
    int *data;
} Image;

// Function prototypes
void flip_image(Image *img);
void change_brightness(Image *img, float factor);
void change_contrast(Image *img, float factor);

// Main function
int main() {
    // Read image
    Image img;
    img.width = 500;
    img.height = 500;
    img.data = (int *)malloc(img.width * img.height * sizeof(int));
    for (int i = 0; i < img.width * img.height; i++) {
        img.data[i] = i;
    }

    // Flip image
    flip_image(&img);

    // Change brightness
    change_brightness(&img, 2.0f);

    // Change contrast
    change_contrast(&img, 0.5f);

    // Write image
    for (int i = 0; i < img.width * img.height; i++) {
        printf("%d ", img.data[i]);
    }

    return 0;
}

// Function definitions
void flip_image(Image *img) {
    int tmp;
    for (int i = 0; i < img->width; i++) {
        for (int j = 0; j < img->height / 2; j++) {
            tmp = img->data[i * img->height + j];
            img->data[i * img->height + j] = img->data[i * img->height + (img->height - 1 - j)];
            img->data[i * img->height + (img->height - 1 - j)] = tmp;
        }
    }
}

void change_brightness(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i] = (int)(img->data[i] * factor);
    }
}

void change_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i] = (int)(img->data[i] * (1.0f + (factor - 1.0f) * (img->data[i] / 255.0f)));
    }
}