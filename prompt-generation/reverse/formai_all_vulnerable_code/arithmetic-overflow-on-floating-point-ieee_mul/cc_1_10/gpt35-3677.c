//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// Function to flip an image
void flipImage(int image[], int size){
    int temp;
    for(int i = 0; i < size/2; i++){
        for(int j = 0; j < size; j++){
            temp = image[i*size+j];
            image[i*size+j] = image[(size-1-i)*size+j];
            image[(size-1-i)*size+j] = temp;
        }
    }
}

// Function to change the brightness of an image
void changeBrightness(int image[], int size, int brightness){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            // Adjusting the brightness level
            int pixel = image[i*size+j] + brightness;
            if(pixel > 255){
                pixel = 255;
            } else if(pixel < 0){
                pixel = 0;
            }
            image[i*size+j] = pixel;
        }
    }
}

// Function to change the contrast of an image
void changeContrast(int image[], int size, float contrast){
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            // Adjusting the contrast level
            int pixel = (int)(factor * (image[i*size+j] - 128) + 128);
            if(pixel > 255){
                pixel = 255;
            } else if(pixel < 0){
                pixel = 0;
            }
            image[i*size+j] = pixel;
        }
    }
}

int main(){
    int option = 0;
    int size = 0;
    int brightness = 0;
    float contrast = 0.0f;
    int* image = NULL;
    
    printf("******** Image Processing Program ********\n");
    printf("Enter the size of the image: ");
    scanf("%d", &size);
    
    // Allocating memory for the image
    image = (int*)malloc(size*size*sizeof(int));
    
    // Accepting user input for the image
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            printf("Enter the pixel value for row %d and column %d: ", i+1, j+1);
            scanf("%d", &image[i*size+j]);
        }
    }
    
    printf("\n\nWhich operation do you want to perform?\n");
    printf("1. Flip Image\n");
    printf("2. Change Brightness\n");
    printf("3. Change Contrast\n");
    printf("Enter your option (1-3): ");
    scanf("%d", &option);
    
    switch(option){
        case 1:
            flipImage(image, size);
            printf("\n******** Flipped Image ********\n");
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    printf("%d ", image[i*size+j]);
                }
                printf("\n");
            }
            break;
        case 2:
            printf("Enter the brightness value (-255 to +255): ");
            scanf("%d", &brightness);
            changeBrightness(image, size, brightness);
            printf("\n******** Brightness-adjusted Image ********\n");
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    printf("%d ", image[i*size+j]);
                }
                printf("\n");
            }
            break;
        case 3:
            printf("Enter the contrast value (0.0 to 2.0): ");
            scanf("%f", &contrast);
            changeContrast(image, size, contrast);
            printf("\n******** Contrast-adjusted Image ********\n");
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size; j++){
                    printf("%d ", image[i*size+j]);
                }
                printf("\n");
            }
            break;
        default:
            printf("Invalid option selected. Program terminated.");
            break;
    }
    
    free(image);
    
    return 0;
}