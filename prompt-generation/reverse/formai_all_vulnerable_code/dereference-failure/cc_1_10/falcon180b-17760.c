//Falcon-180B DATASET v1.0 Category: Recursive ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure for the fractal data
typedef struct {
    int x, y;
    int color;
} FractalData;

// Define a function to print the fractal data
void printFractal(FractalData* data, int size) {
    for (int i = 0; i < size; i++) {
        printf("(%d,%d,%d) ", data[i].x, data[i].y, data[i].color);
    }
    printf("\n");
}

// Define a function to generate the fractal data recursively
void generateFractal(FractalData* data, int x, int y, int size, int color) {
    // Base case: when the size is 1, set the data and return
    if (size == 1) {
        data[0].x = x;
        data[0].y = y;
        data[0].color = color;
        return;
    }

    // Recursive case: divide the size by 2 and generate the fractal recursively
    int halfSize = size / 2;
    generateFractal(data, x, y, halfSize, color);
    generateFractal(data + halfSize, x, y + halfSize, halfSize, color);
    generateFractal(data + halfSize + halfSize, x + halfSize, y, halfSize, color);
    generateFractal(data + halfSize + halfSize + halfSize, x + halfSize, y + halfSize, halfSize, color);
}

// Define a function to set the fractal data and generate the fractal
void setFractal(FractalData* data, int size) {
    // Set the initial position and color
    int x = 0;
    int y = 0;
    int color = 1;

    // Generate the fractal recursively
    generateFractal(data, x, y, size, color);
}

// Define the main function
int main() {
    // Define the size of the fractal
    int size = 10;

    // Allocate memory for the fractal data
    FractalData* data = (FractalData*)malloc(sizeof(FractalData) * size * size);

    // Set the fractal data and generate the fractal
    setFractal(data, size);

    // Print the fractal data
    printFractal(data, size * size);

    // Free the memory for the fractal data
    free(data);

    return 0;
}