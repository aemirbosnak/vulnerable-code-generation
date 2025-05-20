//Falcon-180B DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_FIBONACCI_NUMBERS 1000

// Function to generate a random color
int getRandomColor() {
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    return (r << 16) | (g << 8) | b;
}

// Function to plot a pixel
void plotPixel(int x, int y, int color) {
    int row = y / 10;
    int col = x / 10;
    int offset = row * MAX_COLS + col;
    int index = offset * 3;

    if (offset >= 0 && offset < MAX_ROWS * MAX_COLS) {
        int* pixels = (int*)malloc(MAX_ROWS * MAX_COLS * sizeof(int));
        for (int i = 0; i < MAX_ROWS * MAX_COLS; i++) {
            pixels[i] = 0;
        }
        pixels[index] = color;
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                int value = pixels[i * MAX_COLS + j];
                printf("%6d ", value);
            }
            printf("\n");
        }
        free(pixels);
    }
}

// Function to generate Fibonacci sequence
void generateFibonacciSequence(int maxNumber) {
    int a = 0;
    int b = 1;
    int c = 0;

    for (int i = 0; i < maxNumber; i++) {
        plotPixel(a, i, getRandomColor());
        plotPixel(b, i, getRandomColor());
        int temp = a;
        a = b;
        b += temp;
        c = a + b;
    }
}

int main() {
    srand(time(NULL));

    int rows = 50;
    int cols = 50;

    int maxNumber = rows * cols;

    printf("Enter the maximum number of Fibonacci numbers to generate: ");
    scanf("%d", &maxNumber);

    generateFibonacciSequence(maxNumber);

    return 0;
}