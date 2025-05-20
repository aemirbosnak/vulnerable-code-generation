//FormAI DATASET v1.0 Category: Image Editor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    // Image matrix
    int image[100][100];
    
    // Inputting dimensions of image
    int height, width;
    printf("Enter height and width of image: ");
    scanf("%d %d", &height, &width);
    
    // Inputting values for each pixel of the image
    printf("Enter the image array: \n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    // Outputting the original image
    printf("Original Image: \n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Applying grayscale transformation on the image
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            int avg = (image[i][j] >> 16) & 0xFF;
            avg += (image[i][j] >> 8) & 0xFF;
            avg += image[i][j] & 0xFF;
            avg /= 3;
            image[i][j] = avg;
        }
    }

    // Outputting the grayscale image
    printf("Grayscale Image: \n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    // Applying edge detection on the image
    int edge_image[100][100];
    for(int i=1; i<height-1; i++) {
        for(int j=1; j<width-1; j++) {
            int x = ((image[i-1][j-1] + image[i-1][j] + image[i-1][j+1]) - (image[i+1][j-1] + image[i+1][j] + image[i+1][j+1]));
            int y = ((image[i-1][j-1] + image[i][j-1] + image[i+1][j-1]) - (image[i-1][j+1] + image[i][j+1] + image[i+1][j+1]));
            edge_image[i][j] = (int)(sqrt(x*x + y*y));
        }
    }

    // Outputting the edge detected image
    printf("Edge Detected Image: \n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%d ", edge_image[i][j]);
        }
        printf("\n");
    }

    return 0;
}