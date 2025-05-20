//Falcon-180B DATASET v1.0 Category: Fractal Generation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to generate fractal
void generateFractal(int x1, int y1, int x2, int y2, int depth) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int err = 0;
    int e2 = 0;
    for (int i = 0; i < depth; i++) {
        int x = x1 + i * dx / depth;
        int y = y1 + i * dy / depth;
        printf("*");
        if (i == depth - 1) {
            continue;
        }
        e2 = err;
        if (e2 == 0) {
            y += dy;
            dx += 2;
            err += dy;
        } else if (e2 > 0) {
            x += dx;
            y += 2;
            err += dx - 2 * dy;
        } else {
            x += dx;
            y += dy;
            err += dx + 2 * dy;
        }
    }
}

int main() {
    int width, height, depth;
    printf("Enter the width of the fractal: ");
    scanf("%d", &width);
    printf("Enter the height of the fractal: ");
    scanf("%d", &height);
    printf("Enter the depth of the fractal: ");
    scanf("%d", &depth);

    int x1 = 0, y1 = 0, x2 = width - 1, y2 = height - 1;
    for (int i = 0; i < depth; i++) {
        generateFractal(x1, y1, x2, y2, depth);
        printf("\n");
        y1++;
        y2--;
        x1++;
        x2--;
    }

    return 0;
}