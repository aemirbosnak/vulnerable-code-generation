//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define a struct for an image
struct Image {
    int width;
    int height;
    unsigned char* pixels;
};

// Initialize an image with the specified width and height
void initImage(struct Image* img, int width, int height) {
    img->width = width;
    img->height = height;
    img->pixels = (unsigned char*)malloc(width * height * sizeof(unsigned char));
    for (int i = 0; i < width * height; i++) {
        img->pixels[i] = 0; // Set all pixels to black
    }
}

// Display an image
void displayImage(struct Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            printf("%02X ", img->pixels[y * img->width + x]);
        }
        printf("\n");
    }
    printf("\n");
}

// Close an image
void closeImage(struct Image* img) {
    free(img->pixels);
}

int main() {
    int width, height;
    printf("Enter width: ");
    scanf("%d", &width);
    printf("Enter height: ");
    scanf("%d", &height);

    struct Image img;
    initImage(&img, width, height);

    displayImage(&img);

    closeImage(&img);

    return 0;
}