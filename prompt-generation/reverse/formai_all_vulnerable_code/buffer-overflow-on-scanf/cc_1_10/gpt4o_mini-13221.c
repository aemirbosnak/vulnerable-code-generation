//GPT-4o-mini DATASET v1.0 Category: Fractal Generation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1024

void drawFractal(char canvas[MAX_SIZE][MAX_SIZE], int x, int y, int size) {
    // Base case: if size is 1, draw a single star
    if (size == 1) {
        canvas[y][x] = '*';
        return;
    }

    // Recursive case: draw three smaller triangles
    int newSize = size / 2;

    // Draw the top triangle
    drawFractal(canvas, x, y, newSize);
    // Draw the bottom left triangle
    drawFractal(canvas, x - newSize, y + newSize, newSize);
    // Draw the bottom right triangle
    drawFractal(canvas, x + newSize, y + newSize, newSize);
}

void initializeCanvas(char canvas[MAX_SIZE][MAX_SIZE], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            canvas[i][j] = ' ';
        }
    }
}

void printCanvas(char canvas[MAX_SIZE][MAX_SIZE], int height, int width) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }
}

int main() {
    int size;
    char canvas[MAX_SIZE][MAX_SIZE];

    // Setting the desired fractal depth
    printf("Enter the depth of the Sierpiński triangle (1-10): ");
    scanf("%d", &size);

    if (size < 1 || size > 10) {
        printf("Depth must be between 1 and 10!\n");
        return 1;
    }

    // Calculate the initial size of the triangle
    size = pow(2, size); // 2^depth gives the size
    int height = size; // height will be equal to size
    int width = size * 2; // width will be double the size for proper centering

    // Initialize the canvas
    initializeCanvas(canvas, height, width);

    // Draw the fractal
    drawFractal(canvas, width / 2, 0, size);

    // Print the canvas with fractal
    printCanvas(canvas, height, width);

    return 0;
}