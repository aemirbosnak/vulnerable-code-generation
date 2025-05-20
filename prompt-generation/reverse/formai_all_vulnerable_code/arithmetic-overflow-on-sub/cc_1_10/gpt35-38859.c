//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to flip the image
void flip_image(int image[100][100], int rows, int cols){
    int i, j, temp;
    for(i=0; i<rows; i++){
        for(j=0; j<cols/2; j++){
            //swapping the pixel values
            temp = image[i][j];
            image[i][j] = image[i][cols-j-1];
            image[i][cols-j-1] = temp;
        }
    }
}

//function to change the brightness and contrast of the image
void change_brightness_contrast(int image[100][100], int rows, int cols, int brightness, int contrast){
    int i, j, pixel;
    float factor = (259*(contrast+255))/(255*(259-contrast));
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            //updating the brightness of the pixel
            pixel = image[i][j] + brightness;
            //applying the contrast factor to the pixel
            pixel = factor*(pixel-128) + 128;
            //applying bounds to the pixel value
            if(pixel < 0)
                pixel = 0;
            else if(pixel > 255)
                pixel = 255;
            //setting the new pixel value to the image
            image[i][j] = pixel;
        }
    }
}

int main(){
    int image[100][100], rows, cols, i, j, option, brightness, contrast;
    
    //taking input image from user
    printf("Enter the number of rows and columns of the image: ");
    scanf("%d%d", &rows, &cols);
    printf("Enter the pixel values of the image:\n");
    for(i=0; i<rows; i++){
        for(j=0; j<cols; j++){
            scanf("%d", &image[i][j]);
        }
    }
    
    //displaying the menu and taking user's option
    do{
        printf("\nMenu:\n1. Flip the image\n2. Change brightness and contrast\n3. Exit\nEnter your option: ");
        scanf("%d", &option);
        switch(option){
            case 1:
                flip_image(image, rows, cols); //calling the flip_image function
                printf("Image after flipping:\n");
                for(i=0; i<rows; i++){
                    for(j=0; j<cols; j++){
                        printf("%d ", image[i][j]);
                    }
                    printf("\n");
                }
                break;
            
            case 2:
                printf("Enter the brightness value: ");
                scanf("%d", &brightness);
                printf("Enter the contrast value: ");
                scanf("%d", &contrast);
                change_brightness_contrast(image, rows, cols, brightness, contrast); //calling the change_brightness_contrast function
                printf("Image after changing brightness and contrast:\n");
                for(i=0; i<rows; i++){
                    for(j=0; j<cols; j++){
                        printf("%d ", image[i][j]);
                    }
                    printf("\n");
                }
                break;
            
            case 3:
                exit(0); //exiting the program
            
            default:
                printf("Invalid option! Please select a valid option.\n");
        }
    }while(1); //looping until user selects the exit option
    
    return 0;
}