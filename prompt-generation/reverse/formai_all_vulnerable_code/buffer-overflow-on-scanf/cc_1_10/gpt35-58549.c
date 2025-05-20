//FormAI DATASET v1.0 Category: Fractal Generation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Function declarations
void drawFractal(int level, double x1, double y1, double x2, double y2);
void drawLine(double x1, double y1, double x2, double y2);

// Global variables
const int WIDTH = 800;  // Width of the fractal window
const int HEIGHT = 800; // Height of the fractal window
const double X_MIN = -2.0;    // Minimum x-coordinate of the fractal
const double X_MAX = 2.0;     // Maximum x-coordinate of the fractal
const double Y_MIN = -2.0;    // Minimum y-coordinate of the fractal
const double Y_MAX = 2.0;     // Maximum y-coordinate of the fractal
bool init = false;  // Flag to check if library is initialized

int main()
{
    int level;
    printf("Enter the level of the fractal: ");
    scanf("%d", &level);

    // Initialize the graphics library
    if (!init) {
        init = true;
        printf("Initializing graphics library...\n");
        // Code to initialize the graphics library goes here
    }

    // Draw the fractal
    printf("Drawing fractal...\n");
    drawFractal(level, X_MIN, Y_MIN, X_MAX, Y_MAX);

    // Close the graphics window
    printf("Closing graphics window...\n");
    // Code to close the graphics window goes here

    return 0;
}

// Function to draw the fractal
void drawFractal(int level, double x1, double y1, double x2, double y2)
{
    if (level == 0) {
        drawLine(x1, y1, x2, y2);
    } else {
        double x3 = (2 * x1 + x2) / 3;
        double y3 = (2 * y1 + y2) / 3;
        double x4 = (x1 + x2) / 2 + (y2 - y1) / (2 * sqrt(3));
        double y4 = (y1 + y2) / 2 + (x1 - x2) / (2 * sqrt(3));
        double x5 = (x1 + 2 * x2) / 3;
        double y5 = (y1 + 2 * y2) / 3;

        drawFractal(level - 1, x1, y1, x3, y3);
        drawFractal(level - 1, x3, y3, x4, y4);
        drawFractal(level - 1, x4, y4, x5, y5);
        drawFractal(level - 1, x5, y5, x2, y2);
    }
}

// Function to draw a line
void drawLine(double x1, double y1, double x2, double y2)
{
    printf("Drawing line from (%f, %f) to (%f, %f)\n", x1, y1, x2, y2);
    // Code to draw a line goes here
}