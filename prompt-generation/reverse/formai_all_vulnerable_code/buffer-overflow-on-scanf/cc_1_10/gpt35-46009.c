//FormAI DATASET v1.0 Category: Image Classification system ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_IMAGES 10
#define IMAGE_DIMENSION 10

// Image structure definition
typedef struct Image {
    int pixels[IMAGE_DIMENSION][IMAGE_DIMENSION];
    bool isMalware;
} Image;

// Malware detection function
bool isMalware(Image *image) {
    int numBlackPixels = 0;
    int numWhitePixels = 0;
    for(int i = 0; i < IMAGE_DIMENSION; i++) {
        for(int j = 0; j < IMAGE_DIMENSION; j++) {
            if(image->pixels[i][j] == 0) {
                numBlackPixels++;
            } else {
                numWhitePixels++;
            }
        }
    }
    if(numBlackPixels > numWhitePixels) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Image images[NUM_IMAGES];

    // Prompt user to input pixel values for each image
    for(int i = 0; i < NUM_IMAGES; i++) {
        for(int j = 0; j < IMAGE_DIMENSION; j++) {
            for(int k = 0; k < IMAGE_DIMENSION; k++) {
                printf("Enter value for image %d, pixel (%d,%d): ", i+1, j, k);
                int pixelValue;
                scanf("%d", &pixelValue);
                images[i].pixels[j][k] = pixelValue;
            }
        }
    }

    // Detect malware for each image
    for(int i = 0; i < NUM_IMAGES; i++) {
        images[i].isMalware = isMalware(&images[i]);
    }

    // Display results
    for(int i = 0; i < NUM_IMAGES; i++) {
        printf("Image %d\n", i+1);
        printf("Is malware: %s\n", images[i].isMalware ? "true" : "false");
    }

    return 0;
}