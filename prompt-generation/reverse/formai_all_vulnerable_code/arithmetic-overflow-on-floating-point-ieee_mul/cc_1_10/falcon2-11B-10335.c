//Falcon2-11B DATASET v1.0 Category: Pixel Art Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate a pixel art image based on a mathematical formula
void generatePixelArt(int rows, int columns, float x1, float y1, float x2, float y2) {
    int image[rows][columns];
    float x = x1;
    float y = y1;
    int row = 0;
    int col = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            int value = sqrt(pow(x - x1, 2) + pow(y - y1, 2)) / sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
            if (value < 0.5) {
                image[i][j] = 1;
            } else {
                image[i][j] = 0;
            }
            x += 1;
            if (x >= x2) {
                x = x1;
                y += 1;
            }
        }
        row += 1;
        if (row >= rows) {
            row = 0;
            col += 1;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 10;
    int columns = 10;
    float x1 = 0.0;
    float y1 = 0.0;
    float x2 = 1.0;
    float y2 = 1.0;

    generatePixelArt(rows, columns, x1, y1, x2, y2);

    return 0;
}