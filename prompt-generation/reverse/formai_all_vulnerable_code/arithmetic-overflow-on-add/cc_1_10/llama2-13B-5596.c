//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_STRING_LENGTH 100
#define MAX_INT 100000

void printPattern(int numRows, int numCols, int startX, int startY, int stepX, int stepY) {
    int i, j;
    for (i = startY; i < startY + numRows; i++) {
        for (j = startX; j < startX + numCols; j++) {
            if (i % stepY == 0 && j % stepX == 0) {
                printf("*");
            } else if (i % stepY == 0 && j % stepX != 0) {
                printf(" ");
            } else if (i % stepY != 0 && j % stepX == 0) {
                printf("-");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    int numRows, numCols;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &numRows, &numCols);
    if (numRows < 1 || numCols < 1) {
        printf("Invalid input. Please enter positive integers.\n");
        return 1;
    }

    int startX = 0, startY = 0;
    int stepX = 1, stepY = 1;
    printf("Enter the starting coordinates (x, y): ");
    scanf("%d%d", &startX, &startY);
    if (startX < 0 || startY < 0) {
        printf("Invalid input. Please enter positive integers.\n");
        return 1;
    }

    printf("Enter the step sizes (x, y): ");
    scanf("%d%d", &stepX, &stepY);
    if (stepX < 1 || stepY < 1) {
        printf("Invalid input. Please enter positive integers.\n");
        return 1;
    }

    printPattern(numRows, numCols, startX, startY, stepX, stepY);

    return 0;
}