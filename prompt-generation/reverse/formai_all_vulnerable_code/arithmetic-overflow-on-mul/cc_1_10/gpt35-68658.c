//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Function to flip an image horizontally
void flipImageHorizontal(int height, int width, int pixels[height][width]){
    int i, j;
    for(i=0; i<height; i++) {
        for(j=0; j<width/2; j++) {
            int temp = pixels[i][j];
            pixels[i][j] = pixels[i][width-1-j];
            pixels[i][width-1-j] = temp;
        }
    }
}

// Function to adjust the brightness of an image
void adjustBrightness(int height, int width, int pixels[height][width], int change){
    int i, j;
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            int newVal = pixels[i][j] + change;
            if(newVal<0) newVal = 0;
            if(newVal>255) newVal = 255;
            pixels[i][j] = newVal;
        }
    }
}

// Function to adjust the contrast of an image
void adjustContrast(int height, int width, int pixels[height][width], float change){
    int i, j;
    int averageLuminance = 0;
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            averageLuminance += pixels[i][j];
        }
    }
    // Calculate the average luminance of the pixels in the image
    averageLuminance /= (height*width);
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            int newVal = (int)((pixels[i][j] - averageLuminance)*change + averageLuminance);
            if(newVal<0) newVal = 0;
            if(newVal>255) newVal = 255;
            pixels[i][j] = newVal;
        }
    }
}

int main()
{
    int height, width, change;
    float contrastChange;
    printf("Enter the height of the image: ");
    scanf("%d", &height);
    printf("Enter the width of the image: ");
    scanf("%d", &width);
    int pixels[height][width];
    printf("Enter the pixel values of the image (space separated):\n");
    int i, j;
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            scanf("%d", &pixels[i][j]);
        }
    }
    printf("Enter the amount of change for brightness (negative for darker, positive for brighter): ");
    scanf("%d", &change);
    printf("Enter the amount of change for contrast (between 0 and 1): ");
    scanf("%f", &contrastChange);
    // Flip the image horizontally
    flipImageHorizontal(height, width, pixels);
    // Adjust the brightness of the image
    adjustBrightness(height, width, pixels, change);
    // Adjust the contrast of the image
    adjustContrast(height, width, pixels, contrastChange);
    printf("Modified image:\n");
    for(i=0; i<height; i++) {
        for(j=0; j<width; j++) {
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }
    return 0;
}