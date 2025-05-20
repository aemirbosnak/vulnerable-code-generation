//FormAI DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1000

int main()
{   
    int image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];    
    int height, width, choice, num_pixels;
    
    printf("------ Welcome to the Irregular Image Editor ------\n\n");
    
    printf("Enter the height of image: ");
    scanf("%d", &height);
    
    printf("Enter the width of image: ");
    scanf("%d", &width);
    
    if(height > MAX_IMAGE_SIZE || width > MAX_IMAGE_SIZE){
        printf("Error: Image size is too large.");
        exit(0);
    }
    
    num_pixels = height * width;
    
    printf("\nEnter the pixels of the image:\n\n");   

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("Enter pixel[%d][%d]: ", i, j);
            scanf("%d", &image[i][j]);
        }
    }

    printf("\nWhat would you like to do?\n");

    do {
        printf("\n1. Flip horizontal");
        printf("\n2. Flip vertical");
        printf("\n3. Rotate 90 degrees");
        printf("\n4. Increase brightness");
        printf("\n5. Decrease brightness");
        printf("\n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                for(int i=0; i<height; i++){
                    for(int j=0; j<width/2; j++){
                        int temp = image[i][j];
                        image[i][j] = image[i][width - j - 1];
                        image[i][width - j - 1] = temp;
                    }
                }
                printf("\nImage flipped horizontally!\n");
                break;
                
            case 2:
                for(int i=0; i<height/2; i++){
                    for(int j=0; j<width; j++){
                        int temp = image[i][j];
                        image[i][j] = image[height - i - 1][j];
                        image[height - i - 1][j] = temp;
                    }
                }
                printf("\nImage flipped vertically!\n");
                break;
                
            case 3:
                {
                    int temp = height;
                    height = width;
                    width = temp;
                    int new_image[MAX_IMAGE_SIZE][MAX_IMAGE_SIZE];
                    for(int i=0; i<height; i++){
                        for(int j=0; j<width; j++){
                            new_image[i][j] = image[height - j - 1][i];
                        }
                    }
                    for(int i=0; i<height; i++){
                        for(int j=0; j<width; j++){
                            image[i][j] = new_image[i][j];
                        }
                    }
                    printf("\nImage rotated 90 degrees!\n");
                    break;
                }
                
            case 4:
                for(int i=0; i<height; i++){
                    for(int j=0; j<width; j++){
                        if(image[i][j] < 255){
                            image[i][j] += 1;
                        }
                    }
                }
                printf("\nBrightness increased!\n");
                break;
                
            case 5:
                for(int i=0; i<height; i++){
                    for(int j=0; j<width; j++){
                        if(image[i][j] > 0){
                            image[i][j] -= 1;
                        }
                    }
                }
                printf("\nBrightness decreased!\n");
                break;
                
            case 6:
                printf("\nExiting program...\n");
                break;
                
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;          
        }
        
    } while(choice != 6);

    printf("\nFinal image: \n\n");

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}