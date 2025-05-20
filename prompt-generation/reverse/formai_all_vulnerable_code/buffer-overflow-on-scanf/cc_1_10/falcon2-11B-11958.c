//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_WIDTH 640
#define MAX_HEIGHT 480

// Function to rotate an image by 90 degrees
void rotate(int* image, int width, int height) {
    int temp;
    for (int i = 0; i < height / 2; i++) {
        for (int j = 0; j < width; j++) {
            temp = image[(width - 1 - j) + (height - 1 - i) * width];
            image[(width - 1 - j) + (height - 1 - i) * width] = image[j + (height - 1 - i) * width];
            image[j + (height - 1 - i) * width] = temp;
        }
    }
}

int main() {
    int image[MAX_HEIGHT][MAX_WIDTH];

    printf("Enter the number of rows in the image: ");
    int rows;
    scanf("%d", &rows);

    printf("Enter the number of columns in the image: ");
    int columns;
    scanf("%d", &columns);

    printf("Enter the pixels in the image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("Enter pixel at (%d, %d): ", i, j);
            scanf("%d", &image[i][j]);
        }
    }

    printf("The original image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    rotate(image, columns, rows);

    printf("The rotated image:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}