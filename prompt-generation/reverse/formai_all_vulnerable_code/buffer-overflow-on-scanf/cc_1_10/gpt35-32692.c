//FormAI DATASET v1.0 Category: Image Editor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Function to read input image
void readImage(int image[MAX_SIZE][MAX_SIZE], int* rows, int* cols) {
    scanf("%d %d", rows, cols);
    for(int i=0 ; i<*rows ; i++) {
        for(int j=0 ; j<*cols ; j++) {
            scanf("%d", &image[i][j]);
        }
    }
}

// Function to write output image
void writeImage(int image[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("%d %d\n", rows, cols);
    for(int i=0 ; i<rows ; i++) {
        for(int j=0 ; j<cols ; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

// Function to rotate image 90 degrees clockwise
void rotateClockwise(int image[MAX_SIZE][MAX_SIZE], int* rows, int* cols) {
    int temp[MAX_SIZE][MAX_SIZE];
    for(int i=0 ; i<*rows ; i++) {
        for(int j=0 ; j<*cols ; j++) {
            temp[i][j] = image[i][j];
        }
    }
    int n = *rows;
    *rows = *cols;
    *cols = n;
    for(int i=0 ; i<*rows ; i++) {
        for(int j=0 ; j<*cols ; j++) {
            image[i][j] = temp[*cols-1-j][i];
        }
    }
}

int main() {
    int image[MAX_SIZE][MAX_SIZE];
    int rows, cols;
    readImage(image, &rows, &cols);
    rotateClockwise(image, &rows, &cols);
    writeImage(image, rows, cols);
    return 0;
}