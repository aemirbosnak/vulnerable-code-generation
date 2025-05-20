//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Function to draw a fractal
void drawFractal(int x1, int y1, int x2, int y2, int depth)
{
    if (depth == 0) // base case
    {
        printf("*"); // draw a star
    }
    else // recursive case
    {
        int x3 = (x1 + x2) / 2;
        int y3 = (y1 + y2) / 2;

        drawFractal(x1, y1, x3, y3, depth - 1);
        drawFractal(x3, y3, x2, y2, depth - 1);
    }
}

// Function to generate a fractal
void generateFractal(int width, int height, int depth)
{
    int x1 = 0, y1 = height / 2 - 1; // starting point
    int x2 = width - 1, y2 = height / 2 - 1; // ending point

    for (int i = 0; i < depth; i++) // iterate over the depth
    {
        drawFractal(x1, y1, x2, y2, i); // draw the fractal
        x1 += 2; // move the starting point
        x2 -= 2; // move the ending point
        y1 += 1; // move the starting point up
        y2 -= 1; // move the ending point down
    }
}

int main()
{
    int width, height, depth;

    printf("Enter the width of the fractal: ");
    scanf("%d", &width);

    printf("Enter the height of the fractal: ");
    scanf("%d", &height);

    printf("Enter the depth of the fractal: ");
    scanf("%d", &depth);

    generateFractal(width, height, depth);

    return 0;
}