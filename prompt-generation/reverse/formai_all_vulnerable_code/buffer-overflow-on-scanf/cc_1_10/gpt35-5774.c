//FormAI DATASET v1.0 Category: Image Classification system ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Declare global variable to store the size of the image
int sizeOfImage = 0;

// Declare function to perform Image Classification
void imageClassification(int image[], int size);

int main() {

    // Prompt user to enter the size of the image
    printf("Enter the size of the image: ");
    scanf("%d", &sizeOfImage);
    
    // Declare array to store the pixel values of the image
    int image[sizeOfImage];
    
    // Prompt user to enter pixel values of the image
    for(int i = 0; i < sizeOfImage; i++) {
        printf("Enter pixel value %d: ", i+1);
        scanf("%d", &image[i]);
    }
    
    // Call function to perform Image Classification
    imageClassification(image, sizeOfImage);
    
    return 0;
}

void imageClassification(int image[], int size) {
    
    // Declare variables to store the count of black and white pixels in the image
    int blackPixels = 0, whitePixels = 0;
    
    // Loop through the image to check the pixel values
    for(int i = 0; i < size; i++) {
        if(image[i] == 0) {
            blackPixels++;
        } else if(image[i] == 255) {
            whitePixels++;
        }
    }
    
    // Determine the classification of the image based on pixel count
    if(blackPixels == size) {
        printf("Image is completely black\n");
    } else if(whitePixels == size) {
        printf("Image is completely white\n");
    } else if(blackPixels > whitePixels) {
        printf("Image is predominantly black\n");
    } else {
        printf("Image is predominantly white\n");
    }
}