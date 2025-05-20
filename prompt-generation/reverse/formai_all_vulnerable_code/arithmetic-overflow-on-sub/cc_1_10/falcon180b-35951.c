//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define MAX_COLOR 256

// Function to generate fractal
void generateFractal(int x1, int y1, int x2, int y2, int color) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = 0;
    int err = dx - dy;
    int x = x1;
    int y = y1;

    while (steps < MAX_ITERATIONS) {
        if (err > -dy) {
            x += 1;
            y += 1;
            err += dy;
        } else {
            err += dx;
        }
        steps++;
    }

    if (color == 0) {
        printf(" ");
    } else {
        printf("%c", 219 + color);
    }
}

// Function to generate fractal pattern
void generatePattern(int x1, int y1, int x2, int y2, int color) {
    int i;
    for (i = x1; i <= x2; i++) {
        generateFractal(i, y1, i, y2, color);
    }
}

int main() {
    int x1, y1, x2, y2;
    int color;

    printf("Enter the coordinates of the first point: ");
    scanf("%d %d", &x1, &y1);

    printf("Enter the coordinates of the second point: ");
    scanf("%d %d", &x2, &y2);

    printf("Enter the color of the fractal (0-255): ");
    scanf("%d", &color);

    generatePattern(x1, y1, x2, y2, color);

    return 0;
}