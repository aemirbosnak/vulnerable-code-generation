//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

/* function prototypes */
void flipImage(unsigned char* image, int width, int height);
void adjustBrightness(unsigned char* image, int width, int height, int brightness);
void adjustContrast(unsigned char* image, int width, int height, int contrast);

/* main function */
int main()
{
    int width, height, choice;
    
    /* read image dimensions */
    printf("Enter width and height of the image: ");
    scanf("%d %d", &width, &height);
    
    /* allocate memory for the image */
    unsigned char* image = (unsigned char*)malloc(width * height);
    
    /* read image data */
    printf("Enter pixel values for the image (0-255):\n");
    for(int i=0; i<width*height; i++) {
        scanf("%hhu", &image[i]);
    }
    
    /* display menu */
    do {
        printf("\nChoose a task to perform:\n");
        printf("1. Flip image\n");
        printf("2. Adjust brightness\n");
        printf("3. Adjust contrast\n");
        printf("4. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                flipImage(image, width, height);
                printf("\nImage flipped successfully!\n");
                break;
            case 2:
                printf("\nEnter brightness value (-255 to 255): ");
                int brightness;
                scanf("%d", &brightness);
                adjustBrightness(image, width, height, brightness);
                printf("\nBrightness adjusted successfully!\n");
                break;
            case 3:
                printf("\nEnter contrast value (-255 to 255): ");
                int contrast;
                scanf("%d", &contrast);
                adjustContrast(image, width, height, contrast);
                printf("\nContrast adjusted successfully!\n");
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    } while(choice != 4);
    
    /* free memory */
    free(image);
    
    return 0;
}

/* function to flip image horizontally */
void flipImage(unsigned char* image, int width, int height) {
    for(int row=0; row<height; row++) {
        for(int col=0; col<width/2; col++) {
            unsigned char temp = image[row*width + col];
            image[row*width + col] = image[row*width + width - col - 1];
            image[row*width + width - col - 1] = temp;
        }
    }
}

/* function to adjust brightness */
void adjustBrightness(unsigned char* image, int width, int height, int brightness) {
    for(int i=0; i<width*height; i++) {
        int value = image[i] + brightness;
        if(value < 0) value = 0;
        if(value > 255) value = 255;
        image[i] = (unsigned char)value;
    }
}

/* function to adjust contrast */
void adjustContrast(unsigned char* image, int width, int height, int contrast) {
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for(int i=0; i<width*height; i++) {
        int value = factor * (image[i] - 128) + 128;
        if(value < 0) value = 0;
        if(value > 255) value = 255;
        image[i] = (unsigned char)value;
    }
}