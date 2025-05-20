//FormAI DATASET v1.0 Category: Image compression ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to compress the image
void compress_image(int image[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    int i, j, count;
    int compressed[MAX_SIZE * MAX_SIZE][2];
    int k = 0;
    
    // Iterate over the image matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            
            count = 1;
            
            // Repeat counting until the pixel value changes
            while (j < columns - 1 && image[i][j] == image[i][j + 1]) {
                count++;
                j++;
            }
            
            // Store the compressed pixel values
            compressed[k][0] = image[i][j];
            compressed[k][1] = count;
            k++;
        }
    }
    
    // Print the compressed image
    printf("\nCompressed Image:\n");
    for (i = 0; i < k; i++) {
        printf("%d %d ", compressed[i][0], compressed[i][1]);
    }
}

int main() {
    int image[MAX_SIZE][MAX_SIZE];
    int rows, columns, i, j;
    
    printf("Enter the number of rows and columns of the image (maximum 1000): ");
    scanf("%d %d", &rows, &columns);
    
    printf("Enter the pixel values of the image:\n");
    
    // Read the pixel values
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            scanf("%d", &image[i][j]);
        }
    }
    
    // Compress the image
    compress_image(image, rows, columns);
    
    return 0;
}