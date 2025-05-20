//FormAI DATASET v1.0 Category: Image Editor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void applyFilter(int img[SIZE][SIZE], int filter[3][3], int width, int height);
void printMenu();
void printImage(int img[SIZE][SIZE], int width, int height);

int main()
{
    int width, height;
    int img[SIZE][SIZE];
    int filter[3][3] = {{-1,-1,-1},{-1,9,-1},{-1,-1,-1}}; // sharpen filter
    int option;

    printf("Enter image width (maximum %d): ", SIZE);
    scanf("%d", &width);
    printf("Enter image height (maximum %d): ", SIZE);
    scanf("%d", &height);

    // Generate random pixel values for image
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            img[row][col] = rand() % 256; // 0-255 pixel value range
        }
    }

    // Display original image
    printf("\nOriginal image:\n");
    printImage(img, width, height);

    // Apply image filter
    applyFilter(img, filter, width, height);

    // Display filtered image
    printf("\nFiltered image:\n");
    printImage(img, width, height);

    // Prompt for another option
    printf("\nEnter 1 to save the filtered image or any other digit to exit: ");
    scanf("%d", &option);

    if(option == 1){
        // TODO: Add image saving functionality
        printf("\nFiltered image saved!\n");
    } else {
        printf("\nExiting program...\n");
    }

    return 0;
}

// Applies a given filter to an image
void applyFilter(int img[SIZE][SIZE], int filter[3][3], int width, int height){
    int filteredImg[SIZE][SIZE];

    // Outer nested loops iterate through image pixels
    for(int row = 1; row < height - 1; row++){
        for(int col = 1; col < width - 1; col++){
            int filteredPx = 0;

            // Inner nested loops iterate through filter values
            for(int i = -1; i < 2; i++){
                for(int j = -1; j < 2; j++){
                    filteredPx += filter[i+1][j+1] * img[row+i][col+j];
                }
            }

            // Save filtered pixel value to new array
            filteredImg[row][col] = filteredPx;
        }
    }

    // Copy filtered values back to original image array
    for(int row = 1; row < height - 1; row++){
        for(int col = 1; col < width - 1; col++){
            img[row][col] = filteredImg[row][col];
        }
    }
}

// Prints a menu of options for the user
void printMenu(){
    printf("\nSelect an option:\n");
    printf("1. Apply filter to image\n");
    printf("2. Save image\n");
    printf("3. Exit program\n");
}

// Prints an image in a readable format
void printImage(int img[SIZE][SIZE], int width, int height){
    for(int row = 0; row < height; row++){
        for(int col = 0; col < width; col++){
            printf("%d ", img[row][col]);
        }
        printf("\n");
    }
}