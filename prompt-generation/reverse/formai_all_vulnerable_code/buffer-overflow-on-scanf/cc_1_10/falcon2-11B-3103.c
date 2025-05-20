//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to extract hidden image from stego image
void extract_image(unsigned char *img, unsigned char *stego_img, int width, int height, int stride) {
    int i, j, k;
    unsigned char *image = (unsigned char *)malloc(width * height * sizeof(char));
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            for (k = 0; k < stride; k++) {
                image[j * width + i] = stego_img[j * stride + i];
            }
        }
    }
    printf("Extracted image: \n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%02x", image[i * width + j]);
        }
        printf("\n");
    }
    free(image);
}

// Function to hide image in stego image
void hide_image(unsigned char *img, unsigned char *stego_img, int width, int height, int stride) {
    int i, j, k;
    unsigned char *image = (unsigned char *)malloc(width * height * sizeof(char));
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            for (k = 0; k < stride; k++) {
                image[j * width + i] = img[j * stride + i];
            }
        }
    }
    printf("Hidden image: \n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%02x", image[i * width + j]);
        }
        printf("\n");
    }
    free(image);
}

int main() {
    unsigned char img[1000][1000] = {0}; // Input image
    unsigned char stego_img[1000][1000] = {0}; // Stego image
    int width, height, stride;
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    stride = width * sizeof(char);
    printf("Enter the stride of the image: ");
    scanf("%d", &stride);
    printf("Enter the input image: \n");
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < stride; k++) {
                scanf("%02x", &img[i][j]);
            }
        }
    }
    printf("Enter the stego image: \n");
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            for (int k = 0; k < stride; k++) {
                scanf("%02x", &stego_img[i][j]);
            }
        }
    }
    extract_image(img, stego_img, width, height, stride);
    printf("Do you want to hide the image? (y/n): ");
    char choice;
    scanf("%c", &choice);
    if (choice == 'y') {
        hide_image(img, stego_img, width, height, stride);
    }
    return 0;
}