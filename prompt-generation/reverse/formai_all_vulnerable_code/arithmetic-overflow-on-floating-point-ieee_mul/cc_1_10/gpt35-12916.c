//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: authentic
#include <stdio.h>

#define MAX 1000

void flipImage(int numRows, int numCols, int image[MAX][MAX]) {
    for(int i=0; i<numRows; i++) {
        for(int j=0; j<numCols/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][numCols-j-1];
            image[i][numCols-j-1] = temp;
        }
    }
}

void changeBrightness(int numRows, int numCols, int image[MAX][MAX], int brightness) {
    for(int i=0; i<numRows; i++) {
        for(int j=0; j<numCols; j++) {
            int newPixel = image[i][j] + brightness;
            if(newPixel < 0) {
                newPixel = 0;
            }
            else if(newPixel > 255) {
                newPixel = 255;
            }
            image[i][j] = newPixel;
        }
    }
}

void changeContrast(int numRows, int numCols, int image[MAX][MAX], float contrast) {
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    for(int i=0; i<numRows; i++) {
        for(int j=0; j<numCols; j++) {
            int newPixel = factor * (image[i][j] - 128) + 128;
            if(newPixel < 0) {
                newPixel = 0;   
            }
            else if(newPixel > 255) {
                newPixel = 255;
            }
            image[i][j] = newPixel;
        }
    }
}

int main() {
    int image[MAX][MAX];
    int numRows, numCols;
    int brightness;
    float contrast;
    
    printf("Enter number of rows: ");
    scanf("%d", &numRows);
    
    printf("Enter number of columns: ");
    scanf("%d", &numCols);
    
    for(int i=0; i<numRows; i++) {
        for(int j=0; j<numCols; j++) {
            printf("Enter pixel value for row %d, column %d: ", i+1, j+1);
            scanf("%d", &image[i][j]);
        }
    }
    
    printf("\n");
    printf("1. Flip Image\n");
    printf("2. Change Brightness\n");
    printf("3. Change Contrast\n");
    printf("\nEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            flipImage(numRows, numCols, image);
            break;
        case 2:
            printf("Enter brightness value: ");
            scanf("%d", &brightness);
            changeBrightness(numRows, numCols, image, brightness);
            break;
        case 3:
            printf("Enter contrast value: ");
            scanf("%f", &contrast);
            changeContrast(numRows, numCols, image, contrast);
            break;
        default:
            printf("Invalid choice");
            return 0;
    }
    
    printf("\n");
    printf("Processed Image:\n\n");
    for(int i=0; i<numRows; i++) {
        for(int j=0; j<numCols; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}