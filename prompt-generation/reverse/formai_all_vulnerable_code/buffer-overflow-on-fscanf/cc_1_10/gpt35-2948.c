//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

void setColor(double grayValue);

int main(int argc, char* argv[]) {
    if(argc < 2) {
        printf("Please provide an image file name.\n");
        return 1;
    }

    char* fileName = argv[1];
    FILE* file = fopen(fileName, "r");
    if(file == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    // Load image dimensions from file header (P2 format)
    int width, height, maxVal;
    fscanf(file, "P2 %d %d %d", &width, &height, &maxVal);

    // Read in pixel values into a 2D array (image)
    int image[MAX_HEIGHT][MAX_WIDTH];
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int pixel;
            fscanf(file, "%d", &pixel);
            image[i][j] = pixel;
        }
    }

    // Convert image to ASCII art
    printf("Resulting ASCII art:\n");
    for(int i = 0; i < height; i += 10) {
        for(int j = 0; j < width; j += 5) {
            double sum = 0;
            for(int k = 0; k < 10; k++) {
                for(int l = 0; l < 5; l++) {
                    int currPixel = image[i+k][j+l];
                    sum += currPixel;
                }
            }
            double avg = sum / 50.0;
            setColor(avg);
            printf("X");
        }
        printf("\n");
    }

    return 0;
}

void setColor(double grayValue) {
    if(grayValue > 230) {
        printf("\033[0;37m"); // Light gray
    } else if(grayValue > 200) {
        printf("\033[0;34m"); // Blue
    } else if(grayValue > 170) {
        printf("\033[0;33m"); // Yellow
    } else if(grayValue > 140) {
        printf("\033[0;32m"); // Green
    } else if(grayValue > 110) {
        printf("\033[0;36m"); // Cyan
    } else if(grayValue > 80) {
        printf("\033[0;31m"); // Red
    } else {
        printf("\033[0;30m"); // Black
    }
}