//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

#define WIDTH 120
#define HEIGHT 60

void pixelToChar(int pixel);
void newLine(int i, int *sum, int *rowSum);
int avgPixelValue(char image[HEIGHT][WIDTH], int row, int col);
void convertToAscii(char image[HEIGHT][WIDTH]);

int main() {
    FILE *fp;
    char image[HEIGHT][WIDTH];
    int i, j;
    
    fp = fopen("image.txt", 'r');
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    for(i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fscanf(fp, "%c", &image[i][j]);
        }
    }
    fclose(fp);
    
    convertToAscii(image);
    
    return 0;
}

// Takes in a pixel value 0-255 and returns its corresponding ASCII character
void pixelToChar(int pixel) {
      if (pixel < 25) {
          printf("@");
      } else if (pixel < 50) {
          printf("#");
      } else if (pixel < 75) {
          printf("+");
      } else if (pixel < 100) {
          printf(";");
      } else if (pixel < 125) {
          printf(":");
      } else if (pixel < 150) {
          printf(",");
      } else if (pixel < 175) {
          printf(".");
      } else if (pixel < 200) {
          printf(" ");
      } else if (pixel < 225) {
          printf("'");
      } else {
          printf("`");
      }
}

// If a new row is reached, prints a newline and calculates the average pixel value of the row
void newLine(int i, int *sum, int *rowSum) {
    int avgPixel = *sum / WIDTH;
    pixelToChar(avgPixel);
    *rowSum += avgPixel;
    printf("\n");
    *sum = 0;
}

// Returns the average pixel value of the 9 pixels surrounding the current pixel
int avgPixelValue(char image[HEIGHT][WIDTH], int row, int col) {
    int sum = 0;
    int count = 0;
    int i, j;
    
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if ((row + i >= 0) && (col + j >= 0) && (row + i < HEIGHT) && (col + j < WIDTH)) {
                sum += image[row + i][col +j];
                count++;
            }
        }
    }
    
    return sum / count;
}

// Converts the image to ASCII art by averaging the pixel value of each 3x3 block of pixels and outputting the corresponding ASCII character
void convertToAscii(char image[HEIGHT][WIDTH]) {
    int i, j, k;
    int sum = 0;
    int rowSum = 0;
    int avgPixel;
    
    for (i = 0; i < HEIGHT; i += 3) {
        for (j = 0; j < WIDTH; j += 3) {
            avgPixel = avgPixelValue(image, i, j);
            pixelToChar(avgPixel);
            sum += avgPixel;
            
            if (j == WIDTH - 3) {
                newLine(i, &sum, &rowSum);
            }
        }
        printf("\n"); // Prints a blank line to create a better vertical resolution for the ASCII art
        rowSum = 0;
    }
}