//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

/* Function to flip an image */
void flipImage(int **image, int height, int width) {
    int i, j;
    int temp;
    
    for(i = 0; i < height/2; i++) {
        for(j = 0; j < width; j++) {
            /* Swap values of top and bottom rows */
            temp = image[i][j];
            image[i][j] = image[height - 1 - i][j];
            image[height - 1 - i][j] = temp;
        }
    }
}

/* Function to change brightness of an image */
void changeBrightness(int **image, int height, int width, int brightness) {
    int i, j;
    
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            /* Add brightness value to each pixel value */
            image[i][j] += brightness;
            
            /* Ensure that each pixel value is within the range of 0-255 */
            if(image[i][j] < 0) {
                image[i][j] = 0;
            }
            else if(image[i][j] > 255) {
                image[i][j] = 255;
            }
        }
    }
}

/* Function to change contrast of an image */
void changeContrast(int **image, int height, int width, int contrast) {
    int i, j;
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            /* Apply contrast formula to each pixel value */
            image[i][j] = (int)(factor * (image[i][j] - 128) + 128);
            
            /* Ensure that each pixel value is within the range of 0-255 */
            if(image[i][j] < 0) {
                image[i][j] = 0;
            }
            else if(image[i][j] > 255) {
                image[i][j] = 255;
            }
        }
    }
}

int main() {
    int height, width, brightness, contrast, i, j;
    int **image;
    
    /* Read image dimensions from user */
    printf("Enter height and width of image: ");
    scanf("%d %d", &height, &width);
    
    /* Allocate memory for image */
    image = (int **)malloc(height * sizeof(int *));
    for(i = 0; i < height; i++) {
        image[i] = (int *)malloc(width * sizeof(int));
    }
    
    /* Read pixel values of image from user */
    printf("Enter pixel values of image:\n");
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            scanf("%d", &image[i][j]);
        }
    }
    
    /* Read brightness and contrast values from user */
    printf("Enter brightness value: ");
    scanf("%d", &brightness);
    
    printf("Enter contrast value: ");
    scanf("%d", &contrast);
    
    /* Flip image */
    flipImage(image, height, width);
    
    /* Change brightness of image */
    changeBrightness(image, height, width, brightness);
    
    /* Change contrast of image */
    changeContrast(image, height, width, contrast);
    
    /* Print modified image */
    printf("Modified image:\n");
    for(i = 0; i < height; i++) {
        for(j = 0; j < width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    /* Free memory */
    for(i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);
    
    return 0;
}