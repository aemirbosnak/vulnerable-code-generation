//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function prototypes
void generateFractal(int x1, int y1, int x2, int y2, int depth);
void drawLine(int x1, int y1, int x2, int y2);

int main() {
    srand(time(NULL));
    int x1, y1, x2, y2, depth;

    // Get user input for fractal parameters
    printf("Enter the coordinates of the first point: ");
    scanf("%d %d", &x1, &y1);
    printf("Enter the coordinates of the second point: ");
    scanf("%d %d", &x2, &y2);
    printf("Enter the depth of the fractal: ");
    scanf("%d", &depth);

    // Generate the fractal
    generateFractal(x1, y1, x2, y2, depth);

    return 0;
}

void generateFractal(int x1, int y1, int x2, int y2, int depth) {
    int deltaX = abs(x2 - x1);
    int deltaY = abs(y2 - y1);
    int x = x1, y = y1;
    int newX, newY;

    // Draw the initial line
    drawLine(x1, y1, x2, y2);

    // Recursively generate the fractal
    for (int i = 0; i < depth; i++) {
        // Calculate the coordinates of the new point
        newX = x + (rand() % deltaX) - deltaX / 2;
        newY = y + (rand() % deltaY) - deltaY / 2;

        // Draw a line from the current point to the new point
        drawLine(x, y, newX, newY);

        // Move to the new point for the next iteration
        x = newX;
        y = newY;
    }
}

void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;
    int x = x1;
    int y = y1;

    // Determine the number of steps to take
    steps = abs(dx) + abs(dy);

    // Draw the line
    for (int i = 0; i < steps; i++) {
        if (dx > 0) {
            x++;
        } else if (dx < 0) {
            x--;
        }

        if (dy > 0) {
            y++;
        } else if (dy < 0) {
            y--;
        }

        printf("*");
    }
}