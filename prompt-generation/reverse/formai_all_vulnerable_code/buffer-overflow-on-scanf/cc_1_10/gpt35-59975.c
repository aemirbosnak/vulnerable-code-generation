//FormAI DATASET v1.0 Category: Image compression ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main(){
    int image[MAX_SIZE][MAX_SIZE]; // stores pixel values of image
    int rows, columns; // dimensions of image

    printf("Enter the number of rows and columns of the image: ");
    scanf("%d %d", &rows, &columns);

    // Read pixel values into the image array
    printf("Enter the pixel values of the image (between 0 and 255):\n");
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            scanf("%d", &image[i][j]);
        }
    }

    // Declare and initialize the compressed matrix to all zeroes
    int compressed[MAX_SIZE][MAX_SIZE] = {0};

    // Compress the image by replacing contiguous pixel values with a count of the value 
    int compressed_rows = 0; // tracks the rows in the compressed matrix
    for(int i = 0; i < rows; i++){
        int current_value = image[i][0];
        int count = 1;
        for(int j = 1; j < columns; j++){
            if(image[i][j] == current_value){
                count++;
            } else {
                compressed[compressed_rows][current_value] = count;
                current_value = image[i][j];
                count = 1;
            }
        }
        compressed[compressed_rows][current_value] = count;
        compressed_rows++;
    }

    // Print the compressed matrix
    printf("\nCompressed matrix:\n");
    for(int i = 0; i < compressed_rows; i++){
        for(int j = 0; j < 256; j++){
            if(compressed[i][j] > 0){
                printf("%d:%d ", j, compressed[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}