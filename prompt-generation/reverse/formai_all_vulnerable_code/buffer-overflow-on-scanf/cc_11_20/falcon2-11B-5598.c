//Falcon2-11B DATASET v1.0 Category: Fractal Generation ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITERATIONS 1000

void drawFractal(int x, int y, int iterations) {
    for (int i = 0; i < iterations; i++) {
        int x1 = x + 0.5;
        int y1 = y + 0.5;
        int x2 = x + 1.0;
        int y2 = y + 1.0;
        int x3 = x + 1.0;
        int y3 = y - 1.0;

        if (x1 < 0 || x1 > 1 || y1 < 0 || y1 > 1 || x2 < 0 || x2 > 1 || y2 < 0 || y2 > 1 || x3 < 0 || x3 > 1 || y3 < 0 || y3 > 1) {
            continue;
        }

        int color = 0;
        if (x1 == x && y1 == y) {
            color = 255;
        } else if (x2 == x && y2 == y) {
            color = 255;
        } else if (x3 == x && y3 == y) {
            color = 255;
        }

        printf("%d %d %d\n", x1, y1, color);
    }
}

int main() {
    int x = 0;
    int y = 0;
    int iterations = 0;

    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);
    printf("Enter iterations: ");
    scanf("%d", &iterations);

    for (int i = 0; i < iterations; i++) {
        drawFractal(x, y, MAX_ITERATIONS);
        printf("New iteration %d\n", i + 1);
    }

    return 0;
}