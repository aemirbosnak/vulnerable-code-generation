//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define HEIGHT 100
#define WIDTH 100
#define MAX_VALUE 255

int main() {
    int image[HEIGHT][WIDTH]; // Initialize image array
    int flipped_image[HEIGHT][WIDTH]; // Initialize flipped image array
    
    // Read image values from user
    printf("Enter image values:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            scanf("%d", &image[i][j]);
        }
    }
    
    // Flip image
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            flipped_image[i][j] = image[HEIGHT - i - 1][WIDTH - j - 1];
        }
    }
    
    // Change brightness
    int brightness = 50; // Example value
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            flipped_image[i][j] += brightness;
            if (flipped_image[i][j] > MAX_VALUE) {
                flipped_image[i][j] = MAX_VALUE;
            } else if (flipped_image[i][j] < 0) {
                flipped_image[i][j] = 0;
            }
        }
    }
    
    // Change contrast
    int contrast = 50; // Example value
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            flipped_image[i][j] = (flipped_image[i][j] - 127) * contrast + 127;
            if (flipped_image[i][j] > MAX_VALUE) {
                flipped_image[i][j] = MAX_VALUE;
            } else if (flipped_image[i][j] < 0) {
                flipped_image[i][j] = 0;
            }
        }
    }
    
    // Print flipped image
    printf("Flipped image:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", flipped_image[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}